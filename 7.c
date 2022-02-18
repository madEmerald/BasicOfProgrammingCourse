#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

long long findSumOfMaxesOfPseudoDiagonal(matrix m, bool horizontal) {
    long long sum = 0;
    int n = horizontal ? m.nCols : m.nRows;
    for (int i = 1; i < n; i++) {
        int iDiagonal = horizontal ? 1 : i + 1;
        int jDiagonal = horizontal ? i + 1 : 1;
        int max = horizontal ? m.values[0][i] : m.values[i][0];
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

    printf("%lld",
           findSumOfMaxesOfPseudoDiagonal(a, false) + findSumOfMaxesOfPseudoDiagonal(a, true));

    freeMemMatrix(a);
    return 0;
}