#include "alfiere.h"
#include "scacchiera.h"
Alfiere::Alfiere(const Scacchiera *owner, bool x)
    :Pezzo(owner, x, x ? 'B' : 'b')
{

}

Vector<std::pair<int, int>> Alfiere::canMove(int row, int col)
{
    Vector<std::pair<int, int>> ret;
    bool fin = false;

    //up left
    for(int i = 1; board->valido(row - i, col - i) && !fin; ++i)
    {
        fin = isThisMoveGood(row - i, col - i, &ret);
    }

    fin = false;

    //up right
    for(int i = 1; board->valido(row - i, col + i) && !fin; ++i)
    {
        fin = isThisMoveGood(row - i, col + i, &ret);
    }

    fin = false;

    //down left
    for(int i = 1; board->valido(row + i, col - i) && !fin; ++i)
    {
        fin = isThisMoveGood(row + i, col - i, &ret);
    }

    fin = false;

    //down right
    for(int i = 1; board->valido(row + i, col + i) && !fin; ++i)
    {
        fin = isThisMoveGood(row + i, col + i, &ret);
    }

    return ret;
}

Alfiere * Alfiere::clone() const
{
    return new Alfiere(*this);
}
