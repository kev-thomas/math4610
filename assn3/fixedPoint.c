#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fixedPoint(double (*f)(double), double x0, double tol, double maxIter) {
    double error = 10.0 * tol;
    double x1;
    int i = 0;

    while(error > tol && i < maxIter) {
        x1 = f(x0);
        error = fabs(x1 - x0)
        x0 = x1;
        i += 1;
    }

    return x0;
}