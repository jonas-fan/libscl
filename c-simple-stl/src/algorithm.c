#include <algorithm.h>
#include <stdlib.h>

void sort(void **data, const unsigned int length, int (*compare)(const void *, const void *))
{
    qsort(data, length, sizeof(void *), compare);
}