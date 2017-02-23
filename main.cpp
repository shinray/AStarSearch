#include <iostream>
#include "ucs.h"
#include "astar.h"

// void uniformcost() {
	
// }

int main(int argc,char* argv[]){
	int puzzleType;
	int searchType;
	state st = state();
	
	std::cout << "Welcome to skuo004's 8-puzzle solver.\n";
	std::cout << "Type 1 to use a default puzzle, or 2 to"
			<< " enter your own puzzle." << std::endl;
	
	std::cin >> puzzleType;
	
	if(puzzleType == 2)
	{
		unsigned int input;
		std::vector<char> v(9,0);
		std::cout << "\nEnter your puzzle, use a '0' to represent"
				<< " the blank\n"
				<< "Enter the first row, use space or tabs between"
				<< " numbers" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cin >> input;
			v[i] = '0'+ input;
		}
		std::cout << "Enter the second row" << std::endl;
		for (int i = 3; i < 6; i++)
		{
			std::cin >> input;
			v[i] = '0' + input;
		}
		std::cout << "Enter the third row" << std::endl;
		for (int i = 6; i < 9; i++)
		{
			std::cin >> input;
			v[i] = '0' + input;
		}
		
		st = state(v);
	}
	// else {
		// default
		// state st = state();
	// }
	
	std::cout << "Enter your choice of algorithm" << std::endl;
	std::cin >> searchType;
	
	switch(searchType)
	{
		case 1:
		{
			// UCS UCSsearch = UCS(st);
			// UCSsearch.search();
			AStar UCSsearch = AStar(st);
			UCSsearch.search(2); // 2 for no heuristic
			break;
		}
		case 2:
		{
			AStar misplacedsearch = AStar(st);
			misplacedsearch.search(0); // 0 for misplaced
			break;
		}
		case 3:
		{
			AStar manhattansearch = AStar(st);
			manhattansearch.search(1); // 1 for manhattan
			break;
		}
		case 4:
		{
			state teststate = state('1','2','3','4','5','0','6','7','8');
			state teststate2 = state('1','2','3','0','5','6','4','7','8');
			Node testnode = Node(teststate);
			Node testnode2 = Node(testnode2);
			bool testbool = (testnode > testnode2);
			std::cout << "nodetest: " << testbool << '\n';
		}
		default:
			std::cout << "err: unknown searchType\n";
			return 1;
	}
			
	return 0;
}
