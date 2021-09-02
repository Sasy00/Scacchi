#include "torre.h"

Torre::Torre(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    : Pezzo(owner, x, y, x ? 'T' : 't')
    , moved(false)
{

}
