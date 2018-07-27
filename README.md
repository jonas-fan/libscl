# libsimplecntr

[![Build Status](https://travis-ci.org/jonas-fan/libsimplecntr.svg?branch=master)](https://travis-ci.org/jonas-fan/libsimplecntr)

The `libsimplecntr` is an easy-to-use C++-style container library in C, which provides implementation of non-intrusive data structures.

Supported:

- `list`
- `vector`

## Building

```
$ cd libsimplecntr/
$ mkdir build/
$ cd build/
$ cmake ..
$ make -j4
```

## Example

Here is an example for `vector`, considering the following code snippet:

```c
#include "vector.h"

int main(int argc, char *argv[])
{
    struct vector vector;
    struct vector_entry *entry;
    int index;

    vector_init(&vector);

    for (index = 1; index < argc; ++index) {
        char *str = strdup(argv[index]);
        vector_push_back(&vector, str);
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
```

And the output will be:

```
$ ./vector_test_echo hello world 0123456789
hello
world
0123456789
```

## License

The MIT License (MIT)