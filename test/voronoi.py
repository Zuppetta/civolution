import numpy as np
import matplotlib.pyplot as plt

nber_seed1 = 50
nber_seed2 = 200
world_size = 1024
earth = 0.35


class seed_point:
    def __init__(self, x, y, v):
        self.x = round(x*world_size)
        self.y = round(y*world_size)
        self.v = v

    def dist2(self, x, y):
        return (x-self.x)**2 + (y-self.y)**2


def gen_water():
    seeds = []
    rand = np.random.rand(nber_seed1, 3)
    world = np.zeros((world_size, world_size))
    for i in range(nber_seed1):
        seeds.append(seed_point(rand[i, 0], rand[i, 1], rand[i, 2]))
    for i in range(world_size):
        for j in range(world_size):
            nearest = world_size**2
            for point in seeds:
                if point.dist2(i, j) < nearest:
                    nearest = point.dist2(i, j)
                    world[i, j] = point.v
    return world


def gen_water2(world):
    seeds = []
    rand = np.random.rand(nber_seed2, 3)
    for i in range(nber_seed2):
        seeds.append(seed_point(rand[i, 0], rand[i, 1], rand[i, 2]))
    for i in range(world_size):
        for j in range(world_size):
            ifearth = world[i, j] < earth
            nearest = world_size**2
            for point in seeds:
                if point.dist2(i, j) < nearest:
                    nearest = point.dist2(i, j)
                    if ifearth:
                        if point.v < 0.98:
                            world[i, j] = 0
                        else:
                            world[i, j] = 1
                    else:
                        if point.v < 0.02:
                            world[i, j] = 0
                        else:
                            world[i, j] = 1
    return world

if __name__ == "__main__":

    world = gen_water()

    world = gen_water2(world)

    plt.figure()
    plt.imshow(world)
    plt.show()
