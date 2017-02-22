#include "ucs.h"

UCS::UCS(state st) {
	root = Node(st);
	stack.push(root);
	//search(stack);
}

// Checks to see if a given node is a repeat
// of any of its parents
bool UCS::isRepeat(Node n) {
	bool ret = false;
	Node tobechecked = n;
	Node* tmp = n.getParent();
	while (!ret && tmp != NULL)
	{
		if (tmp->getState() == tobechecked.getState())
		{
			ret = true;
		}
		tmp = tmp->getParent();
	}
	return ret;
}

void UCS::search() {
	while(!s.empty()) {
		Node tmp = s.top();
		std::cout << "Expanding state\n";
		std::cout << tmp.getState();
		s.pop();
		
		if (!tmp.getState().isGoal()) {
			std::vector<state> tmpchildren = tmp.genChild();
			for (int i = 0; i < tmpchildren.size(); i++)
			{
				Node newNode = Node();
				if(!isRepeat(newNode))
				{
					s.push(newNode);
				}
			}
		}
		else {
			// clear, just in case.
			if (!solution.empty()) {
				solution.clear();
			}
			// start calculating solution
			solution.push_back(tmp);
			//s.pop();
			tmp = *(tmp.getParent());
			
			while (tmp.getParent() != NULL) {
				solution.push_back(tmp);
				tmp = *(tmp.getParent());
			}
			
			// push root node
			solution.push_back(tmp);
			
			// for (int i = 0; i < solution.size(); i++)
			// {
				
			// }
		}
	}
}