#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//Jose Moreno-Perez. CS162. Dec 6, 2022. Purpose of program is to allow
//user to read in their favorite games and keep track them. This also 
//includes storing information about each game such as its name, number
//of players, type of game, and a description of the game. The list will
//be stored as a linked list rather than an array.

//Final Submission: All tasks have been implemented and work as expected.

const int NAME{21};  //Limit the size of the game's name/type
const int DESC{141}; //Limit size of description

struct game
{
	char *name; //NOTE: ptr arrays dont need to have size defined
	int players{0};
	char type[NAME];
	char desc[DESC];
};

struct node
{
	game item;
	node *next;
};

void readNewGame(game & newNode);
void readAllGames(node* & head);
void buildList(game & object, node* & head);
void displayOneGame(game & object);
void displayAllGames(node * head);
void deleteMemory(node *& head);
