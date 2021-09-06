#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <qsignalmapper.h>
#include "clickablelabel.h"
#include "model.h"
#include <utility>
#include <QCoreApplication>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void setScacchiera(Scacchiera *s);
    void creaScacchiera();
    void refreshPezzi();
    void caricaImmagini();
    void segnaMossa(int m1, int m2, int m3, int m4);

private:
    Ui::MainWindow *ui;
    QSignalMapper *mapper;
    int getImageIndex(char, char) const;
    ClickableLabel *casella[8][8];
    const int dim = 65;
    QPixmap immagini [12];
    Model *model;

    std::pair<int, int> *firstClick;

    void resetColors();

    inline static int index(int row, int col, int dim)
    {
        return row * dim + col;
    }

    inline static std::pair<int, int> rowcol(int i, int dim)
    {
        std::pair<int,int> ret;
        ret.first = i / dim;
        ret.second = i % dim;
        return ret;
    }

private slots:
    void handleMove(int x);
    inline void quit(){QCoreApplication::quit();}
    void carica();
    void salva();
    void ricomincia();

};
#endif // MAINWINDOW_H
