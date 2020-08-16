#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>


template <class T>
class Stack {
public:
	void add(T* element);
	void remove(T* element);
	void remove(int index);
	bool empty() { return this->elements.empty(); }
	std::vector<T*>* get() { return this->elements; }
	void forEach(void (*ptr)(T* element));
	T* getObj(int index);
	T getCopy(int index);
	T* getAsArray();
	int getIndex(T* element);

private:
	std::vector<T*> elements;

};


template <class T>
void Stack<T>::add(T* element) {
	this->elements.push_back(element);
}

template<class T>
void Stack<T>::remove(T* element) {
	if (element) {
		int y = 0;
		for (auto i = this->elements.begin(); i != this->elements.end(); ++i) {
			if (this->elements[y] == element) {
				this->elements.erase(i);
				break;
			}
			y++;
		}
	}
}

template<class T>
inline T* Stack<T>::getAsArray() {
	return &this->elements[0];
}


template<class T>
inline void Stack<T>::remove(int index)
{
	if (index >= 0 && index < this->elements.size()) {
		auto iter = this->elements.begin() + index;
		this->elements.erase(iter);
	}
}


template<class T>
int Stack<T>::getIndex(T* element) {
	if (element) {
		int y = 0;
		for (auto i = this->elements.begin(); i != this->elements.end(); ++i) {
			if (this->elements[y] == element) {
				return y;
			}
			y++;
		}
	}
}

template<class T>
void Stack<T>::forEach(void(*ptr)(T* element)) {
	for (int i = 0; i < this->elements.size(); i++) {
		(*ptr)(this->elements[i]);
	}
}

template<class T>
T* Stack<T>::getObj(int index) {
	if (index >= 0 && index < this->elements.size()) {
		return elements[index];
	}
	else {
		return nullptr;
	}
}

template<class T>
T Stack<T>::getCopy(int index) {
	return *elements[index];
}
