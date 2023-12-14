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

double myStringToReal(const std::string& str) {
    std::istringstream stream(trim(str));
    double value;
    stream >> value;
    if (stream.fail() || !stream.eof()) {
        error("stringToInteger: Illegal integer format: \"" + str + "\"");
    }
    return value;
}
string myRealToString(double d) {
    std::ostringstream stream;
    stream << std::uppercase << setprecision(10) << d;
    return stream.str();
}
int main() {
    cout << myStringToReal("143.23") << endl;
    cout << myRealToString(1324.555) << endl;
    return 0;
}