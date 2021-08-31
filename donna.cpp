#include "donna.h"

Donna::Donna(const Scacchiera *owner, bool x, const Coppia<int> &y)
    :Pezzo(owner, x, y, x ? 'D' : 'd')
{

}
