#include "torre.h"

Torre::Torre(const Scacchiera *owner, bool x, const Coppia<int> &y, char z)\
    : Pezzo(owner, x, y, z)
    : moved(false)
{

}
