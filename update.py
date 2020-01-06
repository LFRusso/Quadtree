import numpy as np
import os

x, y = np.loadtxt("table.dat", unpack=True)
x_rand = np.random.uniform(low=-100, high=100, size=1000)
y_rand = np.random.uniform(low=-100, high=100, size=1000)
x += x_rand
y += y_rand

os.system("rm -rf table.dat")
np.savetxt("table.dat", (x, y).T, delimiter=" ")