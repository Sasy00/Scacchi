#include "mainwindow.h"
#include "scacchiera.h"
#include <QApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    Scacchiera s;
    s.reset();
    for(int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            DeepPtr<Pezzo> arg = s.getPezzo(i,j);
            if(!(arg == nullptr))
                std::cout<<((*arg).getRepr());
        }
        std::cout<<std::endl;
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.setScacchiera(&s);
    w.caricaImmagini();
    w.refreshPezzi();
    w.show();
    return a.exec();
}
