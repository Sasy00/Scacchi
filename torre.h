#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Torre : public Pezzo
{
public:
    Torre(const Scacchiera *owner, bool x, const std::pair<int, int> &y);
    virtual Vector<std::pair<int, int>>canMove(int row, int col) override;
private:
    bool moved;
};

#endif // TORRE_H
