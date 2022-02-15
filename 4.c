#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int getElementOfSquareOfMatrix(const matrix m, const int rowIndex, const int colIndex) {
    int element = 0;
    for (int i = 0; i < m.nRows; i++)
        element += m.values[i][colIndex] * m.values[rowIndex][i];

    return element;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        int matrixSize = m->nRows;
        matrix squareOfMatrix = getMemMatrix(matrixSize, matrixSize);

        for (int i = 0; i < matrixSize; i++)
            for (int j = i; j < matrixSize; j++)
                squareOfMatrix.values[i][j] = getElementOfSquareOfMatrix(*m, i, j);

        for (int i = 1; i < matrixSize; i++)
            for (int j = 0; j < i; j++)
                squareOfMatrix.values[i][j] = squareOfMatrix.values[j][i];

        m->values = squareOfMatrix.values;

        freeMemMatrix(squareOfMatrix);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    matrix a = getMemMatrix(n, m);
    inputMatrix(a);

    getSquareOfMatrixIfSymmetric(&a);

    outputMatrix(a);

    freeMemMatrix(a);
    return 0;
}
