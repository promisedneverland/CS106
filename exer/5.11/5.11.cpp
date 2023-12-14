#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
#include <algorithm>
#include"simpio.h"
#include<fstream>
#include"random.h"
#include<iomanip>
using namespace std;

void reshape(Grid<int> & grid, int nRows, int nCols)  {
    Vector<int> vec;
    for(int i : grid) {
        vec.add(i);
    }
    Grid<int> res(nRows, nCols);
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nCols; j++) {
            if(i * nCols + j < vec.size())
                res[i][j] = vec[i * nCols + j];
        }
    }
    grid = res;
}

int main() {
    Grid<int> matrix(3, 3);
    Vector<int> values;
    values += 1, 2, 3;
    values += 4, 5, 6;
    values += 7, 8, 9;
    for(int i = 0; i < matrix.numRows(); i++) {
        for(int j = 0; j < matrix.numCols(); j++) {
            cin >> matrix[i][j];
        }
    }
    reshape(matrix, 1, 5) ;
    cout << matrix << endl;
}