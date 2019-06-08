#include "Ontologie.h"
#include<list>



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
    if(var<__concept__.size())
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

void ontologie::afficherListeConceptOnto()
{
    cout<<"\nles concepts : "<<endl;
    for (unsigned long long var = 0; var < liste_onto.size(); ++var) {
        cout<<liste_onto[var].definition<<endl;
    }
}

void ontologie::transformerOnto()
{

    string mot_Typeowl="",mot_TypeRdf="",mot_nomClasse;
    string chGlob="";
    cout<<"BONJOUR :";
    cin>>chGlob;

    list<string> a;
    for (unsigned long long var = 0; var < chGlob.size(); ++var) {
        if(chGlob[var]=='<')
        {
            for (unsigned long long var2 = var; var2 < chGlob.size(); ++var2) {
                if(chGlob[var2]==' ') break;
                else mot_Typeowl+=chGlob[var2];
            }
            if(mot_Typeowl=="owl:Class") {
                for (unsigned long long var3 = var+9; var3 < chGlob.size(); ++var3) {
                    if(chGlob[var3]=='<')
                    {    for (unsigned long long var2 = var3+1; var2 < chGlob.size(); ++var2) {
                            if(chGlob[var2]==' ') break;
                            else mot_TypeRdf+=chGlob[var2];
                        }
                        if(mot_TypeRdf=="rdfs:label"){/*chercher le nom de la classe */
                            for (unsigned long long var = var3+1; var < chGlob.size(); ++var) {
                                if(chGlob[var]=='>')
                                    for (unsigned long long var2 = var3+1; var2 < chGlob.size(); ++var2) {
                                        if(chGlob[var2]=='<')  {cout <<mot_nomClasse<<endl; break;}
                                        else mot_nomClasse+=chGlob[var2];
                                    }
                                }
                            }
                     }
                    }
                    }
                }
            }
            if(mot_Typeowl=="owl:") {

            }
            if(mot_Typeowl=="owl:") {

            }
        }






















