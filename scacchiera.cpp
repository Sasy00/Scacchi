#include "scacchiera.h"
#include "TuttiPezzi.h"
Scacchiera::Scacchiera()
    :board(8, Vector<DeepPtr<Pezzo>>(8))
{
}

COLORE Scacchiera::occupata(int row, int col) const
{
    if(board[row][col] == nullptr)
    {
        return VUOTO;
    }
    return (*(board[row][col])).getIsWhite() ? BIANCO : NERO;
}

bool Scacchiera::valido(int x, int y) const
{
    return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}

void Scacchiera::reset()
{
    //pedoni bianchi
    for(int i = 0; i < 8; ++i)
    {
        board[1][i] = new Pedone(this, true, Coppia<int>(1,i));
    }

    //pedoni neri
    for(int i = 0; i < 8; ++i)
    {
        board[6][i] = new Pedone(this, false, Coppia<int>(6, i));
    }

    //pezzi bianchi
    board[0][0] = new Torre(this, true, Coppia<int>(0, 0));
    board[0][1] = new Cavallo(this, true, Coppia<int>(0, 1));
    board[0][2] = new Alfiere(this, true, Coppia<int>(0, 2));
    board[0][3] = new Donna(this, true, Coppia<int>(0, 3));
    board[0][4] = new Re(this, true, Coppia<int>(0, 4));
    board[0][5] = new Alfiere(this, true, Coppia<int>(0, 5));
    board[0][6] = new Cavallo(this, true, Coppia<int>(0, 6));
    board[0][7] = new Torre(this, true, Coppia<int>(0, 7));

    //pezzi neri
    board[7][0] = new Torre(this, false, Coppia<int>(7, 0));
    board[7][1] = new Cavallo(this, false, Coppia<int>(7, 1));
    board[7][2] = new Alfiere(this, false, Coppia<int>(7, 2));
    board[7][3] = new Donna(this, false, Coppia<int>(7, 3));
    board[7][4] = new Re(this, false, Coppia<int>(7, 4));
    board[7][5] = new Alfiere(this, false, Coppia<int>(7, 5));
    board[7][6] = new Cavallo(this, false, Coppia<int>(7, 6));
    board[7][7] = new Torre(this, false, Coppia<int>(7, 7));
}
