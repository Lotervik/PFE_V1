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
    o1.ajouterConcept("Personne=humain^animal");
    o1.ajouterConcept("walid=Personne^torau");
    o1.ajouterConcept("ana=Personne^walid");
    o1.ajouterConcept("ana2=oiyj^khjnd");
    o1.ajouterConcept("omjlfe=Personne^torakguufyugkyigukgjuiu");
    o1.afficherOnto();


    return 0;
}
