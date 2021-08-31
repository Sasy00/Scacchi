#include "pedone.h"

Pedone::Pedone(const Scacchiera *owner, bool x, const Coppia<int> &y)
    : Pezzo(owner, x, y, x ? 'P' : 'p')
    , moved(false)
{

}
