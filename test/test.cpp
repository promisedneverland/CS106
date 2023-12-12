#include<iostream>
#include<cstdlib>
#include "simpio.h"
#include<cmath>
using namespace std;

int roundToNearestInt(double d) {
    if(d > 0)
        return d + 0.5;
    return d - 0.5;
}
int main() {
    double a = getReal();
    cout << roundToNearestInt(a);
    return 0;
}