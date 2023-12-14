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

bool isMagicSquare(Grid<int> & square) {
    if(square.numCols() != square.numRows()) {
        return false;
    }
    int magicNumber = 0;
    for(int i = 0; i < square.numRows(); i++) {
        int sumR = 0;
        int sumC = 0;
        int sumD1 = 0;
        int sumD2 = 0;
        for(int j = 0; j < square.numCols(); j++) {
            sumR += square[i][j];
            sumC += square[j][i];
            sumD1 += square[j][j];
            sumD2 += square[square.numCols() - j - 1][j];
        }
        if(i == 0) 
            magicNumber = sumR;
        if(sumR != magicNumber || sumC != magicNumber || magicNumber != sumD1 || magicNumber != sumD2) {
            return false;
        }
    }
    return true;
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
    cout << isMagicSquare(matrix) << endl;
}