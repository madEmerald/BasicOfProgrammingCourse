#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sum = 0;
    for (int j = 1; j < m.nCols; j++) {
        int iDiagonal = 1;
        int jDiagonal = j + 1;
        int max = m.values[0][j];
        while (iDiagonal < m.nRows && jDiagonal < m.nCols) {
            if (m.values[iDiagonal][jDiagonal] > max)
                max = m.values[iDiagonal][jDiagonal];

            iDiagonal++;
            jDiagonal++;
        }
        sum += max;
    }

    for (int i = 1; i < m.nRows; i++) {
        int iDiagonal = i + 1;
        int jDiagonal = 1;
        int max = m.values[i][0];
        while (iDiagonal < m.nRows && jDiagonal < m.nCols) {
            if (m.values[iDiagonal][jDiagonal] > max)
                max = m.values[iDiagonal][jDiagonal];

            iDiagonal++;
            jDiagonal++;
        }
        sum += max;
    }
    return sum;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    matrix a = getMemMatrix(n, m);
    inputMatrix(a);

    printf("%lld", findSumOfMaxesOfPseudoDiagonal(a));

    freeMemMatrix(a);
    return 0;
}