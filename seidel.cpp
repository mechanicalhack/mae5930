#include <iostream>
#include <time.h>
#include <vector>
#include <cmath>
#include <fstream>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

int main() {
    
    ofstream fout, foutIter, foutTotalWallTime, foutIterWallTime;
    clock_t start, end;
    
    double time;
    int numIter = 0;
    int N = 100;
    double error = 1;
    double errorCap = pow(10, -13);
    
    //cout << grid << endl;

    //Gauss-Seidel
    fout.open("seidelData.txt");
    foutIter.open("seidelIter.txt");
    foutTotalWallTime.open("seidelTotalWallTime.txt");
    foutIterWallTime.open("seidelIterWallTime.txt");
    
    MatrixXd grid = MatrixXd::Constant(N+2,N+2,0);
    MatrixXd oldGrid = MatrixXd::Constant(N+2,N+2,0);
    
    for(;N<=100;N+=10){
        
        grid.resize(N+2,N+2);
        oldGrid.resize(N+2,N+2);
        
        for (int j = 0; j < N+2; j++){
            grid(0,j) = 1.0;
            oldGrid(0,j) = 1.0;
        }
        
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < N+1; j++){
                grid(i,j) = 0;
            }
        }
        
        numIter = 0;
        start = clock();
        error = 1;
        while(error > errorCap){
            error = 0;
            for(int i = 1; i < N+1; i++){
                for(int j = 1; j < N+1; j++){
                    grid(i,j) = 0.25*(grid(i+1,j)+grid(i-1,j)+grid(i,j+1)+grid(i,j-1));
                    error += (grid(i,j)-oldGrid(i,j))*(grid(i,j)-oldGrid(i,j));
                    numIter++;
                }
            }
            oldGrid = grid;
            error = sqrt(error/(N*N));
        }
        
        end = clock();
        time = double(end-start)/ (double)CLOCKS_PER_SEC;
        foutTotalWallTime << N << " " << time << endl;
        foutIterWallTime << N << " " << (double)time/(double)numIter << endl;
        foutIter << N << " " << numIter << endl;
        cout << N << endl;
    }
    N -= 10;
    //fout << grid;
    //cout << N << endl;
    for(int i = N+1; i >= 0; i--){
        for(int j = 0; j < N+2; j++){
            fout << grid(i,j) << " ";
        }
        fout << endl;
    }
    
    fout.close();
    foutIter.close();
    foutTotalWallTime.close();
    foutIterWallTime.close();
    
    system("python graphSeidel.py");
    
    return 0;
}