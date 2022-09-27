# Author: Kevin Thomas

import sys
import numpy as np


def newton(f, fp, x0, tol, max_iter, verbose: bool = False) -> float:
    """
    Find root of f(x) using Newton's method.
    x1 = x0 - f(x0)/f'(x0)
    """
    # iterate
    for i in range(max_iter):
        error = f(x0) / fp(x0)
        # exit if we hit tolerance
        if abs(error) <= tol:
            break
        x = x0 - error
        # print table
        if verbose:
            print('iteration %-5i |  approximation: %-15.5E  |  error: %-10.5E' % (i+1, x, error))
        x0 = x

    return x


def newton_hybrid(f, fp, a, b, tol, max_iter, verbose: bool = False) -> float:
    """
    Find root of f(x) using a combination of newton's method and the bisection algorithm.
    x1 = x0 - f(x0)/f'(x0)
    """
    # set initial guess
    x0 = (a + b) / 2
    # iterate
    for i in range(max_iter):
        error = f(x0) / fp(x0)
        x = x0 - error
        # exit if we hit tolerance
        if abs(error) <= tol:
            break
        # use bisection
        if x > error:
            c = (a + b) / 2
            if f(a) * f(c) < 0:
                b = c
            else:
                a = c
        # print table
        if verbose:
            print('iteration %-5i |  approximation: %-15.5E  |  error: %-10.5E' % (i+1, x, error))
        x0 = x

    return x


def secant(f, x0, x1, tol, max_iter, verbose: bool = False) -> float:
    """
    Find root of f(x) using secant method.
    """
    # iterate
    for i in range(max_iter):
        # exit if we hit tolerance
        if abs(f(x1)) <= tol:
            break
        # calculate x
        x = x1 - f(x1) * (x1 - x0) / f(x1) - f(x0)
        # print table
        if verbose:
            print('iteration %-5i |  approximation: %-15.5E  |  error: %-10.5E' % (i+1, x, f(x1)))
        x0 = x1
        x1 = x

    return x


def secant_hybrid(f, x0, x1, tol, max_iter, verbose: bool = False) -> float:
    """
    Find root of f(x) using secant method.
    """
    # iterate
    for i in range(max_iter):
        # exit if we hit tolerance
        if abs(f(x1)) <= tol:
            break
        # calculate x
        x = x1 - f(x1) * (x1 - x0) / f(x1) - f(x0)
        # use bisection
        if abs(x) > abs(f(x1)):
            a = x0
            b = x1
            c = (a + b) / 2
            if f(a) * f(c) < 0:
                b = c
            else:
                a = c
            x0 = x1
            x1 = (a + b) / 2
        else:
            x0 = x1
            x1 = x

        # print table
        if verbose:
            print('iteration %-5i |  approximation: %-15.5E  |  error: %-10.5E' % (i+1, x, f(x1)))

    return x


if __name__ == '__main__':
    # tasks 1 and 2
    f = lambda x: x * np.e ** (-x)
    fp = lambda x: (np.e ** (-x)) - (x * np.e ** (-x))
    tol = 0.00001
    max_iter = 1000
    verbose = ('-v' or '--verbose') in sys.argv

    # print(newton(f, fp, -2, tol, max_iter, verbose=verbose))
    # print(secant(f, -1, 1, tol, max_iter, verbose=verbose))

    # tasks 4 and 5
    # f = lambda x: 10.14 * (np.e ** (-x ** 2)) * np.cos(np.pi / x)
    # fp = lambda x: ((1014 * np.cos(np.pi/x) * (x ** 3)) + ( 507 * np.pi * np.sin(np.pi/x) * (np.e ** (x ** 2)))) / (50 * (x ** 2))
    # tol = 0.0000000001
    
    # print(newton_hybrid(f, fp, -3, -1, tol, max_iter, verbose=verbose))
    print(secant_hybrid(f, -3, -1, tol, max_iter, verbose=verbose))