#include <stdio.h>
#include <math.h>
#include <omp.h>

#define NUM_THREADS 8

// function used in approximation (half circle)
double f(double x) {
    return sqrt(1 - (x * x));
}

// trapezoid rule to approximate integrals
double trapezoidRule(double (*f)(double), double lower, double upper, int n) {
    double x;
    double sum[NUM_THREADS];
    double result = 0;
    double h = fabs(upper - lower) / n;
    int totalThreadsCt = 0;

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int thread = omp_get_thread_num();
        int totalThreads = omp_get_num_threads();
        if (thread == 0) totalThreadsCt = totalThreads;

        for(int i = 1; i < n; i = i + totalThreads) {
            x = lower + i * h;
            sum[thread] += f(x);
        }

    }


    for(int i = 0; i < totalThreadsCt; i++) {
        result += sum[i];
    }
    
    return result * h;
}

// driver code
int main() {
    double pi = 2 * trapezoidRule(f, -1, 1, 10000000);
    printf("approximate value of pi: %.10f\n", pi);

    return 0;
}