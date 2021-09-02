#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Pedone : public Pezzo
{
public:
    Pedone(const Scacchiera *owner, bool x, const std::pair<int, int> &y);
    virtual Vector<std::pair<int, int>>canMove(int row, int col) override;
private:
    bool moved;
};

#endif // PEDONE_H
