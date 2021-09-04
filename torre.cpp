#include "torre.h"

Torre::Torre(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    : Pezzo(owner, x, y, x ? 'R' : 'r')
    , moved(false)
{

}

Vector<std::pair<int, int>> Torre::canMove(int row, int col)
{
    return Vector<std::pair<int, int>>();
}

Torre * Torre::clone() const
{
    return new Torre(*this);
}
