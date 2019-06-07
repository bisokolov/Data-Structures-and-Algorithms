// GraphBFSDFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "GraphBFSDFS.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
	Graph g;
	
	g.addVertex("0");
	g.addVertex("1");
	g.addVertex("2");
	g.addVertex("3");
	g.addVertex("4");
	g.addVertex("5");
	g.addVertex("6");
	g.addChild("0", "1");
	g.addChild("0", "2");
	g.addChild("0", "5");
	g.addChild("1", "3");
	g.addChild("3", "4");
	g.addChild("2", "4");
	g.addChild("2", "6");
	g.addChild("5", "6");
	//g.Print();
	
	g.DFS("0");

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
