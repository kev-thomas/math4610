## Matrix Addition

### Function name: `add_matrix`
### Language: python3
### Author: Kevin Thomas

### Description:
Adds matrices `m1` and `m2` and returns the resulting matrix.

### Usage:

```py
m1 = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
m2 = [[1, 0, 0],
     [0, 1, 0],
     [0, 0, 1]]
add_matrix(m1, m2)
# returns [[2, 2, 3],
#          [4, 6, 6],
#          [7, 8, 10]]
```

### Implementation:
```py
def add_matrix(m1, m2):
    return [add_vector(m1[i], m2[i]) for i in range(len(m1))]
```