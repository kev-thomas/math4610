## Fixed Point Iteration

### Function name: `fixed_point`
### Language: python3
### Author: Kevin Thomas

### Description:
Python function that uses fixed point iteration to find the root of a function.

### Usage:

```py
f = lambda x: x * (np.e ** (-x))
x0 = 3
tol = 0.0000001
max_iter = 1000

fixed_point(f, x0, tol, max_iter)

# returns 1.3697495288568338e-13
```

### Implementation:
```py
def fixed_point(f, x0, tol, max_iter) -> float:
    # actual root value for calculating error
    root = 0
    # fixed point functions
    g1 = lambda x: x - f(x)
    g2 = lambda x: x + f(x)
    error = lambda x: abs(x - root)
    
    i = 0
    while error(x0) > tol and i < max_iter:
        x1 = g1(x0)
        x2 = g2(x0)
        
        x0 = x1 if error(x1) < error(x2) else x2
        i +=1

    return x0
```