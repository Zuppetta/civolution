import numpy as np
import matplotlib.pyplot as plt

world_size = 512
nber = 1000
earth = 128


def collaging():
    world = 128*np.ones((world_size, world_size), dtype=np.uint8)
    for i in range(nber):
        print i
        method = np.floor(np.random.rand(1)*2)
        if method == 1:
            world = line(world)
        else:
            world = circle(world)
    return world


def circle(world):
    value, radius = np.random.rand(2)
    radius = radius*world_size*world_size/400 + 10
    if value < 0.53:
        value = -1
    else:
        value = 1
    point = np.random.rand(2)*world_size
    for i in range(world_size):
        for j in range(world_size):
            if (i-point[0])**2 + (j-point[1])**2 < radius:
                world[i, j] += value
    return world


def line(world):
    value = np.random.rand(1)
    if value < 0.5:
        value = -1
    else:
        value = 1
    point = np.random.rand(2, 2)*world_size
    v1 = np.array([point[0, 0] - point[1, 0],
                   point[0, 1] - point[1, 1]])
    for i in range(world_size):
        for j in range(world_size):
            v2 = np.array([i - point[1, 0],
                           j - point[1, 1]])
            test = v1[0]*v2[1] - v1[1]*v2[0]
            if test > 0:
                world[i, j] += value
    return world

if __name__ == "__main__":

    world = collaging()
    world[world < earth] = 0
    world[world >= earth] = 1

    plt.figure()
    plt.imshow(world)
    plt.show()
