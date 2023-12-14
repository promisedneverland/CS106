#include<iostream>
#include"gwindow.h"
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

string myTrim (const string& str) {
    string res = "";
    for(int i = 0; i < str.length(); i++) {
        if(!isspace(str[i])) {
            res += str[i];
        }
    }
    return res;
}

int main() {
    string str;
    // cin >> str;
    str = "Hello \t world sf";
    cout << myTrim(str) << endl;
    return 0;
}