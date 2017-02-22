#include "astar.h"

#include "node.h"

AStar::AStar(state st) {
	Node *root = new Node(st);
}

void AStar::search()
{
	
}

// destructor
AStar::~AStar() {
	// for(Node *n : nodelist){
		// delete n;
	// }
}
