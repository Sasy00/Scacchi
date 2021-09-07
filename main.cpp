#include "mainwindow.h"
#include "scacchiera.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.refreshPezzi();
    return a.exec();
}
