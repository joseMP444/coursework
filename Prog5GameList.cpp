#include "Prog5_header.h"

//Jose Moreno-Perez. CS162. Dec 6, 2022. This is where I implement 
//the functions initialized in my header file. The basic idea is 
//to pass a head pointer between functions to be able to read into
//a linked list as well as display the contents of the list.


//Checking for special cases, all dynamic memory in the list is
//released, including the dynamic arrays used to store the name
//of the games.
void deleteMemory(node *& head)
{
	if (!head) {
		return;
	} else if (!head->next) {
		delete head;
	} else {
		node *temp = nullptr;
		
		while(head != NULL)
		{
			temp = head->next;
			//cout << head->item.name << " will be deleted." << endl;
			delete [] head->item.name;
			//cout << "Game has been deleted." << endl;
			delete head;
			head = temp;
		}

		cout << "All games in the list have been deleted." << endl;
	}
}

//Using a while loop, traversal is performed to echo out
//each node's object and its contents out to the user.
void displayAllGames(node * head)
{
	node *current = head;
	
	cout << "This list currently contains:\n" << endl;

	while(NULL != current)
	{
		displayOneGame(current->item);
		current = current->next;
	}
}

//Once a node's data is passed in, its contents are displayed
//out to the user.
void displayOneGame(game & object)
{
	cout << "Name:\t" << object.name
	     << "\n# of Players\t" << object.players
	     << "\nType:\t" << object.type
	     << "\nDescription:\t" << object.desc
	     << endl << endl;
}


//Adding a node to the list. If the list is empty and head is NULL
//head is initialized to contain the data for the first game in the
//list and its 'next' pointer is set to NULL;
void buildList(node* & head)
{
	if(!head)
	{
		head = new node;
		readNewGame(head->item);
		head->next = NULL;
		return; //Allows us to return to readAllGames function 
			//to allow user the choice of continuing to add
			//to the list.
	}

	node *current = head;

	while(current->next != NULL)
	{
		current = current->next;
	}

	current->next = new node;
	current = current->next;
	readNewGame(current->item);
	current->next = NULL;
}

//While the user wants to continue, more and more items will
//be added to a linked list, implemented above.
void readAllGames(node *& head)
{
	char response{'Y'};

	do 
	{
		cout << "Would you like to read in a new game? Y/N"
		     << endl;
		cin >> response;
		cin.ignore(100, '\n');
		
		if('N' == toupper(response)) break;

		else
		{
			buildList(head); 	
		}	
	} while('Y' == toupper(response));

}

//Each item in my list of games will be stored as a node in a linked list.
//the parameter being passed in will be called within another function
//that will create and append the new node.
void readNewGame(game & newNode)
{
	newNode.name = new char[NAME];

	cout << "Please enter the name of the game you want to save:"
	     << endl;
	cin.get(newNode.name, NAME, '\n');
	cin.ignore(100, '\n');

	cout << "Enter the number of players this game can host at\n"
	     << "a time:" << endl;
	cin >> newNode.players;
	cin.ignore(100, '\n');

	cout << "Now, enter in the type of game this is (for example:\n"
	     << "board game, PC, card game, etc):" << endl;
	cin.get(newNode.type, NAME, '\n');
	cin.ignore(100, '\n');

	cout << "Lastly, enter in a short description of the game:"
	     << endl;
	cin.get(newNode.desc, DESC, '\n');
	cin.ignore(100, '\n');
}

