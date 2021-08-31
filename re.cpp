#include "re.h"

Re::Re(const Scacchiera *owner, bool x, const Coppia<int> &y)
    : Pezzo(owner, x, y, x ? 'R' : 'r')
    , moved(false)
{

}
