#include "re.h"

Re::Re(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    : Pezzo(owner, x, y, x ? 'R' : 'r')
    , moved(false)
{

}

Vector<std::pair<int, int>> Re::canMove(int row, int col)
{
    return Vector<std::pair<int, int>>();
}

Re * Re::clone() const
{
    return new Re(*this);
}
