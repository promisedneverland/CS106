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
using namespace std;


void readVector(istream & is, Vector<int> & vec) {
    vec.clear();
    string line;
    while(getline(is, line)) {
        if(line == "") {
            return;
        }
        vec.add(atoi(line.c_str()));
    }

}
int main() {

    Vector<int> vec;
    ifstream file("input.txt");
    readVector(file, vec);
    for(int i : vec) {
        cout << i << endl;
    }
    cout << endl;

    readVector(file, vec);
    for(int i : vec) {
        cout << i << endl;
    }
    cout << endl;

    readVector(file, vec);
    for(int i : vec) {
        cout << i << endl;
    }
    
    return 0;
}