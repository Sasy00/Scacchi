#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Pedone : public Pezzo
{
public:
    Pedone(const Scacchiera *owner, bool x);
    virtual Vector<std::pair<int, int>>canMove(int row, int col) override;
    virtual Pedone * clone() const override;
private:
    bool moved;
};

#endif // PEDONE_H
