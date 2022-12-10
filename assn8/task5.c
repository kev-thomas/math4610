#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void jacobiIteration(int n, double a[n][n], double b[n], double x[n], double tol, int maxIter) {
    int iter = 0;
    double error = 10.0 * tol;
    double xCopy[n];
    double res[n];
    double x1[n];

    for(int i = 0; i < n; i++) {
        xCopy[i] = x[i];
    }

    for(int i = 0; i < n; i++) {
        double sum = b[i];
        for (int j = 0; j < n; j++) {
            sum -= a[i][j] * xCopy[j];
        }
        res[i] = sum;
    }

    while (error > tol && iter < maxIter) {
        for(int i = 0; i < n; i++) {
            x1[i] = xCopy[i] + res[i] / a[i][i];
        }
        error = 0;

        for(int i = 0; i < n; i++) {
            double d = x1[i] - xCopy[i];
            error += d * d;
        }
        error = sqrtf(error);

        for(int i = 0; i < n; i++) {
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                sum -= a[i][j] * x1[j];
            }
            res[i] = sum;
        }

        for(int i = 0; i < n; i++) {
            xCopy[i] = x1[i];
        }
        iter++;
    }

    for (int i = 0; i < n; i++) {
        x[i] = xCopy[i];
    }
}


int main() {
    double a[100][100];
    double b[100];
    double x[100];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if(i == j) {
                a[i][j] = 200 + rand() % 200;
            }
            else {
                a[i][j] = rand() % 50 - 5;
            }
        }
        x[i] = 0;
        b[i] = 40 + rand() % 500;
    }
    
    jacobiIteration(100, a, b, x, 0.00001, 500);

    for(int i = 0; i < 100; i++) {
        printf("%f\n", x[i]);
    }
}