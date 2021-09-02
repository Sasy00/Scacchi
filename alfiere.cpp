#include "alfiere.h"
#include "scacchiera.h"
Alfiere::Alfiere(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    :Pezzo(owner, x, y, x ? 'A' : 'a')
{

}

Vector<std::pair<int, int>> Alfiere::canMove(int row, int col)
{
    Vector<std::pair<int, int>> ret;
    //up
    for(int i = pos.getFirst() - 1; i >= 0; --i)
    {
        //left
        bool fin = false;
        for(int j = pos.getSecond() - 1; j >= 0 && !fin; --j)
        {
            fin = isThisMoveGood(i, j, &ret);
        }
        //right
        fin = false;
        for(int j = pos.getSecond() + 1; j < 8 && !fin; ++j)
        {
            fin = isThisMoveGood(i, j, &ret);
        }
    }
    for(int i = pos.getFirst()+1; i < 8; ++i)
    {

    }
}
