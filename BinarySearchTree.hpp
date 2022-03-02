#ifndef BST_H
#define BST_H


#include <iostream>
#include <vector>
#include <queue>

using namespace std;


template <class T> class BST {
public:
  class Node {
  public:
    T data;
    Node *left;
    Node *right;
    Node *parent;
    Node(T data) {
      this->data = data;
      left = nullptr;
      right = nullptr;
      parent = nullptr;
    }
  };
  /*
   * Constructor
   */
  BST();

  /*
   * Destructor
   */
  ~BST();

  /*
   * Clears the tree
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
   * @param data - the data to be removed from the BST
   * @return - true if the data was removed, false otherwise
   * @precondition - the data must be in the BST
   * @postcondition - the data is removed from the BST
   * @complexity - O(log n)
   */
  bool remove(T element);

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
  typename BST<T>::Node *successor(Node *node);

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
   * Find for a node in the Tree
   * @param data - the data to be searched for in the Tree
   * @return - nullptr if the data is not in the Tree, the node if it is
   * @complexity - O(log n)
   * @precondition - the data must be in the Tree
   * @postcondition - the data is unchanged
   *
   */
  BST<T>::Node *find(T element);

  /*
   * Returns the number of nodes in the Tree
   * @return - the number of nodes in the Tree
   */
  unsigned int size() const;

  /*
   * Returns the height of the node (the number of edges from the root to the
   * deepest leaf)
   * @return - the height of from the specified node
   * @complexity - O(n)
   * @precondition - the Tree must be non-empty
   * @postcondition - the Tree is unchanged
   */
  unsigned int height(Node *node) const;

  /*
   * Returns the height of the node (the number of edges from the root to the
   * deepest leaf) from the root
   * @return - the height of from the specified node
   * @complexity - O(n)
   * @precondition - the Tree must be non-empty
   * @postcondition - the Tree is unchanged
   */
  unsigned int height() const;

  // TODO - add depth function

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
  unsigned int numElements;
};

void BSTmenu();

#endif
