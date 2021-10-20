// File: Node.h
// Author: Daniel Spiegel
// Doubly-linked list node definition/implementation

#ifndef NODE_H
#define NODE_H

using namespace std;

// Need to prototype template classes if they are to be friends
template <class eltType> class DblLink;
template <class eltType> class DblLinkItr;

template <class eltType> class Node
{	private:

		/*
			Function Name: 	Node
			Member Type:	Mutator
			Description:	Constructor for Node Class
			Parameters: 	eltType info - data in node
							Node *pLink - pointer behind Node
							Node *rLink - pointer in front of Node
			Return Value: 	Node Object
		*/
		Node(eltType info, Node *pLink = 0, Node *rLink=0)
				   : data(info), prev(pLink), next(rLink) {};
		eltType data;
		Node*	prev;
		Node*	next;
	friend class DblLink<eltType>;
	friend class DblLinkItr<eltType>;
};

#endif
