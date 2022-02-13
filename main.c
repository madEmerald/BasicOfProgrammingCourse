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
}

void test() {
    test_swapRows();
    test_swapCols();
}

int main() {
    test();

    return 0;
}
