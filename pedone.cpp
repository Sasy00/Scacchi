#include "pedone.h"

Pedone::Pedone(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    : Pezzo(owner, x, y, x ? 'P' : 'p')
    , moved(false)
{

}

Vector<std::pair<int, int>> Pedone::canMove(int row, int col)
{
    return Vector<std::pair<int, int>>();
}

Pedone * Pedone::clone() const
{
    return new Pedone(*this);
}
