#ifndef CLONABLE_H
#define CLONABLE_H

template<typename T>
class Clonable
{
public:
    virtual T * clone() const = 0;
};

#endif // CLONABLE_H
