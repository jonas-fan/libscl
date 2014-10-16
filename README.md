# c-simple-stl
Implement Simple STL in C

## Build
```
$ git clone https://github.com/yjfan/c-simple-stl.git
$ cd c-simple-stl/build
$ cmake ..
$ make
```

## Container
- Vector
- List
- Queue

## Example
### Vector
```
Vector *vector = vector_create();

vector_push_back(vector, "Hello");
vector_push_back(vector, "World");
vector_push_back(vector, "Very simple");
vector_push_back(vector, "This is simple STL");
vector_push_back(vector, "OTZ");

unsigned int index;

for (index = 0; index < vector_size(vector); ++index) {
    void *element = vector_at(vector, index);

    printf("%s", (char *)element);
}

vector_destroy(vector);
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
