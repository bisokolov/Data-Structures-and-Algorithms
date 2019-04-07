#pragma once

template<typename T,int MAX_SIZE>
class Heap {

	int parent(int position) {
		return (position - 1) / 2;
	}
	int leftChild(int position) {
		return position * 2 + 1;
	}
	int rightChild(int position) {
		return position * 2 + 1;
	}


private:
	T arr[MAX_SIZE];
	int currentSize;
};