## Matrix Hadamard Product

### Function name: `hadamardMatrices`
### Language: C
### Author: Kevin Thomas

### Description:
Takes pointers to matrices `a`, `b`, and `result`, calculates the hadamard product of `a` and `b` and stores the result in `result`. Uses the OpenMP library for parallelization. Also prints the result as it is calculated.

### Usage:

```c
int main() {
    double a[2][2] = {{1, 2},
                      {1, 2}}
    double b[2][2] = {{1, 2},
                      {3, 4}}
    double result[2][2];

    hadamardMatrices(&a[0][0], &b[0][0], &result[0][0], 2, 2);
    // returns {{1, 4},
    //          {3, 8}}
}
```

### Implementation:
```c
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
```