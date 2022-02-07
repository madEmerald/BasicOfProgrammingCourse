#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "vectorVoid.h"
#include "../errors/errors.h"
#include "../../algorithms/basicAlgorithms/basicAlgorithms.h"


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

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    char *destination = (char*) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (v->size == 0)
        sizeError();

    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v))
        reserveV(v, max2(1, v->capacity * 2));

    memcpy(v->data + v->size++ * v->baseTypeSize, source, v->baseTypeSize);
}
