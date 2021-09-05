#ifndef MODEL_H
#define MODEL_H
#include "scacchiera.h"
class Model
{
public:
    Model();
    Vector<Repr> getBoardRepr() const;
    void init();
private:
    Scacchiera s;
};

#endif // MODEL_H
