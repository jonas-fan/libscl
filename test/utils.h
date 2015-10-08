#ifndef CSSTL_TEST_UTILS_H_
#define CSSTL_TEST_UTILS_H_

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_BUFFER_SIZE 64

char * int2string(int number)
{
    char buffer[MAX_BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "%d", number);

    return strdup(buffer);
}

#ifdef __cplusplus
}
#endif

#endif