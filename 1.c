#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int main() {
    int n;
    scanf("%d", &n);

    matrix a = getMemMatrix(n, n);
    inputMatrix(a);

    int minElementRowIndex = getMinValuePos(a).rowIndex;
    int maxElementRowIndex = getMaxValuePos(a).rowIndex;

    swapRows(a, minElementRowIndex, maxElementRowIndex);

    outputMatrix(a);

    freeMemMatrix(a);
    return 0;
}
