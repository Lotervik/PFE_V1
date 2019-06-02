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


}

string Concept::toString()
{
    return this->definition+"="+this->concept_onto+this->cl.toString();
}
