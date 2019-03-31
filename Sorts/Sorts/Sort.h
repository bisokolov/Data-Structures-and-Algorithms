#pragma once
#include "pch.h"


template<typename T>
void InsertionSort(T * arr, int numberOfElements) {
	// elements with index < i are sorted
	for (int i = 1;i < numberOfElements;i++) {
		int j = i - 1; 
		while (j >= 0 && arr[j] > arr[j + 1]) {
			T temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			--j;
		}


	}
}

template<typename T>
void InsertionSortV2(T * arr, int numberOfElements) {
	// inserts directly in it's place
	for (int i = 1;i < numberOfElements;i++) {
		T key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;

	}
}


template<typename T>
void SelectionSort(T* arr, int numberOfElements) {
	for (int i = 0;i < numberOfElements - 1;++i) {
		int minimalIndex = i;
		for (int j = i + 1;j < numberOfElements;++j) {
			if (arr[j] < arr[minimalIndex]) {
				minimalIndex = j;
			}
		}
		if (minimalIndex != i) {
			T temp = arr[i];
			arr[i] = arr[minimalIndex];
			arr[minimalIndex] = temp;
		}
			
	}
}


template<typename T>
void BubbleSort(T* arr, int numberOfElements) {
	for (int i = 0;i < numberOfElements-1;++i) {

		for (int j = 0;j < numberOfElements - i-1;++j) {
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}