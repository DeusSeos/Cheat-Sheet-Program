#include "BinarySearchTree.hpp"

// Constructor
template <class T>
BST<T>::BST()
{
  root = nullptr;
  numElements = 0;
}

// Destructor
template <class T>
BST<T>::~BST() { clear(); }

// Clears the tree
template <class T>
void BST<T>::clear() { clear(root); }

// Recursive function for clear
template <class T>
void BST<T>::clear(Node<T> *node)
{
  if (node == nullptr)
  {
    return;
  }
  clear(node->left);
  clear(node->right);
  delete node;
}

// inserts a node into the BST
template <class T>
bool BST<T>::insert(T element)
{
  Node<T> *node = new Node(element);
  if (root == nullptr)
  {
    root = node;
    ++numElements;
    // cout << "Inserted " << element << " into the tree" << endl
    return true;
  }
  Node<T> *current = root;
  while (true)
  {
    if (current->data == element)
    {
      return false;
    }
    if (current->data > element)
    {
      if (current->left == nullptr)
      {
        current->left = node;
        node->parent = current;
        ++numElements;
        return true;
      }
      current = current->left;
    }
    else
    {
      if (current->right == nullptr)
      {
        current->right = node;
        node->parent = current;
        ++numElements;
        return true;
      }
      current = current->right;
    }
  }
}

// remove a node from the BST
template <class T>
bool BST<T>::remove(T element)
{
  if (root == nullptr)
  {
    return false;
  }
  Node<T> *current = root;
  while (current != nullptr)
  {
    if (current->data == element)
    {
      break;
    }
    if (current->data > element)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }
  if (current == nullptr)
  {
    return false;
  }
  if (current->left == nullptr && current->right == nullptr)
  {
    if (current->parent->left == current)
    {
      current->parent->left = nullptr;
    }
    else
    {
      current->parent->right = nullptr;
    }
    delete current;
    --numElements;
    return true;
  }
  else if (current->left == nullptr || current->right == nullptr)
  {
    Node<T> *child = current->left == nullptr ? current->right : current->left;
    if (current->parent->left == current)
    {
      current->parent->left = child;
    }
    else
    {
      current->parent->right = child;
    }
    child->parent = current->parent;
    delete current;
    --numElements;
    return true;
  }
  else
  {
    // 2 children use the successor(node) function
    Node<T> *succ = successor(current);
    // swap the data
    T temp = current->data;
    current->data = succ->data;
    succ->data = temp;
    // remove the successor
    remove(succ->data);
  }
  return true;
}

// Returns the successor of an element
template <class T>
T BST<T>::successor(T element)
{
  Node<T> *current = root;
  while (current != nullptr)
  {
    if (current->data == element)
    {
      break;
    }
    if (current->data > element)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }
  if (current == nullptr)
  {
    // this should never trigger since we there should be an element
    return -1;
  }
  if (current->right != nullptr)
  {
    Node<T> *successor = current->right;
    while (successor->left != nullptr)
    {
      successor = successor->left;
    }
    return successor->data;
  }
  else
  {
    Node<T> *successor = current->parent;
    while (successor != nullptr && current == successor->right)
    {
      current = successor;
      successor = successor->parent;
    }
    if (successor == nullptr)
    {
      // this should never trigger since we there should be an element
      return -1;
    }
    return successor->data;
  }
}

// Returns the node successor of a node
template <class T>
Node<T> *BST<T>::successor(Node<T> *node)
{
  if (node->right != nullptr)
  {
    Node<T> *successor = node->right;
    while (successor->left != nullptr)
    {
      successor = successor->left;
    }
    return successor;
  }
  else
  {
    Node<T> *successor = node->parent;
    while (successor != nullptr && node == successor->right)
    {
      node = successor;
      successor = successor->parent;
    }
    if (successor == nullptr)
    {
      // this should never trigger since we should always have a successor
      return nullptr;
    }
    return successor;
  }
}

// returns the max value in the BST
template <class T>
T BST<T>::max() const
{
  // iterate through the BST to find the max
  Node<T> *current = root;
  while (current->right != nullptr)
  {
    current = current->right;
  }
  T max = current->data;
  return max;
}

// returns the min value in the BST
template <class T>
T BST<T>::min() const
{
  // iterate through all elements in the tree to find the min
  Node<T> *current = root;
  while (current->left != nullptr)
  {
    current = current->left;
  }
  T min = current->data;
  return min;
}

// finds the element in the Tree
template <class T>
Node<T> *BST<T>::find(T element)
{
  Node<T> *current = root;
  while (current != nullptr)
  {
    if (current->data == element)
    {
      return current;
    }
    if (current->data > element)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }
  return nullptr;
}

// returns the number of nodes in the Tree
template <class T>
unsigned int BST<T>::size() const
{
  return this->numElements;
}

// returns the height from the specified node (the number of edges from the root
// to the deepest leaf)
template <class T>
unsigned int BST<T>::height(Node<T> *node) const
{
  if (node == nullptr)
  {
    return 0;
  }
  unsigned int leftHeight = height(node->left);
  unsigned int rightHeight = height(node->right);
  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// returns the height from the specified node (the number of edges from the root
// to the deepest leaf) from the root
template <class T>
unsigned int BST<T>::height() const
{
  if (root == nullptr)
  {
    return 0;
  }
  unsigned int leftHeight = height(root->left);
  unsigned int rightHeight = height(root->right);
  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// appends to the vector the nodes in the Tree in inorder
template <class T>
void BST<T>::inOrder(Node<T> *node, vector<Node<T>> &list)
{
  if (node == nullptr)
  {
    return;
  }
  inOrder(node->left, list);
  list.push_back(*node);
  inOrder(node->right, list);
  return;
}

// appends to the vector the nodes in the Tree in preorder
template <class T>
void BST<T>::preOrder(Node<T> *node, vector<Node<T>> &list)
{
  if (node == nullptr)
  {
    return;
  }

  list.push_back(*node);
  preOrder(node->left, list);
  preOrder(node->right, list);
  return;
}

// appends to the vector the nodes in the Tree in postorder
template <class T>
void BST<T>::postOrder(Node<T> *node, vector<Node<T>> &list)
{
  if (node == nullptr)
  {
    return;
  }
  postOrder(node->left, list);
  postOrder(node->right, list);
  list.push_back(*node);
  return;
}

// appends to the vector the nodes in the Tree in levelorder
template <class T>
void BST<T>::levelOrder(Node<T> *node, vector<Node<T>> &list)
{
  if (node == nullptr)
  {
    return;
  }
  queue<Node<T> *> q;
  q.push(node);
  while (!q.empty())
  {
    Node<T> *current = q.front();
    q.pop();
    list.push_back(*current);
    if (current->left != nullptr)
    {
      q.push(current->left);
    }
    if (current->right != nullptr)
    {
      q.push(current->right);
    }
  }
  return;
}

// appends to the vector the nodes in the Tree in inorder from the root
template <class T>
void BST<T>::inOrder(vector<Node<T>> &list)
{
  if (root == nullptr)
  {
    return;
  }
  inOrder(root->left, list);
  list.push_back(*root);
  inOrder(root->right, list);
  return;
}

// appends to the vector the nodes in the Tree in preorder from the root
template <class T>
void BST<T>::preOrder(vector<Node<T>> &list)
{
  if (root == nullptr)
  {
    return;
  }

  list.push_back(*root);
  preOrder(root->left, list);
  preOrder(root->right, list);
  return;
}

// appends to the vector the nodes in the Tree in postorder from the root
template <class T>
void BST<T>::postOrder(vector<Node<T>> &list)
{
  if (root == nullptr)
  {
    return;
  }
  postOrder(root->left, list);
  postOrder(root->right, list);
  list.push_back(*root);
  return;
}

// appends to the vector the nodes in the Tree in levelorder from the root
template <class T>
void BST<T>::levelOrder(vector<Node<T>> &list)
{
  if (root == nullptr)
  {
    return;
  }
  queue<Node<T> *> q;
  q.push(root);
  while (!q.empty())
  {
    Node<T> *current = q.front();
    q.pop();
    list.push_back(*current);
    if (current->left != nullptr)
    {
      q.push(current->left);
    }
    if (current->right != nullptr)
    {
      q.push(current->right);
    }
  }
  return;
}

// menu to continue inserting or quit
template <class T>
void insertMenu(BST<T> *tree)
{
  int choice;
  while (true)
  {
    cout << "1. Insert" << endl;
    cout << "2. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
      T element;
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

template <class T>
void successorMenu(BST<T> *tree)
{
  T element;
  cout << "Enter the element to find the successor: ";
  cin >> element;
  cout << endl;
  T successor = tree->successor(element);
  cout << "The successor of " << element << " is " << successor << endl;
}

// Tree menu
// Create a Tree variable from the Tree class
// BST<int> tree;
// loop through the menu and call the appropriate function
// 1. Insert
// 2. Remove
// 3. Find
// 4. Clear
// 5. Quit
// 6. Print size
// 7. Print height fromroot
// 8. Print Tree In Order
// 9. Print Tree Pre Order
// 10. Print Tree Post Order
// 11. Print Tree Level Order
// 12. Find Successor
// 13. Max
// 14. Min
// run the selected function
void BSTmenu()
{
  BST<int> tree;
  int choice;
  while (true)
  {
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
    cout << "12. Find Successor" << endl;
    cout << "13. Max" << endl;
    cout << "14. Min" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
    {
      insertMenu(&tree);
      //   cout << &tree;
      break;
    }
    case 2:
    {
      int element;
      cout << "Enter the element to remove: ";
      cin >> element;
      cout << endl;
      tree.remove(element);
      break;
    }
    case 3:
    {
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
      cout << "The height of the tree fromroot is: " << tree.height()
           << endl;
      break;
    case 8:
    {
      vector<Node<int>> list;
      tree.inOrder(list);
      cout << "The tree in order is: ";
      for (size_t i = 0; i < list.size(); i++)
      {
        cout << list[i].data << " ";
      }
      cout << endl;
      break;
    }
    case 9:
    {
      vector<Node<int>> list;
      tree.preOrder(list);
      cout << "The tree pre order is: ";
      for (size_t i = 0; i < list.size(); i++)
      {
        cout << list[i].data << " ";
      }
      cout << endl;
      break;
    }
    case 10:
    {
      vector<Node<int>> list;
      tree.postOrder(list);
      cout << "The tree post order is: ";
      for (size_t i = 0; i < list.size(); i++)
      {
        cout << list[i].data << " ";
      }
      cout << endl;
      break;
    }
    case 11:
    {
      vector<Node<int>> list;
      tree.levelOrder(list);
      cout << "The tree level order is: ";
      for (size_t i = 0; i < list.size(); i++)
      {
        cout << list[i].data << " ";
      }
      cout << endl;
      break;
    }
    case 12:
    {
      successorMenu(&tree);
      break;
    }
    case 13:
    {
      if (tree.size() == 0)
      {
        cout << "The tree is empty" << endl;
      }
      else
      {
        cout << "The max element is: " << tree.max() << endl;
      }
      break;
    }
    case 14:
    {
      if (tree.size() == 0)
      {
        cout << "The tree is empty" << endl;
      }
      else
      {
        cout << "The min element is: " << tree.min() << endl;
      }
      break;
    }
    default:
      cout << "Invalid choice" << endl;
      break;
    }
  }
}
