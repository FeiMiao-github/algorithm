#include "main.h"
#include <stdio.h>
#include <malloc.h>

int main(void) {
    /* code here */ 
    int length = 10;
    int *p = getIntArray(length);
    printArray(length, p);

    free(p);
    return 0;
}