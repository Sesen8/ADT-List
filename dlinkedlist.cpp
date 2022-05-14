// Remember to write your headers!


#include "object.h"
#include "dlinkedlist.h"

#include <iostream>
#include <string>
using namespace std;
using std::string;

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &other){
}

DoubleLinkedList &DoubleLinkedList::operator=(const DoubleLinkedList &rhs) {
	return *this;
}

DoubleLinkedList::DoubleLinkedList(){
    _head = nullptr;
    _tail = nullptr;
    _size = 0;

}

DoubleLinkedList::~DoubleLinkedList() {
    Node* tmp = _head;
    while(tmp!=nullptr){
        Node* next = tmp->next;
        delete tmp;
        tmp = next;
    }
    delete _head;


}

bool DoubleLinkedList::Insert(Object *element, size_t position) {
    if(position >_size){
        return false;
    }

    Node* newNode = new Node();
    newNode->data = element;
    newNode->next= nullptr;
    newNode->previous=nullptr;

    if(_size==0){
        _head=newNode;
        _tail=newNode;
    }
    else if(position==0){
        newNode->next=_head;
        _head->previous=newNode;
        _head=newNode;

    }

    else {
        Node *tmp = _head;
        for (int i = 0; i < position-1; i++) {
            tmp = tmp->next;
        }

        newNode->next = tmp->next;
        newNode->previous = tmp;
        tmp->next = newNode;
        if(newNode->next !=nullptr){
            newNode->next->previous=newNode;
        }

    }

    _size++;
	return true;
}

int DoubleLinkedList::IndexOf(const Object *element) const {

    int i = 0;
    for (Node* tmp = _head; tmp != nullptr; tmp = tmp->next){
        if (tmp->data->Equals(*element)){
            return i;
        }
        i++;
    }

	return -1;
}

Object *DoubleLinkedList::Remove(size_t position) {
    if (position >= _size){
        return nullptr;
    }

    Object* ptr = nullptr;
    Node* tmp = new Node();
    tmp= nullptr;

    if (position == 0){
        ptr = _head->data;
        _head->data = nullptr;
        tmp = _head->next;
        _head->next = nullptr;
        delete _head;
        _head = tmp;
    }
    else if (position>0){
        tmp = _head;

        for (size_t i = 0; i < position -1; i++){
            tmp = tmp->next;
        }

        Node* deleteNode = new Node();
        deleteNode = tmp->next;
        ptr = deleteNode->data;
        tmp->next = deleteNode->next;
        deleteNode->next = nullptr;
        deleteNode->data = nullptr;
        delete deleteNode;
    }
    _size--;
    return ptr;

}

Object *DoubleLinkedList::Get(size_t position) const {
    if (position >= _size){
        return nullptr;
    }
    Node* tmp = _head;
    for (size_t i = 0; i < position; i++) {
        tmp = tmp->next;
    }
    return tmp->data;

}

string DoubleLinkedList::ToString() const {
    string returnString;
    returnString = "{";

    Node* tmp = new Node;

    for(tmp=_head;tmp!=nullptr;tmp=tmp->next){
        returnString = tmp->data->ToString() + " ";
    }

    returnString = tmp->data->ToString() + "}";

	return returnString;
}

void DoubleLinkedList::Clear() {
    Node* tmp = _head;

    while (tmp != nullptr){
        if (tmp->data)
            delete tmp->data;

        Node* toDelete = tmp;
        tmp = tmp->next;
        delete toDelete;
    }
    _head = nullptr;
    _tail=nullptr;
    _size = 0;

}
