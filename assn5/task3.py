import matplotlib.pyplot as plt

from task1 import implicit_euler
from task2 import analytic_euler

if __name__ == "__main__":
    tests = [
        {'num': 1, 'a': 0.2},
        {'num': 2, 'a': 0.01},
        {'num': 3, 'a': 2.0}
    ]
    for test in tests:
        x1, y1 = implicit_euler(test['a'], 0.0005, 10)
        x2, y2 = analytic_euler(test['a'], 0.0005, 10)

        plt.title(f'Test {test["num"]}')
        plt.xlabel('t')
        plt.ylabel('P(t)')
        plt.plot(x1, y1, 'blue', label='Implicit')
        plt.plot(x2, y2, 'orange', label='Analytic')
        plt.savefig(f"./task3/test{test['num']}.png")
        plt.clf()