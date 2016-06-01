import numpy as np
import matplotlib.pyplot as plt

earth = 3

world = np.genfromtxt('./world.txt', dtype=int, delimiter=',')
world[world < earth] = 0
world[world >= earth] = 1

plt.figure()
plt.imshow(world)
plt.show()
