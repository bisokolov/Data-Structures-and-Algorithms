#include "pch.h"
#include "string"
#include "list"




struct Node {
	int value;
	Node * next;
};

struct Edge {
	int source, destination;
};

class Graph {
public:


private:
	int numberOfNodes;
	Node * getAdjListNode(int destination, Node* head);
};
Node* Graph::getAdjListNode(int destination, Node* head) {
	Node* newNode = new Node;
}


