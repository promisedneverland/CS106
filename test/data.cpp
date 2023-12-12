#include<iostream>
#include<cstdlib>
#include "random.h"
using namespace std;
int main() {
    srand(time(NULL));
    const int N = 100;
    printf("%f\n", randomReal(-N, N));
    return 0;
}