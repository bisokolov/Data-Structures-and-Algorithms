
#include "pch.h"
#include <iostream>
#include "stackImplementation.h"

int main()
{
	Stack<int> test{ 10 };
	test.push(5);
	test.push(14);
	test.push(3);
	test.push(12);
	test.push(35);
	test.push(30);

	test.testPrint();

	Stack<int> testTwo;
	testTwo = test;
	testTwo.testPrint();
	
	/*


	std::cout << "Top element is: " << test.top() << std::endl;

	test.pop();
	std::cout << "Next top element is: " << test.top() << std::endl;

	test.pop();
	std::cout << "Next top element is: " << test.top() << std::endl;
	*/

	/*
	Stack<int> var;
	var.push(4);
	std::cout << var.top() << std::endl;
	std::cout << var.getCapacity() << std::endl;
	var.push(6);
	std::cout << var.top() << std::endl;
	std::cout << var.getCapacity() << std::endl;
	var.push(3);
	std::cout << var.top() << std::endl;
	std::cout << var.getCapacity() << std::endl;
	var.push(300);
	std::cout << var.top() << std::endl;
	std::cout << var.getCapacity() << std::endl;
	var.push(300);
	std::cout << var.top() << std::endl;
	std::cout << var.getCapacity() << std::endl;
	*/


	system("Pause");
	return 0;

}



