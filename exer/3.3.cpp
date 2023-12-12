#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

string mySubStr (const string& str, int pos, int n) {
    if(pos > str.length()) {
        error("pos too large");
        return NULL;
    }    
    string res = "";
    for(int i = pos; i < str.length() && i < pos + n; i++) {
        res += str[i];
    }
    return res;
}

string mySubStr (const string& str, int pos) {
    return mySubStr(str, pos, str.length());
}

int main() {
    string str;
    // cin >> str;
    str = "Helloworld sf";
    cout << mySubStr(str, 4, 3) << endl;
    return 0;
}