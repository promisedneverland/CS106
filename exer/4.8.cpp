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
using namespace std;

int c = 0;//this is comment
// */
int b = 0;/*aflfa
    thsl
    sf

*/ int d = 0; //int a = 0;
string checkSingleLine(string line) {
    int pos;
    if((pos = line.find("//")) != string::npos) {
        return line.substr(0, pos);
    } else {
        return line;
    }
}
void removeComments(istream & is, ostream & os) {
    bool multiLineCommenting = false;
    while(!is.eof()) {
        string line;
        getline(is, line);
        line = checkSingleLine(line);
        int pos;
        if(multiLineCommenting) {
            if((pos = line.find("*/")) != string::npos) {
                multiLineCommenting = false;
                os << line.substr(pos + 2) << endl;
            } else {
                continue;
            }
        } else {
            if((pos = line.find("/*")) != string::npos) {
                multiLineCommenting = true;
                os << line.substr(0, pos) << endl;
            } else {
                os << line << endl;
            }
        }
    }

}
int main() {
    ifstream input("4.8.cpp");
    removeComments(input, cout);
    return 0;
}