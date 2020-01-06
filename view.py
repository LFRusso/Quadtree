import numpy as np
from matplotlib import pyplot as plt
import matplotlib.patches as patches

x1, x2, y1, y2 = np.loadtxt("rects.dat", unpack=True)
x, y = np.loadtxt("rede1", unpack=True)

fig,ax = plt.subplots(1)

w = abs(x2-x1)
h = abs(y2-y1)

for i in range(len(x2)):
    ax.add_patch(patches.Rectangle((x1[i], y1[i]), height=h[i], width=w[i], linewidth=1,edgecolor='k',facecolor='none'))

ax.scatter(x, y, color = "r", s=2)
fig.tight_layout()

plt.show()