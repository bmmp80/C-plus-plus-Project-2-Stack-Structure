/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/11/2019
Project 2 (Stack)
*/
#ifndef _Employee_
#define _Employee_

#include <cstdlib>
#include <iostream>
#include <string>

//header file for employee

class Employee
{
public:
	Employee();
	Employee(int IdNum, std::string last, std::string first);
	Employee(const Employee &person);
	~Employee();
	void setFirstName(std::string first);
	void setLastName(std::string last);
	void setID(int IdNum);
	int getID();
	std::string getFirstName();
	std::string getLastName();
	friend std::ostream& operator<<(std::ostream &outs, Employee &person);
	friend std::istream& operator>>(std::istream &ins, Employee &person);
	void print();
private:
	int ID;
	std::string lastname;
	std::string firstname;
};
#endif


