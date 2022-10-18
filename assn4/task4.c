#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double absError(double u, double v) {
    return u - v;
}

double relError(double u, double v) {
    return (u - v) / u;
}