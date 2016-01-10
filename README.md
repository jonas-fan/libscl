# simple-container
[![Build Status](https://travis-ci.org/yjfan/simple-container.svg)](https://travis-ci.org/yjfan/simple-container)

Implement container in C

## Build
```
$ git clone https://github.com/yjfan/simple-container.git
$ cd simple-container/build
$ cmake ..
$ make -j4
$ cd ../bin/test/
$ ./vector_test
$ ./list_test
$ ./queue_test
$ ./stack_test
$ ./ring_buffer_test
```

## Container
- Vector
- List
- Queue
- Stack
- Ring buffer

## Example
```cpp
vector_t *vector = vector_create(sizeof(int));

for (int index = 0; index < 8; ++index) {
    vector_push_back(vector, &index);
}

const unsigned int length = vector_size(vector);

int data;

for (unsigned int index = 0; index < length; ++index) {
    vector_at(vector, index, &data);

    printf("vector[%u] => %d\n", index, data);
}

vector_destroy(vector);
```

```
vector[0] => 0
vector[1] => 1
vector[2] => 2
vector[3] => 3
vector[4] => 4
vector[5] => 5
vector[6] => 6
vector[7] => 7
```

## License
The MIT License (MIT)

Copyright (c) 2014 Jian Fan <jianfan.tw@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
