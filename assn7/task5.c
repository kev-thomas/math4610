#include <stdio.h>
#include <math.h>
#include <omp.h>

// outer product of 2 vectors
void outerVectors(double *a, double *b, double *result, int rows, int cols) {
    #pragma omp parallel for
    for(int i = 0; i < rows; i++) {
        for(int  j = 0; j < cols; j++) {
            result[i*rows+j] = a[i] * b[j];
            printf("%f ", result[i*rows+j]);
        }
        printf("\n");
    }
}

// driver code for testing
int main() {
    double a[100];
    double b[100];
    double result[100][100];

    for(int i = 0; i < 100; i++) {
            a[i] = i;
            b[i] = i;
    }

    outerVectors(&a[0], &b[0], &result[0][0], 100, 100);
}