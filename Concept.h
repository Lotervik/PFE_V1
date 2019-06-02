#ifndef CONCEPT_H
#define CONCEPT_H
#include<iostream>
#include<Clifford.h>
using namespace std;
class Concept
{
public:
    Concept();
    Concept(string __concept__);
    string toString();
    string concept_onto;
    string definition;
    Clifford cl;
};

#endif // CONCEPT_H
