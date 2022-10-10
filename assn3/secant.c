#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double secant(double (*f)(double), double x0, double x1, double tol, int maxIter) {
    double error;
    double x;

    for(int i = 0; i < maxIter; i++) {
        error = f(x0) / fp(x0);

        if(fabs(f(x1)) <= tol) {
            break;
        }
        x = x1 - f(x1) * (x1 - x0) / f(x1) - f(x0);
        x0 = x1;
        x1 = x;
    }

    return x;
}