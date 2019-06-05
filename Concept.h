#ifndef CONCEPT_H
#define CONCEPT_H
#include<iostream>
#include<clifford.h>
using namespace std;

class Concept
{
public:
    Concept();
    Concept(string __concept__);
    string toString();
    void toClifford();

    string concept_onto;
    string definition; // le nom du concept
    Clifford cl;
};

#endif // CONCEPT_H
