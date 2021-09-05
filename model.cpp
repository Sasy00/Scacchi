#include "model.h"

Model::Model()
{

}

void Model::init()
{
    s.reset();
}

Vector<Repr> Model::getBoardRepr() const
{
    return s.getRepresentation();
}


