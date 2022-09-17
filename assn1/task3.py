import sys
import numpy as np
from task2 import find_root

if __name__ == '__main__':
    f = lambda x: x * (np.e ** (-x))
    tol = 0.0000001
    max_iter = 10
    verbose = ('-v' or '--verbose') in sys.argv

    for i in range(-3, 7):
        print(find_root(f, i, tol, max_iter, verbose=verbose))