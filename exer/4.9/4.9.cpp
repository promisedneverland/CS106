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

void removeChars(istream & is, string remove) {
    char ch;
    string res = "";
    while((ch = is.get()) != EOF){
        if(remove.find(ch) != string::npos) {

        } else {
            res += ch;
        }

    }
    cout << res << endl;
}
int main() {
    ifstream input("4.8.cpp");
    removeChars(input, "aeiou");
    return 0;
}