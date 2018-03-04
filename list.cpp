#include "list.h"
#include "num.h"
#include "stdlib.h"
#include <fstream>

List::List() {
    anchor = nullptr;
    }

 List::List(const List& l){
    copyList(l);
 }

bool List::isValid(Node* p) {
    if(isEmpty()) {
        return false;
        }

    Node* aux = anchor;
    do {
        if(aux == p) {
            return true;
            }
        aux = aux->getNext();
        }
    while(aux != nullptr);

    return false;
    }

bool List::isEmpty() {
    return anchor == nullptr;
    }

void List::insertData(Node* p, const Num& e) {
    if(!isValid(p) and p != nullptr){
        std::cout << "Error, Posicion Invalida" << std::endl;
        return;
    }

    Node* aux = new Node(e);
    if(aux == nullptr) {
        std::cout << "Memoria insuficiente al tratar de insertar" << std::endl;
        return;
        }

    if(p == nullptr) {
        aux->setNext(anchor);
        anchor = aux;
        }
    else {
        aux->setNext(p->getNext());
        p->setNext(aux);
        }
    counter++;
    //std::cout << "Se Agrego La Num Satisfactoriamente" << std::endl;
    }

void List::deleteData(Node* p) {
    if(!isValid(p) and p == nullptr){
        std::cout << "Error, Posicion Invalida" << std::endl;
        return;
    }
    if(p == anchor) { /// Eliminar el primero
        anchor = anchor->getNext();
        }
    else { ///Eliminar el segundo en adelante
        prevPos(p)->setNext(p->getNext());
        }
    delete p;
    counter--;
    //std::cout << "Se Elimino La Num Satisfactoriamente" << std::endl;
    }

void List::printData() {
    if(isEmpty()){
        return;
    }

    Node* aux = anchor;
    while(aux != nullptr) {
        std::cout << aux->getData().getN() <<std::endl;

        aux = aux->getNext();
        }
    }

Node* List::firstPos() {
    return anchor;
    }

Node* List::lastPos() {
   if(isEmpty()) {
        return nullptr;
        }
    Node* aux = anchor;
    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
        }
    return aux;
    }

Node* List::nextPos(Node* p) {
    if(!isValid(p)) {
        return nullptr;
        }
        if(p->getNext() == anchor){
            return nullptr;
        }
    return p->getNext();
    }

Node* List::prevPos(Node* p) {
    if(isEmpty() or p == anchor) { ///le falta al otro codigo
        return nullptr;
        }
    Node* aux = anchor;
    do {
        if(aux->getNext() == p) {
            return aux;
            }
        aux = aux->getNext();
        }while(aux != anchor);
    return nullptr;
    }



void List::deleteAll() {
    if(isEmpty()){
        return;
    }

    Node* aux;

    do {
        aux = anchor;

        anchor = anchor->getNext();

        delete aux;
    }while(anchor != nullptr);
    counter = 0;
}

void List::copyList(const List& l){
    if(l.anchor == nullptr) {
        return;
        }

    Node* aux = l.anchor;
    do {
        insertData(lastPos(), aux->getData());

        aux = aux->getNext();
        }
    while(aux != nullptr);
}

void List::SquareNumbers(){
    if(isEmpty()) return;
    Node* aux = firstPos();

    while(aux != nullptr){
        aux->setData(aux->getData().Square());
        aux = aux->getNext();
    }

}
unsigned long long int List::SumNumbers()
{
    unsigned long long int Sum = 0;

    Node* aux = anchor;

    while(aux != nullptr){
        Sum += aux->getData().getN();
        aux = aux->getNext();
    }
    return Sum;
}

void List::SetNumbers(unsigned long long n)
{
    unsigned long long div;
    int mod;

    mod = n % 10;
    div = n / 10;
    if(div > 9){
        SetNumbers(div);
    }
    else{
        insertData(lastPos(), Num(div));
    }
    insertData(lastPos(), Num(mod));
}

long long int List::getCounter()
{
    return counter;
}
