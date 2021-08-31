#include "scacchiera.h"
#include "TuttiPezzi.h"
Scacchiera::Scacchiera()
    :chiera(8, Vector<DeepPtr<Pezzo>>(8))
{
}

COLORE Scacchiera::occupata(int row, int col) const
{
    if(chiera[row][col] == nullptr)
    {
        return VUOTO;
    }
    return (*(chiera[row][col])).getIsWhite() ? BIANCO : NERO;
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
        chiera[1][i] = new Pedone(this, true, Coppia<int>(1,i));
    }

    //pedoni neri
    for(int i = 0; i < 8; ++i)
    {
        chiera[6][i] = new Pedone(this, false, Coppia<int>(6, i));
    }

    //pezzi bianchi
    chiera[0][0] = new Torre(this, true, Coppia<int>(0, 0));
    chiera[0][1] = new Cavallo(this, true, Coppia<int>(0, 1));
    chiera[0][2] = new Alfiere(this, true, Coppia<int>(0, 2));
    chiera[0][3] = new Donna(this, true, Coppia<int>(0, 3));
    chiera[0][4] = new Re(this, true, Coppia<int>(0, 4));
    chiera[0][5] = new Alfiere(this, true, Coppia<int>(0, 5));
    chiera[0][6] = new Cavallo(this, true, Coppia<int>(0, 6));
    chiera[0][7] = new Torre(this, true, Coppia<int>(0, 7));

    //pezzi neri
    chiera[7][0] = new Torre(this, false, Coppia<int>(7, 0));
    chiera[7][1] = new Cavallo(this, false, Coppia<int>(7, 1));
    chiera[7][2] = new Alfiere(this, false, Coppia<int>(7, 2));
    chiera[7][3] = new Donna(this, false, Coppia<int>(7, 3));
    chiera[7][4] = new Re(this, false, Coppia<int>(7, 4));
    chiera[7][5] = new Alfiere(this, false, Coppia<int>(7, 5));
    chiera[7][6] = new Cavallo(this, false, Coppia<int>(7, 6));
    chiera[7][7] = new Torre(this, false, Coppia<int>(7, 7));
}
