#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"

void test_swapRows() {
    matrix m = getMemMatrix(3, 3);
    matrix expectedMatrix = getMemMatrix(3, 3);

    int c = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            c++;
            m.values[i][j] = c;
        }

    expectedMatrix.values[0][0] = 4;
    expectedMatrix.values[0][1] = 5;
    expectedMatrix.values[0][2] = 6;
    expectedMatrix.values[1][0] = 1;
    expectedMatrix.values[1][1] = 2;
    expectedMatrix.values[1][2] = 3;
    expectedMatrix.values[2][0] = 7;
    expectedMatrix.values[2][1] = 8;
    expectedMatrix.values[2][2] = 9;

    swapRows(m, 0, 1);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            assert(m.values[i][j] == expectedMatrix.values[i][j]);

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_swapCols() {
    matrix m = getMemMatrix(3, 3);
    matrix expectedMatrix = getMemMatrix(3, 3);

    int c = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            c++;
            m.values[i][j] = c;
        }

    expectedMatrix.values[0][0] = 2;
    expectedMatrix.values[0][1] = 1;
    expectedMatrix.values[0][2] = 3;
    expectedMatrix.values[1][0] = 5;
    expectedMatrix.values[1][1] = 4;
    expectedMatrix.values[1][2] = 6;
    expectedMatrix.values[2][0] = 8;
    expectedMatrix.values[2][1] = 7;
    expectedMatrix.values[2][2] = 9;

    swapCols(m, 0, 1);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            assert(m.values[i][j] == expectedMatrix.values[i][j]);

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
    matrix m = getMemMatrix(3, 3);
    matrix expectedMatrix = getMemMatrix(3, 3);

    m.values[0][0] = 7;
    m.values[0][1] = 0;
    m.values[0][2] = 6;
    m.values[1][0] = 9;
    m.values[1][1] = 3;
    m.values[1][2] = 5;
    m.values[2][0] = 1;
    m.values[2][1] = 2;
    m.values[2][2] = 4;

    expectedMatrix.values[0][0] = 1;
    expectedMatrix.values[0][1] = 2;
    expectedMatrix.values[0][2] = 4;
    expectedMatrix.values[1][0] = 7;
    expectedMatrix.values[1][1] = 0;
    expectedMatrix.values[1][2] = 6;
    expectedMatrix.values[2][0] = 9;
    expectedMatrix.values[2][1] = 3;
    expectedMatrix.values[2][2] = 5;

    insertionSortRowsMatrixByRowCriteria(m, sum);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            assert(m.values[i][j] == expectedMatrix.values[i][j]);

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_insertionSortRowsMatrixByRowCriteria_oneRow() {
    matrix m = getMemMatrix(1, 3);
    matrix expectedMatrix = getMemMatrix(1, 3);

    m.values[0][0] = 1;
    m.values[0][1] = 2;
    m.values[0][2] = 3;

    expectedMatrix.values[0][0] = 1;
    expectedMatrix.values[0][1] = 2;
    expectedMatrix.values[0][2] = 3;

    insertionSortRowsMatrixByRowCriteria(m, sum);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            assert(m.values[i][j] == expectedMatrix.values[i][j]);

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_insertionSortColsMatrixByColCriteria() {
    matrix m = getMemMatrix(3, 3);
    matrix expectedMatrix = getMemMatrix(3, 3);

    m.values[0][0] = 7;
    m.values[0][1] = 0;
    m.values[0][2] = 6;
    m.values[1][0] = 9;
    m.values[1][1] = 3;
    m.values[1][2] = 5;
    m.values[2][0] = 1;
    m.values[2][1] = 2;
    m.values[2][2] = 4;

    expectedMatrix.values[0][0] = 0;
    expectedMatrix.values[0][1] = 6;
    expectedMatrix.values[0][2] = 7;
    expectedMatrix.values[1][0] = 3;
    expectedMatrix.values[1][1] = 5;
    expectedMatrix.values[1][2] = 9;
    expectedMatrix.values[2][0] = 2;
    expectedMatrix.values[2][1] = 4;
    expectedMatrix.values[2][2] = 1;

    insertionSortColsMatrixByColCriteria(m, sum);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            assert(m.values[i][j] == expectedMatrix.values[i][j]);

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_insertionSortColsMatrixByColCriteria_oneCol() {
    matrix m = getMemMatrix(3, 1);
    matrix expectedMatrix = getMemMatrix(3, 1);

    m.values[0][0] = 1;
    m.values[1][0] = 2;
    m.values[2][0] = 3;

    expectedMatrix.values[0][0] = 1;
    expectedMatrix.values[1][0] = 2;
    expectedMatrix.values[2][0] = 3;

    insertionSortColsMatrixByColCriteria(m, sum);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            assert(m.values[i][j] == expectedMatrix.values[i][j]);

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
    matrix m1 = getMemMatrix(3, 3);
    matrix m2 = getMemMatrix(3, 3);

    m1.values[0][0] = 2;
    m1.values[0][1] = 4;
    m1.values[0][2] = 5;
    m1.values[1][0] = 6;
    m1.values[1][1] = 7;
    m1.values[1][2] = 4;
    m1.values[2][0] = 5;
    m1.values[2][1] = 7;
    m1.values[2][2] = 3;

    m2.values[0][0] = 2;
    m2.values[0][1] = 4;
    m2.values[0][2] = 5;
    m2.values[1][0] = 6;
    m2.values[1][1] = 7;
    m2.values[1][2] = 4;
    m2.values[2][0] = 5;
    m2.values[2][1] = 7;
    m2.values[2][2] = 3;

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_areTwoMatricesEqual_notEqualMatrices() {
    matrix m1 = getMemMatrix(3, 3);
    matrix m2 = getMemMatrix(3, 3);

    m1.values[0][0] = 2;
    m1.values[0][1] = 4;
    m1.values[0][2] = 5;
    m1.values[1][0] = 6;
    m1.values[1][1] = 7;
    m1.values[1][2] = 4;
    m1.values[2][0] = 5;
    m1.values[2][1] = 7;
    m1.values[2][2] = 3;

    m2.values[0][0] = 8;
    m2.values[0][1] = 5;
    m2.values[0][2] = 4;
    m2.values[1][0] = 8;
    m2.values[1][1] = 7;
    m2.values[1][2] = 2;
    m2.values[2][0] = 1;
    m2.values[2][1] = 3;
    m2.values[2][2] = 9;

    assert(!areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isEMatrix_oneElement() {
    matrix m = getMemMatrix(1, 1);
    m.values[0][0] = 1;

    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_EMatrix() {
    matrix m = getMemMatrix(5, 5);
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (i == j)
                m.values[i][j] = 1;
            else
                m.values[i][j] = 0;

    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_notEMatrix() {
    matrix m = getMemMatrix(5, 5);
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (i == j)
                m.values[i][j] = 1;
            else
                m.values[i][j] = 0;
    m.values[0][4] = 1;

    assert(!isEMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_oneElement() {
    matrix m = getMemMatrix(1, 1);
    m.values[0][0] = 1;

    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_SymmetricMatrix() {
    matrix m = getMemMatrix(5, 5);
    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++) {
            m.values[i][j] = i + j;
            m.values[j][i] = i + j;
        }


    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_notSymmetricMatrix() {
    matrix m = getMemMatrix(5, 5);
    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++) {
            m.values[i][j] = i + j;
            m.values[j][i] = i + j;
        }
    m.values[2][3] = 0;

    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    matrix m = getMemMatrix(3, 3);
    matrix expectedMatrix = getMemMatrix(3, 3);

    m.values[0][0] = 1;
    m.values[0][1] = 2;
    m.values[0][2] = 4;
    m.values[1][0] = 0;
    m.values[1][1] = 9;
    m.values[1][2] = 5;
    m.values[2][0] = 8;
    m.values[2][1] = 6;
    m.values[2][2] = 3;

    expectedMatrix.values[0][0] = 1;
    expectedMatrix.values[0][1] = 0;
    expectedMatrix.values[0][2] = 8;
    expectedMatrix.values[1][0] = 2;
    expectedMatrix.values[1][1] = 9;
    expectedMatrix.values[1][2] = 6;
    expectedMatrix.values[2][0] = 4;
    expectedMatrix.values[2][1] = 5;
    expectedMatrix.values[2][2] = 3;

    transposeSquareMatrix(m);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            assert(m.values[i][j] == expectedMatrix.values[i][j]);

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test() {
    test_swapRows();
    test_swapCols();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortRowsMatrixByRowCriteria_oneRow();
    test_insertionSortColsMatrixByColCriteria();
    test_insertionSortColsMatrixByColCriteria_oneCol();
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
}

int main() {
    test();

    return 0;
}
