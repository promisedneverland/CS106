#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

bool in(string str, char c) {
    size_t found = str.find(c);
    if(found == string::npos) {
        return false;
    } else {
        return true;
    }
}
string removeChar(string str, string remove) {
    string res = "";
    for(int i = 0; i < str.length(); i++) {
        if(!in(remove, str[i])) {
            res += str[i];
        }
    }
    return res;
}
int main() {
    string str;
    cin >> str;
    str = "counterrevolutionaries";
    cout << removeChar(str, "aeiou") << endl;
    return 0;
}