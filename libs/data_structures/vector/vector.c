#include <malloc.h>
#include <stdio.h>
#include "vector.h"
#include "../errors/errors.h"
#include "../../algorithms/basicAlgorithms/basicAlgorithms.h"

vector createVector(const size_t n) {
    int *data = (int*)malloc(sizeof(int) * n);
    if (data == NULL)
        allocationError();

    return (vector) {data, 0, n};
}

void reserve(vector *v, const size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else {
        int *data = (int*)realloc(v->data, sizeof(int) * newCapacity);
        if (data == NULL)
            allocationError();
    }
    v->capacity = newCapacity;

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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, const int x) {
    if (isFull(v))
        reserve(v, max2(1, v->capacity * 2));

    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (v->size == 0)
        sizeError();

    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index < 0 || index >= v->size)
        indexError(index);

    return &v->data[index];
}

int* back(vector *v) {
    if (v->size == 0)
        sizeError();

    return &v->data[v->size - 1];
}

int* front(vector *v) {
    if (v->size == 0)
        sizeError();

    return &v->data[0];
}
