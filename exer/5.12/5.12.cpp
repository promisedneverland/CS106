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
using namespace std;


int main() {
    int input;
    stack<int> s; 
    while(cin >> input) {
        if(input == 0) {
            break;
        }
        s.push(input);
    }
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}