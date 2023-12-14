#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
#include <algorithm>
using namespace std;

string addCommas(string digits){
    string res = "";
    for(int i = 0; i < digits.length(); i++) {
        if(i % 3 == 0 && i != 0) {
            res += ',';
        }
        res += digits[digits.length() - i - 1];
    }
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    string str;
    cin >> str;
    cout << addCommas(str) << endl;
    return 0;
}