#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include"gtypes.h"
#include<vector>
#include"gwindow.h"
using namespace std;


#define N_ACROSS 50
#define N_DOWN 30
#define DELTA 67

int main() {
    vector<GPoint> vec;
    GWindow gw;

    double interval_across = gw.getWidth() / (N_ACROSS - 1);
    double interval_down = gw.getHeight() / (N_DOWN - 1);
    
    for(int i = 0; i < N_ACROSS; i++) {
        vec.push_back(GPoint(i * interval_across, 0));
    }
    for(int i = 1; i < N_DOWN - 1; i++) {
        vec.push_back(GPoint(gw.getWidth(), i * interval_down));
    }
    for(int i = N_ACROSS - 1; i >= 0; i--) {
        vec.push_back(GPoint(i * interval_across, gw.getHeight()));
    }
    for(int i = N_DOWN - 1; i >= 0; i--) {
        vec.push_back(GPoint(0, i * interval_down));
    }

    int cur = 0;
    do {
        int next = (cur + DELTA) % vec.size();
        gw.drawLine(vec[cur], vec[next]);
        cur = next;
    } while(cur != 0);
}