/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/11/2019
Project 2 (Stack)
*/

#ifndef _SLLStack_
#define _SLLStack_
#include "Employee.h"
#include "Lnode.h"

//Header file for singly linked list stack

class SLLStack
{
	public:
		//Constructor
		SLLStack();

		//The copy constructor (performs initialization).
		SLLStack (const SLLStack &s);
		
		//Destructor
		~SLLStack ();
		
		//Place a new item on top of the stack. 
		bool push (const Employee &new_item);

		//Remove and return the top stack item.
		bool pop (Employee &item); 
	
		//Return top stack item without removing it. 
		bool getTop (Employee &item) const;
		
		//Returns true if the stack is empty, otherwise returns false.
		bool is_empty() const;

		//Returns the number of elements in the stack.
		int size() const;

		//Print all the elements in the stack onto the screen. 
		void print() const;
		
		//Prints a certain number of elements in the stack onto the screen.
		void print(int numElements) const;

		//Ovverrides the == operator: checks for Stack equality.
		bool operator == (const SLLStack &s) const;
		

	private:
		Lnode *top;
		// The top of the Linked List based Stack.
		int num; 
		//the number of elements in the stack.

};
#endif