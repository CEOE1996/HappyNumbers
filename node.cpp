#include "node.h"

Node::Node()
{
    next = nullptr;
}

Node::Node(const Num& e) : Node()
{
    data = e;
}

Num& Node::getData()
{
    return data;
}
Node* Node::getNext()
{
    return next;
}


void Node::setData(const Num& e)
{
    data = e;
}

void Node::setNext(Node* p)
{
    next = p;
}
