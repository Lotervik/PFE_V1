#include "Synonyme.h"

Synonyme::Synonyme()
{

}

Synonyme::Synonyme(string mot)
{
    _mot_=mot;
}

void Synonyme::ajouterSynonyme(string mot)
{
    _synonymes_.push_back(mot);
}

void Synonyme::clear()
{
    _mot_="";
    _synonymes_.clear();
}
