#include <malloc.h>
#include <stdio.h>
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
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
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
        int t = sortKeys[sortedPartLength];
        int i = sortedPartLength;
        while (i > 0 && sortKeys[i - 1] > t) {
            swap(&sortKeys[i], &sortKeys[i - 1], sizeof(int));
            swapRows(m, i, i - 1);
            i--;
        }
    }
    free(sortKeys);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *sortKeys = malloc(m.nCols * sizeof(int));
    int *colElements = malloc(m.nRows * sizeof(int));
    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++)
            colElements[i] = m.values[i][j];

        sortKeys[j] = criteria(colElements, m.nRows);
    }
    free(colElements);

    for (size_t sortedPartLength = 1; sortedPartLength < m.nCols; sortedPartLength++) {
        int t = sortKeys[sortedPartLength];
        int j = sortedPartLength;
        while (j > 0 && sortKeys[j - 1] > t) {
            swap(&sortKeys[j], &sortKeys[j - 1], sizeof(int));
            swapCols(m, j, j - 1);
            j--;
        }
    }
    free(sortKeys);
}
