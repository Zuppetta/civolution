import numpy as np
import matplotlib.pyplot as plt

world_size = 1024
earth = 0.3

if __name__ == "__main__":
    world = np.random.rand(world_size, world_size)
    world[0, 0] = earth * world_size**2
    world = np.abs(np.fft.ifft2(world))
    print world

    world[world < earth] = 1
    world[world >= earth] = 0
    plt.figure()
    plt.imshow(world)
    plt.show()
