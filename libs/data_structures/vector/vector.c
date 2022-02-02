#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void allocationError() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vector createVector(const size_t n) {
    int *data = malloc(sizeof(int) * n);
    if (data == NULL)
        allocationError();

    return (vector) {data, 0, n};
}

void reserve(vector *v, const size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else {
        int *data = realloc(v->data, sizeof(int) * newCapacity);
        if (data == NULL)
            allocationError();
    }

    if (newCapacity < v->size)
        v->size = newCapacity;
}

void clear(vector *v) {
    reserve(v, 0);
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}
