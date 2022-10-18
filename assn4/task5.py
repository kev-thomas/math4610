import numpy as np


def explicit_euler(a, b, p0):
    """
    use explicit euler method on equation
    dP/dt = aP - BP^2
    """
    f = lambda p: (a * p) - b * (p ** 2)
    h = lambda t: (50 - t) / 50
    t0 = 0

    s = []

    for i in range(1, 50):
        t = t0 + h(t0)
        p = p0 + h(t0) * f(p0)

        s.append(p)

        p0 = p
        t0 = t
    
    return s


if __name__ == '__main__':
    b = 0.0005
    p0 = 10.0

    print("Test 1")    
    a = 0.2
    print(explicit_euler(a, b, p0))
    print()

    print("Test 2") 
    a = 0.01
    print(explicit_euler(a, b, p0))
    print()

    print("Test 3")
    a = 2.0
    print(explicit_euler(a, b, p0))