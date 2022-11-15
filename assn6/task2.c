#include <stdio.h>
#include <math.h>

// function used in approximation (half circle)
double f(double x) {
    return sqrt(1 - (x * x));
}

// trapezoid rule to approximate integrals
double trapezoidRule(double (*f)(double), double lower, double upper, int n) {
    double x, sum, result;
    double h = fabs(upper - lower) / n;

    for(int i = 1; i < n; i++) {
        x = lower + i * h;
        sum += f(x);
    }

    result = (h / 2) * (f(lower) + f(upper) + 2 * sum);

    return result;
}

// driver code
int main() {
    double pi = 2 * trapezoidRule(f, -1, 1, 100000);
    printf("approximate value of pi: %.10f\n", pi);

    return 0;
}