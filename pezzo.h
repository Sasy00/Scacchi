#ifndef PEZZO_H
#define PEZZO_H

#include "vector.h"
#include "coppia.h"

//forward declaration
class Scacchiera;

class Pezzo
{
public:
    Pezzo(const Scacchiera *owner, bool x, const Coppia<int> &y, char z);
    virtual ~Pezzo();
    virtual Vector<Coppia<int>> canMove(int row, int col) = 0;

    bool getIsWhite() const;
    Coppia<int> getPosition() const;
    char getRepr() const;
private:
    const Scacchiera *board;
    bool isWhite;
    Coppia<int> pos;
    char repr;
};

#endif // PEZZO_H
