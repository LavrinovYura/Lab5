#include <assert.h>
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

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    arr = insert(arr, &size, 10101);
  
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 10101) {
            flag = 0;
            break;
        }
    }
    assert(flag == 0);

    for (int i = 0; i < size; ++i) {
        if (2 * i + 1 < size) if (arr[i] < arr[2 * i + 1]) flag = -1;
        if (2 * i < size) if (arr[i] < arr[2 * i]) flag = -1;
    }
    assert(flag == 0);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}

void test_max() {
    int flag = 0;
    int size = 10;
    int* arr = createArr(size);
    build(arr, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int orig_max = INT_MIN;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > orig_max) orig_max = arr[i];
    }
    int new_max = extract_max(arr, &size);
    assert(new_max == orig_max);

    for (int i = 0; i < size; ++i) {
        if (arr[i] == new_max) {
            flag = -1;
            break;
        }
    }
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}