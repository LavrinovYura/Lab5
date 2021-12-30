#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "heap.h"


int numberCount(FILE* file) {
    fseek(file, 0, SEEK_SET);
    int count = 0;
    while (1) {
        int value;
        if (fscanf(file, "%d", &value) == 1)
            count++;
        if (feof(file))
            return count;
    }
}

void read(FILE* file, int size, int* data) {
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < size; ++i) {
        fscanf(file, "%d", &data[i]);
    }
}

//void tests() {
//    test_max();
//    test_add();
//    test_build();
//}

int main(int argc, char** argv) {
    //tests();
    if (argc != 3) return -1;

    FILE* fin = fopen(argv[1], "r");
    int size = numberCount(fin);
    int* data = (int*)malloc(sizeof(int) * size);
    read(fin, size, data);
    fclose(fin);
    build(data, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", data[i]);
    }
    FILE* fout = fopen(argv[2], "w");
    for (int i = 0; i < size; ++i) {
        fprintf(fout, "%d ", data[i]);
    }
    fclose(fout);
    free(data);
    return 0;
}