#ifndef PEZZO_H
#define PEZZO_H

#include "vector.h"
#include "clonable.h"
#include <utility>

//forward declaration
class Scacchiera;

class Pezzo : public Clonable<Pezzo>
{
public:
    Pezzo(const Scacchiera *owner, bool x, char z);
    virtual ~Pezzo();
    virtual Vector<std::pair<int, int>> canMove(int row, int col) = 0;

    bool getIsWhite() const;
    //std::pair<int, int> getPosition() const;
    char getRepr() const;
    virtual Pezzo *clone() const = 0;
protected:
    /**
     * @brief isThisMoveGood
     * @param row
     * @param col
     * @param ret the move will be saved in this array if it is doable
     * @return true if last move, false if you can still move
     */
    bool isThisMoveGood(int row, int col, Vector<std::pair<int, int>> *ret);

    const Scacchiera *board;
    bool isWhite;
    //std::pair<int, int> pos;
    char repr;
};

#endif // PEZZO_H
