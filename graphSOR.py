import numpy as np
import matplotlib.pyplot as plt

A = np.genfromtxt("jacobiData.txt")
B = np.genfromtxt("seidelData.txt")
C = np.genfromtxt("sorData.txt")

plt.figure(1)
plt.contourf(C,100)
plt.title('2D Heat Transfer (SOR)')
plt.xlabel('dx')
plt.ylabel('dy')
#plt.gca().invert_xaxis()
plt.rcParams.update({'font.size': 22})
plt.colorbar()
plt.gca().set_aspect('equal', adjustable='box')

#plt.figure(2)
#plt.contourf(B,100)
#plt.gca().invert_yaxis()
#plt.title('2D Heat Transfer (Gauss Seidel)')
#plt.xlabel('dx')
#plt.ylabel('dy')
#plt.rcParams.update({'font.size': 22})

#plt.figure(3)
#plt.contourf(C,100)
#plt.gca().invert_yaxis()
#plt.title('2D Heat Transfer (Successive Overrelaxation SOR)')
#plt.xlabel('dx')
#plt.ylabel('dy')
#plt.rcParams.update({'font.size': 22})

plt.show()
