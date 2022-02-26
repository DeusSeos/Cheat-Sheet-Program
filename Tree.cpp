#include "Tree.hpp"


// Constructor
template<class T>
Tree<T>::Tree() {
    root = nullptr;
    numElements = 0;
}

// Destructor
template<class T>
Tree<T>::~Tree() {
    clear();
}

// Clears the tree
template<class T>
void Tree<T>::clear() {
    clear(root);
}


// Recursive function for clear
template<class T>
void Tree<T>::clear(Node *node) {
    if (node == nullptr) {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
}


// Inserts a node into the Tree
template<class T>
bool Tree<T>::insert(T element) {
    Node *node = new Node(element);
    if (root == nullptr) {
        root = node;
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
                return true;
            }
            current = current->left;
        } else {
            if (current->right == nullptr) {
                current->right = node;
                node->parent = current;
                return true;
            }
            current = current->right;
        }
    }
}

// removes a node from the Tree
template<class T>
bool Tree<T>::remove(T element) {
    Node *node = find(element);
    if (node == nullptr) {
        return false;
    }
    if (node->left == nullptr && node->right == nullptr) {
        if (node->parent->left == node) {
            node->parent->left = nullptr;
        } else {
            node->parent->right = nullptr;
        }
        delete node;
        return true;
    }
    else if (node->left == nullptr || node->right == nullptr) {
        Node *child = node->left == nullptr ? node->right : node->left;
        if (node->parent->left == node) {
            node->parent->left = child;
        } else {
            node->parent->right = child;
        }
        child->parent = node->parent;
        delete node;
        return true;
    }
    else {
        Node *successor = node->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }
        node->data = successor->data;
        remove(successor->data);
    }
}

// finds the element in the Tree
template<class T>
Tree<T>::Node& Tree<T>::find(T element) {
    Node *current = root;
    while (current != nullptr) {
        if (current->data == element) {
            return current;
        }
        if (current->data > element) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

// returns the number of nodes in the Tree
template<class T>
unsigned int Tree<T>::size() const{
    return this->numElements;
}

// returns the height from the specified node (the number of edges from the root to the deepest leaf)
template<class T>
unsigned int Tree<T>::height(Node *node) const{
    if (node == nullptr) {
        return 0;
    }
    unsigned int leftHeight = height(node->left);
    unsigned int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


// appends to the vector the nodes in the Tree in inorder
template<class T>
void Tree<T>::inOrder(Node* node, vector<Node>& list) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left, list);
    list.push_back(*node);
    inOrder(node->right, list);
    return;
}


// appends to the vector the nodes in the Tree in preorder
template<class T>
void Tree<T>::preOrder(Node* node, vector<Node>& list) {
    if (node == nullptr) {
        return;
    }

    list.push_back(*node);
    preOrder(node->left, list);
    preOrder(node->right, list);
    return;
}

// appends to the vector the nodes in the Tree in postorder
template<class T>
void Tree<T>::postOrder(Node* node, vector<Node>& list) {
    if (node == nullptr) {
        return;
    }
    postOrder(node->left, list);
    postOrder(node->right, list);
    list.push_back(*node);
    return;
}

// appends to the vector the nodes in the Tree in levelorder
template<class T>
