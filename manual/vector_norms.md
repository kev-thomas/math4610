## Vector Norms

### Function name: `l1_vector`
### Language: python3
### Author: Kevin Thomas

### Description:
Returns the L1 norm of vector `v`.


### Usage:

```py
v = [1, 2, 3]
l1_vector(v)
# returns 6
```

### Implementation:
```py
def l1_vector(v):
    l = [abs(v[i]) for i in range(len(v))]
    return sum(l)
```

### Function name: `l2_vector`

### Description:
Returns the L2 norm of vector `v`.


### Usage:

```py
v = [1, 2, 3]
l2_vector(v)
# returns 3.7416573867739413
```

### Implementation:
```py
def l2_vector(v):
    l = [v[i] * v[i] for i in range(len(v))]
    return sqrt(sum(l))
```

### Function name: `inf_vector`

### Description:
Returns the infinity norm of vector `v`.


### Usage:

```py
v = [1, 2, 3]
inf_vector(v)
# returns 3
```

### Implementation:
```py
def inf_vector(v):
    l = [abs(v[i]) for i in range(len(v))]
    return max(l)
```