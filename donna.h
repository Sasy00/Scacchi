#ifndef DONNA_H
#define DONNA_H

#include "pezzo.h"

class Donna : public Pezzo
{
public:
    Donna();
    virtual Vector<Coppia<int>>canMove(int row, int col) override;
};

#endif // DONNA_H
