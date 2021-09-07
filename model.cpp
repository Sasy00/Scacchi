#include "model.h"
#include "pedone.h"
Model::Model(): s(new Scacchiera)
{

}

Model::~Model()
{
    delete s;
}

void Model::init()
{
    s->reset();
    turnWhite = true;
    nMossa = 1;
    regola50 = 0;
}

Vector<Repr> Model::getBoardRepr() const
{
    return s->getRepresentation();
}

Model::STATE Model::move(const std::pair<int, int> &src, const std::pair<int, int> &dest)
{
    DeepPtr<Pezzo> ptr = s->getPezzo(src.first, src.second);

    if(!(ptr == nullptr) && (*(ptr)).getIsWhite() == turnWhite)
    {
        Vector<std::pair<int, int>> moves = s->getPieceMoves(src.first, src.second);
        bool trovato = false;
        for(auto it = moves.begin(); it != moves.end() && !trovato; ++it)
        {
            trovato = *it == dest;
        }
        if(trovato)
        {
            ++regola50;
            if(dynamic_cast<Pedone *>(&(*ptr)) || !(s->getPezzo(dest.first, dest.second) == nullptr))
            {
                regola50 = 0;
            }
            s->move(src, dest); 
            turnWhite = !turnWhite;
            if(turnWhite)
            {
                increaseMossa();
            }
            if(regola50 >= 50 || s->getStallo(turnWhite))
            {
                return PATTA;
            }
            if(s->getScaccoMatto(turnWhite))
            {
                if(turnWhite)
                {
                    return NERO;
                }
                else
                {
                    return BIANCO;
                }
            }

        }
    }
    return CONTINUA;
}

void Model::reset(){
    s->reset();
    turnWhite = true;
    nMossa = 1;
    regola50 = 0;
}

Vector<std::pair<int, int>> Model::getPieceMoves(int row, int col) const
{
    DeepPtr<Pezzo> ptr = s->getPezzo(row, col);
    if(!(ptr == nullptr) && (*(ptr)).getIsWhite() == turnWhite)
        return s->getPieceMoves(row, col);
    return Vector<std::pair<int, int>>(1);
}

