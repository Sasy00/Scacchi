#include "alfiere.h"

Alfiere::Alfiere(const Scacchiera *owner, bool x, const Coppia<int> &y)
    :Pezzo(owner, x, y, x ? 'A' : 'a')
{

}
