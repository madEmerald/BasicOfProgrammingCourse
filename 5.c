#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "libs/data_structures/matrix/matrix.h"

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool isUnique(long long *a, const int n) {
    qsort(a, n, sizeof(long long), compare_ints);

    for (int i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1])
            return false;
    return true;
}

long long getSum(int *a, const int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int matrixSize = m.nRows;

    long long *rowSums = malloc(sizeof (long long) * m.nRows);
    for (int i = 0; i < matrixSize; i++)
        rowSums[i] = getSum(m.values[i], matrixSize);

    if (isUnique(rowSums, matrixSize))
        transposeSquareMatrix(m);

    free(rowSums);
}

int main() {
    int n;
    scanf("%d", &n);

    matrix a = getMemMatrix(n, n);
    inputMatrix(a);

    transposeIfMatrixHasNotEqualSumOfRows(a);

    outputMatrix(a);

    freeMemMatrix(a);
    return 0;
}
