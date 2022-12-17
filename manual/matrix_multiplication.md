## Matrix Multiplication

### Function name: `mult_matrix`
### Language: python3
### Author: Kevin Thomas

### Description:
Multiplies matrices `m1` and `m2` and returns the resulting matrix.

### Usage:

```py
m1 = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
m2 = [[1, 0, 0],
     [0, 1, 0],
     [0, 0, 1]]
mult_matrix(m1, m2)
# returns [[1, 2, 3],
#          [4, 5, 6],
#          [7, 8, 9]]
```

### Implementation:
```py
def mult_matrix(m1, m2):
    r = np.zeros((len(m1), len(m2[0])))

    for i in range(len(m1)):
        for j in range(len(m2[0])):
            for k in range(len(m2)):
                r[i][j] += m1[i][k] * m2[k][j]
    return r
```