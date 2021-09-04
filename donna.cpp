#include "donna.h"

Donna::Donna(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    :Pezzo(owner, x, y, x ? 'Q' : 'q')
{

}

Vector<std::pair<int, int>> Donna::canMove(int row, int col)
{
    return Vector<std::pair<int, int>>();
}

Donna * Donna::clone() const
{
    return new Donna(*this);
}
