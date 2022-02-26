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
    * clears the BST
    */
    void clear();

    /*
    * Recurvisve function for clear
    */
    void clear(Node *node);


    /*
    * Inserts a node into the BST
    * @param data - the data to be inserted into the BST
    * @return - true if the data was inserted, false otherwise
    * @complexity - O(log n)
    */
    bool insert(T element);


    /*
    * Removes a node from the BST
    * @param data - the data to be removed from the BST (removes the first occurence)
    * @return - true if the data was removed, false otherwise
    * @precondition - the data must be in the BST
    * @postcondition - the data is removed from the BST
    * @complexity - O(log n)
    */
    bool remove(T element);


    /*
    * Find for a node in the BST
    * @param data - the data to be searched for in the BST
    * @return - true if the data is in the BST, false otherwise
    * @complexity - O(log n)
    * @precondition - the data must be in the BST
    * @postcondition - the data is removed from the BST
    * 
    */
    Node& find(T element);

    /*
    * Returns the number of nodes in the BST
    * @return - the number of nodes in the BST
    */
    unsigned int size() const;

    /*
    * Returns the height of the node (the number of edges from the root to the deepest leaf) 
    * @return - the height of from the specified node
    * @complexity - O(n)
    * @precondition - the BST must be non-empty
    * @postcondition - the BST is unchanged
    */
    unsigned int height(Node *node) const;

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

    /*
    * Returns a list of the nodes in the BST in pre-order traversal
    * @return - a list of the nodes in the BST
    * @complexity - O(n)
    * @precondition - the BST must be non-empty
    * @postcondition - the BST is unchanged
    */
    std::vector<T> preOrder();

    /*
    * Returns a list of the nodes in the BST in in-order traversal
    * @return - a list of the nodes in the BST
    * @complexity - O(n)
    * @precondition - the BST must be non-empty
    */
    std::vector<T> inOrder();

    /*
    * Returns a list of the nodes in the BST in post-order traversal
    * @return - a list of the nodes in the BST
    * @complexity - O(n)
    * @precondition - the BST must be non-empty
    * @postcondition - the BST is unchanged
    */
    std::vector<T> postOrder();



private:
    Node *root;
    unsigned int size;
};

#endif BST_H;
