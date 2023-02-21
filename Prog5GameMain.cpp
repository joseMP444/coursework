#include "Prog5_header.h"

//Jose Moreno-Perez. CS162. Dec 6, 2022.
//This is the main body of code used to call implemented functions
//and build a linked list containing the user's favorite games.
//Main calls on the readAllGames function to allow user to build 
//their list, creating new nodes, and the display function allows
//traversal through each node to display. At the end the list is
//destroyed and memory is released back to the heap.

int main()
{
	node *head = nullptr; //represents our first node/first game in list

	readAllGames(head);
	displayAllGames(head);

	deleteMemory(head);
	
	return 0;
}
