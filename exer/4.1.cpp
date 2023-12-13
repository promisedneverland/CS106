#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
#include <algorithm>
#include <iomanip>
using namespace std;

void display(){
    cout << fixed << setprecision(7) << right;
    string line = "|";
    for(int i = -90; i <= 90; i += 15) {

        cout << setw(3) << i << line << setw(10) << sin(i) << line << setw(10) << cos(i) << line  << endl;
    }
}
int main() {
    display();
    return 0;
}