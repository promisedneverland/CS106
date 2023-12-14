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

double mean(Vector<double> & data) {
    double sum = 0;
    for(double d : data) {
        sum += d;
    }
    return sum / data.size();
}
int main() {
    Vector<double> data;
    data.add(5);
    data.add(15);
    data.add(2);
    cout << mean(data) << endl;
}