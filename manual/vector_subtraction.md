## Vector Addition

### Function name: `subtract_vector`
### Language: python3
### Author: Kevin Thomas

### Description:
Returns the difference of vectors `v1` and `v2`.


### Usage:

```py
v1 = [2, 5]
v2 = [2, 4]
subtract_vector(v1, v2)
# returns [0, 1]
```

### Implementation:
```py
def subtract_vector(v1, v2):
    return [v1[i] - v2[i] for i in range(len(v1))]
```