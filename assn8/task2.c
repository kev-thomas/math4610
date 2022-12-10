#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    double error = 10.0 * tol;
    int iter = 0;
    double norm;
    double aNew[n];

    for (int i = 0; i < n; i++) {
        xNew[i] = x[i];
    }

    while (error > tol && iter < maxIter) {
        matrixVectorProduct(n, n, a, x, xNew);
        norm = l2Norm(n, xNew);

        for (int i = 0; i < n; i++) {
            xNew[i] /= norm;
        }

        matrixVectorProduct(n, n, a, xNew, aNew);
        lambdaNew = vectorDotProduct(n, xNew, aNew);
        error = fabs(lambdaNew - lambda);
        lambda = lambdaNew;

        for(int i = 0; i < n; i++) {
            x[i] = xNew[i];
        }

        iter++;
    }
    return lambda;
}

int main() {
    double a[15][15];
    double x[15];

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if(i == j) {
                a[i][j] = 40 + rand() % 50;
            }
            else {
                a[i][j] = rand() % 10;
            }
            printf("%f ", a[i][j]);
        }
        x[i] = 1.0;
        printf("\n");
    }
    printf("\n\n");

    printf("%f\n", matrixPowerMethod(15, a, x, 1000, 0.00001));
}
