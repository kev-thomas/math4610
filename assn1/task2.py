# find root of of number using fixed point problem
# Functional iteration:
# g(x) = x - f(x) -> g(x*) = x* - f(x*) = x* - 0 = x*
# Absolute error in approximation: e_k = |x_k - x*|, k=1,2,...
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


if __name__ == '__main__':
    f = lambda x: x * (np.e ** (-x))
    x0 = 3
    tol = 0.0000001
    max_iter = 1000
    verbose = ('-v' or '--verbose') in sys.argv

    print(find_root(f, x0, tol, max_iter, verbose=verbose))