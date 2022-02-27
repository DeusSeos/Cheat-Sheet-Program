#include "Tree.hpp"

// Constructor
template <class T> Tree<T>::Tree() {
  root = nullptr;
  numElements = 0;
}

// Destructor
template <class T> Tree<T>::~Tree() { clear(); }

// Clears the tree
template <class T> void Tree<T>::clear() { clear(root); }

// Recursive function for clear
template <class T> void Tree<T>::clear(Node *node) {
  if (node == nullptr) {
    return;
  }
  clear(node->left);
  clear(node->right);
  delete node;
}

//TODO: CHANGE THIS TO INSERT LEFT AND RIGHT EQUALLY
// Inserts a node into the Tree
template <class T> bool Tree<T>::insert(T element) {
  Node *node = new Node(element);
  if (root == nullptr) {
    root = node;
    ++numElements;
    // cout << "Inserted " << element << " into the tree" << endl;
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

// removes a node from the Tree
template <class T> bool Tree<T>::remove(T element) {
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
    --numElements;
    return true;
  } else if (node->left == nullptr || node->right == nullptr) {
    Node *child = node->left == nullptr ? node->right : node->left;
    if (node->parent->left == node) {
      node->parent->left = child;
    } else {
      node->parent->right = child;
    }
    child->parent = node->parent;
    delete node;
    --numElements;
    return true;
  } else {
    Node *successor = node->right;
    while (successor->left != nullptr) {
      successor = successor->left;
    }
    node->data = successor->data;
    remove(successor->data);
    --numElements;
    return true;
  }
  return false;
}

// finds the element in the Tree
template <class T> typename Tree<T>::Node *Tree<T>::find(T element) {
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
template <class T> unsigned int Tree<T>::size() const {
  return this->numElements;
}

// returns the height from the specified node (the number of edges from the root
// to the deepest leaf)
template <class T> unsigned int Tree<T>::height(Node *node) const {
  if (node == nullptr) {
    return 0;
  }
  unsigned int leftHeight = height(node->left);
  unsigned int rightHeight = height(node->right);
  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// returns the height from the specified node (the number of edges from the root
// to the deepest leaf) from the root
template <class T> unsigned int Tree<T>::height() const {
  if (root == nullptr) {
    return 0;
  }
  unsigned int leftHeight = height(root->left);
  unsigned int rightHeight = height(root->right);
  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// appends to the vector the nodes in the Tree in inorder
template <class T> void Tree<T>::inOrder(Node *node, vector<Node> &list) {
  if (node == nullptr) {
    return;
  }
  inOrder(node->left, list);
  list.push_back(*node);
  inOrder(node->right, list);
  return;
}

// appends to the vector the nodes in the Tree in preorder
template <class T> void Tree<T>::preOrder(Node *node, vector<Node> &list) {
  if (node == nullptr) {
    return;
  }

  list.push_back(*node);
  preOrder(node->left, list);
  preOrder(node->right, list);
  return;
}

// appends to the vector the nodes in the Tree in postorder
template <class T> void Tree<T>::postOrder(Node *node, vector<Node> &list) {
  if (node == nullptr) {
    return;
  }
  postOrder(node->left, list);
  postOrder(node->right, list);
  list.push_back(*node);
  return;
}

// appends to the vector the nodes in the Tree in levelorder
template <class T> void Tree<T>::levelOrder(Node *node, vector<Node> &list) {
  if (node == nullptr) {
    return;
  }
  queue<Node *> q;
  q.push(node);
  while (!q.empty()) {
    Node *current = q.front();
    q.pop();
    list.push_back(*current);
    if (current->left != nullptr) {
      q.push(current->left);
    }
    if (current->right != nullptr) {
      q.push(current->right);
    }
  }
  return;
}

// appends to the vector the nodes in the Tree in inorder from the root
template <class T> void Tree<T>::inOrder(vector<Node> &list) {
  if (root == nullptr) {
    return;
  }
  inOrder(root->left, list);
  list.push_back(*root);
  inOrder(root->right, list);
  return;
}

// appends to the vector the nodes in the Tree in preorder from the root
template <class T> void Tree<T>::preOrder(vector<Node> &list) {
  if (root == nullptr) {
    return;
  }

  list.push_back(*root);
  preOrder(root->left, list);
  preOrder(root->right, list);
  return;
}

// appends to the vector the nodes in the Tree in postorder from the root
template <class T> void Tree<T>::postOrder(vector<Node> &list) {
  if (root == nullptr) {
    return;
  }
  postOrder(root->left, list);
  postOrder(root->right, list);
  list.push_back(*root);
  return;
}

// appends to the vector the nodes in the Tree in levelorder from the root
template <class T> void Tree<T>::levelOrder(vector<Node> &list) {
  if (root == nullptr) {
    return;
  }
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *current = q.front();
    q.pop();
    list.push_back(*current);
    if (current->left != nullptr) {
      q.push(current->left);
    }
    if (current->right != nullptr) {
      q.push(current->right);
    }
  }
  return;
}


// menu to continue inserting or quit
void insertMenu(Tree<int> *tree) {
  int choice;
  while (true) {
    cout << "1. Insert" << endl;
    cout << "2. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
    case 1:
      int element;
      cout << "Enter the element to insert: ";
      cin >> element;
      cout << endl;
      tree->insert(element);
    //   cout << tree;
      break;
    case 2:
      return;
    default:
      cout << "Invalid choice" << endl;
      break;
    }
  }
}


// Tree menu
// Create a Tree variable from the Tree class
// Tree<int> tree;
// loop through the menu and call the appropriate function
// 1. Insert
// 2. Remove
// 3. Find
// 4. Clear
// 5. Quit
// 6. Print size
// 7. Print height from root
// 8. Print Tree In Order
// 9. Print Tree Pre Order
// 10. Print Tree Post Order
// 11. Print Tree Level Order
// run the selected function
void treeMenu() {
  Tree<int> tree;
  int choice;
  while (true) {
    cout << "1. Insert" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Find" << endl;
    cout << "4. Clear" << endl;
    cout << "5. Quit" << endl;
    cout << "6. Print size" << endl;
    cout << "7. Print height from root" << endl;
    cout << "8. Print Tree In Order" << endl;
    cout << "9. Print Tree Pre Order" << endl;
    cout << "10. Print Tree Post Order" << endl;
    cout << "11. Print Tree Level Order" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
    case 1: {
      insertMenu(&tree);
    //   cout << &tree;
      break;
    }
    case 2: {
      int element;
      cout << "Enter the element to remove: ";
      cin >> element;
      cout << endl;
      tree.remove(element);
      break;
    }
    case 3: {
      int element;
      cout << "Enter the element to find: ";
      cin >> element;
      cout << endl;
      tree.find(element);
      break;
    }
    case 4:
      tree.clear();
      break;
    case 5:
      return;
    case 6:
      cout << "The size of the tree is: " << tree.size() << endl;
      break;
    case 7:
      cout << "The height of the tree from root is: " << tree.height() << endl;
      break;
    case 8: {
      vector<Tree<int>::Node> list;
      tree.inOrder(list);
      cout << "The tree in order is: ";
      for (size_t i = 0; i < list.size(); i++) {
        cout << list[i].data << " ";
      }
      cout << endl;
      break;
    }
    case 9: {
      vector<Tree<int>::Node> list;
      tree.preOrder(list);
      cout << "The tree pre order is: ";
      for (size_t i = 0; i < list.size(); i++) {
        cout << list[i].data << " ";
      }
      cout << endl;
      break;
    }
    case 10: {
      vector<Tree<int>::Node> list;
      tree.postOrder(list);
      cout << "The tree post order is: ";
      for (size_t i = 0; i < list.size(); i++) {
        cout << list[i].data << " ";
      }
      cout << endl;
      break;
    }
    case 11: {
      vector<Tree<int>::Node> list;
      tree.levelOrder(list);
      cout << "The tree level order is: ";
      for (size_t i = 0; i < list.size(); i++) {
        cout << list[i].data << " ";
      }
      cout << endl;
      break;
    }
    default:
      cout << "Invalid choice" << endl;
      break;
    }
  }
}