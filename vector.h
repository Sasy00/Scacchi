#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class Vector
{
public:
    /**
     * @brief Constructor for class Vector
     * @param x: initial size of the vector
     */

    Vector(int x = 10);
    ~Vector();

    /**
     * @brief assignment operator
     * @param o: source vector
     * @return this vector as reference
     */
    Vector &operator=(const Vector& o);

    /**
     * @brief Copy constructor
     */
    Vector(const Vector&);

    /**
     * @brief operator []
     * @param n: index
     * @return reference to the n-th element of the vector
     */
    T & operator[](int n) const;

    /**
     * @brief inserts a copy of the argument at the end of the vector
     * @param o: element to be inserted
     */
    void pushBack(const T &o);

    /**
     * @brief deletes the last element of the vector without returning it. to have a copy of the last element use Vector::last()
     */
    void popBack();

    /**
     * @brief last
     * @return reference to the last element of the vector
     */
    T& last() const;

    /**
     * @brief removes the n-th element of the vector and moves back by one all the next elements
     */
    void remove(int n);

    /**
     * @brief size
     * @return the number of elements inside the vector
     */
    inline int size() const {return _size;}

    /**
     * @brief capacity
     * @return size + free space already allocated
     */
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
Vector<T>::Vector(const Vector<T> &o)
    :_arr(new T*[o._capacity])
    ,_size(0)
    ,_capacity(o._capacity)

{
    int fin = o.size();
    for(int i = 0; i < fin; ++i)
    {
        pushBack(o[i]);
    }
}

template<class T>
T & Vector<T>::operator[](int x) const
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
T & Vector<T>::last() const
{
    return *_arr[_size - 1];
}

template<class T>
Vector<T> & Vector<T>::operator=(const Vector<T> &o)
{
    for(int i = 0; i < _size; ++i)
    {
        delete _arr[i];
    }

    _size = 0;

    int fin = o.size();
    for(int i = 0; i < fin; ++i)
    {
        pushBack(o[i]);
    }
    return *this;
}

#endif // VECTOR_H
