#ifndef SYNONYME_H
#define SYNONYME_H
#include<vector>
#include<string>
using namespace std;


class Synonyme
{
public:
    Synonyme();
    Synonyme(string mot);
    void ajouterSynonyme(string mot);
    void clear();
    string _mot_;
    vector<string> _synonymes_;
};

#endif // SYNONYME_H
