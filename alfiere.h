#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Alfiere : public Pezzo
{
public:
    Alfiere(const Scacchiera *owner, bool x, const std::pair<int, int> &y);
    virtual Vector<std::pair<int, int>>canMove(int row, int col) override;
};

#endif // ALFIERE_H
