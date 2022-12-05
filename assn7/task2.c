#include <stdio.h>
#include <math.h>

// get hadamard product of 2 vectors of length n
void hadamardVectors(double *a, double *b, double *result, int n) {
    for(int i = 0; i < n; i++) {
        result[i] += a[i] * b[i];
        printf("%f ", result[i]);
    }
    printf("\n");
}

// driver code for testing
int main() {
    double a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    double b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    double result[10];

    hadamardVectors(&a[0], &b[0], &result[0], 10);
}