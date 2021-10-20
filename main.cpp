/*
		Author: 		Peter Strong
		Major:			Computer Science
		Creation Date: 	10/07/2021
		Due Date:		10/15/2021
		Course:			CSC 237
		Professor: 		Dr. Spiegel
		Assignment: 	#2
		Filename: 		testLL.cpp
		Purpose: 		driver program to test DblLink Class
						- Prompts user to choose different actions once
						  a doubly linked list and performs those actions
*/

#include <iostream>
#include "Node.h"
#include "DblLink.h"
#include "DblLinkItr.h"

using namespace std;

/*
	Function Name: 	printoptions
	Description:	Prints selection menu to the user
	Parameters: 	n/a
	Return Value: 	n/a
*/
void printOptions();

/*
	Function Name: 	addElements
	Description:	Adds elements in order to the list
	Parameters: 	DblLink<int> & - list being added to
	Return Value: 	n/a
*/
void addElements(DblLink<int> &dblLink);

/*
	Function Name: 	removeElements
	Description:	Removes element from list determined by the user
	Parameters: 	DblLink<int> & - list being removed from
	Return Value: 	n/a
*/
void removeElements(DblLink<int> &dblLink);

int main(){
	char choice;
    DblLink<int> dblLink;

	printOptions();
	cin >> choice;
	while(choice != '5'){
		switch(choice){
			case '1':
				addElements(dblLink);
				break;
			case '2':
				removeElements(dblLink);
				break;
			case '3':
				dblLink.printListForwards(dblLink);
				break;
			case '4':
				dblLink.printListBackwards(dblLink);
				break;
			default:
				break;
		}
		printOptions();
		cin >> choice;
	}

    return 0;
}

// Prints selection menu to the user
void printOptions(){
	cout << "\nMAKE A SELECTION: \n"
		 << "1. Add Elements\n"
		 << "2. Remove Elements\n"
		 << "3. Print List Forwards\n"
		 << "4. Print List Backwards\n"
		 << "5. Exit\n\n"
		 << "ENTER 1-5: ";
}

// Adds elements to list in order
void addElements(DblLink<int> &dblLink){
	int num;
	cout << "Insert: ";
	cin >> num;
	cout << endl;
	dblLink.insert(num);
}

// Removes element from list determined by the user
void removeElements(DblLink<int> &dblLink){
	int num;
	cout << "Remove: ";
	cin >> num;
	cout << endl;
	dblLink.remove(num);
}
