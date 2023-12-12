#include<iostream>
#include"error.h"
#include<cstdlib>
#include<cmath>
using namespace std;

int windChill(int t, int w) {
    if(w == 0) 
        return t;
    return round(35.74 + 0.6215 * t - 35.75 * pow(w, 0.16) + 0.4275 * t * pow(w, 0.16));
}

int main() {
    for(int w = 5; w <= 60; w += 5) {
        for(int f = 40; f >= -45; f-=5) {
            printf("%d ", windChill(f, w));
        }
        cout << endl;
    }
    return 0;
}