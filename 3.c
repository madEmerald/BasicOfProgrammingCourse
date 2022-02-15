#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int getMin(int *a, const int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    matrix a = getMemMatrix(n, m);
    inputMatrix(a);

    sortColsByMinElement(a);

    outputMatrix(a);

    freeMemMatrix(a);
    return 0;
}
