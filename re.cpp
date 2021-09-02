#include "re.h"

Re::Re(const Scacchiera *owner, bool x, const std::pair<int, int> &y)
    : Pezzo(owner, x, y, x ? 'R' : 'r')
    , moved(false)
{

}
