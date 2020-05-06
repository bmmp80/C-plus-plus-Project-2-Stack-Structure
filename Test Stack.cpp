// Name: Brandon Prenger
// Email: prenger.30@wright.edu
// Course Number: CS3100
// Course: Data Structures and Algorithms
// Instructor: Meilin Liu
// Date: 06/12/2019
// Project: Stack (Project #2)


#include "SSLStack.h"
#include "Lnode.h"
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	//file to open: C:\Users\Brandon\Desktop\CS3100\Projects\Project2\Employee-Database.txt
	cout << "input queue number of records you would like to read: ";
	int capacity;
	cin >> capacity;

	SLLStack myStack;
	string filename;
	cout << "which file do you want to open? ";
	cin >> filename;

	ifstream my_stream;
	my_stream.open(filename);
	if (my_stream.is_open())
	{
		cout << "open file" << endl;
		string line;
		Employee nextEmployee;
		for (int i = 0; i < capacity; i++) 		
		{
			my_stream >> nextEmployee;
			nextEmployee.print();
			myStack.push(nextEmployee);
		}

		bool quit = false;
		int option = 100;
		while (!quit)
		{

			cout << "1 to push" << endl;
			cout << "2 to pop" << endl;
			cout << "3 to check top" << endl;
			cout << "4 to print the stack" << endl;
			cout << "5 to save the stack to a file" << endl;
			cout << "6 to quit the program" << endl;
			cin >> option;

			Employee inputEmployee;
			switch (option)
			{

			case 1:
				//push		
				//print number of elements
				//print 5 records if stack is > 5
				cout << "Enter an employee record (last name, first name, ID): ";
				cin >> inputEmployee;
				myStack.push(inputEmployee);
				cout << "stack size: " << myStack.size() << endl;

				//print out last 5 elements
				myStack.print(5);
					break;

			case 2:
				//pop
				/*Pop: prompt user for a number, and if the number of the elements in the 
				stack is larger than the number entered by the user, pop the specified number 
				of the elements from the stack, and print the employee records popped from 
				the stack, and the remaining number of the elements in the stack to the screen. 
				Otherwise, pop all the elements from the stack.*/
				int numRecords;
				cout << "Enter the number of employee records you would like to pop: " << endl;
				cin >> numRecords;
				if (myStack.size() > numRecords)
				{
					while (numRecords > 0)
					{
						myStack.pop(inputEmployee);
						cout << inputEmployee;
						numRecords--;
					}
					cout << "Remaining number of elements: " << myStack.size() << endl;
				}
				else
				{
					while (myStack.size() > 0)
					{
						myStack.pop(inputEmployee);
					}
				}

				if (myStack.pop(inputEmployee) == false)
				{
					cout << "Error: stack is empty";
				}
				break;
			case 3:
				//check top
				/*Top: print the employee record on the top of the stack and 
				the remaining number of the elements in the stack to the screen. */
				myStack.pop(inputEmployee);
				cout << "Remaining number of elements: " << myStack.size() << endl;
				break;
			case 4:
				//print stack
				myStack.print();
				break;
			case 5:
				/*Save: save all the elements in a stack to a file on the disk.*/

				/*Old save method:
				cout << "Enter output file name: ";
				string fileName;
				cin >> fileName;
				Qqueue Qcopy(newQueue);
				ofstream outfile(fileName);
				int size = newQueue.size();
				for (int i = 0; i < size; i++)
				{
					string lastName = Qcopy.dequeue();
					outfile << lastName << endl;
				}
				outfile.close();
				break;*/
				break;
			case 6:
			{
				//quit
				quit = true;
				break;
			}

			default:
				cout << "Error: reached default case" << endl;
				break;
			}

		}
		my_stream.close();
	}
	else
	{
		cout << "Error: unable to open file";
	}
	return 0;
}