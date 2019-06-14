#ifndef ROLE_H
#define ROLE_H

#include<iostream>
using namespace std;
class Role
{
public:
    Role();
    Role(string role,string dom,string min,string max,string pc);

    string role,dom,min,max,pc;
};

#endif // ROLE_H
