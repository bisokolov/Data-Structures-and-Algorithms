#pragma once
#include "pch.h"
#include "stackImplementation.h"



template <typename T>
class Stack {
public:
	Stack(const int capacity = 1);
	Stack(const Stack<T> &);
	~Stack() {
		deleteStack();
	}
	Stack<T> & operator=(const Stack<T> &);

	T top();
	void pop();
	void push(const T &);
	void testPrint();
	int getCapacity()
	{
		return capacity;
	}
	int getSize()
	{
		return size;
	}
	bool isEmpty()
	{
		return size == 0;
	}

private:
	T * arr;
	int size;
	int capacity;
	void deleteStack();
	void copyStack(const Stack<T> &,const int);

};




template<typename T>
Stack<T>::Stack(const int capacity) {
	this->capacity = capacity;
	arr = new T[this->capacity];
	size = 0;
}

template<typename T>
Stack<T>::Stack(const Stack & other) {

		copyStack(other,other.capacity);
	
}

template<typename T>
T Stack<T>::top() {
	if (size == 0) {
		std::cout << "Stack is empty ";
		throw std::exception();
	}
	return arr[size - 1];
}

template<typename T>
void Stack<T>::push(const T & value) {
	if (size == capacity) {
		Stack<T> temp(*this);
		deleteStack();
		copyStack(temp, temp.capacity + 1);
	}
	arr[size] = value;
	++size;
}

template<typename T>
void Stack<T>::pop() {
	if (size == 0) {
		std::cout << "Stack is empty ";
		throw std::exception();
	}
	--size;
}

template<typename T>
void Stack<T>::testPrint() {
	for (int i = 0;i < size;++i) {
		std::cout << "Index is: " << i << " Value is: " << arr[i] << std::endl;
	}
	std::cout << "Size is: " << size << std::endl;
	std::cout << "Capacity is: " << capacity << std::endl;
}


template<typename T>
void Stack<T>::copyStack(const Stack<T> & other,const int maxCapacity) {
	
	this->size = other.size;
	this->capacity = maxCapacity;
	this->arr = new T[this->capacity];
	for (int i = 0;i < this->size;++i) {
		this->arr[i] = other.arr[i];
	}
}

template<typename T>
void Stack<T>::deleteStack() {
	delete[] this->arr;
	this->capacity = 0;
	this->size = 0;
}


template<typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> &other) {
	if (this != &other) {
		deleteStack();
		copyStack(other,other.capacity);
	}
	return *this;

}