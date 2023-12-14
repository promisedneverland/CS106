#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

string capitalize(string str) {
    if(str == "") {
        return "";
    }
    string res = "";
    res += toupper(str[0]);
    for(int i = 1; i < str.length(); i++) {
        res += tolower(str[i]);
    }
    return res;
}
int main() {
    string str;
    cin >> str;
    // str = "Helloworldsf";
    cout << capitalize(str) << endl;
    return 0;
}