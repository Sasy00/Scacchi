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
    bool move(const std::pair<int, int> &src, const std::pair<int, int> &dest);
    Vector<std::pair<int, int>> getPieceMoves(int row, int col);
    Vector<std::pair<int, int>> getMosseGiocatore(bool white, bool serveScacco);
    Vector<Repr> getRepresentation() const;
    bool getStallo(bool white);
    bool getScaccoMatto(bool white);
    bool sottoScacco(bool white);
    Vector<std::pair<int, int>> controllaMosse(int row, int col, const Vector<std::pair<int, int>> &mosse); //se ci sono mosse illegali in mosse vengono tolte
private:
    //2 dimensional array of pointers to Pezzo representing the chessboard
    Vector<Vector<DeepPtr<Pezzo>>> board;
    bool whiteQueenCastle;
    bool whiteKingCastle;
    bool blackQueenCastle;
    bool blackKingCastle;


};

/*
 * V funzione per avere tutte le mosse possibili del giocatore di turno
 * controllare se sei sotto scacco (se nelle mosse possibili ce n'è una che combacia con la posizione del re opposto)
 * controllare se la mossa è legale (sei sotto scacco dopo aver fatto la mossa)
 * controllare se è scaccomatto se dopo tutte le mosse possibili sei sotto scacco
 * controllare se è stallo ovvero se dopo tutte le mosse possibili sei sotto scacco MA ora non sei sotto scacco
 * controllare la roba delle 50 mosse
 * controllare la roba della ripetizione 3 volte della posizione --come cazzo si fa pt
 * ✓ promozione pedone
 * ✓ arrocco
 * en passant
 *
 */

#endif // SCACCHIERA_H
