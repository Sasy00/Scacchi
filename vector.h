#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class Vector
{
public:
    Vector(int x = 10);
    ~Vector();

    T & operator[](int);

    void pushBack(const T &);
    void popBack();
    T& last();
    void remove(int);

    inline int size() const {return _size;}
    inline int capacity() const {return _capacity;}

private:
    T **_arr;
    int _size;
    int _capacity;
};

template<class T>
Vector<T>::Vector(int x)
    :_arr(x == 0 ? new T*[10] : new T*[x]),
      _size(0),
      _capacity(x == 0 ? 10 : x)
{

}
template<class T>
Vector<T>::~Vector()
{
    for(int i = 0; i < _size; ++i)
    {
        delete _arr[i];
    }
    delete[] _arr;
}

template<class T>
T & Vector<T>::operator[](int x)
{
    return *(_arr[x]);
}

template<class T>
void Vector<T>::pushBack(const T& o)
{
    if(_size == _capacity)
    {
        T **newArr = new T*[_capacity * 2];
        for(int i = 0; i < _capacity; ++i)
        {
            newArr[i] = _arr[i];
        }
        delete[] _arr;
        _arr = newArr;
        _capacity *= 2;
    }
    _arr[_size] = new T(o);
    _size++;
}

template<class T>
void Vector<T>::remove(int x)
{
    if(x >= _size)
        return;
    delete _arr[x];
    for(int i = x; i < _size - 1; ++i)
    {
        _arr[i] = _arr[i+1];
    }
    _size--;
}

template<class T>
void Vector<T>::popBack()
{
    if(_size > 0)
    {
        delete _arr[_size - 1];
        _size--;
    }
}

template<class T>
T & Vector<T>::last()
{
    return *_arr[_size - 1];
}

#endif // VECTOR_H
