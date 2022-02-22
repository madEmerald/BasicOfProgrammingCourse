#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include "libs/data_structures/matrix/matrix.h"

float getDistance(int *a, const int n) {
    float distance = 0;
    for (int i = 0; i < n; i++)
        distance += a[i] * a[i];

    return sqrt(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    int *sortKeys = malloc(m.nRows * sizeof(int));
    for (int i = 0; i < m.nRows; i++)
        sortKeys[i] = criteria(m.values[i], m.nCols);

    for (size_t sortedPartLength = 1; sortedPartLength < m.nRows; sortedPartLength++) {
        int *insertingRow = m.values[sortedPartLength];
        float insertingRowKey = sortKeys[sortedPartLength];
        int i = sortedPartLength;
        while (i > 0 && sortKeys[i - 1] > insertingRowKey) {
            m.values[i] = m.values[i - 1];
            sortKeys[i] = sortKeys[i - 1];
            i--;
        }
        m.values[i] = insertingRow;
        sortKeys[i] = insertingRowKey;
    }
    free(sortKeys);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    matrix a = getMemMatrix(n, m);
    inputMatrix(a);

    sortByDistances(a);

    outputMatrix(a);

    freeMemMatrix(a);
    return 0;
}
