#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class Vector
{
public:
    Vector(unsigned int x = 10);
    ~Vector();

    T & operator[](int);

    void pushBack(const T &);
    void remove(int);

    inline int size() const {return _size;}
    inline int capacity() const {return _capacity;}

private:
    T *_arr;
    int _size;
    int _capacity;
};

#include "vector.cpp"

#endif // VECTOR_H
