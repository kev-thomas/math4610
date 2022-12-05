#include <stdio.h>
#include <math.h>
#include <omp.h>

// hadamard product of matrices
void hadamardMatrices(double *a, double *b, double *result, int rows, int cols) {
    #pragma omp parallel for
    for(int i = 0; i < rows; i++) {
        for(int  j = 0; j < cols; j++) {
            result[i*rows+j] = a[i*rows+j] * b[i*rows+j];
            printf("%f ", result[i*rows+j]);
        }
        printf("\n");
    }
}

// driver code for testing
int main() {
    double a[100][200];
    double b[100][200];
    double result[100][200];

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 200; j++) {
            a[i][j] = i + j;
            b[i][j] = i + j;
        }
    }

    hadamardMatrices(&a[0][0], &b[0][0], &result[0][0], 100, 200);
}