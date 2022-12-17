## Vector Scalar Multiplication

### Function name: `mult_s_vector`
### Language: python3
### Author: Kevin Thomas

### Description:
Returns the result of multiplying vector `v` by scalar `s`.


### Usage:

```py
v = [2, 3]
s = 13
mult_s_vector(v, s)
# returns [26, 39]
```

### Implementation:
```py
def mult_s_vector(v, s):
    return [v[i] * s for i in range(len(v))]
```