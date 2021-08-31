#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Pedone : public Pezzo
{
public:
    Pedone(const Scacchiera *owner, bool x, const Coppia<int> &y);
    virtual Vector<Coppia<int>>canMove(int row, int col) override;
private:
    bool moved;
};

#endif // PEDONE_H
