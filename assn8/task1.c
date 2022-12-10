#include <stdio.h>
#include <math.h>
#include <omp.h>

// kronecker product of two matrices
void kroneckerMatrices(int aRows, int aCols, int bRows, int bCols, 
    double a[aRows][aCols], double b[bRows][bCols], double result[aRows*bRows][aCols*bCols]) {
    
    #pragma omp parallel for
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < aCols; j++) {
            for (int k = 0; k < bRows; k++) {
                for (int l = 0; l < bCols; l++) {
                    result[i*bRows + k][j*bCols + l] = a[i][j] * b[k][l];
                }
            }
        }
    }
}

// driver code for testing
int main() {
    double a[2][2] = {{1, 2}, {0, 1}};
    double b[2][2] = {{2, 2}, {2, 2}};
    double result[4][4];

    kroneckerMatrices(2, 2, 2, 2, a, b, result);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }
}
