

#include "pch.h"
#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int> st;
	
	st.push(3);
	st.push(4);
	st.push(6);
	Stack<int> st2(st);
	
	st2.pop();
	st.push(10);
	st.push(20);
	st.pop();

    

}

