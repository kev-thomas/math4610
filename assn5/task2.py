import numpy as np
def analytic_euler(a, b, p, n=100, h=1.0):
    vals = [[i*h, a / ((a / p - b) * np.e ** (-a * i*h) + b)] for i in range(n)]
    return zip(*vals)