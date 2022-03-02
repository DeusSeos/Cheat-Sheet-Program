#ifndef NODE_H
#define NODE_H

template<class T>
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

#endif