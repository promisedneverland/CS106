#include<iostream>
#include<cstdlib>
using namespace std;

enum direction {EAST = 3, WEST};

const double CENTIMETERS = 2.54;
void defaultFunction(int a, int& b) {
    b = 0;
}
void error() {
    exit(EXIT_FAILURE);
}
int main() {
    int C;
    cin >> C;    
    cout << -1 % 4 << endl;
    defaultFunction(1, C);
    return 0;
}
