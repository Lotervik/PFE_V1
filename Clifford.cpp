#include "Clifford.h"
#include<vector>
#include<iostream>
Clifford::Clifford()
{
	/*b rabi inchalah*/
}

Clifford::Clifford(string ch)
{
    vector<string> v;
    vector<Clifford> c;
    string sh;
    Clifford cl;
    Clifford cl1;
    for(unsigned long long i =0;i<ch.length();i++){

        if(ch.at(i)!=' '&& ch.at(i)!='^')  { sh+=ch.at(i);  }
        else if(ch.at(i)!=' ') {v.push_back(sh);   sh="";}
    }
    if(sh!="") v.push_back(sh);

    for(unsigned long long j=0; j<v.size(); j++){
        cl.dom="UNIV";
        cl.min="";
        cl.max="";
        cl.pc="";
        if(v[j].at(0)=='M'&&v[j].at(1)=='I'&&v[j].at(2)=='N') cl.min=v[j].substr(3,v[j].size());
        else if(v[j].at(0)=='M'&&v[j].at(1)=='A'&&v[j].at(2)=='X') cl.max=v[j].substr(3,v[j].size());
        else cl.pc=v[j];

        c.push_back(cl);
    }

     for(unsigned long long j=0; j<c.size(); j++) {

         //std::cout <<c[j].toString()<<endl;

         cl1=UnionCL(cl1,c[j]);


     }

    this->dom=cl1.dom;
    this->pc=cl1.pc;
    this->min=cl1.min;
    this->max=cl1.max;

}

Clifford::Clifford(string dom, string min, string max, string pc)
{
    this->dom=dom;
    this->pc=pc;
    this->max=max;
    this->min=min;

}

Clifford Clifford::UnionCL(Clifford &a, Clifford &b)
{

    Clifford c("","","","");

    if(a.dom=="UNIV" || b.dom=="UNIV" ) c.dom="UNIV";
    else if(a.dom!=""&&b.dom!="") c.dom=a.dom+'.'+b.dom;
        else if (a.dom!="") {
            c.dom=a.dom;
        } else c.dom=b.dom;

    if (a.min=="") c.min=b.min;
        else if (b.min=="") c.min=a.min;
                 else c.min=std::to_string(c.maximum(stod(a.min),stod(b.min)));

    if (a.max=="") c.max=b.max;
        else if (b.max=="") c.max=a.max;
                 else c.max=std::to_string(c.minimum(stod(a.max),stod(b.max)));


    if(a.pc!=""&&b.pc!="") c.pc=a.pc+"-"+b.pc;
    else if(a.pc!="") c.pc=a.pc;
         else c.pc=b.pc;

    return c;
}

bool Clifford::comparer(Clifford a, Clifford b)
{
    if(a.dom!=b.dom || a.min!=b.min || a.max!=b.max || a.pc!=b.pc)
        return false;
    else /* mzl kayen khedma hna :p */
        return true;
}

string Clifford::toString() {
    if(min==""&& max==""&&pc==""&&dom=="") return "b0\n";
    if(min==""&& max=="")   return "< " + dom + ", MIN-R , MAX-R, {" + pc + "} >\n";
        else if (min=="")   return "< " + dom + ", MIN-R , " + max + " , {" + pc + "} >\n";
                 else  return "< " + dom + ", " + min + " , MAX-R , {" + pc + "} >\n";

}

double Clifford::maximum(double a, double b)
{
     if(a>b) return a; else return b;
}

double Clifford::minimum(double a, double b)
{
     if(a<b) return a; else return b;
}
