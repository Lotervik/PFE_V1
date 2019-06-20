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

    ifstream _dict_file_;
    vector<Synonyme> _dict_;
};

#endif // DICTIONNAIRE_H
