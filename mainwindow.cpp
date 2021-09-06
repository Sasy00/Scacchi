#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include <string>
#include <iostream>
#include "QDir"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
   ,mapper(new QSignalMapper(this)),model(new Model()), firstClick(nullptr)
{
    ui->setupUi(this);
    model->init();
    caricaImmagini();
    creaScacchiera();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete mapper;
    delete firstClick;
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            delete casella[i][j];
        }
    }
}




void MainWindow::creaScacchiera()
{
    bool alternato = true;

    for(int i = 0; i < 8; ++i){
        for(int y = 0; y < 8; ++y){
            casella[i][y] = new ClickableLabel(this);
            casella[i][y]->setGeometry(50+(y*dim),50+((7-i)*dim),dim,dim);
            casella[i][y]->setAutoFillBackground(true);
            if(alternato)
                casella[i][y]->setStyleSheet("QLabel { background-color : black}");
            else
                casella[i][y]->setStyleSheet("QLabel { background-color : white}");
            alternato = !alternato;
            casella[i][y]->show();

            connect(casella[i][y], SIGNAL(clicked()), mapper, SLOT(map()));
            mapper->setMapping(casella[i][y], index(i, y, 8));
        }
        alternato = !alternato;
    }
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleMove(int)));
}


void MainWindow::refreshPezzi()
{
    const int red = 15;
    Vector<Repr> v = model->getBoardRepr();

    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            casella[i][j]->clear();
        }
    }

    for(int i = 0; i < v.size(); ++i)
    {
        char tipo = std::toupper(v[i].pezzo);
        char colore = std::toupper(v[i].colore);
        int row = v[i].pos.first;
        int col = v[i].pos.second;
        casella[row][col]->setPixmap(immagini[getImageIndex(colore,tipo)].scaled(dim-red,dim-red,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        casella[row][col]->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }

}

void MainWindow::caricaImmagini(){
    std::string path = QDir::currentPath().toStdString();
    path += "\\debug\\pezzi\\";
    immagini[0].load(QString((path + std::string("WP.png")).c_str()));
    immagini[1].load(QString((path + std::string("BP.png")).c_str()));
    immagini[2].load(QString((path + std::string("WR.png")).c_str()));
    immagini[3].load(QString((path + std::string("BR.png")).c_str()));
    immagini[4].load(QString((path + std::string("WB.png")).c_str()));
    immagini[5].load(QString((path + std::string("BB.png")).c_str()));
    immagini[6].load(QString((path + std::string("WN.png")).c_str()));
    immagini[7].load(QString((path + std::string("BN.png")).c_str()));
    immagini[8].load(QString((path + std::string("WQ.png")).c_str()));
    immagini[9].load(QString((path + std::string("BQ.png")).c_str()));
    immagini[10].load(QString((path + std::string("WK.png")).c_str()));
    immagini[11].load(QString((path + std::string("BK.png")).c_str()));
}

int MainWindow::getImageIndex(char colore, char tipo) const{

    switch(tipo){
        case 'P':
            if(colore == 'W')
                return 0;
            else return 1;
            break;
        case 'R':
            if(colore == 'W')
                return 2;
            else return 3;
            break;
        case 'B':
            if(colore == 'W')
                return 4;
            else return 5;
            break;
        case 'N':
            if(colore == 'W')
                return 6;
            else return 7;
            break;
        case 'Q':
            if(colore == 'W')
                return 8;
            else return 9;
            break;
        case 'K':
            if(colore == 'W')
                return 10;
            else return 11;
            break;
    }

    return 0;
}

void MainWindow::handleMove(int x)
{
    resetColors();
    Vector<std::pair<int, int>> moves;
    std::pair<int, int> pos = rowcol(x, 8);
    int row = pos.first;
    int col = pos.second;
    moves = model->getPieceMoves(row, col);
    if(!firstClick)
    {
        if(moves.size() != 0)
        {
            firstClick = new std::pair<int, int>(row, col);
            for(int i = 0; i < moves.size(); ++i)
            {
                casella[moves[i].first][moves[i].second]->setStyleSheet("QLabel { background-color : red}");
            }
        }
    }
    else
    {

        bool trovato = false;
        Vector<std::pair<int, int>> oldPieceMoves = model->getPieceMoves(firstClick->first, firstClick->second);
        for(int i = 0; i < oldPieceMoves.size() && !trovato; ++i)
        {
            trovato = oldPieceMoves[i] == std::pair<int, int>(row, col);
        }
        if(trovato)
        {
            model->move(*firstClick, std::pair<int, int>(row, col));
            delete firstClick;
            firstClick = nullptr;
            refreshPezzi();
        }
        else
        {
            /*
            if(model->getPieceMoves(row, col).size() > 0)
            {
                delete firstClick;
                firstClick = new std::pair<int, int>(row, col);
            }
            else
            {
                delete firstClick;
                firstClick = nullptr;
            }
            */
            delete firstClick;
            firstClick = nullptr;
        }
    }

}

void MainWindow::resetColors()
{
    bool alternato = true;
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(alternato)
                casella[i][j]->setStyleSheet("QLabel { background-color : black}");
            else
                casella[i][j]->setStyleSheet("QLabel { background-color : white}");
            alternato = !alternato;
        }
        alternato = !alternato;
    }
}
