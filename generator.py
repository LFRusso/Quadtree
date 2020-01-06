import numpy as np
from matplotlib import pyplot as plt
import os
import time


x1 = [np.random.normal(-10521, 20000)/100 for i in range(10000)]
x2 = [np.random.normal(50521, 10000)/100 for i in range(10000)]
x = x1+x2

y = [np.random.normal(521, 84000)/100 for i in range(20000)]

np.savetxt("table.dat", np.array([x, y]).T, delimiter=" ")

print("[Generator.py] runnig quadtree")
start = time.time()
os.system('./quadtree')
end = time.time()
print(end - start)

os.system('python3 view.py')