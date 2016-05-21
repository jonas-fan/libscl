# libscl
[![Build Status](https://travis-ci.org/yjfan/libscl.svg?branch=master)](https://travis-ci.org/yjfan/libscl)

The simple container library for C.
All containers are implemented with **Non thread-safe** and **Design by Contract** style.

## Build
```
$ git clone https://github.com/yjfan/libscl.git
$ cd libscl/
$ mkdir build/
$ cd build/
$ cmake .. -DCMAKE_BUILD_TYPE=<Release|Debug> -DCMAKE_INSTALL_PREFIX=<prefix>
$ make -j4
$ make install
```

## Container
- List
- Vector
- Queue (List based)
- Stack (List based)
- Ring buffer

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

The output is

```
hello
libscl
doubly linked list
```

## License
The MIT License (MIT)
