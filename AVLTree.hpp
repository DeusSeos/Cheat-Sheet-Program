#ifndef AVL_H
#define AVL_H

#include "Tree.hpp"

template <class T>
class AVL : public Tree<T> {


public:
    // Constructor
    AVL();

    // Destructor
    ~AVL();

    /*
    * inserts a node into the BST
    * @param data - the data to be inserted into the BST
    * @return - true if the data was inserted, false otherwise
    * @complexity - O(log n)
    */
    bool insert(int element);

    /*
    * Returns an unordered_map mapping nodes to balance factors,
    * where the balance factor is the difference in height between the right height minus the left height
    * @return - an unordered_map mapping nodes to balance factors
    */
    unordered_map<T, int> balance_factors();



    

private:



#endif