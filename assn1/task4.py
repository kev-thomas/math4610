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


if __name__ == '__main__':
    f = lambda x: 10.14 * (np.e ** (-x ** 2)) * np.cos(np.pi / x)
    a = -3
    b = 7
    tol = 0.0000001
    verbose = ('-v' or '--verbose') in sys.argv

    print(find_root(f, a, b, tol, verbose=verbose))

    f2 = lambda x: x * (np.e ** (-x))
    print(find_root(f2, -12, 15, tol, verbose=verbose))