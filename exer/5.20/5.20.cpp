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
#include<map>
#include<sstream>
using namespace std;

   

int main() {
    map<int, string> m;
    map<string, vector<int>> inverseMap;

    string file = "5.19.txt";
    ifstream inFile(file);
    if(inFile.fail()) {
        return 0;
    }

    string line;
    while(getline(inFile, line)) {
        if(line.length() < 5 || line[3] != '-') {
            cerr << "error" << endl;
        }
        int code = atoi(line.substr(0,3).c_str());
        string state = line.substr(4);
        m[code] = state;
        inverseMap[state].push_back(code);
    }
    while(1) {
        cout << "Enter code or state" << endl;
        int code;
        getline(cin, line);
        istringstream ss(line);
        ss >> code;
        if(ss.fail()) {
            for(int i : inverseMap[line]) {
                cout << i << endl;
            }
        } else {
            cout << m[code] << endl;
        }
    }
}