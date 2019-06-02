#include "Ontologie.h"




ontologie::ontologie(string nom):nom(nom)
{

}

void ontologie::ajouterConcept(string __concept__)
{
    Concept __Concept__;
    __Concept__.concept_onto=__concept__;
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

