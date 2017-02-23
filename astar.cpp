#include "astar.h"



AStar::AStar(state st) {
	Node *root = new Node(st);
	q.push(root);
	nodelist.push_back(root);
	return;
}

// Checks to see if a given node is a repeat
// of any of its parents
bool AStar::isRepeat(Node n) {
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

void AStar::search(int heuristic)
{
	int nodeCount = 0;
	int maxQsize = 1;
	int currQsize = 1;
	while(!q.empty()) {
		Node* tmp = q.top();
		std::cout << "Expanding state\n";
		std::cout << tmp->getState();
		q.pop();
		currQsize--;
		
		// second explored check
		if (std::find(explored.begin(), explored.end(), tmp->getState()) != explored.end())
		{ // if already explored, continue loop
			continue;
		}
		
		if (tmp->getState().isGoal()) {
			int finalDepth = tmp->getDepth();
			// clear, just in case.
			if (!solution.empty()) {
				solution.clear();
			}
			// start calculating solution
			solution.push_back(*tmp);
			tmp = tmp->getParent();
			
			while (tmp != NULL) {
				solution.push_back(*tmp);
				tmp = tmp->getParent();
			}
			std::cout << "\nNodes expanded: " << nodeCount << '\n';
			std::cout << "Max queue size: " << maxQsize << '\n';
			std::cout << "Goal node depth: " << finalDepth << '\n';
			std::cout << "soln size: " << solution.size() << '\n';
			switch(heuristic)
			{
				case 0:
					std::cout << "heuristic: misplaced tile\n";
					break;
				case 1:
					std::cout << "heuristic: manhattan dist\n";
					break;
				case 2:
					std::cout << "heuristic: none (uniform cost search)\n";
					break;
				default:
					std::cout << "astar: unknown heuristic\n";
					break;
			}
			return;
		}
		else {
			explored.push_back(tmp->getState());
			nodeCount++;
			std::vector<state> tmpchildren = tmp->genChild();
			for (unsigned i = 0; i < tmpchildren.size(); i++)
			{
				//Node newNode = Node(tmpchildren[i], tmp);
				Node* newNode = new Node(tmpchildren[i], tmp);
				nodelist.push_back(newNode);
				//if(!isRepeat(*newNode))
				
				
				if (std::find(explored.begin(), explored.end(), newNode->getState()) == explored.end())
				{// if not found then push
					q.push(newNode);
					// if Misplaced
					if(heuristic == 2) // UCS
					{
						
					}
					else if (heuristic == 0)
					{
						newNode->misplaced(); // calculate hcost
					}
					// if manhattan
					else if (heuristic == 1)
					{
						newNode->manDist(); // calculate hcost
					}
					else{
						std::cout << "astar: invalid heuristic\n";
						exit(1);
					}
					currQsize++;
					// calculates max
					maxQsize = (currQsize > maxQsize) ? currQsize : maxQsize;
				}
			}
		}
		Node* next = q.top();
		std::cout << "The best state to expand with a g(n) = " << 
			next->getDepth() << " and h(n) = " << next->hcost_() << " is...\n";
		/*
		if (!tmp->getState().isGoal()) {
			nodeCount++; // expanding node
			std::vector<state> tmpchildren = tmp->genChild();
			//std::priority_queue<Node*> 
			for (unsigned i = 0; i < tmpchildren.size(); i++)
			{
				Node* newNode = new Node(tmpchildren[i], tmp);
				// if Misplaced
				if (heuristic == 0)
				{
					newNode->misplaced(); // calculate hcost
				}
				// if manhattan
				else if (heuristic == 1)
				{
					newNode->manDist(); // calculate hcost
				}
				else{
					std::cout << "astar: invalid heuristic\n";
					exit(1);
				}
				
				nodelist.push_back(newNode); // to be deleted
				if(!isRepeat(*newNode))
				{
					q.push(newNode); // only push after cost is calculated
					currQsize++;
					// calculates max
					maxQsize = (currQsize > maxQsize) ? currQsize : maxQsize;
				}
			}
		}
		else {
			int finalDepth = tmp->getDepth();
			if (!solution.empty()) {
				solution.clear();
			}
			// start calculating solution
			solution.push_back(*tmp);
			tmp = tmp->getParent();
			while (tmp != NULL) {
				solution.push_back(*tmp);
				tmp = tmp->getParent();
			}
			std::cout << "\nNodes expanded: " << nodeCount << '\n';
			std::cout << "Max queue size: " << maxQsize << '\n';
			std::cout << "Goal node depth: " << finalDepth << '\n';
			return;
		}
		*/
	}
	std::cout << "\nA*: ERROR: queue emptied!\n";
}

// destructor
AStar::~AStar() {
	for(Node *n : nodelist){
		delete n;
	}
}
