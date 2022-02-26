#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>

using namespace std;

// Tree header file

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
    * Constructor for an empty tree
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
    * Recurvisve function for clear
    */
    void clear(Node *node);


    /*
    * Inserts a node into the Tree
    * @param data - the data to be inserted into the Tree
    * @return - true if the data was inserted, false otherwise
    * @complexity - O(log n)
    */
    bool insert(T element);


    /*
    * Removes a node from the Tree
    * @param data - the data to be removed from the Tree (removes the first occurence)
    * @return - true if the data was removed, false otherwise
    * @precondition - the data must be in the Tree
    * @postcondition - the data is removed from the Tree
    * @complexity - O(log n)
    */
    bool remove(T element);


    /*
    * Find for a node in the Tree
    * @param data - the data to be searched for in the Tree
    * @return - true if the data is in the Tree, false otherwise
    * @complexity - O(log n)
    * @precondition - the data must be in the Tree
    * @postcondition - the data is removed from the Tree
    * 
    */
    Node& find(T element);

    /*
    * Returns the number of nodes in the Tree
    * @return - the number of nodes in the Tree
    */
    unsigned int size() const;

    /*
    * Returns the height of the node (the number of edges from the root to the deepest leaf) 
    * @return - the height of from the specified node
    * @complexity - O(n)
    * @precondition - the Tree must be non-empty
    * @postcondition - the Tree is unchanged
    */
    unsigned int height(Node *node) const;


    /*
    * appends a list of the nodes in the Tree in in-order traversal to the vector
    * @param node - the node to traverse from, list - the vector to append the nodes to
    * @return - a list of the nodes in the Tree
    * @complexity - O(n)
    * @precondition - the Tree must be non-empty
    */
    void inOrder(Node* node, vector<Node>& list);


    /*
    * appends a list of the nodes in the Tree in pre-order traversal to the vector
    * @param node - the node to traverse from, list - the vector to append the nodes to
    * @return - a list of the nodes in the Tree
    * @complexity - O(n)
    * @precondition - the Tree must be non-empty
    * @postcondition - the Tree is unchanged
    */
    void preOrder(Node* node, vector<Node>& list);



    /*
    * appends a list of the nodes in the Tree in post-order traversal to the vector
    * @param node - the node to traverse from, list - the vector to append the nodes to
    * @return - a list of the nodes in the Tree
    * @complexity - O(n)
    * @precondition - the Tree must be non-empty
    * @postcondition - the Tree is unchanged
    */
    void postOrder(Node* node, vector<Node>& list);



private:
    Node *root;
    unsigned int numElements;

};
#endif TREE_H

