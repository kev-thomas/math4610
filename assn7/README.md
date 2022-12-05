# Assignment #7

## Task 1

First, I created the following basic method to perform matrix multiplication:

```c
#include <stdio.h>
#include <math.h>

// multiply matrices
void multMatrices(double *a, double *b, double *result, int aRows, int bRows, int bCols) {
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
```

I compiled and ran the code using the following shell commands and got the output as shown:

```shell
% gcc -c task1.c
% gcc -o task1 task1.o
% ./task1
3.000000 3.000000
3.000000 6.000000
```

I then modified my code to use the OpenMP library:

### Code (`task1.c`):

```c
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
```

I was then able to recompile the code to include the OpenMP library and verify that it produced the same output:

```shell
% gcc -c task1.c
% gcc -o task1 task1.o -lm -lgomp
% ./task1
3.000000 3.000000
3.000000 6.000000
```

## Task 2

I created a basic method to compute the hadamard product of 2 vectors, and tested it using on 2 small arrays of the same numbers to easily verify that the code is correct.

### Code (`task2.c`):

```c
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
```

I then compiled and tested the code in the same manner as the previous task:

```shell
% gcc -c task2.c
% gcc -o task2 task2.o
% ./task2
1.000000 4.000000 9.000000 16.000000 25.000000 36.000000 49.000000 64.000000 81.000000 0.000000
```

## Task 3

I modified my code from task 2 to include the OpenMP directives for parallelism as shown:

### Code (`task3.c`):

```c
#include <stdio.h>
#include <math.h>
#include <omp.h>

// get hadamard product of 2 vectors of length n
void hadamardVectors(double *a, double *b, double *result, int n) {
    #pragma omp parallel for
    for(int i = 0; i < n; i++) {
        result[i] = a[i] * b[i];
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
```

i also compiled it and ran it the same way as I did in task 1:

```shell
% gcc -c task3.c
% gcc -o task3 task3.o -lm -lgomp
% ./task3
1.000000 4.000000 9.000000 16.000000 25.000000 36.000000 49.000000 64.000000 81.000000 0.000000
```

## Task 4

I wrote the following code to find the hadamard product of 2 matrices:

### Code (`task4.c`):

```c
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
```

I compiled and ran the code using the same commands as in the previous tasks (I've omitted the output because it is extremely long):

```shell
% gcc -c task4.c
% gcc -o task4 task4.o
% ./task4

```

## Task 5

I wrote the following routine that finds the outer product of 2 vectors in parallel:

### Code (`task5.c`):

```c
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
```

The code was compiled and ran in the same manner as the previous tasks:

```shell
% gcc -c task5.c
% gcc -o task5 task5.o
% ./task5
0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000...
```

Based on the definition of an outer product, in order to find the outer product of 2 matrices, you would need to have 4 nested loops in order to multiply every combination of matrix elements. These matrices would also need to be the same dimensions.