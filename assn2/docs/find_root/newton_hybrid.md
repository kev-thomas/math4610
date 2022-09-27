# Newton's / Bisection hybrid root finding method

**Routine name:** `newton_hybrid`
**Author:** Kevin Thomas
**Language:** Python

**Description:** Approximates the root of a function given the function, its derivative, upper and lower bounds, maximum number of iterations, and a tolerance goal. Uses the bisection method within Newton's method.

## Usage:
The routine supports a boolean `verbose` keyword argument that prints a table of iterations.

Input:
```py
f = lambda x: x * np.e ** (-x)
fp = lambda x: (np.e ** (-x)) - (x * np.e ** (-x))
tol = 0.00001
max_iter = 1000

newton_hybrid(f, fp, -3, -1, tol, max_iter, verbose=verbose)
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
# returns -2.032052099592921e-18
```

## Implementation:
```py
def newton_hybrid(f, fp, a, b, tol, max_iter, verbose: bool = False) -> float:
    """
    Find root of f(x) using a combination of newton's method and the bisection algorithm.
    x1 = x0 - f(x0)/f'(x0)
    """
    # set initial guess
    x0 = (a + b) / 2
    # iterate
    for i in range(max_iter):
        error = f(x0) / fp(x0)
        x = x0 - error
        # exit if we hit tolerance
        if abs(error) <= tol:
            break
        # use bisection
        if x > error:
            c = (a + b) / 2
            if f(a) * f(c) < 0:
                b = c
            else:
                a = c
        # print table
        if verbose:
            print('iteration %-5i |  approximation: %-15.5E  |  error: %-10.5E' % (i+1, x, error))
        x0 = x

    return x
```