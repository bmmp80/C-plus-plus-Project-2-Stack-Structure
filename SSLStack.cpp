/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/11/2019
Project 2 (Stack)
*/
#include "SSLStack.h"
#include "Lnode.h"
using namespace std;

//This file creates a stack data structure

//constructor
SLLStack::SLLStack()
{
	top = nullptr;
	num = 0;
}

//copy constructor	
SLLStack::SLLStack(const SLLStack& s)
{
	num = s.num;
	Lnode* nextNode = s.top;
	Lnode* prev = nullptr;
	//copying each element of the list
	while (nextNode != nullptr)
	{
		Lnode* newNode = new Lnode(nextNode->NewEmployee);
		if (prev == nullptr) //if it is the first element in the list
		{
			top = newNode;
		}
		else
		{
			prev->next = newNode;
		}
		prev = newNode;
		nextNode = nextNode->next;
	}
}

//destructor
SLLStack::~SLLStack()
{
	num = 0;
	Lnode* nextNode = top;
	Lnode* copy;

	//deleting each element of the list
	while (nextNode != nullptr)
	{
		copy = nextNode->next;
		delete nextNode;
		nextNode = copy;
	}
}

//Place a new item on top of the stack. 
bool SLLStack::push(const Employee& new_item)
{
	Lnode* newNode = new Lnode(new_item);
	if (top == nullptr)
	{
		top = newNode;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
	num++;
	return true;
}

//Remove and return the top stack item. Check if stack is empty.
bool SLLStack::pop(Employee& item)
{
	//if stack is empty
	if (num == 0)
	{
		return false;
	}
	else
	{
		item = top->NewEmployee;
		Lnode* newTop = top->next;
		delete top;
		top = newTop;
		num--;
		return true;
	}
}

// Return top stack item without removing it. 
bool SLLStack::getTop(Employee &item) const
{
	//if stack is empty
	if (num == 0)
	{
		return false;
	}
	else
	{
		item = top->NewEmployee;
		return true;
	}
}


// Returns true if the stack is empty, otherwise returns false.
bool SLLStack::is_empty() const
{
	return(num == 0);
}

// Returns the number of elements in the stack.
int SLLStack::size() const
{
	return num;
}

//Print all the elements in the stack onto the screen.
void SLLStack::print() const
{
	Lnode* nextNode = top;
	//printing each element of the list
	while (nextNode != nullptr)
	{
		cout << nextNode->NewEmployee;
		nextNode = nextNode->next;
	}
}
 
//Checks for stack equality.
bool SLLStack::operator == (const SLLStack& s) const
{
	if (num != s.num)
	{
		return false;
	}
		
	Lnode* nextNode1 = s.top;
	Lnode* nextNode2 = top;

	//comparing each element from the original stack
	while ((nextNode1 != nullptr) && (nextNode2 != nullptr))
	{
		if((nextNode1->NewEmployee.getID() == nextNode2->NewEmployee.getID()) 
		&& (nextNode1->NewEmployee.getFirstName() == nextNode2->NewEmployee.getFirstName()) 
		&& (nextNode1->NewEmployee.getLastName() == nextNode2->NewEmployee.getLastName()))
		{
			nextNode1 = nextNode1->next;
			nextNode2 = nextNode2->next;
		}
		else
		{
			return false;
		}
	}
	return true;
}

//print a certain number of elements
void SLLStack::print(int numElements) const
{
	Lnode* nextNode = top;
	//printing each element of the list
	while ((nextNode != nullptr) && (numElements > 0))
	{
		cout << nextNode->NewEmployee;
		nextNode = nextNode->next;
		numElements--;
	}
}