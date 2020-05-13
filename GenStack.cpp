//Rose Albrecht ealbrecht@chapman.edu 2300456
#include "GenStack.h"
using namespace std;
//constructor(im really hoping that we never have a nest 500 deep...)
GenStack::GenStack()
{
	//char myStack[500];
	char* myStack = new char[500];
	maxSize = 500;
	top = -1;
}
//destructor
GenStack::~GenStack()
{
	//delete myStack;
}
//pushes something to the stack
void GenStack::push(char d)
{
	if (top > 500)
	{
		//check if full before inserting
		cout << "the stack is full -- that doesnt work";
	}
	else
	{
		//myStack[++top] = d;
		myStack[++top] = d;
		//each time we increment and add an element our top will shift over 1
	}
}
//returns the top value without removing it from the stack
char GenStack::peek()
{
	if (top < 0)
	{
		cout << "the stack is empty -- that doesnt work";
		//check if empty before popping
	}
	else
	{
		return myStack[top];
		//when you evaluate you have to move where the top value is so when we look at the top were ignoring stuff over the top value
	}
}
//pops the top value
char GenStack::pop()
{
	if (top < 0)
	{
		cout << "the stack is empty -- that doesnt work";
		//check if empty before popping
	}
	else
	{
		return myStack[top--];
		//when you evaluate you have to move where the top value is so when we look at the top were ignoring stuff over the top value
	}
}
/*int GenStack::size()
{
	return (top + 1);
}
bool GenStack::isFull(int maxSize)
{
	return(top == maxSize - 1);
}*/
//tells us if the stack is empty
bool GenStack::isEmpty()
{
	return (top == -1);
}