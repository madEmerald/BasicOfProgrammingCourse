#include <stdio.h>
#include <stdbool.h>
#include "libs/data_structures/matrix/matrix.h"

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int nNonDescendingRowsMatrices = 0;
    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            nNonDescendingRowsMatrices++;

    return nNonDescendingRowsMatrices;
}

int main() {
    int nMatrix;
    scanf("%d", &nMatrix);

    int n, m;
    scanf("%d %d", &n, &m);

    matrix *ms = getMemArrayOfMatrices(nMatrix, n, m);
    inputMatrices(ms, nMatrix);

    printf("%d", countNonDescendingRowsMatrices(ms, nMatrix));

    freeMemMatrices(ms, n);
    return 0;
}
