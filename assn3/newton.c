#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newton(double (*f)(double), double (*fp)(double), double x0, double tol, int maxIter) {
    double x;
    double error;

    for(int i = 0; i < maxIter; i++) {
        error = f(x0) / fp(x0);

        if(fabs(error) <= tol) {
            break;
        }
        x = x0 - error;
        x0 = x;
    }

    return x;
}