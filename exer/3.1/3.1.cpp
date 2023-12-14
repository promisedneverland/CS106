#include<iostream>
#include"gwindow.h"
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

bool myEndsWith (const string& str, const string& suffix) {
    if(suffix.length() > str.length())
        return false;
    for(int i = 0; i < suffix.length(); i++) {
        if(str[i + str.length() - suffix.length()] != suffix[i])
            return false;
    }
    return true;
}
bool myEndsWith (const string& str, const char suffix) {
    string strSuffix = "";
    strSuffix += suffix;
    return myEndsWith(str, strSuffix);
}

int main() {
    string str = "ADr";
    printf("%d\n", myEndsWith(str, 'c'));
    return 0;
}