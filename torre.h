#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Torre : public Pezzo
{
public:
    Torre();
    virtual Vector<Coppia<int>>canMove(int row, int col) override;
private:
    bool moved;
};

#endif // TORRE_H
