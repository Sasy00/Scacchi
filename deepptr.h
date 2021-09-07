#ifndef DEEPPTR_H
#define DEEPPTR_H

#include <clonable.h>

template<class T>
class DeepPtr
{
public:
    DeepPtr(const Clonable<T> *o = nullptr);

    ~DeepPtr();
    DeepPtr(const DeepPtr &o);
    DeepPtr & operator=(const DeepPtr &o);

    T & operator*() const;
    bool operator==(const DeepPtr &o) const;
private:
    T *ptr;
};

template<class T>
DeepPtr<T>::DeepPtr(const Clonable<T> *o)
    :ptr(o ? o->clone() : nullptr)

{

}

template <class T>
DeepPtr<T>::~DeepPtr()
{
    delete ptr;
}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr &o):
    ptr(o.ptr ? (o.ptr)->clone() : nullptr)
{

}

template <class T>
DeepPtr<T> & DeepPtr<T>::operator=(const DeepPtr<T> &o)
{
    if(this == &o)
    {
        return *this;
    }
    delete ptr;
    ptr = o.ptr ? (o.ptr)->clone() : nullptr;
    return *this;
}

template <class T>
T & DeepPtr<T>::operator*() const
{
    return *ptr;
}

template <class T>
bool DeepPtr<T>::operator==(const DeepPtr<T> &o) const
{
    return ptr == o.ptr;
}

#endif // DEEPPTR_H
