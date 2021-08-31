#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Re : public Pezzo
{
public:
    Re(const Scacchiera *owner, bool x, const Coppia<int> &y);
    virtual Vector<Coppia<int>>canMove(int row, int col) override;
private:
    bool moved;
};

#endif // RE_H
