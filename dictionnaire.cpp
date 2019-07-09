#include "dictionnaire.h"
#include<iostream>

Dictionnaire::Dictionnaire()
{


}

Dictionnaire::Dictionnaire(string chemin)
{
    char c;
    string mot="";
    Synonyme syn;
    _dict_file_.open(chemin);
    if(_dict_file_){
        while (_dict_file_.get(c)) {
            switch (c) {
            case ' ':
                break;
            case '\n':
                break;

            case ':':   syn._mot_=mot;
                        mot="";
                break;

            case ';':   syn.ajouterSynonyme(mot);
                        _dict_.push_back(syn);
                        syn.clear();
                        mot="";
                break;

            case ',': syn.ajouterSynonyme(mot);
                        mot="";
                break;

            default:mot+=c;
            }
        }

    } else {

    }
}

Synonyme Dictionnaire::chercher(string s)
{
    Synonyme syn("");
    for (unsigned long long var = 0; var < _dict_.size(); ++var) {
        if(_dict_.at(var)._mot_==s)
            return _dict_.at(var);
    }
    return syn;
}
