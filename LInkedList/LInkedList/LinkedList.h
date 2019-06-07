#pragma once
#include "pch.h"
#include <iostream>
#include <assert.h>

template<typename T>
struct Node {
	Node* previous;
	Node* next;
	T data;
};


template<typename T>
class LinkedList {
public:
	LinkedList();
	Node<T>* Search(T data);
	void AddFront(T data);
	void AddTail(T data);
	void Print() const;
	int  Count() const;
	void InsertAtPosition(int position, T data);
	T DeleteAtPosition(int position);
private:
	Node<T>* front;
	Node<T>* back;
};

template<typename T>
LinkedList<T>::LinkedList() {
	front = back = nullptr;
}

template<typename T>
void LinkedList<T>::AddFront(T data) {
	if (front == nullptr) {
		front = new Node<T>();
		front->data = data;
		front->next = front->previous = nullptr;
		back = front;
	}
	else {
		Node<T> * ptr = new Node<T>();
ptr->data = data;
ptr->next = front;
ptr->previous = nullptr;
front->previous = ptr;
front = ptr;
	}
}

template<typename T>
void LinkedList<T>::AddTail(T data) {
	if (back == nullptr) {
		back = new Node<T>();
		back->data = data;
		back->next = back->previous = nullptr;
		front = back;
	}
	else {
		Node<T> * ptr = new Node<T>();
		ptr->data = data;
		ptr->next = nullptr;
		ptr->previous = back;
		back->next = ptr;
		back = ptr;
	}
}

template<typename T>
Node<T> * LinkedList<T>::Search(T data) {
	if (front == nullptr) {
		return nullptr;
	}

	Node<T> * ptr = front;
	while (ptr->data != data) {
		ptr = ptr->next;
	}
	if (ptr == nullptr) {
		return nullptr;
	}
	return ptr;
}


template<typename T>
void LinkedList<T>::Print() const {
	Node<T> * ptr = front;

	std::cout << "Head is : " << front;
	std::cout << std::endl;
	std::cout << "Tail is : " << back;
	std::cout << std::endl;

	while (ptr != nullptr) {
		std::cout << std::endl;
		std::cout << "current node adress is :" << ptr;
		std::cout << std::endl;
		std::cout << "current node data is :";

		std::cout << ptr->data << " ";

		std::cout << std::endl;
		std::cout << "previous node adress is :" << ptr->previous;
		std::cout << std::endl;
		std::cout << "next node adress is:" << ptr->next;
		std::cout << std::endl;


		ptr = ptr->next;
		std::cout << std::endl;
	}
	std::cout << std::endl;

}


template<typename T>
int LinkedList<T>::Count() const {
	Node<T> * current = front;
	int count = 0;
	while (current != nullptr) {
		current = current->next;
		++count;
	}
	return count;
}



template<typename T>
void LinkedList<T>::InsertAtPosition(int position, T data) {

	int prevPos = 0;
	Node<T> *previosPtr = front;
	while (prevPos != position - 1 && (previosPtr->next != nullptr)) {
		++prevPos;
		previosPtr = previosPtr->next;
	}
	assert(prevPos == position - 1);
	if (position == 0) {
		AddFront(data);
	}
	else if (previosPtr->next == nullptr) {
		AddTail(data);
	}
	else {
		Node<T> *nextPtr = previosPtr->next;
		Node<T> *insertionNode = new Node<T>;
		insertionNode->data = data;
		insertionNode->previous = previosPtr;
		insertionNode->next = nextPtr;
		previosPtr->next = insertionNode;
		nextPtr->previous = insertionNode;
	}
}



template<typename T>
T LinkedList<T>::DeleteAtPosition(int position) {
	if (position == 0) {
		Node<T> *ptr = front;
		front = front->next;
		front->previous = nullptr;
		T value = ptr->data;
		delete ptr;
		return value;
	}

	Node<T> *positionPointer = front;
	int posCounter = 0;
	while (posCounter != position && (positionPointer->next != nullptr)) {
		++posCounter;
		positionPointer = positionPointer->next;
	}
	assert(posCounter == position);
	
	if (positionPointer->next == nullptr) {
		back = back->previous;
		back->next = nullptr;
		T value = positionPointer->data;
		delete positionPointer;
		return value;
	}
	else {
		Node<T> * previousPtr = positionPointer->previous;
		Node<T> * nextPtr = positionPointer->next;
		previousPtr->next = nextPtr;
		nextPtr->previous = previousPtr;
		T value = positionPointer->data;
		delete positionPointer;
		return value;
	}

}