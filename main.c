#include <assert.h>
#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

#define nMatrices 3

void test() {

}

int main() {
    test();
    matrix m = getMemMatrix(3, 3);

    inputMatrix(m);
    outputMatrix(m);


    matrix *ms = getMemArrayOfMatrices(nMatrices, 2, 2);
    inputMatrices(ms, nMatrices);
    outputMatrices(ms, nMatrices);

    freeMemMatrix(m);
    freeMemMatrices(ms, nMatrices);

    return 0;
}
