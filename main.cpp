#include <iostream>
#include "ucs.h"
#include "state.cpp"

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
			UCS UCSsearch = UCS(st);
			UCSsearch.search();
			break;
		}
		case 2:
			break;
		case 3:
			break;
		default:
			std::cout << "err: unknown searchType\n";
			return 1;
	}
			
	return 0;
}
