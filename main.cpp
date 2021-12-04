#include <iostream>
#include <random>

#include "BlackjackGame.h"

void gameInit()
{
	// get player name
	cout << "Enter the player's first name: ";
	string name;
	cin >> name;

	// initialize game object
	BlackjackGame bg(name);

	// play game
	char ch;
	do 
	{
		bg.playGame();
		cout << " ----- TOTAL SCORE: " << bg.getTotalScore() << endl;
		cout << endl << "Play Again(Y/N)? ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	
}


int main()
{
	// seed the random 
	srand(time(NULL));

	//start game
	gameInit();
}
