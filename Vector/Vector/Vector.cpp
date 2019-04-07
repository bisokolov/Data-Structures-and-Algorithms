// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Vector.h"

int main()
{
	
	Vector<int> vec;
	Vector<int> vec2;
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(3);

	vec2.push_back(10);
	vec2.push_back(11);
	vec2.push_back(12);

	Vector<int> vec3 = vec + vec2;
	vec3 += vec;
	vec3.Print();

	/*
	Vector<int> myVector(4);
	myVector.push_back(3);
	myVector.push_back(7);
	myVector.push_back(1);

	myVector.Print();


	Vector<int> otherVector(myVector);
	
	otherVector.push_back(100);
	otherVector.push_back(200);
	otherVector.push_back(500);
	otherVector.resize(30);

	otherVector.Print();
    std::cout << "Hello World!\n"; 
	*/
	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
