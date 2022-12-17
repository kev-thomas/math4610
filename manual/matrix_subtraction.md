## Matrix Addition

### Function name: `subtract_matrix`
### Language: python3
### Author: Kevin Thomas

### Description:
Subtracts matrix `m2` from matrix `m1` and returns the resulting matrix.

### Usage:

```py
m1 = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
m2 = [[1, 0, 0],
     [0, 1, 0],
     [0, 0, 1]]
subtract_matrix(m1, m2)
# returns [[0, 2, 3],
#          [4, 4, 6],
#          [7, 8, 8]]
```

### Implementation:
```py
def subtract_matrix(m1, m2):
    return [subtract_vector(m1[i], m2[i]) for i in range(len(m1))]
```