import numpy as np
from matplotlib import pyplot as plt

def normalize(x):
    if x <= 0:
        return 0
    else:
        return 1


x = np.array([normalize(np.random.normal(-0.8,1)) for i in range(100000)])

print(x)

plt.hist(x, bins=2)
plt.show()