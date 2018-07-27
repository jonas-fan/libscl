#define _GNU_SOURCE

#include "../src/vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    struct vector vector;
    struct vector_entry *entry;
    int index;

    vector_init(&vector);

    for (index = 1; index < argc; ++index) {
        char *str = strdup(argv[index]);
        assert(str);
        int rc = vector_push_back(&vector, str);
        assert(rc == 1);
    }

    vector_for_each(&vector, entry) {
        printf("%s\n", (char *)entry->data);
    }

    while (!vector_empty(&vector)) {
        entry = vector_back(&vector);
        free(entry->data);
        vector_pop_back(&vector);
    }

    vector_term(&vector);

    return 0;
}