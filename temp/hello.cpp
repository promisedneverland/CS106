#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;

struct myPoint {
    bool operator==(myPoint p) {
        cout << "method" << endl;
        return false;
    }
    int x; int y;
};

bool operator==(myPoint p1, myPoint p2) {
    cout << "free" << endl;
    return false;
}
ostream operator<<(ostream& os, myPoint i) {
    return os << "hi";
}
int main() {
    myPoint p;
    cout << p << endl;
}