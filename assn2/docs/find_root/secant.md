# Newton's root finding method

**Routine name:** `secant`
**Author:** Kevin Thomas
**Language:** Python

**Description:** Approximates the root of a function given the function, initial estimates `x0` and `x1`, maximum number of iterations, and a tolerance goal.

## Usage:
The routine supports a boolean `verbose` keyword argument that prints a table of iterations.

Input:
```py
f = lambda x: x * np.e ** (-x)
tol = 0.00001
max_iter = 1000

secant(f, -1, 1, tol, max_iter, verbose=verbose)
```

Output:
```py
iteration 1     |  approximation: 1.71828E+00      |  error: 3.67879E-01
iteration 2     |  approximation: 6.32121E-01      |  error: 3.08215E-01
iteration 3     |  approximation: 1.41007E+00      |  error: 3.35949E-01
iteration 4     |  approximation: 2.96171E-01      |  error: 3.44235E-01
iteration 5     |  approximation: 1.06583E+00      |  error: 2.20251E-01
iteration 6     |  approximation: 7.59206E-02      |  error: 3.67116E-01
iteration 7     |  approximation: 6.98715E-01      |  error: 7.03701E-02
iteration 8     |  approximation: 5.55057E-03      |  error: 3.47418E-01
iteration 9     |  approximation: 3.51297E-01      |  error: 5.51985E-03
iteration 10    |  approximation: 3.07235E-05      |  error: 2.47234E-01
iteration 11    |  approximation: 1.04063E-01      |  error: 3.07226E-05
iteration 12    |  approximation: 9.43921E-10      |  error: 9.37784E-02
# returns 9.439212009812676e-10
```

## Implementation:
```py
def secant(f, x0, x1, tol, max_iter, verbose: bool = False) -> float:
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
        # print table
        if verbose:
            print('iteration %-5i |  approximation: %-15.5E  |  error: %-10.5E' % (i+1, x, f(x1)))
        x0 = x1
        x1 = x

    return x
```