#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

string acronym(string str) {
    if(str == "") {
        return "";
    }
    string res = "";
    res += toupper(str[0]);
    for(int i = 1; i < str.length(); i++) {
        if(!isalpha(str[i - 1])) {
           res += toupper(str[i]); 
        }
    }
    return res;
}
int main() {
    string str;
    cin >> str;
    str = "Acquired Immune Deficiency Syndrome";
    cout << acronym(str) << endl;
    return 0;
}