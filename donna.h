#ifndef DONNA_H
#define DONNA_H

#include "pezzo.h"

class Donna : public Pezzo
{
public:
    Donna(const Scacchiera *owner, bool x, const std::pair<int, int> &y);
    virtual Vector<std::pair<int, int>>canMove(int row, int col) override;
    virtual Donna * clone() const override;
};

#endif // DONNA_H
