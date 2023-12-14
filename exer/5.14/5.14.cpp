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
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;

bool check(string str) {
    stack<char> stbrackets;
    stack<char> stbig;
    stack<char> stsquare;
    for(int i = 0; i < str.length(); i++) {
        switch (str[i])
        {
        case '(':
            stbrackets.push(str[i]);
            break;
        case '[':
            stsquare.push(str[i]);
            break;
        case '{':
            stbig.push(str[i]);
            break;
        case ')':
            if(stbrackets.empty()) {
                return false;
            }
            stbrackets.pop();
            break;
        case ']':
            if(stsquare.empty()) {
                return false;
            }
            stsquare.pop();
            break;
        case '}':
            if(stbig.empty()) {
                return false;
            }
            stbig.pop();
            break;
        default:
            break;
        }
    }
    if(stsquare.empty() && stbig.empty() && stbrackets.empty())
        return true;
    return false;
}

int main() {
    string str;
    getline(cin, str);
    cout << check(str) << endl;
}