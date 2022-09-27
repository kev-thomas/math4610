# Secant / Bisection root finding method

**Routine name:** `secant_hybrid`
**Author:** Kevin Thomas
**Language:** Python

**Description:** Approximates the root of a function given the function, two initial estimates, maximum number of iterations, and a tolerance goal. This method implements bisection within the secant root finding algorithm.

## Usage:
The routine supports a boolean `verbose` keyword argument that prints a table of iterations.

Input:
```py
f = lambda x: x * np.e ** (-x)
fp = lambda x: (np.e ** (-x)) - (x * np.e ** (-x))
tol = 0.00001
max_iter = 1000

secant_hybrid(f, -3, -1, tol, max_iter, verbose=verbose)
```

Output:
```py
iteration 1     |  approximation: 5.72566E+01      |  error: -6.72253E+00
iteration 2     |  approximation: 1.71828E+00      |  error: 3.08215E-01
iteration 3     |  approximation: 5.22253E+00      |  error: -1.39404E+00
iteration 4     |  approximation: 1.41007E+00      |  error: -1.00868E-01
iteration 5     |  approximation: 6.98608E-01      |  error: -3.09618E-01
iteration 6     |  approximation: 8.86590E-03      |  error: 8.78764E-03
iteration 7     |  approximation: 6.67590E-02      |  error: -5.70688E-02
iteration 8     |  approximation: 7.82567E-05      |  error: 7.82506E-05
iteration 9     |  approximation: 3.00351E-03      |  error: -1.36399E-02
iteration 10    |  approximation: 6.12388E-09      |  error: 6.12388E-09
# returns 6.123878226063184e-09
```

## Implementation:
```py
def secant_hybrid(f, x0, x1, tol, max_iter, verbose: bool = False) -> float:
    """
    Find root of f(x) using secant method.
    """
    # iterate
    for i in range(max_iter):
        # exit if we hit tolerance
        if abs(f(x1)) <= tol:
            break
        # calculate x
        x = x1 - f(x1) * (x1 - x0) / f(x1) - f(x0)
        # use bisection
        if abs(x) > abs(f(x1)):
            a = x0
            b = x1
            c = (a + b) / 2
            if f(a) * f(c) < 0:
                b = c
            else:
                a = c
            x0 = x1
            x1 = (a + b) / 2
        else:
            x0 = x1
            x1 = x

        # print table
        if verbose:
            print('iteration %-5i |  approximation: %-15.5E  |  error: %-10.5E' % (i+1, x, f(x1)))

    return x
```