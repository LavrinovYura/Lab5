#include "heap.h"
#include <malloc.h>
#include <string.h>
#include <limits.h>

void heapify(int* arr, int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < size && arr[left] > arr[largest]) largest = left;
    if (right < size && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        int v = arr[i];
        arr[i] = arr[largest];
        arr[largest] = v;
        heapify(arr, size, largest);
    }
}

void deleteElement(int* arr, int size, int element) {
    if (size < element) return;
    arr[element] = arr[size - 1];
    size--;
    arr = (int*)realloc(arr, (size) * sizeof(int));
    heapify(arr, size, element);
}

int* insert(int* arr, int* size, int element) {
    *size = *size + 1;
    arr = (int*)realloc(arr, (*size) * sizeof(int));
    arr[*size - 1] = element;
    build(arr, *size);
    return arr;
}

void build(int* arr, int size) {
    for (int i = size / 2; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

int extract_max(int* arr, int* size) {
    int max = arr[0];
    arr[0] = arr[*size - 1];
    *size = *size -1;
    heapify(arr, *size, 0);
    arr = (int*)realloc(arr, (*size) * sizeof(int));
    return max;
}