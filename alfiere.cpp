#include "alfiere.h"
#include "scacchiera.h"
Alfiere::Alfiere(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    :Pezzo(owner, x, y, x ? 'B' : 'b')
{

}

Vector<std::pair<int, int>> Alfiere::canMove(int row, int col)
{
    Vector<std::pair<int, int>> ret;
    bool fin = false;

    //up left
    for(int i = 1; board->valido(pos.first - i, pos.second - i) && !fin; ++i)
    {
        fin = isThisMoveGood(pos.first - i, pos.second - i, &ret);
    }

    fin = false;

    //up right
    for(int i = 1; board->valido(pos.first - i, pos.second + i) && !fin; ++i)
    {
        fin = isThisMoveGood(pos.first - i, pos.second + i, &ret);
    }

    fin = false;

    //down left
    for(int i = 1; board->valido(pos.first + i, pos.second - i) && !fin; ++i)
    {
        fin = isThisMoveGood(pos.first + i, pos.second - i, &ret);
    }

    fin = false;

    //down right
    for(int i = 1; board->valido(pos.first + i, pos.second + i) && !fin; ++i)
    {
        fin = isThisMoveGood(pos.first + i, pos.second + i, &ret);
    }

    return ret;
}

Alfiere * Alfiere::clone() const
{
    return new Alfiere(*this);
}
