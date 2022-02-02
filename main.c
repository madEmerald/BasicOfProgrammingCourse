#include <assert.h>
#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector vector1 = createVector(0);
    pushBack(&vector1, 1);

    assert(getVectorValue(&vector1, 0) == 1);
    assert(vector1.size == 1);
    assert(vector1.capacity == 1);
}

void test_pushBack_fullVector() {
    int *data = malloc(sizeof(int) * 2);
    data[0] = 1;
    data[1] = 2;

    vector vector1 = {data, 2, 2};
    pushBack(&vector1, 3);

    assert(vector1.capacity == 4);
    assert(vector1.data[2] == 3);
    assert(vector1.size == 3);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);

    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    test();

    return 0;
}
