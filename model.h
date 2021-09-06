#ifndef MODEL_H
#define MODEL_H
#include "scacchiera.h"
class Model
{
public:
    Model();
    ~Model();
    Vector<Repr> getBoardRepr() const;
    Vector<std::pair<int, int>> getPieceMoves(int row, int col) const;
    void init();
    inline bool getTurnWhite() const { return turnWhite; }
    bool move(const std::pair<int, int> &src, const std::pair<int, int> &dest);
    void reset();
    inline int getnMossa(){return nMossa;}
    inline int increaseMossa(){return nMossa++;}
private:
    bool turnWhite;
    Scacchiera *s;
    int nMossa;
};

#endif // MODEL_H
