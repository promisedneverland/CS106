#include"domino.h"
#include<iostream>
using namespace std;
ostream& operator<<(ostream& os, domino d) {
    return os << d.toString();
}
