#include <ring_buffer.h>

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct
{
    unsigned int index;
    char data[28];
} test_data_t;

static unsigned int running = 0;

static inline void * produce(void *user_data)
{
    ringbuffer_t *ring_buffer = (ringbuffer_t *)user_data;

    test_data_t data;

    data.index = 0;
    snprintf(data.data, sizeof(data.data), "%s", "data.....");

    while (running) {
        ringbuffer_push(ring_buffer, &data, sizeof(data));

        ++data.index;

        // usleep(1 * 1000);
    }

    printf("Send count: %u\n", data.index);

    pthread_exit(NULL);
}

static inline void * consume(void *user_data)
{
    ringbuffer_t *ring_buffer = (ringbuffer_t *)user_data;

    test_data_t data;
    unsigned int count = 0;

    while (running) {
        if (ringbuffer_pop(ring_buffer, &data, sizeof(data)) == sizeof(data)) {
            // printf("Recv: %u, %s\n", data.index, data.data);
            ++count;
        }
    }

    printf("Recv count: %u\n", count);

    pthread_exit(NULL);
}

int main(/*int argc, char *argv[]*/)
{
    ringbuffer_t *ring_buffer = ringbuffer_create(sizeof(test_data_t) * 128);

    pthread_t consumer;
    pthread_t producer;

    running = 1;

    pthread_create(&consumer, NULL, consume, ring_buffer);
    pthread_create(&producer, NULL, produce, ring_buffer);

    sleep(3);

    running = 0;

    pthread_join(consumer, NULL);
    pthread_join(producer, NULL);

    ringbuffer_destroy(ring_buffer);

    printf("[\033[32mOK\033[m]\n");

    return 0;
}