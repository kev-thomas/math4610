# Newton's root finding method

**Routine name:** `newton`
**Author:** Kevin Thomas
**Language:** Python

**Description:** Approximates the root of a function given the function, its first derivative, an initial estimate, maximum number of iterations, and a tolerance goal.

## Usage:
The routine supports a boolean `verbose` keyword argument that prints a table of iterations.

Input:
```py
f = lambda x: x * np.e ** (-x)
fp = lambda x: (np.e ** (-x)) - (x * np.e ** (-x))
tol = 0.00001
max_iter = 1000

newton(f, fp, -2, tol, max_iter, verbose=True)
```

Output:
```py
iteration 1     |  approximation: -1.33333E+00     |  error: -6.66667E-01
iteration 2     |  approximation: -7.61905E-01     |  error: -5.71429E-01
iteration 3     |  approximation: -3.29472E-01     |  error: -4.32432E-01
iteration 4     |  approximation: -8.16505E-02     |  error: -2.47822E-01
iteration 5     |  approximation: -6.16354E-03     |  error: -7.54869E-02
iteration 6     |  approximation: -3.77565E-05     |  error: -6.12578E-03
iteration 7     |  approximation: -1.42550E-09     |  error: -3.77551E-05
# returns -1.425500682806244e-09
```

## Implementation:
```py
def newton(f, fp, x0, tol, max_iter, verbose: bool = False) -> float:
    """
    Find root of f(x) using Newton's method.
    x1 = x0 - f(x0)/f'(x0)
    """
    # iterate
    for i in range(max_iter):
        error = f(x0) / fp(x0)
        # exit if we hit tolerance
        if abs(error) <= tol:
            break
        x = x0 - error
        # print table
        if verbose:
            print('iteration %-5i |  approximation: %-15.5E  |  error: %-10.5E' % (i+1, x, error))
        x0 = x

    return x
```