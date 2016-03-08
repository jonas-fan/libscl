# libscl
[![Build Status](https://travis-ci.org/yjfan/libscl.svg?branch=master)](https://travis-ci.org/yjfan/libscl)

The simple container library for C

## Build
```
$ git clone https://github.com/yjfan/libscl.git
$ cd libscl/
$ mkdir build/
$ cd build/
$ cmake ..
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
```

## License
The MIT License (MIT)
