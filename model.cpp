#include "model.h"

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
}

Vector<Repr> Model::getBoardRepr() const
{
    return s->getRepresentation();
}

bool Model::move(const std::pair<int, int> &src, const std::pair<int, int> &dest)
{
    DeepPtr<Pezzo> ptr = s->getPezzo(src.first, src.second);

    if(!(ptr == nullptr) && (*(ptr)).getIsWhite() == turnWhite)
    {
        Vector<std::pair<int, int>> moves = s->getPieceMoves(src.first, src.second);
        bool trovato = false;
        for(int i = 0; i < moves.size() && !trovato; ++i)
        {
            trovato = moves[i] == dest;
        }
        if(trovato)
        {
            s->move(src, dest);
            turnWhite = !turnWhite;
            return true;
        }
    }
    return false;
}

Vector<std::pair<int, int>> Model::getPieceMoves(int row, int col) const
{
    DeepPtr<Pezzo> ptr = s->getPezzo(row, col);
    if(!(ptr == nullptr) && (*(ptr)).getIsWhite() == turnWhite)
        return s->getPieceMoves(row, col);
    return Vector<std::pair<int, int>>(1);
}

void Model::reset(){
    s->reset();
    turnWhite = true;
    nMossa = 1;
}
