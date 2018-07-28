# libsimplecntr
[![Build Status](https://travis-ci.org/jonas-fan/libsimplecntr.svg?branch=master)](https://travis-ci.org/jonas-fan/libsimplecntr)

A simple container library in C.

`libsimplecntr` provides data structure implementations, which makes organizing data easier.

Data structure support:

- `list`

## Building

```
$ cd libsimplecntr/
$ mkdir build/
$ cd build/
$ cmake ..
$ make -j4
```

## Example

For `list`, considering code snippet as below:

```c
int main(int argc, char *argv[])
{
    struct list list;
    struct list_entry *entry;
    int index;
    char *str;

    list_init(&list);

    for (index = 1; index < argc; ++index) {
        str = strdup(argv[index]);
        list_push_back(&list, str);
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
```

And the output will be:

```
$ ./list_test_for_each hello world 12345
hello
world
12345
```

## License

The MIT License (MIT)