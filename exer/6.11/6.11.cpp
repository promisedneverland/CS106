#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<cctype>
#include"tokenscanner.h"
#include<assert.h>
#include<stack>
using namespace std;


double cal(double lhs, double rhs, string op) {
    char o = op[0];
    switch (o)
    {
    case '+':
        return lhs + rhs;

    case '-':
        return lhs - rhs;
    
    case '*':
        return lhs * rhs;
    case '/':
        return lhs / rhs;

    default:
        break;
    }
    return 0;
}

int main() {
    
    while(true) {
        string line;
        getline(cin, line);
        TokenScanner scanner(line);
        scanner.ignoreWhitespace();
        scanner.scanNumbers();

        stack<string> st;
        while(scanner.hasMoreTokens()) {
            string token = scanner.nextToken();
            if(isdigit(token[0])) {
                if(st.empty()) {
                    st.push(token);
                } else {
                    assert(st.size() == 2);
                    assert(!isdigit(st.top()[0]));
                    string op = st.top();
                    st.pop();
                    double lhs = stod(st.top());
                    double rhs = stod(token);
                    st.pop();
                    st.push(to_string(cal(lhs, rhs, op)));
                }
            } else {
                assert(st.size() == 1);
                assert(token.length() == 1);
                st.push(token);
            }
            // cout << token << endl;
        }
        double res = stod(st.top());
        if(abs(res - int(res)) > 0.00001) {
            cout << res << endl;
        } else {
            cout << (int) res << endl;
        }
    }
}