#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"

void test_reserve_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    reserve(&v, 0);

    assert(v.data == NULL);
}

void test_reserve_sizeChanging() {
    int *data = malloc(sizeof(int) * 2);
    data[0] = 1;
    data[1] = 2;

    vector v = {data, 2, 2};
    reserve(&v, 1);

    assert(v.size == 1);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_shrinkToFit() {
    int *data = malloc(sizeof(int) * 2);
    data[0] = 1;
    data[1] = 2;

    vector v = {data, 2, 5};
    shrinkToFit(&v);

    assert(v.capacity == 2);

    deleteVector(&v);
}

void test_shrinkToFit_emptyVector() {
    vector  v = createVector(0);
    shrinkToFit(&v);

    assert(v.capacity == 0);

    deleteVector(&v);
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);

    assert(getVectorValue(&v, 0) == 1);
    assert(v.size == 1);
    assert(v.capacity == 1);
}

void test_pushBack_fullVector() {
    int *data = malloc(sizeof(int) * 2);
    data[0] = 1;
    data[1] = 2;

    vector v = {data, 2, 2};
    pushBack(&v, 3);

    assert(v.capacity == 4);
    assert(v.data[2] == 3);
    assert(v.size == 3);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);

    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    int *data = malloc(sizeof(int) * 2);
    data[0] = 1;
    data[1] = 2;

    vector v = {data, 2, 2};
    int *pointer = atVector(&v, 0);
    assert(v.data[0] = *pointer);
    assert(v.data[1] = *(pointer + 1));

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    int *data = malloc(sizeof(int) * 2);
    data[0] = 4;
    data[1] = 8;

    vector v = {data, 2, 2};
    int *pointer = atVector(&v, 1);
    assert(*pointer == 8);

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 5);

    assert(*back(&v) == 5);
}

void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 5);

    assert(*front(&v) == 5);
}

void test_isEmpty() {
    vector v = createVector(1);

    assert(isEmpty(&v));
}

void test_isFull() {
    vector v = createVector(1);
    pushBack(&v, 5);

    assert(isFull(&v));
}

void test_getVectorElement_requestToLastElement() {
    int *data = malloc(sizeof(int) * 2);
    data[0] = 4;
    data[1] = 1;

    vector v = {data, 2, 2};
    int element = getVectorValue(&v, 1);
    assert(element == 1);

    deleteVector(&v);
}

void test_getVectorElement_requestToFirstElement() {
    int *data = malloc(sizeof(int) * 2);
    data[0] = 7;
    data[1] = 3;

    vector v = {data, 2, 2};
    int element = getVectorValue(&v, 0);
    assert(element == 7);

    deleteVector(&v);
}

void test() {
    test_reserve_emptyVector();
    test_reserve_sizeChanging();
    test_shrinkToFit();
    test_shrinkToFit_emptyVector();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    test_isEmpty();
    test_isFull();
    test_getVectorElement_requestToLastElement();
    test_getVectorElement_requestToFirstElement();
}

int main() {
    test();

    vectorVoid v;

    return 0;
}
