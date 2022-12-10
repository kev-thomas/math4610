import numpy as np
import matplotlib.pyplot as plt


def simpson(f, a, b, n):
    h = (b - a) / n
    x = a
    result = 0

    for i in range(n):
        x2 = x + h/2
        x3 = x + h
        result += f(x) + 4 * f(x2) + f(x3)
        x += h

    return result * h / 6


# driver code
if __name__ == "__main__":
    f = lambda x: np.e ** -(x*x)
    n = lambda a, b, h: int((b - a) / h)
    h = 1/2
    error = lambda x: abs(x - 0.6498803300786573037276521829129935239240253152760926685227030955)

    results = []
    errors = []
    h_vals = []

    for i in range(10):
        result = simpson(f, 0, np.pi/4, n(0, np.pi/4, h))
        print(f"n: {n(0, np.pi/4, h)}  h: {h}  result: {result}")

        results.append(result)
        errors.append(error(result))
        h_vals.append(h)
        h /= 2

    plt.xlabel('h')
    plt.ylabel('error')
    plt.xscale('log')
    plt.yscale('log')
    plt.plot(h_vals, errors)
    
    plt.savefig('./task5.png')
