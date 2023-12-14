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
using namespace std;

void randomSub() {
    string path;
    cin >> path;
    ifstream input;
    input.open(path);
    if(input.fail()){
        return ;
    }
    char ch;
    string res = "";
    while((ch = input.get()) != EOF) {
        if(islower(ch)) {
            res += char(randomInteger('a', 'z'));
        } else if(isupper(ch)) {
            res += char(randomInteger('A', 'Z'));
        } else {
            res += ch;
        }
    }
    cout << res << endl;
}
int main() {
    randomSub();
    return 0;
}