#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/basicAlgorithms/basicAlgorithms.h"

int getMinInArea(const matrix m) {
    position maxValuePos = getMaxValuePos(m);

    int min = m.values[maxValuePos.rowIndex][maxValuePos.colIndex];
    for (int i = 0; i < maxValuePos.rowIndex; i++) {
        int d = maxValuePos.rowIndex - i;
        for (int j = max2(maxValuePos.colIndex - d, 0); j < min2(maxValuePos.colIndex + d + 1, m.nCols); j++)
            if (m.values[i][j] < min)
                min = m.values[i][j];
    }
    return min;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    matrix a = getMemMatrix(n, m);
    inputMatrix(a);

    printf("%d", getMinInArea(a));

    freeMemMatrix(a);
    return 0;
}
