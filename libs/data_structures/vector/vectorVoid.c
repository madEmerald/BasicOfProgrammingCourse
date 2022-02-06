#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "vectorVoid.h"

int max2(const int a, const int b) {
    return a > b ? a : b;
}

void allocationError() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

void sizeError() {
    fprintf(stderr, "size error");
    exit(1);
}

void indexError(size_t index) {
    fprintf(stderr, "IndexError: a[%zu] is not exists", index);
    exit(1);
}

vectorVoid createVectorV(const size_t n, const size_t baseTypeSize) {
    void *data = malloc(sizeof(baseTypeSize) * n);
    if (data == NULL)
        allocationError();

    return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else {
        void *data = realloc(v->data, sizeof(v->baseTypeSize) * newCapacity);
        if (data == NULL)
            allocationError();
    }
    v->capacity = newCapacity;

    if (newCapacity < v->size)
        v->size = newCapacity;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    reserveV(v, 0);
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}
