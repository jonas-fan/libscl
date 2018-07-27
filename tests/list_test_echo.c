#define _GNU_SOURCE

#include "../lib/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    struct list list;
    struct list_entry *entry;
    int index;

    list_init(&list);

    for (index = 1; index < argc; ++index) {
        char *str = strdup(argv[index]);
        assert(str);
        int rc = list_push_back(&list, str);
        assert(rc == 1);
    }

    list_for_each(&list, entry) {
        printf("%s\n", (char *)entry->data);
    }

    while (!list_empty(&list)) {
        entry = list_front(&list);
        free(entry->data);
        list_pop_front(&list);
    }

    list_term(&list);

    return 0;
}