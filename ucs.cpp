#include "ucs.h"
#include "state.h"
#include "node.h"


UCS::UCS(state st) {
	Node* root = new Node(st);
	q.push(root);
	nodelist.push_back(root);
	//search(stack);
	return;
}

// destructor
UCS::~UCS() {
	for(Node *n : nodelist){
		delete n;
	}
}

// Checks to see if a given node is a repeat
// of any of its parents
bool UCS::isRepeat(Node n) {
	bool ret = false;
	Node tobechecked = n;
	Node* tmp = n.getParent();
	while (!ret && tmp != NULL)
	{
		if (tmp->getState().getState() == tobechecked.getState().getState())
		{
			ret = true;
		}
		tmp = tmp->getParent();
	}
	return ret;
}

void UCS::search() {
	while(!q.empty()) {
		Node* tmp = q.front();
		std::cout << "Expanding state\n";
		std::cout << tmp->getState();
		q.pop();
		
		if (!tmp->getState().isGoal()) {
			std::vector<state> tmpchildren = tmp->genChild();
			for (unsigned i = 0; i < tmpchildren.size(); i++)
			{
				//Node newNode = Node(tmpchildren[i], tmp);
				Node* newNode = new Node(tmpchildren[i], tmp);
				nodelist.push_back(newNode);
				if(!isRepeat(*newNode))
				{
					q.push(newNode);
				}
			}
		}
		else {
			// clear, just in case.
			if (!solution.empty()) {
				solution.clear();
			}
			// start calculating solution
			solution.push_back(*tmp);
			//s.pop();
			tmp = tmp->getParent();
			
			while (tmp != NULL) {
				solution.push_back(*tmp);
				tmp = tmp->getParent();
			}
			
			// push root node
			//solution.push_back(*tmp);
			
			// for (int i = 0; i < solution.size(); i++)
			// {
				
			// }
			return;
		}
	}
}
