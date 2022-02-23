#include <math.h>
#include <stdio.h>
#include <malloc.h>

typedef struct matrix {
    float **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
} matrix;


void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%f", &m.values[i][j]);
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
            printf("%f ", m.values[i][j]);
        if (i == m.nRows - 1)
            printf("\b}");
        printf("\n ");
    }
}


matrix getMemMatrix(int nRows, int nCols) {
    float **values = (float **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (float *) malloc(sizeof(float ) * nCols);
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

int getMaxAbsValue(const matrix m) {
    int max = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            int absValue = fabsf(m.values[i][j]);
            if (absValue > max)
                max = absValue;
        }
    return max;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *maxAbsValues = malloc(sizeof(int) * nMatrix);
    maxAbsValues[0] = getMaxAbsValue(ms[0]);
    int min = maxAbsValues[0];

    for (int i = 1; i < nMatrix; i++) {
        maxAbsValues[i] = getMaxAbsValue(ms[i]);

        if (maxAbsValues[i] < min)
            min = maxAbsValues[i];
    }

    for (int i = 0; i < nMatrix; i++)
        if (maxAbsValues[i] == min)
            outputMatrix(ms[i]);

    free(maxAbsValues);
}

int main() {
    int nMatrix;
    scanf("%d", &nMatrix);

    int n;
    scanf("%d", &n);

    matrix *ms = getMemArrayOfMatrices(nMatrix, n, n);
    inputMatrices(ms, nMatrix);

    printMatrixWithMaxZeroRows(ms, nMatrix);

    freeMemMatrices(ms, n);
    return 0;
}