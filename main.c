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
}

void test() {
    test_swapRows();
    test_swapCols();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortRowsMatrixByRowCriteria_oneRow();
    test_insertionSortColsMatrixByColCriteria();
    test_insertionSortColsMatrixByColCriteria_oneCol();
}

int main() {
    test();

    return 0;
}
