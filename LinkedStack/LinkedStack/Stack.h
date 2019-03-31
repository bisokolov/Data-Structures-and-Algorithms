#pragma once
#include "pch.h"
#include <iostream>


template<typename T>
struct Node {
	Node(T d) : data(d) { this->prev = nullptr; }
	T data; 
	Node * prev;
	Node() {
		
		prev = nullptr;
	}

};

template<typename T>
class Stack {
public:

	Stack<T>();
	~Stack<T>();
	Stack<T>(const Stack<T> &);
	void push(const T &);
	T top();
	void pop();
	void deleteStack();
	void copyStack(const Stack<T> &);
	bool isEmpty() const;


private:
	Node<T> * topPtr;
};

template<typename T>
Stack<T>::Stack() {
	topPtr = nullptr;
}


template<typename T>
Stack<T>::Stack(const Stack<T> & other) {
	if (!other.isEmpty()) {
		copyStack(other);
	}
	else this->topPtr = nullptr;
}


template<typename T>
Stack<T>::~Stack() {
	deleteStack();
}

template<typename T>
void Stack<T>::push(const T & elem) {
	Node<T> * ptr = new Node<T>;
	ptr->data = elem;
	ptr->prev = this->topPtr;
	topPtr = ptr;
}


template<typename T>
T Stack<T>::top() {
	return topPtr->data;
}


template<typename T>
void Stack<T>::pop() {
	Node<T> * ptr = this->topPtr;
	topPtr = topPtr->prev;
	delete ptr;
}


template<typename T>
bool Stack<T>::isEmpty() const {
	return this->topPtr == nullptr;
}


template<typename T>
void Stack<T>::deleteStack() {
	if (!isEmpty()) {
		Node<T> *ptr;
		while (this->topPtr != nullptr) {
			ptr = this->topPtr->prev;
			delete this->topPtr;
			this->topPtr = ptr;
		}
	}
}


template<typename T>
void Stack<T>::copyStack(const Stack<T> & other) {
	Node<T> *ptr = other.topPtr;
	this->topPtr = new Node<T>(ptr->data);
	Node<T> * prevPtr = this->topPtr;
	ptr = ptr->prev;

	while (ptr) {
		prevPtr->prev = new Node<T>(ptr->data);
		prevPtr = prevPtr->prev;
		ptr = ptr->prev;
	}
	

}