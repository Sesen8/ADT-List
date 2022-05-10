// Remember to write your headers!


#include "object.h"
#include "dlinkedlist.h"

#include <string>
using std::string;

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &other){
}

DoubleLinkedList &DoubleLinkedList::operator=(const DoubleLinkedList &rhs) {
	return *this;
}

DoubleLinkedList::DoubleLinkedList(){

}

DoubleLinkedList::~DoubleLinkedList() {

}

bool DoubleLinkedList::Insert(Object *element, size_t position) {
	return false;
}

int DoubleLinkedList::IndexOf(const Object *element) const {
	return -1;
}

Object *DoubleLinkedList::Remove(size_t position) {
	return nullptr;
}

Object *DoubleLinkedList::Get(size_t position) const {
	return nullptr;
}

string DoubleLinkedList::ToString() const {
	return "";
}

void DoubleLinkedList::Clear() {

}
