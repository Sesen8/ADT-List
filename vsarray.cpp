//
// Created by Arias Arevalo, Carlos on 5/6/20.
//

#include "object.h"
#include "list.h"
#include "vsarray.h"

#include <string>
using std::string;

VSArray::VSArray(size_t capacity, double increasePercentage){
}
VSArray::VSArray(const VSArray& list){
}
VSArray::~VSArray(){
}
const VSArray& VSArray::operator=(const VSArray& rhs){
	return *this;
}

bool VSArray::Insert(Object* element, size_t position){
	return false;
}
int VSArray::IndexOf(const Object* element)const{
	return -1;
}
Object* VSArray::Remove(size_t position){
	return nullptr;
}
Object* VSArray::Get(size_t position)const{
	return nullptr;
}
string VSArray::ToString()const{
	return "";
}
void VSArray::Clear(){

}

void VSArray::Resize() {

}

size_t VSArray::GetCapacity() const {
	return _capacity;
}
