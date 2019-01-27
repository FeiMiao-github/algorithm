/* 测试数据生成 */
#include "testDate.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int* getIntArray(int len) {
    srand((unsigned)time(NULL));
    int *pRet = (int *)malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        *(pRet + i) = rand() % 100;
    }

    return pRet;
}

void printArray(int length, int *pArray) {
    printf("{");
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            printf("%d", *(pArray));
            continue;
        }
        printf(", %d", *(pArray+i));
    }
    printf("}");
}