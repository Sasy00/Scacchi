#include "donna.h"
#include "scacchiera.h"

Donna::Donna(const Scacchiera *owner, bool x)
    :Pezzo(owner, x, x ? 'Q' : 'q')
{

}

Vector<std::pair<int, int>> Donna::canMove(int row, int col)
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

Donna * Donna::clone() const
{
    return new Donna(*this);
}
