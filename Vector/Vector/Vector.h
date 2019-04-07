#pragma once
#include "pch.h"
#include <iostream>

template<typename T>
class Vector {
public:

	Vector(int maxSize = 1);
	Vector(const Vector<T> &);
	Vector<T> & operator=(const Vector<T> &);
	void push_back(const T);
	void resize(int);
	void reserve(int);
	void Print() const;
	T GetAt(const int) const ;
	void SetAt(const int, const T &);
	Vector<T> operator+ (const Vector<T> &) const ;
	Vector<T>& operator+= (const Vector<T> &);
private:
	T *arr;
	int size;
	int max_size;

	void copyVector(const Vector<T> &, int);
	void deleteVector();
};

template<typename T>
Vector<T>::Vector(int maxSize) {
	this->size = 0;
	this->max_size = maxSize;
	arr = new T[this->max_size];
}


template<typename T>
void Vector<T>::resize(int size) {
	if (size <= this->max_size) {
		this->size = size;
	}
	else {
		Vector<T> temp(*this);
		deleteVector();
		copyVector(temp, size);

	}
}


template<typename T>
void Vector<T>::reserve(int maxSize) {
	this->size = 0;
	this->max_size = maxSize;
	this->arr = new T[maxSize];
}


template<typename T>
void Vector<T>::deleteVector() {
	delete[] arr;
	this->size = 0;
	this->max_size = 0;
	this->arr = nullptr;
}




template<typename T>
void Vector<T>::copyVector(const Vector<T> & other, int maxSize) {
	this->size = other.size;
	this->max_size = maxSize;
	this->arr = new T[this->max_size];
	for (int i = 0;i < this->size;++i) {
		this->arr[i] = other.arr[i];
	}

}


template<typename T>
Vector<T>::Vector(const Vector<T> & other) {
	copyVector(other,other.max_size);
}

template<typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> & other) {
	if (this != &other) {
		deleteVector();
		copyVector(other,other.max_size);
	}
}


template<typename T>
void Vector<T>::push_back(const T element) {
	if (size < max_size) {
		arr[size] = element;
		++size;
	}
	else {
		Vector<T> temp(*this);
		deleteVector();
		copyVector(temp,temp.max_size * 2);
		arr[size] = element;
		++size;

	}
}


template<typename T>
void Vector<T>::Print() const {
	for (int i = 0;i < size;++i) {
		std::cout << "Element i : " << arr[i] << std::endl;
	}
	std::cout << "Size is :" << this->size << std::endl;
	std::cout << "Max size is :" << this->max_size;
	std::cout << std::endl << std::endl << " Bye " << std::endl;
}


template<typename T>
T Vector<T>::GetAt(const int index) const {
	return this->arr[index];
}

template<typename T>
void Vector<T>::SetAt(const int index, const T & value) {
	this->arr[index] = value;
}


template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T> & other) const {
	Vector<T> returnVector(this->size + other.size);
	for (int i = 0;i < this->size;++i) {
		returnVector.push_back(this->arr[i]);
	}
	for (int i = 0;i < other.size;++i) {
		returnVector.push_back(other.arr[i]);
	}
	return returnVector;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T> & other)  {
	this->resize(this->size + other.size);
	this->max_size = this->size + other.size;
	for (int i = 0;i < other.size;++i) {
		this->push_back(other.arr[i]);
	}
	return *this;
}