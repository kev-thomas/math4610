## Secant Method

### Function name: `secant`
### Language: python3
### Author: Kevin Thomas

### Description:
Approximates the root of a function given the function, initial estimates `x0` and `x1`, maximum number of iterations, and a tolerance goal. Also supports a boolean `verbose` keyword argument that prints a table of iterations.

### Usage:
```py
f = lambda x: x * np.e ** (-x)
tol = 0.00001
max_iter = 1000

secant(f, -1, 1, tol, max_iter, verbose=verbose)
# returns 9.439212009812676e-10
```

### Implementation:
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