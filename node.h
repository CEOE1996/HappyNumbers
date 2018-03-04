#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "Num.h"

class Node{
    private:
        Num data;
        Node* next;

    public:
        Node();
        Node(const Num&);

        Num& getData();
        Node* getNext();

        void setData(const Num&);
        void setNext(Node*);
};

#endif // NODE_H_INCLUDED
