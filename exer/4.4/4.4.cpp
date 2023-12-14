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

void fileCount(){
    ifstream inputStream;
    
    do {
        cout << "Enter file name" << endl;
        string fileName;
        cin >> fileName;
        inputStream.open(fileName);
    } while(inputStream.fail());

    string line;
    int countLine = 0;
    while(getline(inputStream, line)) {
        countLine++;
    }
    cout << countLine << " lines" << endl;

    inputStream.clear();
    inputStream.seekg(0, ios::beg);
    string word;
    int countWord = 0;
    while(!inputStream.eof()) {
        inputStream >> word;
        countWord++;
    }
    cout << countWord << " words" << endl;

    inputStream.clear();
    inputStream.seekg(0, ios::beg);
    int countChar = 0;
    while(inputStream.get() != EOF) {
        countChar++;
    }
    cout << countChar << " char" << endl;
    inputStream.close();
    
}
int main() {
    fileCount();
    return 0;
}