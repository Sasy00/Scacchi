#include "cavallo.h"

Cavallo::Cavallo(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    :Pezzo(owner, x, y, x ? 'N' : 'n')
{

}

Vector<std::pair<int, int>> Cavallo::canMove(int row, int col)
{
    return Vector<std::pair<int, int>>();
}

Cavallo * Cavallo::clone() const
{
    return new Cavallo(*this);
}
