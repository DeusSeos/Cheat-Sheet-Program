#include "BinarySearchTree.hpp"


// Constructor
template<class T>
BST<T>::BST() {
  root = nullptr;
  numElements = 0;
}

//Destructor
template<class T>
BST<T>::~BST() {
  clear();
}

// inserts a node into the BST
template<class T>
bool BST<T>::insert(T element) {
    Node *node = new Node(element);
    if (root == nullptr) {
        root = node;
        ++numElements;
        // cout << "Inserted " << element << " into the tree" << endl
        return true;
    }
    Node *current = root;
    while (true) {
        if (current->data == element) {
        return false;
        }
        if (current->data > element) {
        if (current->left == nullptr) {
            current->left = node;
            node->parent = current;
            ++numElements;
            return true;
        }
        current = current->left;
        } else {
        if (current->right == nullptr) {
            current->right = node;
            node->parent = current;
            ++numElements;
            return true;
        }
        current = current->right;
        }
    }
}

//remove a node from the BST
template<class T>
bool BST<T>::remove(T element){
    if (root == nullptr) {
        return false;
    }
    Node *current = root;
    while (current != nullptr) {
        if (current->data == element) {
            break;
        }
        if (current->data > element) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == nullptr) {
        return false;
    }
    if (current->left == nullptr && current->right == nullptr) {
        if (current->parent->left == current) {
            current->parent->left = nullptr;
        } else {
            current->parent->right = nullptr;
        }
        delete current;
        --numElements;
        return true;
    }
    else if (current->left == nullptr || current->right == nullptr){
        Node *child = current->left == nullptr ? current->right : current->left;
        if (current->parent->left == current) {
            current->parent->left = child;
        } else {
            current->parent->right = child;
        }
        child->parent = current->parent;
        delete current;
        --numElements;
        return true;
    }
    else {
        // 2 children use the successor(node) function
        Node *successor = successor(current);
        // swap the data
        T temp = current->data;
        current->data = successor->data;
        successor->data = temp;
        // remove the successor
        remove(successor->data);
       
    }
}


// Returns the successor of an element
template<class T>
T BST<T>::successor(T element) {
    Node *current = root;
    while (current != nullptr) {
        if (current->data == element) {
            break;
        }
        if (current->data > element) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == nullptr) {
        // this should never trigger since we there should be an element
        return -1;
    }
    if (current->right != nullptr) {
        Node *successor = current->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }
        return successor->data;
    } else {
        Node *successor = current->parent;
        while (successor != nullptr && current == successor->right) {
            current = successor;
            successor = successor->parent;
        }
        if (successor == nullptr) {
            // this should never trigger since we there should be an element
            return -1;
        }
        return successor->data;
    }
}

//Returns the node successor of a node
template<class T>
typename Tree<T>::Node* BST<T>::successor(typename Tree<T>::Node *node) {
    if (node->right != nullptr) {
        Node *successor = node->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }
        return successor;
    } else {
        Node *successor = node->parent;
        while (successor != nullptr && node == successor->right) {
            node = successor;
            successor = successor->parent;
        }
        if (successor == nullptr) {
            // this should never trigger since we should always have a successor
            return nullptr;
        }
        return successor;
    }
}



// returns the max value in the BST
template<class T>
T BST<T>::max() const{
    //iterate through the BST to find the max 
    Node *current = root;
    while(current->right != nullptr){
        current = current->right;
    }
    T max = current->data;
}


// returns the min value in the BST
template<class T>
T BST<T>::min() const{
    //iterate through all elements in the tree to find the min 
    Node *current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    T min = current->data;
}