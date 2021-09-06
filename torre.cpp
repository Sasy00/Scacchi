#include "torre.h"
#include "scacchiera.h"
#include <string>
Torre::Torre(const Scacchiera *owner, bool x)
    : Pezzo(owner, x, x ? 'R' : 'r')
    , moved(false)
{

}

Vector<std::pair<int, int>> Torre::canMove(int row, int col)
{
    Vector<std::pair<int, int>> ret;
    bool fin;

    //down
    fin = false;
    for(int i = 1; board->valido(row + i, col) && !fin; ++i)
    {
        fin = isThisMoveGood(row + i, col, &ret);
    }

    //up
    fin = false;
    for(int i = 1; board->valido(row - i, col) && !fin; ++i)
    {
        fin = isThisMoveGood(row - i, col, &ret);
    }

    //left
    fin = false;
    for(int i = 1; board->valido(row, col - i) && !fin; ++i)
    {
        fin = isThisMoveGood(row, col - i, &ret);
    }

    //right
    fin = false;
    for(int i = 1; board->valido(row, col + i) && !fin; ++i)
    {
        fin = isThisMoveGood(row, col + i, &ret);
    }

    return ret;
}

Torre * Torre::clone() const
{
    return new Torre(*this);
}
