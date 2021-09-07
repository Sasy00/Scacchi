#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include <QAction>
#include <QCoreApplication>
#include <string>
#include <iostream>
#include "QDir"
#include <QFileDialog>
#include "QTextStream"
#include <sstream>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
   ,mapper(new QSignalMapper(this)),model(new Model()), firstClick(nullptr)
{
    ui->setupUi(this);
    connect(ui->actionEsci, SIGNAL(triggered(bool)), this, SLOT(quit()));
    connect(ui->actionCarica_Partita, SIGNAL(triggered(bool)), this, SLOT(carica()));
    connect(ui->actionSalva_Partita, SIGNAL(triggered(bool)), this, SLOT(salva()));
    connect(ui->actionRicomincia, SIGNAL(triggered(bool)), this, SLOT(ricomincia()));
    model->init();
    caricaImmagini();
    creaScacchiera();
    ui->plainTextEdit->setPlainText("");
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
            Model::STATE res;
            res = model->move(*firstClick, std::pair<int, int>(row, col));
            segnaMossa(firstClick->first, firstClick->second, row, col);
            delete firstClick;
            firstClick = nullptr;
            refreshPezzi();
            switch(res)
            {
                case Model::PATTA:
                    ui->fondotesto->setText("La partita è PATTA!");
                    break;
                case Model::BIANCO:
                    ui->fondotesto->setText("Vince il BIANCO!");
                    break;
                case Model::NERO:
                    ui->fondotesto->setText("Vince il NERO!");
                    break;
                default:
                    break;
             }
        }
        else
        {

            if(model->getPieceMoves(row, col).size() > 0)
            {
                delete firstClick;
                firstClick = nullptr;
                handleMove(x);
            }
            else
            {
                delete firstClick;
                firstClick = nullptr;
            }
            /*
            delete firstClick;
            firstClick = nullptr;
            */
        }
    }

}

void MainWindow::segnaMossa(int m1, int m2, int m3, int m4){
    QString s;
    s.clear();
    ui->plainTextEdit->moveCursor (QTextCursor::End);
    if(!model->getTurnWhite()){
        s.append(QString::number(model->getnMossa()));
        s.append(". ");
        s.append(char(m2+'a'));
        s.append(char((m1+1)+'0'));
        s.append(char(m4+'a'));
        s.append(char((m3+1)+'0'));
        ui->plainTextEdit->insertPlainText(s);
        ui->fondotesto->setText("Tocca al Nero");
    }
    else{
        s.append(' ');
        s.append(char(m2+'a'));
        s.append(char((m1+1)+'0'));
        s.append(char(m4+'a'));
        s.append(char((m3+1)+'0'));
        s.append('\n');
        ui->plainTextEdit->insertPlainText(s);
        ui->fondotesto->setText("Tocca al Bianco");
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

void MainWindow::carica(){
    QString filename = QFileDialog::getOpenFileName(this,tr("Carica Partita"),"", tr("Partita (*.LPGN)"));
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    std::string gamestring;
    while (!file.atEnd()) {
        gamestring = file.readAll().toStdString();
    }
    file.close();
    if(gamestring.size() < 7)
        return;
    ricomincia();

    ui->plainTextEdit->setPlainText(gamestring.c_str());

    std::stringstream ss(gamestring);
    std::string nmoveS;
    std::string whiteMove;
    std::string blackMove;

    while(!ss.eof())
    {
        ss >> nmoveS;
        ss >> whiteMove;
        model->move(std::pair<int, int>(whiteMove[1] - '1', whiteMove[0] - 'a'), std::pair<int, int>(whiteMove[3] - '1', whiteMove[2] - 'a'));
        if(!ss.eof())
        {
            ss >> blackMove;
            model->move(std::pair<int, int>(blackMove[1] - '1', blackMove[0] - 'a'), std::pair<int, int>(blackMove[3] - '1', blackMove[2] - 'a'));
        }
    }
    refreshPezzi();
}

void MainWindow::salva(){
    QString filename = QFileDialog::getSaveFileName(this,tr("Salva Partita"), "", tr("Partita (*.LPGN)"));
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << ui->plainTextEdit->toPlainText();
    file.close();
}

void MainWindow::ricomincia(){
    model->reset();
    resetColors();
    delete firstClick;
    firstClick = nullptr;
    ui->plainTextEdit->setPlainText("");
    refreshPezzi();
}
