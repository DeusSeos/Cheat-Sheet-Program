#ifndef BST_H
#define BST_H

#include <Tree.hpp>

template <class T>
class BST : public Tree<T>
{
public:
    /*
     * Constructor
     */
    BST();

    /*
     * Destructor
     */
    ~BST();


    /*
    * Inserts a node into the BST
    * @param data - the data to be inserted into the BST
    * @return - true if the data was inserted, false otherwise
    * @complexity - O(log n)
    */
    bool insert(T element) override;


    /*
    * Removes a node from the BST
    * @param data - the data to be removed from the BST
    * @return - true if the data was removed, false otherwise
    * @precondition - the data must be in the BST
    * @postcondition - the data is removed from the BST
    * @complexity - O(log n)
    */
    bool remove(T element) override;


    /*
    * Returns the successor of an element in the BST
    * @param data - the element to find the successor of
    * @return - the successor of the element
    * @precondition - the element must be in the BST
    * @complexity - O(log n)
    * @postcondition - the successor of the element is returned
    */
    T successor(T element);


    /*
    * Returns a successor node of a node in the BST
    * @param data - the node to find the successor of
    * @return - the successor node of the element
    * @precondition - the element must be in the BST
    * @complexity - O(log n)
    * @postcondition - the successor node of the element is returned
    * @note - this function is only used in the remove function
    */
    typename Tree<T>::Node* successor(typename Tree<T>::Node *node);



    /*
    * Returns the maximum value in the BST
    * @return - the maximum value in the BST
    * @complexity - O(n)
    * @precondition - the BST must be non-empty
    * @postcondition - the BST is unchanged
    */
    T max() const;

    /*
    * Returns the minimum value in the BST
    * @return - the minimum value in the BST
    * @complexity - O(n)
    * @precondition - the BST must be non-empty
    * @postcondition - the BST is unchanged
    */
    T min() const;


};

#endif
