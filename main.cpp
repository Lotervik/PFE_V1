#include "mainwindow.h"
#include <QApplication>
#include<ontologie.h>
#include<dictionnaire.h>
int main(int argc, char *argv[])
{

    /*QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();*/
    /*ontologie o1("o1"),o2("o2");
    o1.ajouterConcept("Personne=humain^animal^MIN 4^$KADER#majorant");
    o1.ajouterConcept("walid=Personne^torau");
    o1.ajouterConcept("ana=Personne^walid^MAX 6");
    o1.ajouterConcept("ana2=oiyj^khjnd");
    o1.ajouterConcept("ryad");
    o1.ajouterConcept("omjlfe=Personne^tgukiu");
    //o1.transformerOnto();
    o1.afficherOnto();
    o1.afficherListeConceptOnto();
*/
    Concept c,a("c1=a^b^MIN 4^c^$vfoot#ball"),
            b("c2=z^y^a^MAX 6^MIN 5^$kola#dlzd");

    Dictionnaire d("C:\\Users\\Ryad\\Desktop\\dict.txt");

    cout<<a.toString()<<endl;
    cout<<b.toString()<<endl;
    cout<<"SIM(a,b)= "<<c.calculeSimilarite(a,b)<<endl;
    cout<<"SIMSEM(a,b)= "<<c.calculSimilariteSemantique(a,b,d)<<endl;


    return 0;
}
