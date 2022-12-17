## Vector Dot Product

### Function name: `triple_vector`
### Language: python3
### Author: Kevin Thomas

### Description:
Returns the triple product of vectors `v1`, `v2` and `v3`. More specifically, returns the dot product of `v3` and the cross product of `v1` and `v2`.

### Usage:

```py
v1 = [1, 1, 1]
v2 = [1, 1, 1]
v3 = [1, 2, 3]
dot_vector(v1, v2, v3)
# returns 0
```

### Implementation:
```py
def triple_vector(v1, v2, v3):
    return dot_vector(cross_vector(v1, v2), v3)
```