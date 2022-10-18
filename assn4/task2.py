import numpy as np


def est_second_derivative(f, x0, h):
    """
    Estimates the second derivative of function f at 
    point x0 using initial increment h.
    """
    return (f(x0 - h) - 2 * f(x0) + f(x0 - h))


if __name__ == '__main__':
    f = lambda x: ((x - (np.pi / 2)) * np.tan(x) ** 2) / (x ** 2 + 65)
    x0 = np.pi / 4
    h = 0.1
    for i in range(5):
        print(f'h: {h}  approximation: {est_second_derivative(f, x0, h)}')
        h *= h