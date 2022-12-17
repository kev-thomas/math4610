## Matrix Vector Action

### Function name: `action_matrix`
### Language: python3
### Author: Kevin Thomas

### Description:
Returns the result of matrix `m` action on vector `v`.

### Usage:

```py
m = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
v = [1, 2, 3]
action_matrix(m, v)
# returns [14, 32, 50]
```

### Implementation:
```py
def action_matrix(m, v):
    return [dot_vector(m[i], v) for i in range(len(m))]
```