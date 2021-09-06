#include "cavallo.h"
#include "scacchiera.h"
Cavallo::Cavallo(const Scacchiera *owner, bool x)
    :Pezzo(owner, x, x ? 'N' : 'n')
{

}

Vector<std::pair<int, int>> Cavallo::canMove(int row, int col)
{
    Vector<std::pair<int, int>> ret;
    if(board->valido(row - 1, col - 2))
    {
        isThisMoveGood(row - 1, col - 2, &ret);
    }

    if(board->valido(row + 1, col - 2))
    {
        isThisMoveGood(row + 1, col - 2, &ret);
    }

    if(board->valido(row + 1, col + 2))
    {
        isThisMoveGood(row + 1, col + 2, &ret);
    }

    if(board->valido(row - 1, col + 2))
    {
        isThisMoveGood(row - 1, col + 2, &ret);
    }

    if(board->valido(row - 2, col - 1))
    {
        isThisMoveGood(row - 2, col - 1, &ret);
    }

    if(board->valido(row - 2, col + 1))
    {
        isThisMoveGood(row - 2, col + 1, &ret);
    }

    if(board->valido(row + 2, col - 1))
    {
        isThisMoveGood(row + 2, col - 1, &ret);
    }
    if(board->valido(row + 2, col + 1))
    {
        isThisMoveGood(row + 2, col + 1, &ret);
    }

    return ret;

}

Cavallo * Cavallo::clone() const
{
    return new Cavallo(*this);
}
