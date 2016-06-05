import numpy as np
import matplotlib.pyplot as plt

A = np.genfromtxt("seidelData.txt")

plt.figure(1)
plt.contourf(A,100)
plt.title('2D Heat Transfer (Gauss Seidel)')
plt.xlabel('dx')
plt.ylabel('dy')
#plt.gca().invert_xaxis()
plt.rcParams.update({'font.size': 22})
plt.colorbar()
plt.gca().set_aspect('equal', adjustable='box')

plt.show()
