#define _USE_MATH_DEFINES

const double C = 3e8;

#include <cmath>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

double distance(pair<double,double> p1,pair<double,double> p2){
    double x1 = p1.first, y1 = p1.second;
    double x2 = p2.first, y2 = p2.second;
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double computeTime(pair<double,double> R, pair<double,double> T){
    double d = distance(R,T);
    return d/C;
}

int main(){
    pair<double,double> R1={0,0}, R2={100,1200}, R3={0,1000};
    pair<double,double> T={400,300};
    double toa1 = computeTime(R1,T);
    double toa2 = computeTime(R2,T);
    double toa3 = computeTime(R3,T);
    cout<<"Time of Arrival at R1: "<<toa1<<" seconds"<<endl;
    cout<<"Time of Arrival at R2: "<<toa2<<" seconds"<<endl;   
    cout<<"Time of Arrival at R3: "<<toa3<<" seconds"<<endl;

    cout<<"TDOA between R1 and R2: "<<toa1-toa2<<" seconds"<<endl;
    cout<<"TDOA between R1 and R3: "<<toa1-toa3<<" seconds"<<endl;
    cout<<"TDOA between R2 and R3: "<<toa2-toa3<<" seconds"<<endl;
    return 0;
}
