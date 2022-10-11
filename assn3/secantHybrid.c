#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double secantHybrid(double (*f)(double), double x0, double x1, double tol, int maxIter) {
    double error;
    double x;
    double a;
    double b;
    double c;

    for(int i = 0; i < maxIter; i++) {
        if(fabs(f(x1)) <= tol) {
            break;
        }
        x = x1 - f(x1) * (x1 - x0) / f(x1) - f(x0);

        if(fabs(x) > fabs(f(x1))) {
            a = x0;
            b = x1;
            c = (a + b) / 2;
            if(f(a) * f(c) < 0) {
                b = c;
            }
            else {
                a = c;
            }
            x0 = x1;
            x1 = (a + b) / 2;
        }
        else {
            x0 = x1;
            x1 = x;
        }
    }

    return x;
}