#ifndef COPPIA_H
#define COPPIA_H

template<class T>
class Coppia
{
public:
    Coppia(const T &x, const T &y);

    //big 3
    Coppia(const Coppia &o);
    ~Coppia();
    Coppia & operator=(const Coppia &o);

    inline T & getFirst() const { return *first; }
    inline T & getSecond() const { return *second; }

private:
    T *first;
    T *second;
};

template <class T>
Coppia<T>::Coppia(const T &x, const T &y)
    : first(new T(x))
    , second(new T(y))
{

}

template <class T>
Coppia<T>::Coppia(const Coppia<T> &o)
    : first(new T(*(o.first)))
    , second(new T(*(o.second)))
{

}

template  <class T>
Coppia<T>::~Coppia()
{
    delete first;
    delete second;
}

template <class T>
Coppia<T> & Coppia<T>::operator=(const Coppia<T> &o)
{
    if(this == &o)
    {
        return *this;
    }

    delete first;
    delete second;

    first = new T(*(o.first));
    second = new T(*(o.second));

    return *this;
}

#endif // COPPIA_H
