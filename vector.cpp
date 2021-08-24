#include "vector.h"

template<class T>
Vector<T>::Vector(unsigned int x)
    :_arr(x == 0 ? new T[10] : new T[x]),
      _size(0),
      _capacity(x == 0 ? 10 : x)
{

}
template<class T>
Vector<T>::~Vector()
{
    /*
    for(int i = 0; i < _capacity; ++i)
    {
        delete _arr[i];
    }
    */
    delete[] _arr;
}

template<class T>
T & Vector<T>::operator[](int x)
{
    return _arr[x];
}

template<class T>
void Vector<T>::pushBack(const T& o)
{
    if(_size == _capacity)
    {
        T *newArr = new T[_capacity * 2];
        for(int i = 0; i < _capacity; ++i)
        {
            newArr[i] = _arr[i];
        }
        delete[] _arr;
        _arr = newArr;
        _capacity *= 2;
    }
    _arr[_size] = o;
    _size++;
}
