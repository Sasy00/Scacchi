#include "cavallo.h"

Cavallo::Cavallo(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    :Pezzo(owner, x, y, x ? 'C' : 'c')
{

}
