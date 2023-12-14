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

void roll(stack<char> & st, int n, int k) {
    if(st.size() < n) {
        cerr << "wrong" << endl;
        return;
    }
    stack<char> sReverse;
    stack<char> sLeft;
    queue<char> q;
    for(int i = 0; i < k % n; i++) {
        sReverse.push(st.top());
        st.pop();
    }
    for(int i = 0; i < n - k % n; i++) {
        sLeft.push(st.top());
        st.pop();
    }

    while(!sReverse.empty()) {
        st.push(sReverse.top());
        sReverse.pop();
    }
    while(!sLeft.empty()) {
        st.push(sLeft.top());
        sLeft.pop();
    }
   
}
int main() {
    stack<char> stack({'A', 'B', 'C', 'D'});
    // while(!stack.empty()) {
    //     cout << stack.top() << endl;
    //     stack.pop();
    // }
    roll(stack, 3, 2);
    while(!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }
}