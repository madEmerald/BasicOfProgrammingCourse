#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include "matrix.h"
#include "../../algorithms/basicAlgorithms/basicAlgorithms.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);

    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
        printf("\n");
    }
    printf("\n");
}

void outputMatrix(matrix m) {
    printf("{");
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        if (i == m.nRows - 1)
            printf("\b}");
        printf("\n ");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, const int i1, const int i2) {
    swap(&m.values[i1], &m.values[i2], sizeof(int **));
}

void swapCols(matrix m, const int j1, const int j2) {
    for (int i = 0; i < m.nRows; i++)
        swap(&m.values[i][j1], &m.values[i][j2], sizeof(int));
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *sortKeys = malloc(m.nRows * sizeof(int));
    for (int i = 0; i < m.nRows; i++)
        sortKeys[i] = criteria(m.values[i], m.nCols);

    for (size_t sortedPartLength = 1; sortedPartLength < m.nRows; sortedPartLength++) {
        int *insertingRow = m.values[sortedPartLength];
        int insertingRowKey = sortKeys[sortedPartLength];
        int i = sortedPartLength;
        while (i > 0 && sortKeys[i - 1] > insertingRowKey) {
            m.values[i] = m.values[i - 1];
            sortKeys[i] = sortKeys[i - 1];
            i--;
        }
        m.values[i] = insertingRow;
        sortKeys[i] = insertingRowKey;
    }
    free(sortKeys);
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *sortKeys = malloc(m.nCols * sizeof(int));
    int *column = malloc(m.nRows * sizeof(int));
    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++)
            column[i] = m.values[i][j];

        sortKeys[j] = criteria(column, m.nRows);
    }
    free(column);

    for (size_t sortedPartLength = 0; sortedPartLength < m.nCols - 1; sortedPartLength++) {
        int minPos = sortedPartLength;
        for (int j = sortedPartLength + 1; j < m.nCols; j++)
            if (sortKeys[j] < sortKeys[minPos])
                minPos = j;

        swap(&sortKeys[sortedPartLength], &sortKeys[minPos], sizeof(int));
        swapCols(m, sortedPartLength, minPos);
    }
    free(sortKeys);
}

bool isSquareMatrix(const matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(const matrix m1, const matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m1.nCols; j++)
            if (m1.values[i][j] != m2.values[i][j])
                return false;
    return true;
}

bool isEMatrix(const matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (i == j) {
                if (m.values[i][j] != 1)
                    return false;
            } else if (m.values[i][j] != 0)
                return false;
    return true;
}

bool isSymmetricMatrix(const matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++)
            if (m.values[j][i] != m.values[i][j])
                return false;

    return true;
}

void transposeSquareMatrix(matrix m) {
    assert(isSquareMatrix(m));

    matrix newMatrix = getMemMatrix(m.nRows, m.nCols);
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            newMatrix.values[i][j] = m.values[j][i];

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            m.values[i][j] = newMatrix.values[i][j];

    freeMemMatrix(newMatrix);
}

position getMinValuePos(const matrix m) {
    int min = m.values[0][0];
    position minElementPosition = {0, 0};
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < min) {
                minElementPosition = (position) {i, j};
                min = m.values[i][j];
            }
    return minElementPosition;
}

position getMaxValuePos(const matrix m) {
    int max = m.values[0][0];
    position maxElementPosition = {0, 0};
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > max) {
                maxElementPosition = (position) {i, j};
                max = m.values[i][j];
            }
    return maxElementPosition;
}

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

int getElementOfProductOfMatrices(const matrix m1, const matrix m2, const int rowIndex, const int colIndex) {
    int element = 0;
    for (int i = 0; i < m1.nRows; i++)
        element += m1.values[i][colIndex] * m2.values[rowIndex][i];

    return element;
}

matrix mulMatrices(const matrix m1, const matrix m2) {
    matrix product = getMemMatrix(m1.nRows, m2.nCols);

    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++)
            product.values[i][j] = getElementOfProductOfMatrices(m1, m2, i, j);
    return product;
}