//
//  main.cpp
//  Benchmark
//
//  Created by Rob Lloyd on 5/24/16.
//

#include <iostream>
#include <time.h>
#include <vector>
#include <cmath>
#include <fstream>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

int main() {
    
    ofstream fout;
    clock_t start, end;
    
    double time;
    int iter = 0;
    int N = 10;
    double omega = 0.85;
    double error = 1;
    double errorCap = pow(10, -13);
    
    //use eigen vector instead of vector???????
    MatrixXd grid = MatrixXd::Constant(N+2,N+2,0);
    MatrixXd oldGrid = MatrixXd::Constant(N+2,N+2,0);
    
    for (int j = 0; j < N+2; j++){
        grid(0,j) = 1.0;
        oldGrid(0,j) = 1.0;
    }
    
    cout << grid << endl;
    
    //Jacobi
    fout.open("jacobiData.txt");
    start = clock();
    while(error > errorCap){
        error = 0;
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < N+1; j++){
                grid(i,j) = 0.25*(oldGrid(i+1,j)+oldGrid(i-1,j)+oldGrid(i,j+1)+oldGrid(i,j-1));
                error += (grid(i,j)-oldGrid(i,j))*(grid(i,j)-oldGrid(i,j));
            }
        }
        oldGrid = grid;
        error = sqrt(error/(N*N));
    }
    end = clock();
    time = double(end-start)/ (double)CLOCKS_PER_SEC;
    fout << grid;
    fout.close();
    error = 1;
    
    for (int j = 0; j < N+2; j++){
        for (int i = 1; i < N+2; i++){
            grid(i,j) = 0.0;
            oldGrid(i,j) = 0.0;
        }
    }
    
    //Gauss-Seidel
    fout.open("seidelData.txt");
    start = clock();
    while(error > errorCap){
        error = 0;
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < N+1; j++){
                grid(i,j) = 0.25*(grid(i+1,j)+grid(i-1,j)+grid(i,j+1)+grid(i,j-1));
                error += (grid(i,j)-oldGrid(i,j))*(grid(i,j)-oldGrid(i,j));
            }
        }
        oldGrid = grid;
        error = sqrt(error/(N*N));
    }
    end = clock();
    time = double(end-start)/ (double)CLOCKS_PER_SEC;
    fout << grid;
    fout.close();
    
    error = 1;
    
    for (int j = 0; j < N+2; j++){
        for (int i = 1; i < N+2; i++){
            grid(i,j) = 0.0;
            oldGrid(i,j) = 0.0;
        }
    }
    
    //Successive Overrelaxation (SOR)
    fout.open("sorData.txt");
    start = clock();
    while(error > errorCap){
        error = 0;
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < N+1; j++){
                grid(i,j) = (1-omega)*oldGrid(i,j) + omega*(0.25*(grid(i+1,j)+grid(i-1,j)+grid(i,j+1)+grid(i,j-1)));
                error += (grid(i,j)-oldGrid(i,j))*(grid(i,j)-oldGrid(i,j));
            }
        }
        oldGrid = grid;
        error = sqrt(error/(N*N));
    }
    end = clock();
    time = double(end-start)/ (double)CLOCKS_PER_SEC;
    fout << grid;
    fout.close();
    
    system("python graph.py");
    
    return 0;
}
