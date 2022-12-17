## Bisection/Newton's Hybrid Method

### Function name: `newton_hybrid`
### Language: python3
### Author: Kevin Thomas

### Description:
Approximates the root of a function given the function, its derivative, upper and lower bounds, maximum number of iterations, and a tolerance goal. Uses the bisection method within Newton's method. Supports a boolean `verbose` keyword argument that prints a table of iterations.


### Usage:

```py
f = lambda x: x * np.e ** (-x)
fp = lambda x: (np.e ** (-x)) - (x * np.e ** (-x))
tol = 0.00001
max_iter = 1000

newton_hybrid(f, fp, -3, -1, tol, max_iter, verbose=verbose)
# returns -2.032052099592921e-18
```

### Implementation:
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