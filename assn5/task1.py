import numpy as np
import matplotlib.pyplot as plt

from find_root import newton

def implicit_euler(a, b, p0, n=100, h=1):

    fp = lambda p: 1 - a * h + 2 * h * b * p
    
    p_vals = np.zeros((n), dtype=float)
    p_vals[0] = p0
    for i in range(1, n):
        f = lambda p: p - p_vals[i-1] - h * (a * p - b * p * p)
        p_vals[i] = newton(f, fp, p_vals[i-1], 0.0001, 100)

    return zip(*[[i*h, p_vals[i]] for i in range(n)])


# driver code
if __name__ == "__main__":
    tests = [
        {'num': 1, 'a': 0.2},
        {'num': 2, 'a': 0.01},
        {'num': 3, 'a': 2.0}
    ]
    for test in tests:
        x, y = implicit_euler(test['a'], 0.0005, 10)
        plt.title(f'Test {test["num"]}')
        plt.xlabel('t')
        plt.ylabel('P(t)')
        plt.plot(x, y)
        plt.savefig(f"./task1/test{test['num']}.png")
        plt.clf()