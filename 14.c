#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "libs/data_structures/matrix/matrix.h"

bool isZeroRow(const int *a, int n) {
    for (int i = 0; i < n; i++)
        if (a[i] != 0)
            return false;
    return true;
}

int countZeroRows(matrix m) {
    int nZeroRows = 0;
    for (int i = 0; i < m.nRows; i++)
        if (isZeroRow(m.values[i], m.nCols))
            nZeroRows++;

    return nZeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *zeroRowsNumber = malloc(sizeof(int) * nMatrix);
    zeroRowsNumber[0] = countZeroRows(ms[0]);
    int max = zeroRowsNumber[0];

    for (int i = 1; i < nMatrix; i++) {
        zeroRowsNumber[i] = countZeroRows(ms[i]);

        if (zeroRowsNumber[i] > max)
            max = zeroRowsNumber[i];
    }

    for (int i = 0; i < nMatrix; i++)
        if (zeroRowsNumber[i] == max)
            outputMatrix(ms[i]);

    free(zeroRowsNumber);
}

int main() {
    int nMatrix;
    scanf("%d", &nMatrix);

    int n, m;
    scanf("%d %d", &n, &m);

    matrix *ms = getMemArrayOfMatrices(nMatrix, n, m);
    inputMatrices(ms, nMatrix);

    printMatrixWithMaxZeroRows(ms, nMatrix);

    freeMemMatrices(ms, n);
    return 0;
}