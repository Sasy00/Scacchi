#include "scacchiera.h"
#include "TuttiPezzi.h"

Scacchiera::~Scacchiera(){

}
Scacchiera::Scacchiera()
    :board(8, Vector<DeepPtr<Pezzo>>(8))
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            board[i].pushBack(nullptr);
        }
    }
}

COLORE Scacchiera::occupata(int row, int col) const
{
    if(board[row][col] == nullptr)
    {
        return VUOTO;
    }
    return (*(board[row][col])).getIsWhite() ? BIANCO : NERO;
}

bool Scacchiera::valido(int x, int y) const
{
    return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}

void Scacchiera::reset()
{

    //pedoni
    for(int i = 0; i < 8; ++i)
    {
        //bianchi
        board[1][i] = new Pedone(this, true, std::pair<int, int>(1,i));
        //neri
        board[6][i] = new Pedone(this, false, std::pair<int, int>(6, i));
    }

    //pezzi bianchi
    board[0][0] = new Torre(this, true, std::pair<int, int>(0, 0));
    board[0][1] = new Cavallo(this, true, std::pair<int, int>(0, 1));
    board[0][2] = new Alfiere(this, true, std::pair<int, int>(0, 2));
    board[0][3] = new Donna(this, true, std::pair<int, int>(0, 3));
    board[0][4] = new Re(this, true, std::pair<int, int>(0, 4));
    board[0][5] = new Alfiere(this, true, std::pair<int, int>(0, 5));
    board[0][6] = new Cavallo(this, true, std::pair<int, int>(0, 6));
    board[0][7] = new Torre(this, true, std::pair<int, int>(0, 7));

    //pezzi neri
    board[7][0] = new Torre(this, false, std::pair<int, int>(7, 0));
    board[7][1] = new Cavallo(this, false, std::pair<int, int>(7, 1));
    board[7][2] = new Alfiere(this, false, std::pair<int, int>(7, 2));
    board[7][3] = new Donna(this, false, std::pair<int, int>(7, 3));
    board[7][4] = new Re(this, false, std::pair<int, int>(7, 4));
    board[7][5] = new Alfiere(this, false, std::pair<int, int>(7, 5));
    board[7][6] = new Cavallo(this, false, std::pair<int, int>(7, 6));
    board[7][7] = new Torre(this, false, std::pair<int, int>(7, 7));
}
const DeepPtr<Pezzo> Scacchiera::getPezzo(int row, int col) const
{
    return board[row][col];
}

void Scacchiera::move(const std::pair<char, int> &src, const std::pair<char, int> &dest)
{
    board[dest.second - 1][dest.first - 'a'] = board[src.second - 1][src.first - 'a'];
    board[src.second - 1][src.first - 'a'] = nullptr;
}

Vector<Repr> Scacchiera::getRepresentation() const
{
    Vector<Repr> ret;
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(!(board[i][j] == nullptr))
            {
                ret.pushBack(Repr(std::pair<int,int>(i, j),
                                  (*board[i][j]).getRepr(),
                                  (*board[i][j]).getIsWhite() ? 'W' : 'B'));
            }
        }
    }
    return ret;
}


