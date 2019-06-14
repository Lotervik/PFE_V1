#include "mainwindow.h"
#include <QApplication>
#include<ontologie.h>
int main(int argc, char *argv[])
{

    /*QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();*/
    ontologie o1("o1"),o2("o2");
    o1.ajouterConcept("Personne=humain^animal^MIN 4^$perglknkl uhj");
    o1.ajouterConcept("walid=Personne^torau");
    o1.ajouterConcept("ana=Personne^walid^MAX 6");
    o1.ajouterConcept("ana2=oiyj^khjnd");
    o1.ajouterConcept("ryad");
    o1.ajouterConcept("omjlfe=Personne^tgukiu");
    //o1.transformerOnto();
    o1.afficherOnto();
    o1.afficherListeConceptOnto();

    Concept c,a("Personne=humain^nola^MIN 4"),
            b("ana=humain^anis^MAX 6");
    cout<<a.toString()<<endl;
    cout<<b.toString()<<endl;
    cout<<"SIM(a,b)= "<<c.calculeSimilarite(a,b);


    return 0;
}
