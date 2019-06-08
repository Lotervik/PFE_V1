#include "Concept.h"

Concept::Concept()
{

}

Concept::Concept(string __concept__)
{
    string ch1,ch2;
    for (unsigned long long i = 0; i < __concept__.size(); ++i) {
        if(__concept__[i]=='=')
        {
            definition=ch1;
            for (unsigned long long j = i+1; j < __concept__.size(); ++j) {
                ch2=__concept__[j];
            }
            concept_onto=ch2;
            break;
        }
        else ch1=__concept__[i];
    }
    this->toClifford();



}

string Concept::toString()
{
    string ch = this->definition+" = "+this->concept_onto;
    for (unsigned long long var = 0; var < __Max_Size_affichage__-definition.size()-concept_onto.size(); ++var) {
        ch+=" ";
    }
    return ch+this->cl.toString();
}

void Concept::toClifford()
{

    Clifford cl1(this->concept_onto);

    this->cl=cl1;
}

bool Concept::subsumption(Concept &c, Concept &d)
{
    Concept a;
    a.cl=Clifford::UnionCL(c.cl,d.cl);
    if(c.cl.toString()=="b0") return true;
    else if(a.cl.toString()=="b0") return false;
    else {

    }
    return true;
}












