#ifndef MODEL_H
#define MODEL_H
#include "scacchiera.h"
class Model
{
public:
    enum STATE
    {
        PATTA = -1,
        CONTINUA = 0,
        BIANCO = 1,
        NERO = 2
    };

    Model();
    ~Model();
    Vector<Repr> getBoardRepr() const;
    Vector<std::pair<int, int>> getPieceMoves(int row, int col) const;
    void init();
    void reset();
    inline bool getTurnWhite() const { return turnWhite; }
    STATE move(const std::pair<int, int> &src, const std::pair<int, int> &dest);
    inline int getnMossa(){ return nMossa; }
    inline int increaseMossa(){ return ++nMossa; }

private:
    bool turnWhite;
    Scacchiera *s;
    int nMossa;
    int regola50;
};

#endif // MODEL_H
