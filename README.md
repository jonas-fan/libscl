# libscl
[![Build Status](https://travis-ci.org/jonas-fan/libscl.svg?branch=master)](https://travis-ci.org/jonas-fan/libscl)

The simple container library in C.

## Build
```
$ cd libscl/
$ mkdir build/
$ cd build/
$ cmake ..
$ make -j4
```

## Example
```cpp
#include <stdio.h>
#include <string.h>
#include <list.h>

int main(int argc, char *argv[])
{
    list_t *list = list_create();

    list_push_back(list, (void *)strdup("hello"));
    list_push_back(list, (void *)strdup("libscl"));
    list_push_back(list, (void *)strdup("doubly linked list"));

    while (!list_empty(list)) {
        char *string = (char *)list_front(list);

        printf("%s\n", string);

        list_pop_front(list);

        free(string);
    }

    list_destroy(list);

    return 0;
}
```

Output:

```
hello
libscl
doubly linked list
```

## License
The MIT License (MIT)