#include "mainwindow.h"
#include "scacchiera.h"
#include <QApplication>
#include <iostream>

std::pair<std::pair<char, int>,std::pair<char, int>> stringToTwoPairs(const char *s)
{
    //format XX YY
    std::pair<char, int> src(s[0],s[1] - '0');
    std::pair<char, int> dest(s[3], s[4] - '0');
    return std::pair<std::pair<char, int>,std::pair<char, int>>(src, dest);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.refreshPezzi();
    return a.exec();
}
