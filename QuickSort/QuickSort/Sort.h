#pragma once
#include "pch.h"

template<typename T>
int partition(T *arr, int leftIndex, int rightIndex) {
	T splitter = arr[rightIndex];
	//partitionIndexs points to the first element bigger than the splitter, if such element exists
	int partitionIndex = leftIndex;
	for (int i = leftIndex;i < rightIndex ;++i) {
		if (arr[i] < splitter) {
			T temp = arr[i];
			arr[i] = arr[partitionIndex];
			arr[partitionIndex] = temp;
 			++partitionIndex;
		}
	}
	T temp = arr[rightIndex];
	arr[rightIndex] = arr[partitionIndex];
	arr[partitionIndex] = temp;
	return partitionIndex;
}

template<typename T>
void QuickSort(T * arr, int leftIndex, int rightIndex) {
	if (leftIndex < rightIndex) {
		int partitionIndex = partition(arr, leftIndex, rightIndex);
		QuickSort(arr, leftIndex, partitionIndex - 1);
		QuickSort(arr, partitionIndex + 1, rightIndex);
	}
}


template<typename T>
void QuickSortVTwo(T *arr, int leftIndex, int rightIndex) {
	while (leftIndex < rightIndex) {
		int partitionIndex = partition(arr, leftIndex, rightIndex);
		if ((partitionIndex - leftIndex) < (rightIndex - partitionIndex)) {
			QuickSortVTwo(arr,leftIndex,partitionIndex-1);
			leftIndex = partitionIndex +1;
		}
		else {
			QuickSortVTwo(arr,partitionIndex+1,rightIndex);
			rightIndex= partitionIndex-1;
		}

	}
}