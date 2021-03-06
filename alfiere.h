#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Alfiere : public Pezzo
{
public:
    Alfiere(const Scacchiera *owner, bool x);
    virtual Vector<std::pair<int, int>>canMove(int row, int col) override;
    virtual Alfiere * clone() const override;
};

#endif // ALFIERE_H
