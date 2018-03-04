#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <string>
#include "node.h"
#include "num.h"
#include <fstream>

class List{
private:
    Node* anchor;
    long long int counter = 0;

    bool isValid(Node*);
public:
    List();
    List(const List&);

    bool isEmpty();

    void insertData(Node*,const Num&);
    void deleteData(Node*);

    Node* firstPos();
    Node* lastPos();
    Node* nextPos(Node*);
    Node* prevPos(Node*);

    void deleteAll();

    void copyList(const List&);
    void SquareNumbers();
    unsigned long long int SumNumbers();
    void SetNumbers(unsigned long long n);

    long long int getCounter();

    void printData();
};

#endif // LIST_H_INCLUDED
