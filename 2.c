#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int getMax(int *a, const int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    matrix a = getMemMatrix(n, m);
    inputMatrix(a);

    sortRowsByMinElement(a);

    outputMatrix(a);

    return 0;
}
