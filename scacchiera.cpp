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
    for(int i = 0; i < 8; ++i)
    {
        for(int y = 0; y < 8; ++y)
        {
            board[i][y] = nullptr;
        }
    }
    //pedoni
    for(int i = 0; i < 8; ++i)
    {
        //bianchi
        board[1][i] = new Pedone(this, true);
        //neri
        board[6][i] = new Pedone(this, false);
    }

    //pezzi bianchi
    board[0][0] = new Torre(this, true);
    board[0][1] = new Cavallo(this, true);
    board[0][2] = new Alfiere(this, true);
    board[0][3] = new Donna(this, true);
    board[0][4] = new Re(this, true);
    board[0][5] = new Alfiere(this, true);
    board[0][6] = new Cavallo(this, true);
    board[0][7] = new Torre(this, true);

    //pezzi neri
    board[7][0] = new Torre(this, false);
    board[7][1] = new Cavallo(this, false);
    board[7][2] = new Alfiere(this, false);
    board[7][3] = new Donna(this, false);
    board[7][4] = new Re(this, false);
    board[7][5] = new Alfiere(this, false);
    board[7][6] = new Cavallo(this, false);
    board[7][7] = new Torre(this, false);

    whiteKingCastle = true;
    whiteQueenCastle = true;
    blackKingCastle = true;
    blackQueenCastle = true;
}
const DeepPtr<Pezzo> Scacchiera::getPezzo(int row, int col) const
{
    return board[row][col];
}

bool Scacchiera::move(const std::pair<int, int> &src, const std::pair<int, int> &dest)
{
    DeepPtr<Pezzo> ptr = board[src.first][src.second];
    auto temp = board[dest.first][dest.second];
    if(!(temp == nullptr))
    {
        if(dynamic_cast<Torre *>(&(*temp)))
        {
            if((*temp).getIsWhite())
            {
                if(whiteKingCastle)
                {
                    if(dest.first == 0 && dest.second == 7)
                    {
                        whiteKingCastle = false;
                    }
                }
                if(whiteQueenCastle)
                {
                    if(dest.first == 0 && dest.second == 0)
                    {
                        whiteQueenCastle = false;
                    }
                }
            }
            else
            {
                if(blackKingCastle)
                {
                    if(dest.first == 7 && dest.second == 7)
                    {
                        blackKingCastle = false;
                    }
                }
                if(blackQueenCastle)
                {
                    if(dest.first == 7 && dest.second == 0)
                    {
                        blackQueenCastle = false;
                    }
                }
            }
        }
    }
    if(dynamic_cast<Re *>( &( *(ptr) ) ) ) //if source piece is a king
    {
        if((*ptr).getIsWhite())
        {
            if(whiteKingCastle || whiteQueenCastle)
            {
                if(dest.first == 0 && dest.second == 6 && whiteKingCastle)
                {
                    board[0][6] = board[0][4];
                    board[0][5] = board[0][7];
                    board[0][4] = nullptr;
                    board[0][7] = nullptr;
                    whiteKingCastle = false;
                    whiteQueenCastle = false;
                    return true;
                }
                else if(dest.first == 0 && dest.second == 2 && whiteQueenCastle)
                {
                    board[0][2] = board[0][4];
                    board[0][3] = board[0][0];
                    board[0][4] = nullptr;
                    board[0][0] = nullptr;
                    whiteKingCastle = false;
                    whiteQueenCastle = false;
                    return true;
                }
                else
                {
                    whiteKingCastle = false;
                    whiteQueenCastle = false;
                }
            }
        }
        else
        {
            if(blackKingCastle || blackQueenCastle)
            {
                if(dest.first == 7 && dest.second == 6 && blackKingCastle)
                {
                    board[7][6] = board[7][4];
                    board[7][5] = board[7][7];
                    board[7][4] = nullptr;
                    board[7][7] = nullptr;
                    blackKingCastle = false;
                    blackQueenCastle = false;
                    return true;
                }
                else if(dest.first == 7 && dest.second == 2 && blackQueenCastle)
                {
                    board[7][2] = board[7][4];
                    board[7][3] = board[7][0];
                    board[7][4] = nullptr;
                    board[7][0] = nullptr;
                    blackKingCastle = false;
                    blackQueenCastle = false;
                    return true;
                }
                else
                {
                    blackKingCastle = false;
                    blackQueenCastle = false;
                }
            }

        }

    }
    if(dynamic_cast<Torre *>(&(*ptr)))
    {
        if((*ptr).getIsWhite())
        {
            if(whiteKingCastle)
            {
                whiteKingCastle = !(src.first == 0 && src.second == 7);
            }
            if(whiteQueenCastle)
            {
                whiteQueenCastle = !(src.first == 0 && src.second == 0);
            }
        }
        else
        {
            if(blackKingCastle)
            {
                blackKingCastle = !(src.first == 7 && src.second == 7);
            }
            if(blackQueenCastle)
            {
                blackQueenCastle = !(src.first == 7 && src.second == 0);
            }
        }
    }
    if(dynamic_cast<Pedone *>(&(*ptr)))
    {
        if((*ptr).getIsWhite())
        {
            if(dest.first == 7)
            {
                board[src.first][src.second] = nullptr;
                board[dest.first][dest.second] = new Donna(this, true);
                return true;
            }
        }
        else
        {
            if(dest.first == 0)
            {
                board[src.first][src.second] = nullptr;
                board[dest.first][dest.second] = new Donna(this, false);
                return true;
            }
        }
    }
    board[dest.first][dest.second] = board[src.first][src.second];
    board[src.first][src.second] = nullptr;
    return true;
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

Vector<std::pair<int, int>> Scacchiera::getMosseGiocatore(bool white, bool serveScacco)
{
    Vector<std::pair<int, int>> ret;
    DeepPtr<Pezzo> ptr;
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            ptr = board[i][j];
            if(!(ptr == nullptr))
            {
                if((*ptr).getIsWhite() == white)
                {
                    if(serveScacco)
                        ret += getPieceMoves(i, j);
                    else
                        ret += (*ptr).canMove(i, j);
                }
            }
        }
    }
    return ret;
}

Vector<std::pair<int, int>> Scacchiera::getPieceMoves(int row, int col)
{
    Vector<std::pair<int, int>> ret;
    DeepPtr<Pezzo> ptr = board[row][col];
    if(!(ptr == nullptr))
    {
        ret = (*ptr).canMove(row, col);
        //----------------------- ARROCCO --------------------------------
        if(dynamic_cast<Re *>(&(*ptr)))
        {
            //if not sotto scacco
            //if f1 and g1 are not under a tack
            bool white = (*ptr).getIsWhite();
            if(white)                                   //se siamo bianchi
            {
                if(whiteKingCastle || whiteQueenCastle) //se può arroccare
                {
                    auto v = getMosseGiocatore(!white, false);
                    if(whiteKingCastle && (board[0][5] == nullptr) && (board[0][6] == nullptr)) //se può fare arroco corto e f1 e g1 sono libere
                    {
                        bool minaccia = false;
                        for(int i = 0; i < v.size() && !minaccia; ++i)
                        {
                            std::pair<int, int> attack = v[i];
                            minaccia = (attack.first == 0 && attack.second == 5) || (attack.first == 0 && attack.second == 6); //minaccia == true sse almeno un pezzo nemico può andare lì
                        }
                        if(!minaccia)
                        {
                                                                        //se c'è un pedone nero in h2
                            auto temp = board[1][7];
                            if(!(temp == nullptr))
                            {
                                if(dynamic_cast<Pedone *>(&(*temp)) && (*temp).getIsWhite() == false)
                                {
                                    minaccia = true;                    //metti minaccia a true
                                }
                            }
                            temp = board[1][4];
                            if(!(temp == nullptr))
                            {
                                if(dynamic_cast<Pedone *>(&(*temp)) && (*temp).getIsWhite() == false)
                                {
                                    minaccia = true;
                                }
                            }
                        }

                        if(!minaccia)
                        {
                            ret.pushBack(std::pair<int, int>(0, 6));
                        }
                    }
                    if(whiteQueenCastle && (board[0][1] == nullptr) && (board[0][2] == nullptr) && (board[0][3] == nullptr)) //se può fare arroco lungo e b1 e c1 e d1 sono libere
                    {
                        bool minaccia = false;
                        for(int i = 0; i < v.size() && !minaccia; ++i)
                        {
                            minaccia = v[i].first == 0 && (v[i].second == 2 || v[i].second == 3); //minaccia == true sse almeno un pezzo nemico può andare lì
                        }
                        if(!minaccia)
                        {
                                                                        //se c'è un pedone nero in b2
                            auto temp = board[1][1];
                            if(!(temp == nullptr))
                            {
                                if(dynamic_cast<Pedone *>(&(*temp)) && (*temp).getIsWhite() == false)
                                {
                                    minaccia = true;                    //metti minaccia a true
                                }
                            }
                            temp = board[1][4];
                            if(!(temp == nullptr))
                            {
                                if(dynamic_cast<Pedone *>(&(*temp)) && (*temp).getIsWhite() == false)
                                {
                                    minaccia = true;
                                }
                            }
                        }
                        if(!minaccia)
                        {
                            ret.pushBack(std::pair<int, int>(0, 2));
                        }
                    }
                }
            }
            else        //black
            {
                if(blackKingCastle || blackQueenCastle) //se può arroccare
                {
                    auto v = getMosseGiocatore(!white, false);
                    if(blackKingCastle && (board[7][5] == nullptr) && (board[7][6] == nullptr)) //se può fare arroco corto e f1 e g1 sono libere
                    {
                        bool minaccia = false;
                        for(int i = 0; i < v.size() && !minaccia; ++i)
                        {
                            minaccia = v[i].first == 7 && (v[i].second == 5 || v[i].second == 6); //minaccia == true sse almeno un pezzo nemico può andare lì
                        }
                        if(!minaccia)
                        {
                                                                        //se c'è un pedone nero in h2
                            auto temp = board[6][7];
                            if(!(temp == nullptr))
                            {
                                if(dynamic_cast<Pedone *>(&(*temp)) && (*temp).getIsWhite() == true)
                                {
                                    minaccia = true;                    //metti minaccia a true
                                }
                            }
                            temp = board[6][4];
                            if(!(temp == nullptr))
                            {
                                if(dynamic_cast<Pedone *>(&(*temp)) && (*temp).getIsWhite() == true)
                                {
                                    minaccia = true;
                                }
                            }
                        }

                        if(!minaccia)
                        {
                            ret.pushBack(std::pair<int, int>(7, 6));
                        }
                    }
                    if(blackQueenCastle && (board[7][1] == nullptr) && (board[7][2] == nullptr) && (board[7][3] == nullptr)) //se può fare arroco lungo e b1 e c1 e d1 sono libere
                    {
                        bool minaccia = false;
                        for(int i = 0; i < v.size() && !minaccia; ++i)
                        {
                            minaccia = v[i].first == 7 && (v[i].second == 2 || v[i].second == 3); //minaccia == true sse almeno un pezzo nemico può andare lì
                        }
                        if(!minaccia)
                        {
                                                                        //se c'è un pedone nero in b2
                            auto temp = board[6][1];
                            if(!(temp == nullptr))
                            {
                                if(dynamic_cast<Pedone *>(&(*temp)) && (*temp).getIsWhite() == true)
                                {
                                    minaccia = true;                    //metti minaccia a true
                                }
                            }
                            temp = board[6][4];
                            if(!(temp == nullptr))
                            {
                                if(dynamic_cast<Pedone *>(&(*temp)) && (*temp).getIsWhite() == true)
                                {
                                    minaccia = true;
                                }
                            }
                        }
                        if(!minaccia)
                        {
                            ret.pushBack(std::pair<int, int>(7, 2));
                        }
                    }
                }
            }
        }
        auto buone = controllaMosse(row, col, ret);
        return buone;
    }
    return ret;
}

bool Scacchiera::getStallo(bool white)
{
    if(getMosseGiocatore(white, true).size() == 0 && !sottoScacco(white))
        return true;
    return false;
}

bool Scacchiera::getScaccoMatto(bool white)
{
    if(getMosseGiocatore(white, true).size() == 0 && sottoScacco(white))
        return true;
    return false;
}

bool Scacchiera::sottoScacco(bool white)
{
    std::pair<int, int> kingpos;
    bool trovato = false;
    for(int i = 0; i < 8 && !trovato; ++i)
    {
        for(int j = 0; j < 8 && !trovato; ++j)
        {
            auto ptr = board[i][j];
            if (!(ptr == nullptr) && (*ptr).getIsWhite() == white && dynamic_cast<Re *>(&(*ptr)))
            {
                trovato = true;
                kingpos.first = i;
                kingpos.second = j;
            }
        }
    }
    auto v = getMosseGiocatore(!white, false);
    for(int i = 0; i < v.size(); ++i)
    {
        if(kingpos == v[i])
            return true;
    }
    return false;
}
#include <iostream>

Vector<std::pair<int, int>> Scacchiera::controllaMosse(int row, int col, const Vector<std::pair<int, int>> &mosse)
{
    Vector<std::pair<int, int>> ret;
    Vector<Vector<DeepPtr<Pezzo>>> temp;
    for(int i = 0; i < mosse.size(); ++i)
    {
        temp = board;
        board[mosse[i].first][mosse[i].second] = board[row][col];
        board[row][col] = nullptr;
        if(!sottoScacco((*temp[row][col]).getIsWhite()))
        {
            ret.pushBack(mosse[i]);
        }
        board = temp;
    }

    return ret;
}


