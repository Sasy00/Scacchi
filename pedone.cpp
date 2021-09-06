#include "pedone.h"
#include "scacchiera.h"
Pedone::Pedone(const Scacchiera *owner, bool x)
    : Pezzo(owner, x, x ? 'P' : 'p')
    , moved(false)
{

}

Vector<std::pair<int, int>> Pedone::canMove(int row, int col)
{
    Vector<std::pair<int, int>> ret;
    DeepPtr<Pezzo> ptr = board->getPezzo(row + 1, col);
    //spinta di 1
    if(isWhite)
    {
        if(board->valido(row + 1, col))
        {
            ptr = board->getPezzo(row + 1, col);
            if(ptr == nullptr)
            {
                ret.pushBack(std::pair<int, int>(row + 1, col));

                if(row == 1) //not yet moved
                {
                    ptr = board->getPezzo(row + 2, col);
                    if(ptr == nullptr)
                    {
                        ret.pushBack(std::pair<int, int>(row + 2, col));
                    }
                }
            }
        }


        //cattura
        if(board->valido(row + 1, col -1))
        {
            ptr = board->getPezzo(row + 1, col - 1);
            if( !( ptr == nullptr ) && !( ( *ptr ).getIsWhite() ) )
            {
                ret.pushBack(std::pair<int,int>(row + 1, col - 1));
            }
        }
        if(board->valido(row + 1, col + 1))
        {
            ptr = board->getPezzo(row + 1, col + 1);
            if( !( ptr == nullptr ) && !( ( *ptr ).getIsWhite() ) )
            {
                ret.pushBack(std::pair<int,int>(row + 1, col + 1));
            }
        }

    }
    else
    {
        if(board->valido(row - 1, col))
        {
            ptr = board->getPezzo(row - 1, col);
            if(ptr == nullptr)
            {
                ret.pushBack(std::pair<int, int>(row - 1, col));

                if(row == 6) //not yet moved
                {
                    ptr = board->getPezzo(row - 2, col);
                    if(ptr == nullptr)
                    {
                        ret.pushBack(std::pair<int, int>(row - 2, col));
                    }
                }
            }
        }
        //cattura
        if(board->valido(row - 1, col - 1))
        {
            ptr = board->getPezzo(row - 1, col - 1);
            if( !( ptr == nullptr ) && ( ( *ptr ).getIsWhite() ) )
            {
                ret.pushBack(std::pair<int,int>(row - 1, col - 1));
            }
        }
        if(board->valido(row - 1, col + 1))
        {
            ptr = board->getPezzo(row - 1, col + 1);
            if( !( ptr == nullptr ) && ( ( *ptr ).getIsWhite() ) )
            {
                ret.pushBack(std::pair<int,int>(row - 1, col + 1));
            }
        }
    }
    return ret;
}

Pedone * Pedone::clone() const
{
    return new Pedone(*this);
}
