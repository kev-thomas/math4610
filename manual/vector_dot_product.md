## Vector Dot Product

### Function name: `dot_vector`
### Language: python3
### Author: Kevin Thomas

### Description:
Returns the dot product of vectors `v1` and `v2`.

### Usage:

```py
v1 = [1, 1, 1]
v2 = [1, 1, 1]
dot_vector(v1, v2)
# returns 3
```

### Implementation:
```py
def dot_vector(v1, v2):
    v = [v1[i] * v2[i] for i in range(len(v1))]
    return sum(v)
```