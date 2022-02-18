#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"

void test_swapRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9 }, 3, 3);
    matrix expectedMatrix = createMatrixFromArray((int[]) {4, 5, 6,
                                                              1, 2, 3,
                                                              7, 8, 9 }, 3, 3);

    swapRows(m, 0, 1);

    assert(areTwoMatricesEqual(m, expectedMatrix));

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_swapCols() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9 }, 3, 3);
    matrix expectedMatrix = createMatrixFromArray((int[]) {2, 1, 3,
                                                              5, 4, 6,
                                                              8, 7, 9 }, 3, 3);

    swapCols(m, 0, 1);

    assert(areTwoMatricesEqual(m, expectedMatrix));

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

int sum(int *a, int size) {
    int s = 0;
    for (int i = 0; i < size; i++)
        s += a[i];

    return s;
}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m = createMatrixFromArray((int[]) {7, 0, 6,
                                                 9, 3, 5,
                                                 1, 2, 4 }, 3, 3);
    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 2, 4,
                                                              7, 0, 6,
                                                              9, 3, 5 }, 3, 3);

    insertionSortRowsMatrixByRowCriteria(m, sum);

    assert(areTwoMatricesEqual(m, expectedMatrix));

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_insertionSortRowsMatrixByRowCriteria_oneRow() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);
    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);

    insertionSortRowsMatrixByRowCriteria(m, sum);

    assert(areTwoMatricesEqual(m, expectedMatrix));

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_selectionSortColsMatrixByColCriteria() {
    matrix m = createMatrixFromArray((int[]) {7, 0, 6,
                                                 9, 3, 5,
                                                 1, 2, 4 }, 3, 3);
    matrix expectedMatrix = createMatrixFromArray((int[]) {0, 6, 7,
                                                              3, 5, 9,
                                                              2, 4, 1 }, 3, 3);

    selectionSortColsMatrixByColCriteria(m, sum);

    assert(areTwoMatricesEqual(m, expectedMatrix));

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_selectionSortColsMatrixByColCriteria_oneCol() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);
    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);

    selectionSortColsMatrixByColCriteria(m, sum);

    assert(areTwoMatricesEqual(m, expectedMatrix));

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_isSquareMatrix_squareMatrix() {
    matrix m = getMemMatrix(3, 3);

    assert(isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isSquareMatrix_notSquareMatrix() {
    matrix m = getMemMatrix(3, 4);

    assert(!isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_areTwoMatricesEqual_equalMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {2, 4, 5,
                                                  6, 7, 4,
                                                  5, 7, 3 }, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {2, 4, 5,
                                                  6, 7, 4,
                                                  5, 7, 3 }, 3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_areTwoMatricesEqual_notEqualMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {2, 4, 5,
                                                  6, 7, 4,
                                                  5, 7, 3 }, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {8, 5, 4,
                                                  8, 7, 2,
                                                  1, 3, 9 }, 3, 3);

    assert(!areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isEMatrix_oneElement() {
    matrix m = createMatrixFromArray((int[]) {1}, 1, 1);

    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_EMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 0, 0,
                                                 0, 1, 0, 0, 0,
                                                 0, 0, 1, 0, 0,
                                                 0, 0, 0, 1, 0,
                                                 0, 0, 0, 0, 1}, 5, 5);

    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_notEMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 0, 0,
                                                 0, 1, 0, 0, 0,
                                                 0, 0, 1, 0, 0,
                                                 0, 0, 0, 1, 0,
                                                 1, 0, 0, 0, 1}, 5, 5);

    assert(!isEMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_oneElement() {
    matrix m = createMatrixFromArray((int[]) {1}, 1, 1);

    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_SymmetricMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5,
                                                 2, 1, 2, 3, 4,
                                                 3, 2, 1, 2, 3,
                                                 4, 3, 2, 1, 2,
                                                 5, 4, 3, 2, 1}, 5, 5);


    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_notSymmetricMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5,
                                                 2, 1, 2, 3, 4,
                                                 3, 2, 1, 2, 3,
                                                 4, 3, 2, 1, 2,
                                                 6, 4, 3, 2, 1}, 5, 5);

    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 4,
                                                 0, 9, 5,
                                                 8, 6, 3 }, 3, 3);
    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 0, 8,
                                                              2, 9, 6,
                                                              4, 5, 3 }, 3, 3);

    transposeSquareMatrix(m);

    assert(areTwoMatricesEqual(m, expectedMatrix));

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_getMinValuePos_oneElement() {
    matrix m = createMatrixFromArray((int[]) {1}, 1, 1);

    position p = getMinValuePos(m);

    assert(p.rowIndex == 0);
    assert(p.colIndex == 0);
    freeMemMatrix(m);
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray((int[]) {7, 10, 6,
                                                 9,  3, 5,
                                                 1,  2, 4 }, 3, 3);

    position p = getMinValuePos(m);

    assert(p.rowIndex == 2);
    assert(p.colIndex == 0);
    freeMemMatrix(m);
}

void test_getMaxValuePos_oneElement() {
    matrix m = createMatrixFromArray((int[]) {1}, 1, 1);

    position p = getMaxValuePos(m);

    assert(p.rowIndex == 0);
    assert(p.colIndex == 0);
    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray((int[]) {0, 6, 7,
                                                 3, 5, 9,
                                                 2, 4, 1 }, 3, 3);

    position p = getMaxValuePos(m);

    assert(p.rowIndex == 1);
    assert(p.colIndex == 2);
    freeMemMatrix(m);
}

void test() {
    test_swapRows();
    test_swapCols();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortRowsMatrixByRowCriteria_oneRow();
    test_selectionSortColsMatrixByColCriteria();
    test_selectionSortColsMatrixByColCriteria_oneCol();
    test_isSquareMatrix_squareMatrix();
    test_isSquareMatrix_notSquareMatrix();
    test_areTwoMatricesEqual_equalMatrices();
    test_areTwoMatricesEqual_notEqualMatrices();
    test_isEMatrix_oneElement();
    test_isEMatrix_EMatrix();
    test_isEMatrix_notEMatrix();
    test_isSymmetricMatrix_oneElement();
    test_isSymmetricMatrix_notSymmetricMatrix();
    test_isSymmetricMatrix_SymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos_oneElement();
    test_getMinValuePos();
    test_getMaxValuePos_oneElement();
    test_getMaxValuePos();
}

int main() {
    test();

    return 0;
}
