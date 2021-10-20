/*
		Author: 		Peter Strong
		Major:			Computer Science
		Creation Date: 	10/07/2021
		Due Date:		10/15/2021
		Course:			CSC 237
		Professor: 		Dr. Spiegel
		Assignment: 	#2
		Filename: 		DblLink.h
		Purpose: 		DbLink class
						- Creates and handles doubly linked lists
*/

#ifndef DBLLINK_H
#define DBLLINK_H

#include <iostream>
#include "Node.h"
#include <assert.h>

using namespace std;

// Must prototype class in order to be friends
template <class eltType> class DblLinkItr;

template <class eltType> class DblLink
{
	public:
		/*
			Function Name: 	DblLink
			Member Type:	Mutator
			Description:	Constructor for DblLink class
			Parameters: 	n/a
			Return Value: 	DblLink object
		*/
		DblLink();

		/*
			Function Name: 	DblLink
			Member Type:	Mutator
			Description:	Copy constructor for DblLink class
			Parameters: 	DblLink& - DblLink being copied
			Return Value: 	DblLink Object
		*/
		DblLink(DblLink&);

		/*
			Function Name: 	~DblLink
			Member Type:	Mutator
			Description:	Destructor for DblLink class
			Parameters: 	n/a
			Return Value: 	n/a
		*/
		~DblLink();

		/*
			Function Name: 	operator=
			Member Type:	Mutator
			Description:	Sets this to be equal to list being passed
			Parameters: 	DblLink& - DblLink being copied
			Return Value: 	DblLink object
		*/
		DblLink& operator=(DblLink& dl);

		/*
			Function Name: 	empty
			Member Type:	Facilitator
			Description:	Returns true if list is empty
			Parameters: 	n/a
			Return Value: 	bool - list is empty
		*/
		bool empty();

		/*
			Function Name: 	insert
			Member Type:	Mutator
			Description:	Inserts elt in order from least to greatest
			Parameters: 	eltType elt - data being added to list
			Return Value: 	n/a
		*/
		void insert(eltType elt);

		/*
			Function Name: 	remove
			Member Type:	Mutator
			Description:	Removes a elt from list determined by the user
			Parameters: 	eltType elt - data being removed
			Return Value: 	n/a
		*/
		void remove(eltType elt);

		/*
			Function Name: 	printListForwards
			Member Type:	Inspector
			Description:	Prints list starting at the first element
			Parameters: 	DblLink& - DblLink being printed
			Return Value: 	n/a
		*/
		void printListForwards(DblLink& dl);

		/*
			Function Name: 	printListBackwards
			Member Type:	Inspector
			Description:	Prints list starting at the last element
			Parameters: 	DblLink& - DblLink being printed
			Return Value: 	n/a
		*/
		void printListBackwards(DblLink& dl);

	private:
		Node<eltType>* head;	// Starting point of list

		/*
			Function Name: 	destroy
			Member Type:	Mutator
			Description:	Destroys a DblLink list
			Parameters: 	Node<eltType> * - first node being deleted
			Return Value: 	n/a
		*/
		void destroy(Node<eltType> *);

	friend class DblLinkItr<eltType>;
};

// Constructor
template <class eltType> DblLink<eltType>::DblLink() : head(NULL)
{}

// Copy Constructor
template <class eltType> DblLink<eltType>::DblLink(DblLink<eltType> &dl){
	if(!dl.empty()){
		head = NULL;

		DblLinkItr<eltType> l(dl);
		for(l.start(); !l.isLastNode(); ++l){
			insert(l.curr->data);
		}
		insert(l.curr->data);
	}
}

//Destructor
template <class eltType> DblLink<eltType>::~DblLink()
{ destroy(head); }

// Destroys a DblLink list
template <class eltType> void DblLink<eltType>::destroy(Node<eltType> *l){
	while(l != NULL){
		Node<eltType> *doomed = l;
		l = l->next;
		delete doomed;
	}
}

// Sets current list equal to another list
template <class eltType> DblLink<eltType> &DblLink<eltType>::operator=(DblLink &dl){
	if(!dl.empty()){
		if(this != &dl){
			destroy(head);

			DblLinkItr<eltType> l(dl);
			for(l.start(); !l.isLastNode(); ++l){
				insert(l.curr->data);
			}
			insert(l.curr->data);
		}
	}
	return *this;
}

// Checks if list is empty, returns true if empty
template <class eltType> bool DblLink<eltType>::empty(){
    return(head == NULL);
}

// Inserts element into list in order from least to greatest
template <class eltType> void DblLink<eltType>::insert(eltType elt){

    if(empty()){
        head = new Node<eltType>(elt, NULL, NULL);

    } else if(elt <= head->data){
        Node<eltType>* p = new Node<eltType>(elt, NULL, head);
        head = p;
        head->next->prev = p;

    } else {
        Node<eltType>* p = head;

        while(p->next != NULL && elt > p->data){
            p = p->next;
        }

		// Insert at end if elt is greater than last elt of list
        if(p->data < elt){
			Node<eltType>* end = new Node<eltType>(elt, p, NULL);
			p->next = end;

        } else {
            Node<eltType>* notEnd = new Node<eltType>(elt, p->prev, p);
			p->prev->next = notEnd;
			p->prev = notEnd;
        }
    }
}

// Removes element from list determined by the user
template <class eltType> void DblLink<eltType>::remove(eltType elt){
	if(empty()){
		cout << "LIST IS EMPTY\n";
	} else {
		Node<eltType>* p = head;

		while(p != NULL && p->data != elt)
			p = p->next;

		// One node in list
		if(p->prev == NULL && p->next == NULL){
			head = NULL;
			delete p;
		} else {
			// First node
			if(p->prev == NULL){
				head = head->next;
				head->prev = NULL;
				delete p;
			}
			// Last node
			else if(p->next == NULL){
				p->prev->next = NULL;
				delete p;

			} else {	// Middle node
				p->prev->next = p->next;
				p->next->prev = p->prev;
				delete p;
			}
		}
	}
}

// Prints list starting at the first node
template <class eltType> void DblLink<eltType>::printListForwards(DblLink &dl){
	DblLinkItr<eltType> l(dl);

	if(l.isEmpty()){
		cout << "LIST IS EMPTY\n";
	} else {
		for(l.start(); !l.isLastNode(); ++l){
			l();
		}
		l();
		cout << endl;
	}
}

// Prints list starting at the last node
template <class eltType> void DblLink<eltType>::printListBackwards(DblLink &dl) {
	DblLinkItr<eltType> l(dl);

	 if(l.isEmpty()){
		cout << "LIST IS EMPTY\n";
	 } else {
		for(l.start(); !l.isLastNode(); ++l);	// Moves iterator to last item
		for(; !l.isFirstNode(); --l){
			l();
		}
		l();
		cout << endl;
	 }
}

#endif
