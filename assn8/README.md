# Assignment #8

## Task 1

I wrote the following C program to calculate the kronecker product of 2 matrices using OpenMP:

### Code (`task1.c`):

```c
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
```

I then ran the following commands in the shell prompt to compile and run the code, and received output as shown below:

```shell
% gcc -c task1.c
% gcc -o task1 task1.o -lm -lgomp
% ./task1
2.000000 2.000000 4.000000 4.000000
2.000000 2.000000 4.000000 4.000000
0.000000 0.000000 2.000000 2.000000
0.000000 0.000000 2.000000 2.000000
```

## Task 2

For task 2, I wrote the following program to perform the power method for finding the greatest eigenvalue of a matrix:

### Code (`task2.c`):

```c
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

```

I tested the `matrixPowerMethod` routine by generating a random diagonally dominant 15x15 matrix. I ran the following commands in the terminal, which produced the following output:

```shell
% gcc -c task2.c
% gcc -o task2 task2.o -lm
% ./task2
73.000000 6.000000 7.000000 5.000000 3.000000 5.000000 6.000000 2.000000 9.000000 1.000000 2.000000 7.000000 0.000000 9.000000 3.000000
6.000000 80.000000 6.000000 2.000000 6.000000 1.000000 8.000000 7.000000 9.000000 2.000000 0.000000 2.000000 3.000000 7.000000 5.000000
9.000000 2.000000 62.000000 8.000000 9.000000 7.000000 3.000000 6.000000 1.000000 2.000000 9.000000 3.000000 1.000000 9.000000 4.000000
7.000000 8.000000 4.000000 55.000000 0.000000 3.000000 6.000000 1.000000 0.000000 6.000000 3.000000 2.000000 0.000000 6.000000 1.000000
5.000000 5.000000 4.000000 7.000000 76.000000 5.000000 6.000000 9.000000 3.000000 7.000000 4.000000 5.000000 2.000000 5.000000 4.000000
7.000000 4.000000 4.000000 3.000000 0.000000 77.000000 8.000000 6.000000 8.000000 8.000000 4.000000 3.000000 1.000000 4.000000 9.000000
2.000000 0.000000 6.000000 8.000000 9.000000 2.000000 66.000000 6.000000 4.000000 9.000000 5.000000 0.000000 4.000000 8.000000 7.000000
1.000000 7.000000 2.000000 7.000000 2.000000 2.000000 6.000000 41.000000 0.000000 6.000000 1.000000 5.000000 9.000000 4.000000 9.000000
0.000000 9.000000 1.000000 7.000000 7.000000 1.000000 1.000000 5.000000 49.000000 7.000000 7.000000 6.000000 7.000000 3.000000 6.000000
5.000000 6.000000 3.000000 9.000000 4.000000 8.000000 1.000000 2.000000 9.000000 43.000000 9.000000 0.000000 8.000000 8.000000 5.000000
0.000000 9.000000 6.000000 3.000000 8.000000 5.000000 6.000000 1.000000 1.000000 5.000000 69.000000 8.000000 4.000000 8.000000 1.000000
0.000000 3.000000 0.000000 4.000000 4.000000 4.000000 4.000000 7.000000 6.000000 3.000000 1.000000 67.000000 5.000000 9.000000 6.000000
2.000000 1.000000 7.000000 8.000000 5.000000 7.000000 4.000000 1.000000 8.000000 5.000000 9.000000 7.000000 75.000000 3.000000 8.000000
8.000000 3.000000 1.000000 8.000000 9.000000 6.000000 4.000000 3.000000 3.000000 3.000000 8.000000 6.000000 0.000000 44.000000 8.000000
8.000000 8.000000 9.000000 7.000000 7.000000 6.000000 4.000000 3.000000 0.000000 3.000000 0.000000 9.000000 2.000000 5.000000 84.000000


132.795867
```

## Task 3

For task 3, I copied and modified my code from task 2 as shown below. The modified code includes the new optimized algorithm alongside the old one, and the driver code tests each algorithm on matrices of sizes 15, 100, and 500 and outputs the time taken per matrix per algorithm.
### Code (`task3.c`):

```c
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

// largest eigenvalue of a matrix using the power method
double matrixPowerMethodNew(int n, double a[n][n], double x[n], int maxIter, double tol) {
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
    
    double s1N = omp_get_wtime();
    double r1N = matrixPowerMethodNew(15, a1, x1, 1000, 0.00001);
    double e1N = omp_get_wtime();

    double s2 = omp_get_wtime();
    double r2 = matrixPowerMethod(100, a2, x2, 1000, 0.00001);
    double e2 = omp_get_wtime();

    double s2N = omp_get_wtime();
    double r2N = matrixPowerMethodNew(100, a2, x2, 1000, 0.00001);
    double e2N = omp_get_wtime();

    double s3 = omp_get_wtime();
    double r3 = matrixPowerMethod(500, a3, x3, 1000, 0.00001);
    double e3 = omp_get_wtime();

    double s3N = omp_get_wtime();
    double r3N = matrixPowerMethodNew(500, a3, x3, 1000, 0.00001);
    double e3N = omp_get_wtime();

    printf("old 15x15: %f\nnew 15x15: %f\n", e1-s1, e1N-s1N);
    printf("old 100x100: %f\nnew 100x100: %f\n", e2-s2, e2N-s2N);
    printf("old 500x500: %f\nnew 500x500: %f\n", e3-s3, e3N-s3N);
}
```

Compiling and running the code was the same as in the previous task:

```shell
% gcc -c task3.c
% gcc -o task3 task3.o -lm
% ./task3
old 15x15: 0.000028
new 15x15: 0.000003
old 100x100: 0.001761
new 100x100: 0.000093
old 500x500: 0.001647
new 500x500: 0.001605
```

Our timing results show that the new algorithm is significantly faster for smaller algorithms, achieving an approximate performance increase of 830% for the 15x15 matrix and 1800% for the 100x100 matrix. The 500/500 matrix was quite close for both algorithms, showing the performance drop-off that occurs as the problem size increases.

## Task 4

For task 4, I copied and modified my code from task 3 by removing the old algorithm and adding the OpenMP directive to the `matrixVectorProduct` routine, since it has a nested for-loop, giving it a runtime complexity of O(n^2) and would cause it to have the most impact on larger problem sizes.

### Code (`task4.c`):

```c
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
```

Compiling and running the code in the terminal produced the following output:

```shell
% gcc -c task3.c
% gcc -o task3 task3.o -lm
% ./task3
15x15: 0.000017
100x100: 0.000918
500x500: 0.001517
```

The new method that utilizes parallelization is slower for 15x15 and 100x100 matrices, but slightly faster for the 500x500 matrices. This is likely because the overhead required to parallelize is greater than the total runtime without for smaller problems. It's likely that extremely large problem sizes would see greater decreases in runtime, given the small performance gain for the 500x500 matrices.


