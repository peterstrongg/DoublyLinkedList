/*
		Author: 		Peter Strong
		Major:			Computer Science
		Creation Date: 	10/07/2021
		Due Date:		10/15/2021
		Course:			CSC 237
		Professor: 		Dr. Spiegel
		Assignment: 	#2
		Filename: 		DblLinkItr.h
		Purpose: 		DbLinkItr Class 
						- Iterator for a DblLink object,
							iterates through the list using
							various functions
*/

#ifndef DBLLINKITR_H
#define DBLLINKITR_H

#include <iostream>
#include "Node.h"
#include "DblLink.h"

using namespace std;

template <class eltType> class DblLink;

template <class eltType> class DblLinkItr
{
	public:
		/*
			Function Name: 	DblLinkItr
			Member Type:	Mutator
			Description:	Constructor for DblLinkItr Iclass
			Parameters: 	DblLink<eltType> &dl - iterators list
			Return Value: 	DblLinkItr object
		*/
		DblLinkItr(DblLink<eltType> &dl);

		/*
			Function Name: 	DblLinkItr
			Member Type:	Mutator
			Description:	Constructor for DblLinkItr Iclass
			Parameters: 	const DblLink<eltType> &dl - iterators list
			Return Value: 	DblLinkItr object
		*/
		DblLinkItr(const DblLink<eltType> &dl);


		/*
			Function Name: 	start
			Member Type:	Mutator
			Description:	Sets the iterator at the head of the list
			Parameters: 	n/a
			Return Value: 	n/a
		*/
		void start();

		/*
			Function Name: 	isEmpty
			Member Type:	Facilitator
			Description:	Returns true if iterator's list is empty
			Parameters: 	n/a
			Return Value: 	bool - true if list is empty
		*/
		bool isEmpty();

		/*
			Function Name: 	isLastNode
			Member Type:	Facilitator
			Description:	Returns true if iterator is at the last node
			Parameters: 	n/a
			Return Value: 	bool - true if iterator is at last node
		*/
		bool isLastNode();

		/*
			Function Name: 	isFirstNode
			Member Type:	Facilitator
			Description:	Returns true if iterator is at the first node
			Parameters: 	n/a
			Return Value: 	bool - true if iterator is at first node
		*/
		bool isFirstNode();


		/*
			Function Name: 	operator()
			Member Type:	Inspector
			Description:	Prints iterator's node data
			Parameters: 	n/a
			Return Value: 	DblLinkItr object
		*/
		DblLinkItr& operator()();

		/*
			Function Name: 	operator++
			Member Type:	Mutator
			Description:	Moves iterator to next node in list
			Parameters: 	n/a
			Return Value: 	DblLinkItr object
		*/
		DblLinkItr& operator++();

		/*
			Function Name: 	operator--
			Member Type:	Mutator
			Description:	Moves iterator to previous node in list
			Parameters: 	n/a
			Return Value: 	DblLinkItr object
		*/
		DblLinkItr& operator--();

	private:
		const DblLink<eltType> &itr;
		Node<eltType> *curr;

	friend class DblLink<eltType>;
};

// Constructor
template <class eltType> DblLinkItr<eltType>::DblLinkItr(DblLink<eltType> &dl) : itr(dl), curr(dl.head)
{}

// Constructor
template <class eltType> DblLinkItr<eltType>::DblLinkItr(const DblLink<eltType> &dl) : itr(dl), curr(dl.head)
{}


// Moves iterator to start of list
template <class eltType> void DblLinkItr<eltType>::start()
{curr = itr.head;}


// Checks if list is empty
template <class eltType> bool DblLinkItr<eltType>::isEmpty()
{return curr == NULL;}


// Checks if iterator is at last node
template <class eltType> bool DblLinkItr<eltType>::isLastNode() {
	if(!isEmpty() && curr->next != NULL)
		return false;
	return true;
}


// Checks if iterator is at first node
template <class eltType> bool DblLinkItr<eltType>::isFirstNode() {
	if(curr->prev == NULL)
		return true;
	return false;
}

// Prints data for iterator's current node
template <class eltType> DblLinkItr<eltType> &DblLinkItr<eltType>::operator()(){
	cout << curr->data << " ";
	return *this;
}

// Moves iterator to next node in list
template <class eltType> DblLinkItr<eltType> &DblLinkItr<eltType>::operator++() {
	curr = curr->next;
	return *this;
}

// Moves iterator to previous node in list
template <class eltType> DblLinkItr<eltType> &DblLinkItr<eltType>::operator--() {
	curr = curr->prev;
	return *this;
}

#endif
