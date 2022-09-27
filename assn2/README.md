# Assignment #2

*Note: all code for this assignment is located in `find_root.py`*

## Task 1

### Code:

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
        x0 = x

    return x
```
### Input:
```py
f = lambda x: x * np.e ** (-x)
fp = lambda x: (np.e ** (-x)) - (x * np.e ** (-x))
tol = 0.00001
max_iter = 1000
print(newton(f, fp, -2, tol, max_iter))
```

### Output:

```shell
% python3 find_root.py
9.439212009812676e-10
```

## Task 2

### Code:

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
        
        x0 = x1
        x1 = x

    return x
```
### Input:
```py
f = lambda x: x * np.e ** (-x)
tol = 0.00001
max_iter = 1000
print(secant(f, -1, 1, tol, max_iter))
```

### Output:

```shell
% python3 find_root.py
-1.425500682806244e-09
```

## Task 3

### Code:

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
### Input:
```py
f = lambda x: x * np.e ** (-x)
fp = lambda x: (np.e ** (-x)) - (x * np.e ** (-x))
tol = 0.00001
max_iter = 1000
verbose = ('-v' or '--verbose') in sys.argv
print(newton(f, fp, -2, tol, max_iter, verbose=verbose))
```

### Output:

```shell
% python3 find_root.py -v
iteration 1     |  approximation: -1.33333E+00     |  error: -6.66667E-01
iteration 2     |  approximation: -7.61905E-01     |  error: -5.71429E-01
iteration 3     |  approximation: -3.29472E-01     |  error: -4.32432E-01
iteration 4     |  approximation: -8.16505E-02     |  error: -2.47822E-01
iteration 5     |  approximation: -6.16354E-03     |  error: -7.54869E-02
iteration 6     |  approximation: -3.77565E-05     |  error: -6.12578E-03
iteration 7     |  approximation: -1.42550E-09     |  error: -3.77551E-05
-1.425500682806244e-09
```

## Task 4

### Code:

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
### Input:
```py
f = lambda x: 10.14 * (np.e ** (-x ** 2)) * np.cos(np.pi / x)
fp = lambda x: ((1014 * np.cos(np.pi/x) * (x ** 3)) + ( 507 * np.pi * np.sin(np.pi/x) * (np.e ** (x ** 2)))) / (50 * (x ** 2))
tol = 0.0000000001
max_iter = 1000
verbose = ('-v' or '--verbose') in sys.argv
print(newton_hybrid(f, fp, -3, -1, tol, max_iter, verbose=verbose))
```

### Output:

```shell
% python3 find_root.py
-2.0
```

## Task 5

### Code:

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

### Input:

```py
f = lambda x: x * np.e ** (-x)
fp = lambda x: (np.e ** (-x)) - (x * np.e ** (-x))
tol = 0.00001
max_iter = 1000
print(secant_hybrid(f, -3, -1, tol, max_iter, verbose=verbose))
```

### Output:

```shell
% python3 find_root.py
-1.7314476999095092
```
