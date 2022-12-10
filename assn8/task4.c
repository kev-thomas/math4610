#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

// dot product of vector
double vectorDotProduct(int n, double v1[n], double v2[n]) {
    double result = 0;

    for(int i = 0; i < n; i++) {
        result += v1[i] * v2[i];
    }

    return result;
}

// matrix vector product
void matrixVectorProduct(int rows, int cols, double a[rows][cols], double v[cols], double result[rows]) {
    double s;

    #pragma omp parallel for
    for(int i = 0; i < rows; i++) {
        result[i] = 0;

        for (int j = 0; j < cols; j++) {
            result[i] += a[i][j] * v[j];
        }
    }
}


//l2 norm of vector
double l2Norm(int n, double v[n]) {
    double sum = 0;

    for(int i = 0; i < n; i++) {
        sum += v[i] * v[i];
    }

    return sqrtf(sum);
}


// largest eigenvalue of a matrix using the power method
double matrixPowerMethod(int n, double a[n][n], double x[n], int maxIter, double tol) {
    double lambda = 0.0;
    double lambdaNew = 0.0;
    double xNew[n];
    double xNew2[n];
    double error = 10.0 * tol;
    int iter = 0;
    double norm;
    double aNew[n];

    matrixVectorProduct(n, n, a, x, xNew);

    while (error > tol && iter < maxIter) {
        norm = l2Norm(n, xNew);

        for (int i = 0; i < n; i++) {
            xNew2[i] = xNew[i] / norm;
        }

        matrixVectorProduct(n, n, a, xNew2, aNew);
        lambdaNew = vectorDotProduct(n, xNew2, aNew);
        error = fabs(lambdaNew - lambda);
        lambda = lambdaNew;

        for(int i = 0; i < n; i++) {
            xNew[i] = aNew[i];
        }

        iter++;
    }
    for(int i = 0; i < n; i++) {
        x[i] = xNew2[i];
    }
    return lambda;
}

int main() {
    double a1[15][15];
    double a2[100][100];
    double a3[500][500];
    double x1[15];
    double x2[100];
    double x3[500];

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if(i == j) {
                a1[i][j] = 40 + rand() % 50;
            }
            else {
                a1[i][j] = rand() % 10;
            }
        }
        x1[i] = 1.0;
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if(i == j) {
                a2[i][j] = 40 + rand() % 50;
            }
            else {
                a2[i][j] = rand() % 10;
            }
        }
        x2[i] = 1.0;
    }

    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            if(i == j) {
                a3[i][j] = 40 + rand() % 50;
            }
            else {
                a3[i][j] = rand() % 10;
            }
        }
        x3[i] = 1.0;
    }
    double s1 = omp_get_wtime();
    double r1 = matrixPowerMethod(15, a1, x1, 1000, 0.00001);
    double e1 = omp_get_wtime();

    double s2 = omp_get_wtime();
    double r2 = matrixPowerMethod(100, a2, x2, 1000, 0.00001);
    double e2 = omp_get_wtime();

    double s3 = omp_get_wtime();
    double r3 = matrixPowerMethod(500, a3, x3, 1000, 0.00001);
    double e3 = omp_get_wtime();

    printf("15x15: %f\n", e1-s1);
    printf("100x100: %f\n", e2-s2);
    printf("500x500: %f\n", e3-s3);
}
