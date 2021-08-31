#include "cavallo.h"

Cavallo::Cavallo(const Scacchiera *owner, bool x, const Coppia<int> &y)
    :Pezzo(owner, x, y, x ? 'C' : 'c')
{

}
