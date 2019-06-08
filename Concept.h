#ifndef CONCEPT_H
#define CONCEPT_H
#include<iostream>
#include<Clifford.h>
using namespace std;
const int __Max_Size_affichage__=60;

class Concept
{
public:
    Concept();
    Concept(string __concept__);
    string toString();
    void toClifford();
    bool subsumption(Concept &c,Concept &d);


    string concept_onto;
    string definition; // le nom du concept
    Clifford cl;
};

#endif // CONCEPT_H
