#include "pezzo.h"

Pezzo::Pezzo(const Scacchiera *owner, bool x, const Coppia<int> &y, char z)
    : board(owner)
    , isWhite(x)
    , pos(y)
    , repr(z)
{

}

Pezzo::~Pezzo()
{
    ;
}

bool Pezzo::getIsWhite() const
{
    return isWhite;
}

Coppia<int> Pezzo::getPosition() const
{
    return pos;
}

char Pezzo::getRepr() const
{
    return repr;
}
