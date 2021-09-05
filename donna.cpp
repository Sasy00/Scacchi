#include "donna.h"

Donna::Donna(const Scacchiera *owner, bool x)
    :Pezzo(owner, x, x ? 'Q' : 'q')
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
