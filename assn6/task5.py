from math import sqrt
import numpy as np

def add_vector(v1, v2):
    return [v1[i] + v2[i] for i in range(len(v1))]


def subtract_vector(v1, v2):
    return [v1[i] - v2[i] for i in range(len(v1))]


def mult_s_vector(v, s):
    return [v[i] * s for i in range(len(v))]


def l1_vector(v):
    l = [abs(v[i]) for i in range(len(v))]
    return sum(l)


def l2_vector(v):
    l = [v[i] * v[i] for i in range(len(v))]
    return sqrt(sum(l))


def inf_vector(v):
    l = [abs(v[i]) for i in range(len(v))]
    return max(l)


def dot_vector(v1, v2):
    v = [v1[i] * v2[i] for i in range(len(v1))]
    return sum(v)


def cross_vector(v1, v2):
    a = v1[1] * v2[2] - v1[2] * v2[1]
    b = v1[2] * v2[0] - v1[0] * v2[2]
    c = v1[0] * v2[1] - v1[1] * v2[0]
    return [a, b, c]


def triple_vector(v1, v2, v3):
    return dot_vector(cross_vector(v1, v2), v3)


def action_matrix(m, v):
    return [dot_vector(m[i], v) for i in range(len(m))]


def add_matrix(m1, m2):
    return [add_vector(m1[i], m2[i]) for i in range(len(m1))]


def subtract_matrix(m1, m2):
    return [subtract_vector(m1[i], m2[i]) for i in range(len(m1))]


def mult_matrix(m1, m2):
    r = np.zeros((len(m1), len(m2[0])))

    for i in range(len(m1)):
        for j in range(len(m2[0])):
            for k in range(len(m2)):
                r[i][j] += m1[i][k] * m2[k][j]
    return r


# driver code for testing
if __name__ == '__main__':
    print('Testing functions...')
    print(f'add_vector([1, 1, 1], [1, 1, 1]) = {add_vector([1, 1, 1], [1, 1, 1])}')
    print(f'subtract_vector([1, 1, 1], [1, 1, 1]) = {subtract_vector([1, 1, 1], [1, 1, 1])}')
    print(f'mult_s_vector([1, 1, 1], 2) = {mult_s_vector([1, 1, 1], 2)}')
    print(f'l1_vector([1, 2, 3]) = {l1_vector([1, 2, 3])}')
    print(f'l2_vector([1, 2, 3]) = {l2_vector([1, 2, 3])}')
    print(f'inf_vector([1, 2, 3]) = {inf_vector([1, 2, 3])}')
    print(f'dot_vector([1, 1, 1], [1, 1, 1]) = {dot_vector([1, 1, 1], [1, 1, 1])}')
    print(f'cross_vector([1, 1, 1], [1, 1, 1]) = {cross_vector([1, 1, 1], [1, 1, 1])}')
    print(f'triple_vector([1, 1, 1], [1, 1, 1], [1, 2, 3]) = {triple_vector([1, 1, 1], [1, 1, 1], [1, 2, 3])}')

    m1 = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

    m2 = [[1, 0, 0],
          [0, 1, 0],
          [0, 0, 1]]

    print(f'm1 = {m1}')
    print(f'm2 = {m2}')
    print(f'action_matrix(m1, [1, 2, 3]) = {action_matrix(m1, [1, 2, 3])}')
    print(f'add_matrix(m1, m2) = {add_matrix(m1, m2)}')
    print(f'subtract_matrix(m1, m2) = {subtract_matrix(m1, m2)}')
    print(f'mult_matrix(m1, m2) = {mult_matrix(m1, m2)}')