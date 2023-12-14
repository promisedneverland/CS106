#include<iostream>
#include"gwindow.h"
#include"error.h"
#include<cstdlib>
#include<cmath>
#include<string>
#include <algorithm>
#include"simpio.h"
#include<fstream>
using namespace std;

string getRoot(string path){
    
    for(int i = path.length() - 1; i >= 0; i--) {
        if(path[i] == '.') {
            return path.substr(0, i);
        }
    }
    return path;
}
string getExtension(string path) {
    return path.substr(getRoot(path).length());
}
int main() {
    string str;
    cin >> str;
    cout << getRoot(str) << endl << getExtension(str) << endl; 
    return 0;
}