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

void printLongestLine(){
    cout << "Enter file name" << endl;
    string file;
    cin >> file;
    ifstream inFile;
    while(true) {
        inFile.open(file);
        if(!inFile.fail()) {
            break;
        }
        else {
            cerr << "Not found" << endl;
        }
    }
    string line;
    int maxLength = 0;
    string longestLine;
    while(getline(inFile, line)) {
        if(maxLength < line.length()) {
            longestLine = line;
            maxLength = line.length();
        }
    }
    cout << longestLine << endl;
    inFile.close();

}
int main() {
    printLongestLine();
    return 0;
}