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
string defaultExtension(string path, string ext) {
    if(getExtension(path) == "") {
        return path + ext;
    }
    if(ext != "") {
        if(ext[0] == '*') {
            return getRoot(path) + ext.substr(1);
        } else {
            return path;
        }
    } else {
        return path;
    }
    return "";
}
int main() {
    string str, ext;
    cin >> str >> ext;
    cout << defaultExtension(str, ext) << endl; 
    return 0;
}