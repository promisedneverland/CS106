#include<iostream>
#include<cstdlib>
#include "random.h"
using namespace std;
int main() {
    srand(time(NULL));
    const int N = 100;
    printf("%d\n", rand());
    return 0;
}