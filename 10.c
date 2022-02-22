#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "libs/data_structures/matrix/matrix.h"

long long getSum(int *a, const int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);

    int nUnique = 1;
    for (int i = 0; i < n - 1; i++)
        if (a[i] != a[i + 1])
            nUnique++;

    return nUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long *sums = malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        sums[i] = getSum(m.values[i], m.nCols);

    int nEqClasses = countNUnique(sums, m.nRows);

    free(sums);
    return nEqClasses;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    matrix a = getMemMatrix(n, m);
    inputMatrix(a);

    printf("%d", countEqClassesByRowsSum(a));

    freeMemMatrix(a);
    return 0;
}
