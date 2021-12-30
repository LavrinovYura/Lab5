#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

int* createArr(int size) {
    int* arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 20;
    }
    return arr;
}

void test_build() {
    int flag = 0;
    int size = 10;
    int* arr = createArr(size);
    build(arr, size);

    for (int i = 0; i < size; ++i) {
        if (2 * i + 2 < size) if (arr[i] < arr[2 * i + 2]) flag = -1;
        if (2 * i + 1 < size) if (arr[i] < arr[2 * i + 1]) flag = -1;
    }
    assert(flag == 0);
    free(arr);
}

void test_add() {
    int flag = -1;
    int size = 9;
    int* arr = createArr(size);
    build(arr, size);

    printf("Array before adding value: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int N;
    printf("Input value to add: ");
    scanf_s("%d", &N);

    arr = insert(arr, &size, N);

    printf("Array after adding value: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < size; ++i) {
        if (arr[i] == N) {
            flag = 0;
            break;
        }
    }
    assert(flag == 0);
    free(arr);
}

void test_max() {
    int flag = 0;
    int size = 10;
    int* arr = createArr(size);
    build(arr, size);

    printf("Array before extracting max value: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int orig_max = arr[0];
    int new_max = extract_max(arr, &size);
    assert(new_max == orig_max);

    printf("Array after extracting max value: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Max value: %d", new_max);
    printf("\n");
}