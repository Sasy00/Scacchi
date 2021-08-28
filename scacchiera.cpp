#include "scacchiera.h"

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
    /*
    for(int i = 0; i < 8; ++i)
    {
    }
    */
}
