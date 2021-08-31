#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Alfiere : public Pezzo
{
public:
    Alfiere(const Scacchiera *owner, bool x, const Coppia<int> &y);
    virtual Vector<Coppia<int>>canMove(int row, int col) override;
};

#endif // ALFIERE_H
