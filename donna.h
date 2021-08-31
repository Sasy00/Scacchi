#ifndef DONNA_H
#define DONNA_H

#include "pezzo.h"

class Donna : public Pezzo
{
public:
    Donna(const Scacchiera *owner, bool x, const Coppia<int> &y, char z);
    virtual Vector<Coppia<int>>canMove(int row, int col) override;
};

#endif // DONNA_H
