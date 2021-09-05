#include "pedone.h"

Pedone::Pedone(const Scacchiera *owner, bool x)
    : Pezzo(owner, x, x ? 'P' : 'p')
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
