import numpy as np
import matplotlib.pyplot as plt

nber_seed1 = 40
nber_seed2 = 200
world_size = 1024
earth = 0.2


class seed_point:
    def __init__(self, x, y, v, area):
        self.x = round(x*world_size/2)
        self.y = round(y*world_size/2)
        if area == 1 or area == 3:
            self.x += world_size/2
        if area == 2 or area == 3:
            self.y += world_size/2
        self.v = v

    def dist2(self, x, y):
        temp = (x-self.x)**2 + (y-self.y)**2
        tempx = (abs(x-self.x)-world_size)**2 + (y-self.y)**2
        return np.min([temp, tempx])


def gen1():
    seeds = []
    np.random.seed(15)
    rand = np.random.rand(nber_seed1, 3)
    world = np.zeros((world_size, world_size))
    for i in range(nber_seed1):
        seeds.append(seed_point(rand[i, 0], rand[i, 1], rand[i, 2],
                                np.floor(float(i)/nber_seed1*4)))
    for i in range(world_size):
        for j in range(world_size):
            nearest = world_size**2
            for point in seeds:
                if point.dist2(i, j) < nearest:
                    nearest = point.dist2(i, j)
                    world[i, j] = point.v
    return world, seeds


if __name__ == "__main__":

    world, seeds = gen1()

    world[world < earth] = 0
    world[world >= earth] = 1

    plt.figure()
    plt.imshow(world.T)
    plt.show()
