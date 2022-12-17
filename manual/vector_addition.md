## Vector Addition

### Function name: `add_vector`
### Language: python3
### Author: Kevin Thomas

### Description:
Returns the sum of vectors `v1` and `v2`.


### Usage:

```py
v1 = [0, 1]
v2 = [2, 4]
add_vector(v1, v2)
# returns [2, 5]
```

### Implementation:
```py
def add_vector(v1, v2):
    return [v1[i] + v2[i] for i in range(len(v1))]
```