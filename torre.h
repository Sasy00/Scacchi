#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Torre : public Pezzo
{
public:
    Torre(const Scacchiera *owner, bool x, const Coppia<int> &y);
    virtual Vector<Coppia<int>>canMove(int row, int col) override;
private:
    bool moved;
};

#endif // TORRE_H
