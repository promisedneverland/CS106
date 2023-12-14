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

void reverseQueue(queue<string> & queue) {
    stack<string> st;
    
    while(!queue.empty()){ 
        st.push(queue.front());
        queue.pop();
    }
    while(!st.empty()){ 
        queue.push(st.top());
        st.pop();
    }
}

int main() {
    queue<string> q;
    q.push("a");
    q.push("b");
    q.push("c");
    reverseQueue(q);
    while(!q.empty()){ 
        cout << q.front() << endl;
        q.pop();
    }
}