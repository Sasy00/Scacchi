#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "scacchiera.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setScacchiera(Scacchiera *s);
    void creaScacchiera();
    void refreshPezzi();
    void caricaImmagini();
private:
    Ui::MainWindow *ui;
    Scacchiera *board;
    int getImageIndex(char, char) const;
    QLabel *casella[8][8];
    const int dim = 65;
    QPixmap immagini [12];

};
#endif // MAINWINDOW_H
