import numpy as np


def trapezoid(f, a, b, n=100):
    h = (b - a) / n
    result = (f(a) + f(b)) / 2

    for i in range(1, n):
        sub = i * h + a
        result += f(sub)
    
    return result * h


# driver code
if __name__ == "__main__":
    n = 2
    f = lambda x: np.e ** -(x*x)

    for i in range(4):
        result = trapezoid(f, 0, np.pi/4, n)
        print(f"n: {n}  result: {result}")
        n *= 2
