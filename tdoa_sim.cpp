#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const double C = 3e8;

double distance(pair<double,double> p1, pair<double,double> p2){
    double x1 = p1.first, y1 = p1.second;
    double x2 = p2.first, y2 = p2.second;
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

double computeTime(pair<double,double> R, pair<double,double> T){
    double d = distance(R, T);
    return d / C;
}

int main(){
    pair<double,double> R1={0,0}, R2={100,1200}, R3={0,1000};
    pair<double,double> T={400,300};
    pair<double,double> test={0,0};

    double t1 = computeTime(R1, T);
    double t2 = computeTime(R2, T);
    double t3 = computeTime(R3, T);

    double t1_p = computeTime(R1, test);
    double t2_p = computeTime(R2, test);
    double t3_p = computeTime(R3, test);

    // cout<<"Time of Arrival at R1: "<<t1<<" seconds"<<endl;
    // cout<<"Time of Arrival at R2: "<<t2<<" seconds"<<endl;   
    // cout<<"Time of Arrival at R3: "<<t3<<" seconds"<<endl;

    double noise1 = ((rand() % 100) - 50) * 1e-9;  // ±50 ns
    double noise2 = ((rand() % 100) - 50) * 1e-9;
    double noise3 = ((rand() % 100) - 50) * 1e-9;

    double tdoa_21 = t2 - t1+noise1;
    double tdoa_31 = t3 - t1+noise2;
    double tdoa_32 = t3 - t2+noise3;

    double tdoa_21_p = t2_p - t1_p;
    double tdoa_31_p = t3_p - t1_p;
    double tdoa_32_p = t3_p - t2_p;

    // cout<<"TDOA (R2 - R1): "<<tdoa_21<<" seconds"<<endl;
    // cout<<"TDOA (R3 - R1): "<<tdoa_31<<" seconds"<<endl;

    // double error = pow(tdoa_21_p - tdoa_21, 2) + pow(tdoa_31_p - tdoa_31, 2);
    // cout<<"Error at (0,0): "<<error<<endl;

    double min_error = 1e9;
    pair<double,double> best_point;

    for(int x = 0; x <= 1000; x += 10){
        for(int y = 0; y <= 1000; y += 10){

            pair<double,double> test = {x, y};

            double t1_p = computeTime(R1, test);
            double t2_p = computeTime(R2, test);
            double t3_p = computeTime(R3, test);

            double tdoa_21_p = t2_p - t1_p;
            double tdoa_31_p = t3_p - t1_p;

            double error = pow(tdoa_21_p - tdoa_21, 2) +
                        pow(tdoa_31_p - tdoa_31, 2);

            if(error < min_error){
                min_error = error;
                best_point = test;
            }
        }
    }

    cout<<"Best point: ("<<best_point.first<<", "<<best_point.second<<")"<<endl;
    cout<<"Minimum error: "<<min_error<<endl;


    return 0;
}