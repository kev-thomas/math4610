## Second Derivative Approximation

### Function name: `est_second_derivative`
### Language: python3
### Author: Kevin Thomas

### Description:
Estimates the second derivative of a function `f` at point `x0` using an initial increment `h`.


### Usage:

```py
f = lambda x: ((x - (np.pi / 2)) * np.tan(x) ** 2) / (x ** 2 + 65)
x0 = np.pi / 4
h = 0.0001
est_second_derivative(f, x0, h)
# returns 6.46958531938871e-06
```

### Implementation:
```py
def est_second_derivative(f, x0, h):
    """
    Estimates the second derivative of function f at 
    point x0 using initial increment h.
    """
    return (f(x0 - h) - 2 * f(x0) + f(x0 - h))
```