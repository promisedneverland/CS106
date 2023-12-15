#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include"gtypes.h"
#include<vector>
#include"gwindow.h"
#include"rational.h"
using namespace std;



int main() {
    Rational r1(2,5);
    Rational r2(4,3);
    cout << r1 + r2 << endl;
}