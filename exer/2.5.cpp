#include<iostream>
#include"error.h"
#include<cstdlib>
#include<cmath>
using namespace std;

bool isPerfect(int n) {
    int sum = 0;
    for(int i = 1; i < n; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }
    if(sum == n) 
        return true;
    return false;
}

int main() {
    for(int i = 1; i < 9999; i++) {
        if(isPerfect(i)) {
            cout << i << endl;
        }
    }
    return 0;
}