#ifndef CLIFFORD_H
#define CLIFFORD_H
#include<Role.h>
#include<iostream>
using namespace std;

class Clifford
{
public:
    Clifford();
    Clifford(string ch);
    Clifford(string dom,string min,string max,string pc, string role);
    static Clifford UnionCL(Clifford &a,Clifford &b);
    static bool comparer(Clifford a , Clifford b, int &i);
    string toString();
    int cardinalite();

    string dom,pc;
    string min,max;
    Role r;

private :
    double maximum(double a,double b);
    double minimum(double a,double b);
};

#endif // CLIFFORD_H
