#include "re.h"
#include "scacchiera.h"
Re::Re(const Scacchiera *owner, bool x)
    : Pezzo(owner, x, x ? 'K' : 'k')
    , moved(false)
{

}

Vector<std::pair<int, int>> Re::canMove(int row, int col)
{
    Vector<std::pair<int, int>> ret;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            int r = row - 1 + i;
            int c = col - 1 + j;

            if(!(r == row && c == col)) //if not on the same square
            {
                if(board->valido(r, c))
                {
                    isThisMoveGood(r, c, &ret);
                }
            }
        }
    }
    return ret;
}

Re * Re::clone() const
{
    return new Re(*this);
}
