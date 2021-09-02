#ifndef DEEPPTR_H
#define DEEPPTR_H

template<class T>
class DeepPtr
{
public:
    DeepPtr(const T *o = nullptr);

    ~DeepPtr();
    DeepPtr(const DeepPtr &o);
    DeepPtr & operator=(const DeepPtr &o);

    T & operator*();
    bool operator==(const DeepPtr &o);
private:
    T *ptr;
};

template<class T>
DeepPtr<T>::DeepPtr(const T *o)
    :ptr(o ? new T(*o) : nullptr)

{

}

template <class T>
DeepPtr<T>::~DeepPtr()
{
    delete ptr;
}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr &o):
    ptr(o.ptr ? new T(*(o.ptr)) : nullptr)
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
    ptr = o.ptr ? new T(*(o.ptr)) : nullptr;
    return *this;
}

template <class T>
T & DeepPtr<T>::operator*()
{
    return *ptr;
}

template <class T>
bool DeepPtr<T>::operator==(const DeepPtr<T> &o)
{
    return ptr == o.ptr;
}

#endif // DEEPPTR_H
