## Bisection Method

### Function name: `bisection`
### Language: python3
### Author: Kevin Thomas

### Description:
Solves the root finding problem using the bisection algorithm; Given a function, range [a, b], and tolerance, finds
the root within [a, b] and within the specified tolerance. Additionally supports a verbose boolean parameter (default value is False).

### Usage:

```py
f = lambda x: 10.14 * (np.e ** (-x ** 2)) * np.cos(np.pi / x)
a = -3
b = 7
tol = 0.0000001

print(find_root(f, a, b, tol, verbose=True))
```

Output:
```shell
iteration 1     |  approximation: 2.00000E+00      |  error: 2.50000E+00
iteration 2     |  approximation: -5.00000E-01     |  error: 1.25000E+00
iteration 3     |  approximation: 7.50000E-01      |  error: 6.25000E-01
iteration 4     |  approximation: 1.25000E-01      |  error: 3.12500E-01
iteration 5     |  approximation: -1.87500E-01     |  error: 1.56250E-01
iteration 6     |  approximation: -3.12500E-02     |  error: 7.81250E-02
iteration 7     |  approximation: 4.68750E-02      |  error: 3.90625E-02
iteration 8     |  approximation: 7.81250E-03      |  error: 1.95312E-02
iteration 9     |  approximation: -1.17188E-02     |  error: 9.76562E-03
iteration 10    |  approximation: -1.95312E-03     |  error: 4.88281E-03
iteration 11    |  approximation: 2.92969E-03      |  error: 2.44141E-03
iteration 12    |  approximation: 4.88281E-04      |  error: 1.22070E-03
0.00048828125
```

### Implementation:
```py
def bisection(f, a, b, tol, verbose: bool = False) -> float:
    # max iterations calculated tolerance
    max_iter = -((np.log(tol) / np.log(b - a)) / np.log(2)) + 1
    # error function
    error = lambda: (b - a) / 2
    
    i = 0
    while i < max_iter:
        x = (a + b) / 2

        if f(x) == 0 or error() < tol:
            return x

        # assumes a is negative and b is positive
        if x < 0:
            a = x
        else:
            b = x

        i +=1

        if verbose:
            print('iteration %-5i |  approximation: %-15.5E  |  error: %-10.5E' % (i, x, error()))

    return x
```