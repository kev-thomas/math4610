#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double bisection(double (*f)(double), double a, double b, double tol) {
    double maxIter = -((log(tol) / log(b - a)) / log(2)) + 1;
    int x;
    int i = 0;

    while(i < maxIter) {
        x = (a + b) / 2;

        if(f(x) == 0 || (b - a) / 2 < tol) {
            return x;
        }

        if(x < 0) {
            a = x;
        }
        else {
            b = x;
        }
        i += 1;

    }

    return x;

}