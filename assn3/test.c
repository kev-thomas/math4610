#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fixedPoint(double (*f)(double), double x0, double tol, double maxIter);
double bisection(double (*f)(double), double a, double b, double tol);
double newton(double (*f)(double), double (*fp)(double), double x0, double tol, int maxIter);
double newtonHybrid(double (*f)(double), double (*fp)(double), double x0, double tol, int maxIter);
double secant(double (*f)(double), double x0, double x1, double tol, int maxIter);
double secantHybrid(double (*f)(double), double x0, double x1, double tol, int maxIter);


double f(double x) {
    return x * pow(M_E, -x);
}

double fp(double x) {
    return (pow(M_E, -x) - (x * pow(M_E, -x)));
}

int main() {
    double tol = 0.00001;
    int maxIter = 1000;
    printf("%.15f\n", fixedPoint(f, 1.0, tol, maxIter));
    printf("%.15f\n", bisection(f, -3.0, 4.0, tol));
    printf("%.15f\n", newton(f, fp, -3.0, tol, maxIter));
    printf("%.15f\n", newtonHybrid(f, fp, -3.0, tol, maxIter));
    printf("%.15f\n", secant(f, -2.0, 3.0, tol, maxIter));
    printf("%.15f\n", secantHybrid(f, -2.0, 3.0, tol, maxIter));
}