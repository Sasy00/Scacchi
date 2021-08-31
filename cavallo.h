#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Cavallo : public Pezzo
{
public:
    Cavallo();
    virtual Vector<Coppia<int>>canMove(int row, int col) override;
};

#endif // CAVALLO_H
