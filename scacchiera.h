#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include "vector.h"
#include "deepptr.h"
#include "pezzo.h"

enum COLORE
{
    VUOTO = -1,
    BIANCO = 0,
    NERO = 1
};

class Repr
{
public:
    std::pair<int,int> pos;
    char pezzo;
    char colore;
    Repr() = default;
    Repr(std::pair<int,int> x, char y, char z):pos(x),pezzo(y),colore(z){}
};

class Scacchiera
{
public:
    Scacchiera();
    ~Scacchiera();
    COLORE occupata(int row, int col) const;
    bool valido(int x, int y) const;
    void reset();
    const DeepPtr<Pezzo> getPezzo(int row, int col) const;
    void move(const std::pair<char, int> &src, const std::pair<char, int> &dest);



    Vector<Repr> getRepresentation() const;
private:
    //2 dimensional array of pointers to Pezzo representing the chessboard
    Vector<Vector<DeepPtr<Pezzo>>> board;
};

#endif // SCACCHIERA_H
