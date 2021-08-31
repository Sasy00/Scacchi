#include "pedone.h"

Pedone::Pedone(const Scacchiera *owner, bool x, const Coppia<int> &y, char z)
    : Pezzo(owner, x, y, z)
    , moved(false)
{

}
