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
    double a;
    scanf("%f", &a);
    printf("%f\n", roundToNearestInt(a));
    return 0;
}