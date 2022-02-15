#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix product = mulMatrices(m1, m2);

    return isEMatrix(product);
}

int main() {
    int n;
    scanf("%d", &n);

    matrix a1 = getMemMatrix(n, n);
    inputMatrix(a1);

    matrix a2 = getMemMatrix(n, n);
    inputMatrix(a2);

    if (isMutuallyInverseMatrices(a1, a2))
        printf("YES");
    else
        printf("NO");

    freeMemMatrix(a1);
    freeMemMatrix(a2);
    return 0;
}
