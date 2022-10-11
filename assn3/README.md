# Assignment #3

## Task 1

### Code (`fixedPoint.c`):

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fixedPoint(double (*f)(double), double x0, double tol, double maxIter) {
    double error = 10.0 * tol;
    double x1;
    int i = 0;

    while(error > tol && i < maxIter) {
        x1 = f(x0);
        error = fabs(x1 - x0);
        x0 = x1;
        i += 1;
    }

    return x0;
}
```

### Code (`bisection.c`):

```c
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
```

### Code (`newton.c`):

```c
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
```

### Code (`newtonHybrid.c`):

```c
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

        if(x > error) {
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
```

### Code (`secant.c`):

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double secant(double (*f)(double), double x0, double x1, double tol, int maxIter) {
    double error;
    double x;

    for(int i = 0; i < maxIter; i++) {
        if(fabs(f(x1)) <= tol) {
            break;
        }
        x = x1 - f(x1) * (x1 - x0) / f(x1) - f(x0);
        x0 = x1;
        x1 = x;
    }

    return x;
}
```

### Code (`secantHybrid.c`):

```c
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
```


## Task 2

### Code (`test.c`)

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fixedPoint(double (*f)(double), double x0, double tol, double maxIter);

double f(double x) {
    return x * pow(M_E, -x);
}

double fp(double x) {
    return pow(M_E, -x) - (x * pow(M_E, -x));
}

int main() {
    printf("%.15f", fixedPoint(f, 1.0, 0.00001, 1000));
}
```

### Output:

```shell
% testRootFinding.exe
0.003152888886781
```


## Task 3

### Code (`test.c`)

```c
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
```

### Output:

```shell
% testRootFinding.exe
0.003152888886781
0.000000000000000
-0.000000114797514
-0.000000000000013
0.000000370101308
0.000005054914321
```