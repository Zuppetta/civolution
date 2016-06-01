import math
import numpy as np
import matplotlib.pyplot as plt

size = 1024

grad3 = np.array([[1, 1, 0], [-1, 1, 0], [1, -1, 0], [-1, -1, 0],
                  [1, 0, 1], [-1, 0, 1], [1, 0, -1], [-1, 0, -1],
                  [0, 1, 1], [0, -1, 1], [0, 1, -1], [0, -1, -1]])

p = np.round(np.random.rand(size)*255)
perm = np.zeros(2*size)
for i in range(2*size):
    perm[i] = p[i & size-1]


def dot(g, x, y):
    return g[0]*x + g[1]*y


def simplex_noise(xin, yin):
    F2 = 0.5*(math.sqrt(3.0)-1.0)
    s = (xin + yin)*F2
    i = math.floor(xin + s)
    j = math.floor(yin + s)

    G2 = (3.0 - math.sqrt(3.0))/6.0
    t = (i+j) * G2
    X0 = i - t
    Y0 = j - t
    x0 = xin - X0
    y0 = yin - Y0

    i1 = x0 > y0
    j1 = y0 > x0

    x1 = x0 - i1 + G2
    y1 = y0 - j1 + G2
    x2 = x0 - 1.0 + 2.0*G2
    y2 = y0 - 1.0 + 2.0*G2

    ii = int(i) & 255
    jj = int(j) & 255
    gi0 = perm[ii + perm[jj]] % 12
    gi1 = perm[ii + i1 + perm[jj+j1]] % 12
    gi2 = perm[ii + 1 + perm[jj+1]] % 12

    t0 = 0.5 - x0*x0 - y0*y0
    if t0 < 0:
        n0 = 0
    else:
        t0 *= t0
        n0 = t0*t0*dot(grad3[gi0, :], x0, y0)

    t1 = 0.5 - x1*x1 - y1*y1
    if t1 < 0:
        n1 = 0.0
    else:
        t1 *= t1
        n1 = t1*t1*dot(grad3[gi1, :], x1, y1)

    t2 = 0.5 - x2*x2 - y2*y2
    if t2 < 0:
        n2 = 0
    else:
        t2 *= t2
        n2 = t2*t2*dot(grad3[gi2, :], x2, y2)

    return 0.5*(70*(n0 + n1 + n2) + 1)

if __name__ == "__main__":
    earth = 0.3
    world = np.zeros((size, size))
    scaling = 50
    for i in range(size):
        for j in range(size):
            temp = simplex_noise(i/scaling, j/scaling)
            if temp < earth:
                temp = 0
            else:
                temp = 1
            world[i, j] = temp
    plt.figure()
    plt.imshow(world)
    plt.show()
