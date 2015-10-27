#include <ring_buffer.h>

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static unsigned int running = 0;

static inline void * produce(void *user_data)
{
    ringbuffer_t *ring_buffer = (ringbuffer_t *)user_data;

    unsigned int data = 0;

    while (running) {
        ringbuffer_push(ring_buffer, &data, sizeof(data));

        // printf("Send: %u\n", data);

        ++data;

        usleep(1 * 1000);
    }

    pthread_exit(NULL);
}

static inline void * consume(void *user_data)
{
    ringbuffer_t *ring_buffer = (ringbuffer_t *)user_data;

    unsigned int data;

    while (running) {
        if (ringbuffer_pop(ring_buffer, &data, sizeof(data)) > 0) {
            // printf("Recv: %u\n", data);
        }
    }

    pthread_exit(NULL);
}

int main(/*int argc, char *argv[]*/)
{
    ringbuffer_t *ring_buffer = ringbuffer_create(sizeof(unsigned int) * 8);

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