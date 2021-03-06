#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Re : public Pezzo
{
public:
    Re(const Scacchiera *owner, bool x);
    virtual Vector<std::pair<int, int>>canMove(int row, int col) override;
    virtual Re * clone() const override;
private:
    bool moved;
};

#endif // RE_H
