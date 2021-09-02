#include "pezzo.h"
#include "scacchiera.h"
Pezzo::Pezzo(const Scacchiera *owner, bool x, const std::pair<int, int> &y, char z)
    : board(owner)
    , isWhite(x)
    , pos(y)
    , repr(z)
{

}

Pezzo::~Pezzo()
{
    ;
}

bool Pezzo::getIsWhite() const
{
    return isWhite;
}

std::pair<int, int> Pezzo::getPosition() const
{
    return pos;
}

char Pezzo::getRepr() const
{
    return repr;
}

bool Pezzo::isThisMoveGood(int row, int col, Vector<std::pair<int, int>> *ret)
{
    COLORE occupata = board->occupata(row, col);
    if(occupata == VUOTO)
    {
        ret->pushBack(std::pair<int, int>(row, col));
        return false;
    }
    else if((occupata == BIANCO && isWhite) || (occupata == NERO && !isWhite))
    {
        return true;
    }
    else//((occupata == NERO && isWhite) || (occupata == BIANCO && !isWhite))
    {
        ret->pushBack(std::pair<int, int>(row, col));
        return true;
    }
}
