## Vector Cross Product

### Function name: `cross_vector`
### Language: python3
### Author: Kevin Thomas

### Description:
Returns the cross product of vectors `v1` and `v2`.

### Usage:

```py
v1 = [1, 1, 1]
v2 = [1, 1, 1]
cross_vector(v1, v2)
# returns 0
```

### Implementation:
```py
def cross_vector(v1, v2):
    a = v1[1] * v2[2] - v1[2] * v2[1]
    b = v1[2] * v2[0] - v1[0] * v2[2]
    c = v1[0] * v2[1] - v1[1] * v2[0]
    return [a, b, c]
```