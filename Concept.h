#ifndef CONCEPT_H
#define CONCEPT_H
#include<iostream>
#include<Clifford.h>
#include<dictionnaire.h>
#include<vector>
using namespace std;
const int __Max_Size_affichage__=80;

class Concept
{
public:
    Concept();
    Concept(string __concept__);
    string toString();
    void toClifford();
    Concept intersect(Concept &c,Concept &d);
    bool subsumption(Concept &c,Concept &d,int &i);
    double calculeSimilarite(Concept &c,Concept &d);
    double calculSimilariteSemantique(Concept &c,Concept &d,Dictionnaire &dict);
    vector<string> extraireConcept(Concept &a);
    bool egaux(string _Concept1_,string _Concept2_,Dictionnaire &dict);

    string concept_onto;
    string definition; // le nom du concept
    Clifford cl;
};

#endif // CONCEPT_H
