/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/11/2019
Project 2 (Stack)
*/
#ifndef _Lnode_
#define  _Lnode_

#include <cstdlib>
#include "Employee.h"

//header file for Lnode

class Lnode
{
	public:
		Employee NewEmployee;
		Lnode *next;
		Lnode() 
		{
			next = nullptr;
		}
		Lnode(Employee NewPerson) 
		{
			NewEmployee = NewPerson; next = nullptr;
		}
};


#endif