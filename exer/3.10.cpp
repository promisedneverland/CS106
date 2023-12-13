#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

string replaceAll(string str, string s1, string s2){
    string res = "";
    for(int i = 0; i < str.length(); i++) {
        if(str.substr(i, s1.length()) == s1) {
            res += s2;
            i += s1.length() - 1;
        } else {
            res += str[i];
        }
    }
    return res;
}
int main() {
    string str;
    cin >> str;
    str = "helel world";
    cout << replaceAll(str, "el", "ff") << endl;
    return 0;
}