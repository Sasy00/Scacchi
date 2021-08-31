#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Pedone : public Pezzo
{
public:
    Pedone();
    virtual Vector<Coppia<int>>canMove(int row, int col) override;
private:
    bool moved;
};

#endif // PEDONE_H
