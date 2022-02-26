#include "BinarySearchTree.hpp"



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