#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>

// Binary Search Tree header file

template<class T>
class Tree {

public:
    class Node {
    public:
        T data;
        Node *left;
        Node *right;
        Node *parent;
        Node(T data)
        {
            this->data = data;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }
    };

    /*
    * Constructor
    * 
    */
    Tree();


    /*
    * Destructor
    */
    ~Tree();

    /*
    * clears the tree
    */
    void clear();

    /*
    * Inserts a node into the BST
    * @param data - the data to be inserted into the BST
    * @return - true if the data was inserted, false otherwise
    * @complexity - O(log n)
    */
    bool insert(T element);


    /*
    * Removes a node from the BST
    * @param data - the data to be removed from the BST
    * @return - true if the data was removed, false otherwise
    * @precondition - the data must be in the BST
    * @postcondition - the data is removed from the BST
    * @complexity - O(log n)
    */
    bool remove(T element);



    /*
    * Searches for a node in the BST
    * @param data - the data to be searched for in the BST
    * @return - true if the data is in the BST, false otherwise
    * @complexity - O(log n)
    * @precondition - the data must be in the BST
    * @postcondition - the data is removed from the BST
    * 
    */
    bool search(T element);

    /*
    * Returns the number of nodes in the BST
    * @return - the number of nodes in the BST
    */
    unsigned int size();

    /*
    * Returns the height of the BST (the number of edges from the root to the deepest leaf) from the specified node
    * @return - the height of the BST from the specified node
    * @complexity - O(n)
    * @precondition - the BST must be non-empty
    * @postcondition - the BST is unchanged
    */
    unsigned int height(Node *node);

    /*
    * Returns the maximum value in the BST
    * @return - the maximum value in the BST
    * @complexity - O(n)
    * @precondition - the BST must be non-empty
    * @postcondition - the BST is unchanged
    */
    int max();

    /*
    * Returns the minimum value in the BST
    * @return - the minimum value in the BST
    * @complexity - O(n)
    * @precondition - the BST must be non-empty
    * @postcondition - the BST is unchanged
    */
    int min();

    /*
    * Returns the successor of a node in the BST
    * @param node - the node to find the successor of
    * @return - the successor of the node
    * @complexity - O(log n)
    * @precondition - the BST must be non-empty
    * @postcondition - the BST is unchanged
    */
    Node *successor(Node *node);

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
#endif TREE_H

