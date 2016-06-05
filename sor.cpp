#include <iostream>
#include <time.h>
#include <vector>
#include <cmath>
#include <fstream>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

int main() {
    
    ofstream fout, foutIter, foutTotalWallTime, foutIterWallTime, foutOmega;
    clock_t start, end;
    
    double time;
    int numIter = 0;
    int N = 50;
    double omega = 0.1;
    double error = 1;
    double errorCap = pow(10, -13);
    
    //cout << grid << endl;

    //Successive Overrelaxation (SOR)
    fout.open("sorData.txt");
    foutIter.open("sorIter.txt");
    foutTotalWallTime.open("sorTotalWallTime.txt");
    foutIterWallTime.open("sorIterWallTime.txt");
    
    foutOmega.open("omegaData.txt");
    
    MatrixXd grid = MatrixXd::Constant(N+2,N+2,0);
    MatrixXd oldGrid = MatrixXd::Constant(N+2,N+2,0);
    
    for(;N<=50;N+=10){
        
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
        
            start = clock();
        for(; omega < 2; omega+=.10){ //For making the optimization of omega graph
            numIter = 0;
            error = 1;
            while(error > errorCap){
                error = 0;
                for(int i = 1; i < N+1; i++){
                    for(int j = 1; j < N+1; j++){
                        grid(i,j) = (1-omega)*oldGrid(i,j) + omega*(0.25*(grid(i+1,j)+grid(i-1,j)+grid(i,j+1)+grid(i,j-1)));
                        error += (grid(i,j)-oldGrid(i,j))*(grid(i,j)-oldGrid(i,j));
                        numIter++;
                    }
                }
                oldGrid = grid;
                error = sqrt(error/(N*N));
            }
            cout << omega << " " << numIter << " done\n";
            foutOmega << numIter << endl;
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
    
    system("python graphSOR.py");
    
    return 0;

}