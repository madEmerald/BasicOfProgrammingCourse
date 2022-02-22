#include <stdio.h>
#include <malloc.h>
#include "libs/data_structures/matrix/matrix.h"

position getLeftMin(matrix m) {
    int min = m.values[0][0];
    position minElementPosition = {0, 0};
    for (int j = 0; j < m.nCols; j++)
        for (int i = 0; i < m.nRows; i++)
            if (m.values[i][j] < min) {
                minElementPosition = (position) {i, j};
                min = m.values[i][j];
            }
    return minElementPosition;
}

void swapPenultimateRow(matrix m, int n) {
    int minElementColIndex = getLeftMin(m).colIndex;

    int *minElementCol = malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        minElementCol[i] = m.values[i][minElementColIndex];

    for (int i = 0; i < n; i++)
        m.values[n - 2][i] = minElementCol[i];

    free(minElementCol);
}

int main() {
    int n;
    scanf("%d", &n);

    matrix a = getMemMatrix(n, n);
    inputMatrix(a);

    swapPenultimateRow(a, n);

    outputMatrix(a);

    freeMemMatrix(a);
    return 0;
}
