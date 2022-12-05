#include <stdio.h>
#include <math.h>
#include <omp.h>

// multiply matrices
void multMatrices(double *a, double *b, double *result, int aRows, int bRows, int bCols) {
    #pragma omp parallel for
    for(int i = 0; i < aRows; i++) {
        for(int  j = 0; j < bCols; j++) {
            for(int k = 0; k < bRows; k++) {
                result[i*bCols+j] += a[i*aRows+k] * b[k*bCols+j];
            }
            printf("%f ", result[i+j]);
        }
        printf("\n");
    }
}

// driver code for testing
int main() {
    double a[2][2] = {{1, 1}, {2, 2}};
    double b[2][2] = {{1, 1}, {2, 2}};
    double result[2][2];

    multMatrices(&a[0][0], &b[0][0], &result[0][0], 2, 2, 2);
}