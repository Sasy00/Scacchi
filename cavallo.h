#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Cavallo : public Pezzo
{
public:
    Cavallo(const Scacchiera *owner, bool x, const Coppia<int> &y, char z);
    virtual Vector<Coppia<int>>canMove(int row, int col) override;
};

#endif // CAVALLO_H
