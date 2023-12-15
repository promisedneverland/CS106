#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<cctype>
#include"tokenscanner.h"
#include<assert.h>
#include<stack>
using namespace std;

int raiseToPower(int n, int k) { 
    if(k == 0) {
        return 1;
    }
    return n * raiseToPower(n, k - 1);
}

int main() {
    
    cout << raiseToPower(2, 5) << endl;
}