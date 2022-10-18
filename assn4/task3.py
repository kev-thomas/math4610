import numpy as np
from task2 import est_second_derivative

def linear_regression(x: list, y: list):
    """
    takes a list of x and y values and uses least squares method
    to perform linear regression.
    """
    n = len(x)
    m = [[n, 0],
         [0, 0]]
    o = [0, 0]

    for i in range(n):
        m[0][1] += x[i]
        m[1][0] += x[i]
        m[1][1] += x[i] ** 2
        o += y[i]
        o += x[i] * y[i]
    
    det = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0])

    a = (m[1][1] / det) * o[0] + (-m[1][0] / det) * o[1]
    b = (-m[1][0] / det) * o[0] + (m[0][0] / det) * o[1]

    return a, b


if __name__ == '__main__':
    f = lambda x: ((x - (np.pi / 2)) * np.tan(x) ** 2) / (x ** 2 + 65)
    x0 = 1.0
    h = 0.00001
    x = []
    y = []
    for i in range(6):
        x.append(x0)
        y.append(est_second_derivative(f, x0, h))
        print(f'h: {x[i]}  approximation: {y[i]}')
        x0 += 0.1
    a, b = linear_regression(x, y)
    print(f'a: {a}  b: {b}')
