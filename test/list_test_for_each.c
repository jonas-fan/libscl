#define _GNU_SOURCE

#include "../src/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    struct list list;
    struct list_entry *entry;
    int index;
    int rc;
    char *str;

    list_init(&list);

    for (index = 1; index < argc; ++index) {
        str = strdup(argv[index]);
        assert(str);
        rc = list_push_back(&list, str);
        assert(rc == 1);
    }

    list_for_each(&list, entry) {
        printf("%s\n", (char *)entry->data);
    }

    while ((entry = list_front(&list)) != NULL) {
        free(entry->data);
        list_pop_front(&list);
    }

    return 0;
}