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

void fillGrid(Grid<int> & grid, Vector<int> & values) {
    for(int i = 0; i < grid.numRows(); i++) {
        for(int j = 0; j < grid.numCols(); j++) {
            grid[i][j] = values[i * grid.numRows() + j];
        }
    }
}
int main() {
    Grid<int> matrix(3, 3);
    Vector<int> values;
    values += 1, 2, 3;
    values += 4, 5, 6;
    values += 7, 8, 9;
    fillGrid(matrix, values);
    cout << matrix << endl;
}