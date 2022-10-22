# Assignment #1

## Task 1

For this task, I wrote the `find_root` function in python which uses the fixed point
algorithm to find the root of a function.

### Code (`task1.py`):

#### `find_root` method:
```py
import numpy as np


def find_root(f, x0, tol, max_iter) -> float:
    # actual root value for calculating error
    root = 0
    # fixed point functions
    g1 = lambda x: x - f(x)
    g2 = lambda x: x + f(x)
    error = lambda x: abs(x - root)
    
    i = 0
    while error(x0) > tol and i < max_iter:
        x1 = g1(x0)
        x2 = g2(x0)
        
        x0 = x1 if error(x1) < error(x2) else x2
        i +=1

    return x0

```

#### driver code:
I used the following driver code in the same file so that i could easily run the python module from the command line and test my code with the function f(x) = xe^(-x)

```py
if __name__ == '__main__':
    f = lambda x: x * (np.e ** (-x))
    x0 = 3
    tol = 0.0000001
    max_iter = 1000

    print(find_root(f, x0, tol, max_iter))
```

### Output:

With the driver code, I ran the python module in the command line as shown below:

```shell
% python3 task1.py
1.3697495288568338e-13
```

The returned result is close to 0, which indicates that we're on the right track to being able to find the root using the fixed point method.


## Task 2

For this task, I modified my original function to output a table when you pass `verbose=True` to the function (the verbose parameter is false by default).

### Code (`task2.py`):

#### `find_root` method:
```py
import sys
import numpy as np


def find_root(f, x0, tol, max_iter, verbose: bool = False) -> float:
    # actual root value for calculating error
    root = 0
    # fixed point functions
    g1 = lambda x: x - f(x)
    g2 = lambda x: x + f(x)
    error = lambda x: abs(x - root)
    
    i = 0
    while error(x0) > tol and i < max_iter:
        x1 = g1(x0)
        x2 = g2(x0)

        x0 = x1 if error(x1) < error(x2) else x2
        i +=1

        if verbose:
            print('iteration %-5i |  approximation: %-5.10E  |  error: %-5.10E' % (i, x0, error(x0)))

    return x0

```

#### driver code:
I modified the driver code in the file to check for a verbose flag from the command line so it can pass true or false to the `find_root` method.

```py
if __name__ == '__main__':
    f = lambda x: x * (np.e ** (-x))
    x0 = 3
    tol = 0.0000001
    max_iter = 1000
    verbose = ('-v' or '--verbose') in sys.argv

    print(find_root(f, x0, tol, max_iter, verbose=verbose))
```

### Output:

Using the updated code, I was able to pass the verbose flag in the command line as shown below to receive the following output. The table indicates the current approximation, as well as the error for that iteration.

```shell
% python3 task2.py -v
iteration 1     |  approximation: 2.8506387949E+00  |  error: 2.8506387949E+00
iteration 2     |  approximation: 2.6858508291E+00  |  error: 2.6858508291E+00
iteration 3     |  approximation: 2.5027747114E+00  |  error: 2.5027747114E+00
iteration 4     |  approximation: 2.2979037000E+00  |  error: 2.2979037000E+00
iteration 5     |  approximation: 2.0670350690E+00  |  error: 2.0670350690E+00
iteration 6     |  approximation: 1.8054301412E+00  |  error: 1.8054301412E+00
iteration 7     |  approximation: 1.5086107016E+00  |  error: 1.5086107016E+00
iteration 8     |  approximation: 1.1748802154E+00  |  error: 1.1748802154E+00
iteration 9     |  approximation: 8.1201144257E-01  |  error: 8.1201144257E-01
iteration 10    |  approximation: 4.5150746529E-01  |  error: 4.5150746529E-01
iteration 11    |  approximation: 1.6404725782E-01  |  error: 1.6404725782E-01
iteration 12    |  approximation: 2.4820036266E-02  |  error: 2.4820036266E-02
iteration 13    |  approximation: 6.0845206379E-04  |  error: 6.0845206379E-04
iteration 14    |  approximation: 3.7010130807E-07  |  error: 3.7010130807E-07
iteration 15    |  approximation: 1.3697495289E-13  |  error: 1.3697495289E-13
1.3697495288568338e-13
```

From the output we can see that the function is converging towards our root.


## Task 3

For this task, I modified the code from task 2 to test the fixed point root finding method on points in the range [-3, 7]. 

### Modified driver code:

I used the same `if __name__ == '__main__'` statement so that i could run the the file directly from the command line. The code in this block only executes if that's the main file, so I can avoid copying and pasting the code from task 2 and just import it.

```py
from task2 import find_root

if __name__ == '__main__':
    f = lambda x: x * (np.e ** (-x))
    tol = 0.0000001
    max_iter = 10
    verbose = ('-v' or '--verbose') in sys.argv

    for i in range(-3, 7):
        print(find_root(f, i, tol, max_iter, verbose=verbose))
```

### Output:
From our output we can see that for greater starting values, the root begins to diverge, which isn't ideal at all. 
```shell
% python3 task3.py -v
iteration 1     |  approximation: 5.7256610770E+01  |  error: 5.7256610770E+01
iteration 2     |  approximation: 5.7256610770E+01  |  error: 5.7256610770E+01
iteration 3     |  approximation: 5.7256610770E+01  |  error: 5.7256610770E+01
iteration 4     |  approximation: 5.7256610770E+01  |  error: 5.7256610770E+01
iteration 5     |  approximation: 5.7256610770E+01  |  error: 5.7256610770E+01
iteration 6     |  approximation: 5.7256610770E+01  |  error: 5.7256610770E+01
iteration 7     |  approximation: 5.7256610770E+01  |  error: 5.7256610770E+01
iteration 8     |  approximation: 5.7256610770E+01  |  error: 5.7256610770E+01
iteration 9     |  approximation: 5.7256610770E+01  |  error: 5.7256610770E+01
iteration 10    |  approximation: 5.7256610770E+01  |  error: 5.7256610770E+01
57.256610769563
iteration 1     |  approximation: 1.2778112198E+01  |  error: 1.2778112198E+01
iteration 2     |  approximation: 1.2778076140E+01  |  error: 1.2778076140E+01
iteration 3     |  approximation: 1.2778040080E+01  |  error: 1.2778040080E+01
iteration 4     |  approximation: 1.2778004020E+01  |  error: 1.2778004020E+01
iteration 5     |  approximation: 1.2777967958E+01  |  error: 1.2777967958E+01
iteration 6     |  approximation: 1.2777931895E+01  |  error: 1.2777931895E+01
iteration 7     |  approximation: 1.2777895831E+01  |  error: 1.2777895831E+01
iteration 8     |  approximation: 1.2777859766E+01  |  error: 1.2777859766E+01
iteration 9     |  approximation: 1.2777823699E+01  |  error: 1.2777823699E+01
iteration 10    |  approximation: 1.2777787632E+01  |  error: 1.2777787632E+01
12.77778763162964
iteration 1     |  approximation: 1.7182818285E+00  |  error: 1.7182818285E+00
iteration 2     |  approximation: 1.4100666085E+00  |  error: 1.4100666085E+00
iteration 3     |  approximation: 1.0658312470E+00  |  error: 1.0658312470E+00
iteration 4     |  approximation: 6.9871481895E-01  |  error: 6.9871481895E-01
iteration 5     |  approximation: 3.5129710044E-01  |  error: 3.5129710044E-01
iteration 6     |  approximation: 1.0406311319E-01  |  error: 1.0406311319E-01
iteration 7     |  approximation: 1.0284721895E-02  |  error: 1.0284721895E-02
iteration 8     |  approximation: 1.0523342860E-04  |  error: 1.0523342860E-04
iteration 9     |  approximation: 1.1073491833E-08  |  error: 1.1073491833E-08
1.107349183332993e-08
0
iteration 1     |  approximation: 6.3212055883E-01  |  error: 6.3212055883E-01
iteration 2     |  approximation: 2.9617148759E-01  |  error: 2.9617148759E-01
iteration 3     |  approximation: 7.5920632112E-02  |  error: 7.5920632112E-02
iteration 4     |  approximation: 5.5505749572E-03  |  error: 5.5505749572E-03
iteration 5     |  approximation: 3.0723536828E-05  |  error: 3.0723536828E-05
iteration 6     |  approximation: 9.4392121486E-10  |  error: 9.4392121486E-10
9.439212148590554e-10
iteration 1     |  approximation: 1.7293294335E+00  |  error: 1.7293294335E+00
iteration 2     |  approximation: 1.4225406319E+00  |  error: 1.4225406319E+00
iteration 3     |  approximation: 1.0795651040E+00  |  error: 1.0795651040E+00
iteration 4     |  approximation: 7.1279015079E-01  |  error: 7.1279015079E-01
iteration 5     |  approximation: 3.6332742439E-01  |  error: 3.6332742439E-01
iteration 6     |  approximation: 1.1068453205E-01  |  error: 1.1068453205E-01
iteration 7     |  approximation: 1.1597401528E-02  |  error: 1.1597401528E-02
iteration 8     |  approximation: 1.3372280487E-04  |  error: 1.3372280487E-04
iteration 9     |  approximation: 1.7880592995E-08  |  error: 1.7880592995E-08
1.788059299516649e-08
iteration 1     |  approximation: 2.8506387949E+00  |  error: 2.8506387949E+00
iteration 2     |  approximation: 2.6858508291E+00  |  error: 2.6858508291E+00
iteration 3     |  approximation: 2.5027747114E+00  |  error: 2.5027747114E+00
iteration 4     |  approximation: 2.2979037000E+00  |  error: 2.2979037000E+00
iteration 5     |  approximation: 2.0670350690E+00  |  error: 2.0670350690E+00
iteration 6     |  approximation: 1.8054301412E+00  |  error: 1.8054301412E+00
iteration 7     |  approximation: 1.5086107016E+00  |  error: 1.5086107016E+00
iteration 8     |  approximation: 1.1748802154E+00  |  error: 1.1748802154E+00
iteration 9     |  approximation: 8.1201144257E-01  |  error: 8.1201144257E-01
iteration 10    |  approximation: 4.5150746529E-01  |  error: 4.5150746529E-01
0.4515074652923183
iteration 1     |  approximation: 3.9267374444E+00  |  error: 3.9267374444E+00
iteration 2     |  approximation: 3.8493498299E+00  |  error: 3.8493498299E+00
iteration 3     |  approximation: 3.7673834053E+00  |  error: 3.7673834053E+00
iteration 4     |  approximation: 3.6803099064E+00  |  error: 3.6803099064E+00
iteration 5     |  approximation: 3.5875103058E+00  |  error: 3.5875103058E+00
iteration 6     |  approximation: 3.4882542010E+00  |  error: 3.4882542010E+00
iteration 7     |  approximation: 3.3816734994E+00  |  error: 3.3816734994E+00
iteration 8     |  approximation: 3.2667286452E+00  |  error: 3.2667286452E+00
iteration 9     |  approximation: 3.1421651355E+00  |  error: 3.1421651355E+00
iteration 10    |  approximation: 3.0064575806E+00  |  error: 3.0064575806E+00
3.006457580563127
iteration 1     |  approximation: 4.9663102650E+00  |  error: 4.9663102650E+00
iteration 2     |  approximation: 4.9317009738E+00  |  error: 4.9317009738E+00
iteration 3     |  approximation: 4.8961225900E+00  |  error: 4.8961225900E+00
iteration 4     |  approximation: 4.8595215640E+00  |  error: 4.8595215640E+00
iteration 5     |  approximation: 4.8218398964E+00  |  error: 4.8218398964E+00
iteration 6     |  approximation: 4.7830146406E+00  |  error: 4.7830146406E+00
iteration 7     |  approximation: 4.7429773348E+00  |  error: 4.7429773348E+00
iteration 8     |  approximation: 4.7016533526E+00  |  error: 4.7016533526E+00
iteration 9     |  approximation: 4.6589611562E+00  |  error: 4.6589611562E+00
iteration 10    |  approximation: 4.6148114347E+00  |  error: 4.6148114347E+00
4.614811434737782
iteration 1     |  approximation: 5.9851274869E+00  |  error: 5.9851274869E+00
iteration 2     |  approximation: 5.9700695469E+00  |  error: 5.9700695469E+00
iteration 3     |  approximation: 5.9548216084E+00  |  error: 5.9548216084E+00
iteration 4     |  approximation: 5.9393789313E+00  |  error: 5.9393789313E+00
iteration 5     |  approximation: 5.9237365979E+00  |  error: 5.9237365979E+00
iteration 6     |  approximation: 5.9078895044E+00  |  error: 5.9078895044E+00
iteration 7     |  approximation: 5.8918323511E+00  |  error: 5.8918323511E+00
iteration 8     |  approximation: 5.8755596330E+00  |  error: 5.8755596330E+00
iteration 9     |  approximation: 5.8590656283E+00  |  error: 5.8590656283E+00
iteration 10    |  approximation: 5.8423443879E+00  |  error: 5.8423443879E+00
5.842344387923851

```


## Task 4
For task 4, I developed a root finding method in python that uses the bisection algorithm rather than the fixed point method.

### Code (`task4.py`):

#### `find_root` method:

```py
import sys
import numpy as np


def find_root(f, a, b, tol, verbose: bool = False) -> float:
    # max iterations calculated tolerance
    max_iter = -((np.log(tol) / np.log(b - a)) / np.log(2)) + 1
    # error function
    error = lambda: (b - a) / 2
    
    i = 0
    while i < max_iter:
        x = (a + b) / 2

        if f(x) == 0 or error() < tol:
            return x

        # assumes a is negative and b is positive
        if x < 0:
            a = x
        else:
            b = x

        i +=1

        if verbose:
            print('iteration %-5i |  approximation: %-15.5E  |  error: %-10.5E' % (i, x, error()))

    return x
```

#### Driver code:
We'll continue to use the same if-statement in case we want to import the function above elsewhere later on. We'll also test the method on 2 different equations.

```py
if __name__ == '__main__':
    f = lambda x: 10.14 * (np.e ** (-x ** 2)) * np.cos(np.pi / x)
    a = -3
    b = 7
    tol = 0.0000001
    verbose = ('-v' or '--verbose') in sys.argv

    print(find_root(f, a, b, tol, verbose=verbose))

    f2 = lambda x: x * (np.e ** (-x))
    print(find_root(f2, -12, 15, tol, verbose=verbose))
```

### Output:
Once again I ran the module directly from the command line as shown below, and I got the following results:

```shell
% python3 task4.py -v
iteration 1     |  approximation: 2.00000E+00      |  error: 2.50000E+00
iteration 2     |  approximation: -5.00000E-01     |  error: 1.25000E+00
iteration 3     |  approximation: 7.50000E-01      |  error: 6.25000E-01
iteration 4     |  approximation: 1.25000E-01      |  error: 3.12500E-01
iteration 5     |  approximation: -1.87500E-01     |  error: 1.56250E-01
iteration 6     |  approximation: -3.12500E-02     |  error: 7.81250E-02
iteration 7     |  approximation: 4.68750E-02      |  error: 3.90625E-02
iteration 8     |  approximation: 7.81250E-03      |  error: 1.95312E-02
iteration 9     |  approximation: -1.17188E-02     |  error: 9.76562E-03
iteration 10    |  approximation: -1.95312E-03     |  error: 4.88281E-03
iteration 11    |  approximation: 2.92969E-03      |  error: 2.44141E-03
iteration 12    |  approximation: 4.88281E-04      |  error: 1.22070E-03
0.00048828125
iteration 1     |  approximation: 1.50000E+00      |  error: 6.75000E+00
iteration 2     |  approximation: -5.25000E+00     |  error: 3.37500E+00
iteration 3     |  approximation: -1.87500E+00     |  error: 1.68750E+00
iteration 4     |  approximation: -1.87500E-01     |  error: 8.43750E-01
iteration 5     |  approximation: 6.56250E-01      |  error: 4.21875E-01
iteration 6     |  approximation: 2.34375E-01      |  error: 2.10938E-01
iteration 7     |  approximation: 2.34375E-02      |  error: 1.05469E-01
iteration 8     |  approximation: -8.20312E-02     |  error: 5.27344E-02
iteration 9     |  approximation: -2.92969E-02     |  error: 2.63672E-02
-0.029296875
```
The bisection method worked much quicker than the fixed point method without diverging, which is a good sign.

## Task 5

For task 5, I created a GitHub repository to host my code and track changes. A convenient place to read all of the docs i write, and it lets me switch between my laptop and desktop as needed. You can view the repository at the link below:

[https://github.com/kev-thomas/math4610]