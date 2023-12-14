#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

int point(string str) {
    int count = 0;
    for(int i = 0; i < str.length(); i++) {
        switch (str[i])
        {
        case 'A': case 'E': case 'L' :case 'N' :case 'O' :
            count += 1;
            break;
        
        case 'F' :
            count += 4;
        default:
            break;
        }
    }
    return count;
}
int main() {
    string str;
    cin >> str;
    // str = "Helloworldsf";
    cout << point(str) << endl;
    return 0;
}