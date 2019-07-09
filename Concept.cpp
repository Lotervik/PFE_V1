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
                ch2+=__concept__[j];
            }
            concept_onto=ch2;
            break;
        }
        else ch1+=__concept__[i];
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

Concept Concept::intersect(Concept &c, Concept &d)
{
    vector<string> v;
    string sh;

    string ch =c.concept_onto;
    string ch2 =d.concept_onto,res;

    for(unsigned long long i =0;i<ch.size();i++){

        if(ch.at(i)!=' '&& ch.at(i)!='^')  { sh+=ch.at(i);  }
        else if(ch.at(i)!=' ') {v.push_back(sh);   sh="";}
    }
    if(sh!="") v.push_back(sh);
    sh="";
    for(unsigned long long i =0;i<ch2.size();i++){

        if(ch2.at(i)!=' '&& ch2.at(i)!='^')  { sh+=ch2.at(i);  }
        else if(ch2.at(i)!=' ') {
            for (unsigned long long var = 0; var < v.size(); ++var) {
                if(v[var]==sh)  res+=sh+"^";
            }
            sh="";
        }
    }
    Concept cl(c.definition+"="+res.substr(0,res.size()-1));
    return cl;
}

bool Concept::subsumption(Concept &c, Concept &d ,int &i)
{
    //Clifford machi Concept

    Concept a;
    a.cl=Clifford::UnionCL(c.cl,d.cl);

    if(c.cl.toString()=="b0") {return true;}
    if(a.cl.toString()=="b0") {return false;}
    else {
        return Clifford::comparer(c.cl,a.cl,i);
    }

}

double Concept::calculeSimilarite(Concept &c, Concept &d)
{
    int i;
    double u;
     if (subsumption(c,d,i))
     {
         /*kyn probleme */
         //if(c.cl.toString()=="b0") return 1;
         return 1;
     }
     else {
         Concept a,x;
         a.cl=Clifford::UnionCL(c.cl,d.cl);

         if(a.cl.toString()=="b0") return 0;
         else {
            x = x.intersect(c,d);
            double i=x.cl.cardinalite();
            double v = std::max(c.cl.cardinalite(),d.cl.cardinalite());
            u=i/v ;
            return u;
         }
     }
}

double Concept::calculSimilariteSemantique(Concept &c, Concept &d,Dictionnaire &dict)
{

    vector<string> _C_Concept_ = extraireConcept(c);
    vector<string> _D_Concept_ = extraireConcept(d);
    string _c,_d;
    bool p;
    int _sommmeConceptegaux_=0, i;
    if(!_C_Concept_.empty())
    {

        _c=_C_Concept_.at(0);
        i=0;
        while(_C_Concept_.size()!=0 && !p && i>=_C_Concept_.size()){
            if(egaux(_c,_D_Concept_.at(i),dict))
            {
                _D_Concept_.erase(_D_Concept_.begin()+i);
                p=true;
                _sommmeConceptegaux_++;
            }
            i++;

        }
    return (double) _sommmeConceptegaux_/std::max(_C_Concept_.size(),_D_Concept_.size());
}

}

vector<string> Concept::extraireConcept(Concept &a)
{
    vector<string> v;
    string __nonConcept__;
    for (unsigned long long var = 0; var < a.cl.pc.size(); ++var) {
        if(a.cl.pc.at(var)==',')  { v.push_back(__nonConcept__);  __nonConcept__=""; }
        else __nonConcept__ += a.cl.pc.at(var);
    }
    if(__nonConcept__ != "") v.push_back(__nonConcept__);
    return v;
}

bool Concept::egaux(string _Concept1_, string _Concept2_,Dictionnaire &dict)
{
    Synonyme syn;
    syn=dict.chercher(_Concept1_);
    if (_Concept1_==_Concept2_) return true;
    if(syn._mot_!=""){
        for (int unsigned long long var = 0; var < syn._synonymes_.size(); ++var) {
            if(_Concept2_==syn._synonymes_.at(var)) return true;
        }
    }
    return false;
}


