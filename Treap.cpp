#include "Treap.hpp"

// Constructor
template <class T>
Treap<T>::Treap()
{
    root = nullptr;
    numElements = 0;
}

template <class T>
Treap<T>::~Treap()
{
    clear();
}


