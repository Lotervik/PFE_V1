#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include<fstream>
#include<vector>
#include<Synonyme.h>
using namespace std;

class Dictionnaire
{
public:
    Dictionnaire();
    Dictionnaire(string chemin);
    Synonyme chercher(string s);
    vector<Synonyme> _dict_;

private :
    ifstream _dict_file_;

};

#endif // DICTIONNAIRE_H
