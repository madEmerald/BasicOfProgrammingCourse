#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int main() {
    int n;
    scanf("%d", &n);

    matrix m = getMemMatrix(n, n);
    inputMatrix(m);

    int minElementRowIndex = getMinValuePos(m).rowIndex;
    int maxElementRowIndex = getMaxValuePos(m).rowIndex;

    swapRows(m, minElementRowIndex, maxElementRowIndex);

    outputMatrix(m);

    return 0;
}
