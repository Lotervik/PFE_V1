#include "clifford.h"
#include<vector>
Clifford::Clifford()
{

}

Clifford::Clifford(string ch)
{
    vector<string> v;
    vector<Clifford> c;
    string sh;
    Clifford cl;
    Clifford cl1;
    for(int i =0;i<ch.length();i++){

        if(ch.at(i)!=' '&& ch.at(i)!='^')  { sh+=ch.at(i);  }
        else if(ch.at(i)!=' ') {v.push_back(sh);   sh="";}
    }
    if(sh!="") v.push_back(sh);

    for(int j=0; j<v.size(); j++){
        cl.dom="UNIV";
        cl.pc=v[j];
        c.push_back(cl);
    }

     for(unsigned long long j=0; j<c.size(); j++) {

         //std::cout <<c[j].toString()<<endl;
         cl1=UnionCL(cl1,c[j]);

     }
    cout<<"cl1=="<<cl1.toString();
    this->dom=cl1.dom;
    this->pc=cl1.pc;
    this->min=cl1.min;
    this->max=cl1.max;
}

Clifford::Clifford(string dom, double min, double max, string pc)
{
    this->dom=dom;
    this->pc=pc;
    this->max=max;
    this->min=min;

}

Clifford Clifford::UnionCL(Clifford &a, Clifford &b)
{
    Clifford c("",0,0,"");

    if(a.dom=="UNIV" || b.dom=="UNIV" ) c.dom="UNIV";
    else if(a.dom!=""&&b.dom!="") c.dom=a.dom+'.'+b.dom;
        else if (a.dom!="") {
            c.dom=a.dom;
        } else c.dom=b.dom;

    c.min=c.maximum(a.min,b.min);
    c.max=c.minimum(a.max,b.max);

    if(a.pc!=""&&b.pc!="") c.pc=a.pc+"-"+b.pc;
    else if(a.pc!="") c.pc=a.pc;
         else c.pc=b.pc;
    return c;
}

string Clifford::toString() {
    return "< " + dom + " , " + std::to_string(min) + " , " + std::to_string(max) + " , {" + pc + "} >\n";
}

double Clifford::maximum(double a, double b)
{
     if(a>b) return a; else return b;
}

double Clifford::minimum(double a, double b)
{
     if(a<b) return a; else return b;
}
