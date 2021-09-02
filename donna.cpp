#include "donna.h"

Donna::Donna(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    :Pezzo(owner, x, y, x ? 'D' : 'd')
{

}
