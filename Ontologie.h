#ifndef ONTOLOGIE_H
#define ONTOLOGIE_H
#include<iostream>
#include<vector>
#include<Concept.h>
using namespace std;

class ontologie
{
public:

    ontologie(string nom);
    void ajouterConcept(string __concept__);
    void ajouterConcept(Concept __Concept__);
    void afficherOnto();
    string nom;
    vector<Concept> liste_onto;
};

#endif // ONTOLOGIE_H
