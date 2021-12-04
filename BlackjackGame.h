#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include <iostream>
#include <string>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class BlackjackGame
{
private:
	// player name string
	string player_name;

	// total player score
	int total_score;
	// player's hand score each game
	int player_hand_score;
	// house's hand score each game
	int house_hand_score;

	// index of card to be dealt
	int card_deal_index;
	// array of cards
	int* cards;

public:
	// constructor
	BlackjackGame(string in_name);
	// desctructor
	~BlackjackGame();

	// total score
	int getTotalScore() { return total_score; }
	void PlayerWin();
	void PlayerLose();

	// cards
	void shuffleCards();
	void resetGame();

	// game functions
	void dealToPlayer();
	void dealToHouse();

	// game
	void playGame();

	// debug
	void printDeck();

};

#endif /* BLACKJACK_GAME_H */