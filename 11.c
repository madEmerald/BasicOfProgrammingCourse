#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int getNSpecialElement(matrix m) {
    int nSpecialElement = 0;

    for (int j = 0; j < m.nCols; j++) {
        long long sum = m.values[0][j];
        int max = m.values[0][j];
        for (int i = 1; i < m.nRows; i++) {
            sum += m.values[i][j];

            if (m.values[i][j] > max)
                max = m.values[i][j];
        }
        if (max > sum - max)
            nSpecialElement++;
    }
    return nSpecialElement;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    matrix a = getMemMatrix(n, m);
    inputMatrix(a);

    printf("%d", getNSpecialElement(a));

    freeMemMatrix(a);
    return 0;
}