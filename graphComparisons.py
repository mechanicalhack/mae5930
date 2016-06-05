import numpy as np
import matplotlib.pyplot as plt

A = np.genfromtxt("jacobiIter.txt")
B = np.genfromtxt("seidelIter.txt")
C = np.genfromtxt("sorIter.txt")

D = np.genfromtxt("jacobiIterWallTime.txt")
E = np.genfromtxt("seidelIterWallTime.txt")
F = np.genfromtxt("sorIterWallTime.txt")

G = np.genfromtxt("jacobiTotalWallTime.txt")
H = np.genfromtxt("seidelTotalWallTime.txt")
I = np.genfromtxt("sorTotalWallTime.txt")

A2 = A[:,0]
A1 = A[:,1]

B2 = B[:,0]
B1 = B[:,1]

C2 = C[:,0]
C1 = C[:,1]

D2 = D[:,0]
D1 = D[:,1]

E2 = E[:,0]
E1 = E[:,1]

F2 = F[:,0]
F1 = F[:,1]

G2 = G[:,0]
G1 = G[:,1]

H2 = H[:,0]
H1 = H[:,1]

I2 = I[:,0]
I1 = I[:,1]

plt.figure(1)
plt.plot(A2,A1, "r", label="Jacobi")
plt.plot(B2,B1, "g", label="Gauss Seidel")
plt.plot(C2,C1, "b", label="SOR")
plt.title('Comparison of the Total Iterations')
plt.xlabel('N')
plt.ylabel('# of Total Iterations')
plt.rcParams.update({'font.size': 20})
plt.legend(loc=0)
plt.ylim([-100000000,500000000])

plt.figure(2)
plt.plot(D2,D1, "r", label="Jacobi")
plt.plot(E2,E1, "g", label="Gauss Seidel")
plt.plot(F2,F1, "b", label="SOR")
plt.title('Comparison of the Time per Iteration')
plt.xlabel('N')
plt.ylabel('Time per Iteration')
plt.rcParams.update({'font.size': 20})
plt.legend(loc=0)

plt.figure(3)
plt.plot(G2,G1, "r", label="Jacobi")
plt.plot(H2,H1, "g", label="Gauss Seidel")
plt.plot(I2,I1, "b", label="SOR")
plt.title('Comparison of the Total Walltime')
plt.xlabel('N')
plt.ylabel('Total Wall-Time')
plt.rcParams.update({'font.size': 20})
plt.legend(loc=0)
plt.ylim([-20,120])

plt.show()
