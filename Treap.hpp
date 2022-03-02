#ifndef TREAP_H
#define TREAP_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Treap header file

template <class T>
class Treap
{

public:
    class Node
    {
    public:
        int priority;
        T data;
        Node *left;
        Node *right;
        Node *parent;
        Node(T data, int priority)
        {
            this->data = data;
            this->priority = priority;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }
    };
    // Constructor
    Treap();

    // Destructor
    ~Treap();

    /*
     * Clears the tree
     */
    void clear();

    /*
     * Recurvisve function for clear
     */
    void clear(Node *node);



    /*
     * inserts a node into the BST
     * @param data - the data to be inserted into the BST
     * @return - true if the data was inserted, false otherwise
     * @complexity - O(log n)
     */
    bool insert(int element);

    /*
    * Rotates the tree to the left
    * @param node - the node to rotate to the left
    * @return - the new root of the tree
    * @complexity - O(1)
    * @precondition - node must be a valid node
    * @postcondition - the tree is rotated to the left
    */
    Node *rotateLeft(Node *node);

    /*
    * Rotates the tree to the right
    * @param node - the node to rotate to the right
    * @return - the new root of the tree
    * @complexity - O(1)
    * @precondition - node must be a valid node
    * @postcondition - the tree is rotated to the right
    */
    Node *rotateRight(Node *node);


    /*
     * Removes a node from the BST
     * @param data - the data to be removed from the BST
     * @return - true if the data was removed, false otherwise
     * @precondition - the data must be in the BST
     * @postcondition - the data is removed from the BST
     * @complexity - O(log n)
     */
    bool remove(int element);

    /*
     * Returns an unordered_map mapping nodes to balance factors,
     * where the balance factor is the difference in height between the right
     * height minus the left height
     * @return - an unordered_map mapping nodes to balance factors
     */
    unordered_map<int, int> balance_factors();

    /*
     * Return the height of the tree
     * @return - the height of the tree
     * @complexity - O(1)
     * @precondition - the tree must be initialized
     * @postcondition - the tree is unchanged
     */
    int height();

    /*
     * appends a list of the nodes in the Tree in in-order traversal to the vector
     * @param node - the node to traverse from, list - the vector to append the
     * nodes to
     * @return - a list of the nodes in the Tree
     * @complexity - O(n)
     * @precondition - the Tree must be non-empty
     */
    void inOrder(Node *node, vector<Node> &list);

    /*
     * appends a list of the nodes in the Tree in pre-order traversal to the
     * vector
     * @param node - the node to traverse from, list - the vector to append the
     * nodes to
     * @return - a list of the nodes in the Tree
     * @complexity - O(n)
     * @precondition - the Tree must be non-empty
     * @postcondition - the Tree is unchanged
     */
    void preOrder(Node *node, vector<Node> &list);

    /*
     * appends a list of the nodes in the Tree in post-order traversal to the
     * vector
     * @param node - the node to traverse from, list - the vector to append the
     * nodes to
     * @return - a list of the nodes in the Tree
     * @complexity - O(n)
     * @precondition - the Tree must be non-empty
     * @postcondition - the Tree is unchanged
     */
    void postOrder(Node *node, vector<Node> &list);

    /* appends a list of the nodes in the Tree in level-order traversal to the
     * vector
     * @param node - the node to traverse from, list - the vector to append the
     * nodes to
     * @return - a list of the nodes in the Tree
     * @complexity - O(n)
     * @precondition - the Tree must be non-empty
     * @postcondition - the Tree is unchanged
     */
    void levelOrder(Node *node, vector<Node> &list);

    /*
     * appends a list of the nodes in the Tree in in-order traversal to the vector
     * @param node list - the vector to append the nodes to
     * @return - a list of the nodes in the Tree
     * @complexity - O(n)
     * @precondition - the Tree must be non-empty
     */
    void inOrder(vector<Node> &list);

    /*
     * appends a list of the nodes in the Tree in pre-order traversal to the
     * vector from the root
     * @param list - the vector to append the nodes to
     * @return - a list of the nodes in the Tree
     * @complexity - O(n)
     * @precondition - the Tree must be non-empty
     * @postcondition - the Tree is unchanged
     */
    void preOrder(vector<Node> &list);

    /*
     * appends a list of the nodes in the Tree in post-order traversal to the
     * vector from the root
     * @param node - the vector to append the nodes to
     * @return - a list of the nodes in the Tree
     * @complexity - O(n)
     * @precondition - the Tree must be non-empty
     * @postcondition - the Tree is unchanged
     */
    void postOrder(vector<Node> &list);

    /* appends a list of the nodes in the Tree in level-order traversal to the
     * vector from the root
     * @param node - the vector to append the nodes to
     * @return - a list of the nodes in the Tree
     * @complexity - O(n)
     * @precondition - the Tree must be non-empty
     * @postcondition - the Tree is unchanged
     */
    void levelOrder(vector<Node> &list);

private:
    Node *root;
    int numElements;
};

#endif
