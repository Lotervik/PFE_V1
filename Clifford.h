#ifndef CLIFFORD_H
#define CLIFFORD_H

#include<iostream>
using namespace std;

class Clifford
{
public:
    Clifford();
    Clifford(string ch);
    Clifford(string dom,string min,string max,string pc);
    static Clifford UnionCL(Clifford &a,Clifford &b);
    string toString();

    string dom,pc;
    string min,max;

private :
    double maximum(double a,double b);
    double minimum(double a,double b);
};

#endif // CLIFFORD_H
