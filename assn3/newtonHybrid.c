#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newtonHybrid(double (*f)(double), double (*fp)(double), double x0, double tol, int maxIter) {
    double x;
    double error;
    double a;
    double b;
    double c;

    for(int i = 0; i < maxIter; i++) {
        error = f(x0) / fp(x0);
        x = x0 - error;

        if(fabs(error) <= tol) {
            break;
        }

        if x > error {
            c = (a + b) / 2;
            if(f(a) * f(c) < 0) {
                b = c;
            }
            else {
                a = c;
            }
        }
        x0 = x;
    }

    return x;
}