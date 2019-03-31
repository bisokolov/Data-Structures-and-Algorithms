#pragma once
#include "pch.h"


template<typename T>
void Merge(T* arr, int leftIndex, int median, int rightIndex) {

	int leftSize = median - leftIndex + 1;
	int rightSize = rightIndex - median;
	T* Left= new T[leftSize];
	T* Right = new T[rightSize];

	for (int i = 0;i < leftSize;++i) {
		Left[i] = arr[leftIndex +i];
	}
	for (int j = 0;j < rightSize;++j) {
		Right[j] = arr[median + j+1];
	}
	
	int leftIterate = 0;
	int rightIterate = 0 ;
	int mainIterate = leftIndex;
	while (leftIterate < leftSize && rightIterate < rightSize) {
		if (Left[leftIterate] <= Right[rightIterate]) {
			arr[mainIterate] = Left[leftIterate];
			++leftIterate;
			
			
		}
		else {
			arr[mainIterate] = Right[rightIterate];
			++rightIterate;
			
		}
		++mainIterate;
	}

	while (leftIterate < leftSize) {
		arr[mainIterate] = Left[leftIterate];
		++leftIterate;
		++mainIterate;
	}

	while (rightIterate < rightSize) {
		arr[mainIterate] = Right[rightIterate];
		++rightIterate;
		++mainIterate;
	}
	delete[] Left;
	delete[] Right;
}

template<typename T>
void MergeSort(T * arr, int leftIndex, int rightIndex) {

	if(leftIndex<rightIndex) {
	int median = (leftIndex + rightIndex) / 2;
	MergeSort(arr, leftIndex, median);
	MergeSort(arr, median + 1, rightIndex);
	Merge(arr, leftIndex, median, rightIndex);
	}
}