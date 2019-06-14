#include "Clifford.h"
#include<vector>
#include<iostream>
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
    string roleR,roleC;
    unsigned long long cpt=0;
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
        Role role1;
        if(v[j].at(0)=='$'){
            cpt=0;
            for (unsigned long long var = 0; var < v[j].size(); ++var) {
                if(v[j].at(var)==' ') break;
                roleR+=v[j].at(var);
                cpt++;
            }
            cl.r.pc=v[j].substr(cpt+1,v[j].size());
            cl.r.role=roleR;

        } else if(v[j].at(0)=='M'&&v[j].at(1)=='I'&&v[j].at(2)=='N') cl.min=v[j].substr(3,v[j].size());
        else if(v[j].at(0)=='M'&&v[j].at(1)=='A'&&v[j].at(2)=='X') cl.max=v[j].substr(3,v[j].size());
        else cl.pc=v[j];

        c.push_back(cl);
    }

    for(unsigned long long j=0; j<c.size(); j++) {
        cl1=UnionCL(cl1,c[j]);
    }

    this->dom=cl1.dom;
    this->pc=cl1.pc;
    this->min=cl1.min;
    this->max=cl1.max;
    this->r=cl1.r;
}

Clifford::Clifford(string dom, string min, string max, string pc,string role)
{
    string roleR;
    Role leRole;
    unsigned long long cpt=0;


    this->dom=dom;
    this->pc=pc;
    this->max=max;
    this->min=min;
    if(role!="") {
        for (unsigned long long var = 0; var < role.size(); ++var) {
            if(role.at(var)==' ') break;
            roleR+=role.at(var);
            cpt++;
        }
        leRole.pc=role.substr(cpt+1,role.size());
        leRole.role=roleR;
        this->r=leRole;
    }


}

Clifford Clifford::UnionCL(Clifford &a, Clifford &b)
{

    Clifford c("","","","","");

    if(a.dom=="UNIV" || b.dom=="UNIV" ) c.dom="UNIV";
    else if(a.dom!=""&&b.dom!="") c.dom=a.dom+'.'+b.dom;
         else if (a.dom!="") { c.dom=a.dom; }
              else c.dom=b.dom;

    if (a.min=="") c.min=b.min;
    else if (b.min=="") c.min=a.min;
         else c.min=std::to_string(c.maximum(stod(a.min),stod(b.min)));

    if (a.max=="") c.max=b.max;
    else if (b.max=="") c.max=a.max;
         else c.max=std::to_string(c.minimum(stod(a.max),stod(b.max)));


    if(a.pc!=""&&b.pc!="") c.pc=a.pc+","+b.pc;
    else if(a.pc!="") c.pc=a.pc;
         else c.pc=b.pc;

    /*----------------Pour le Role ---------------*/
    if(a.r.role==b.r.role){
    if(a.r.max=="") c.r.max=b.r.max;
    else if (b.r.max=="") c.r.max=a.r.max;
         else c.r.max=std::to_string(c.minimum(stod(a.r.max),stod(b.r.max)));

    if (a.r.min=="") c.r.min=b.r.min;
        else if (b.r.min=="") c.r.min=a.r.min;
             else c.r.min=std::to_string(c.maximum(stod(a.r.min),stod(b.r.min)));

    if(a.r.dom=="UNIV" || b.r.dom=="UNIV" ) c.r.dom="UNIV";
        else if(a.r.dom!=""&& b.r.dom!="")  c.r.dom=a.r.dom+'.'+b.r.dom;
             else if (a.r.dom!="") { c.r.dom=a.r.dom; }
                  else c.r.dom=b.r.dom;

    if(a.r.pc!=""&& b.r.pc!="") c.r.pc=a.r.pc+"-"+b.r.pc;
       else if(a.r.pc!="") c.r.pc=a.r.pc;
            else c.r.pc=b.r.pc;
    }
    return c;
}

bool Clifford::comparer(Clifford a, Clifford b,int &i)
{
    if(a.dom!=b.dom || a.min!=b.min || a.max!=b.max || a.pc!=b.pc)
        return false;
    else /* mzl kayen khedma hna :p */
        return true;
}

string Clifford::toString() {
    if(r.role==""){
    if(min==""&& max==""&&pc=="") return "b0\n";
    if(min==""&& max=="")   return "< " + dom + ", MIN-R , MAX-R, {" + pc + "} , Null >\n";
        else if (min=="")   return "< " + dom + ", MIN-R , " + max + " , {" + pc + "} , Null >\n";
                 else  if(max=="") return "< " + dom + ", " + min + " , MAX-R , {" + pc + "} , Null >\n";
                        else return "< " + dom + ", " + min + " , "+max+" , {" + pc + "} , Null >\n";
    }else {
        if(min==""&& max==""&&pc=="") return "<  UNIV , MIN-R , MAX-R, Null , {< "+r.role+" , "+r.dom+" , "+r.min+" , "+r.max+" , "+r.pc+" >} >\n";
        if(min==""&& max=="")   return "<  " + dom + " , MIN-R , MAX-R, {" + pc + "} , {< "+r.role+" , "+r.dom+" , "+r.min+" , "+r.max+" , "+r.pc+" >} >\n";

            else if (min=="")   return "<  " + dom + " , MIN-R , "+max+", {" + pc + "} , {< "+r.role+" , "+r.dom+" , "+r.min+" , "+r.max+" , "+r.pc+" >} >\n";

                     else  if(max=="") return "<  " + dom + " , "+min+" , MAX-R , {" + pc + "} , {< "+r.role+" , "+r.dom+" , "+r.min+" , "+r.max+" , "+r.pc+" >} >\n";
                            else return "<  " + dom + " , "+min+" , "+max+", {" + pc + "} , {< "+r.role+" , "+r.dom+" , "+r.min+" , "+r.max+" , "+r.pc+" >} >\n";
    }
}

int Clifford::cardinalite()
{
    /* mzl*/
    int i=0;
    if(this->pc=="") return 0;
    for (unsigned long long var = 0; var < this->pc.size(); ++var) {
        if(this->pc[var]==',') i++;
    }
    return i+1;
}

double Clifford::maximum(double a, double b)
{
     if(a>b) return a; else return b;
}

double Clifford::minimum(double a, double b)
{
     if(a<b) return a; else return b;
}
