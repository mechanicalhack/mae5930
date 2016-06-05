import numpy as np
import matplotlib.pyplot as plt

A = np.genfromtxt("omegaData.txt")
x = A[:,0]
y = A[:,1]

plt.figure(1)
plt.plot(x,y)
plt.title('Omega vs. Number of Iterations to Converge (SOR)')
plt.xlabel('Omega')
plt.ylabel('# of Iterations')
plt.yscale('log')
plt.rcParams.update({'font.size': 22})

plt.show()
