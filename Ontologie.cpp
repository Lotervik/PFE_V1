#include "Ontologie.h"




ontologie::ontologie(string nom):nom(nom)
{

}

void ontologie::ajouterConcept(string __concept__)
{
    string nomConcept;
    unsigned long long var;
    for (var = 0; var < __concept__.size(); ++var) {
        if(__concept__[var]=='=') break;
        else nomConcept+=__concept__[var];
    }

    Concept __Concept__;
    __Concept__.concept_onto = __concept__.substr(var+1,__concept__.size());
    __Concept__.definition = nomConcept;
    __Concept__.toClifford();
    liste_onto.push_back(__Concept__);
}

void ontologie::ajouterConcept(Concept __Concept__)
{

    liste_onto.push_back(__Concept__);
}

void ontologie::afficherOnto()
{
    Concept c;
    for (unsigned long long var = 0; var < liste_onto.size(); ++var) {
       cout << liste_onto[var].toString()<<endl;
    }
}

