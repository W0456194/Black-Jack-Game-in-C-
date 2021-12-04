#include "BlackjackGame.h"

// constructor
BlackjackGame::BlackjackGame(string in_name)
{
	// intialize member variables
	player_name = in_name;

	total_score = 0;
	player_hand_score = 0;
	house_hand_score = 0;

	card_deal_index = -1;

	// allocate array memory for cards
	cards = new int[52];

	// intialize card values
	int index = 0; // index counter
	for (int i = 0; i < 4; i++) // once per suit
	{
		// fill up number ranks
		for (int j = 2; j <= 10; j++)
		{
			cards[index] = j;
			index++;
		}
		cards[index++] = 10; // jack
		cards[index++] = 10; // queen
		cards[index++] = 10; // king
		cards[index++] = 1; //  ace
	}
}


// destructor
BlackjackGame::~BlackjackGame()
{
	// deallocate the memory for cards
	delete[] cards;
}


// handle player winning
void BlackjackGame::PlayerWin()
{
	// add 50 points when player wins
	cout << "WINNER! WINNER! CHICKEN DINNER!" << endl;
	cout << "Player won!" << endl;
	total_score += 50;
}


// handle player losing
void BlackjackGame::PlayerLose()
{
	// deduct 50 points when player loses.
	cout << "Player lost ..." << endl;
	total_score -= 50;
}


// shuffle deck of cards
void BlackjackGame::shuffleCards()
{
	int randIndex = 0;
	int temp = 0;
	// for each card in cards
	for (int i = 0; i < 52; i++)
	{
		// get random index 
		randIndex = rand() % 52;

		// swap card values at random and current index
		temp = cards[i];
		cards[i] = cards[randIndex];
		cards[randIndex] = temp;
	}
}


// reset the game for new round
void BlackjackGame::resetGame()
{
	shuffleCards();

	// initial deal
	player_hand_score = cards[0] + cards[1]; // first 2 cards in deck
	house_hand_score = cards[2] + cards[3]; // next 2 cards in deck
	card_deal_index = 4; // land the index pointer on 4 and wait
}


// deal a card to player
void BlackjackGame::dealToPlayer()
{
	// deal a card
	// check for ACE card
	if (cards[card_deal_index] == 1)
	{
		// check if ace will bust the player
		if (player_hand_score + 11 > 21)
		{
			// if bust possibile, add 1
			player_hand_score += 1;
		}
		else
		{
			// if safe from bust, add 11
			player_hand_score += 11;
		}

		// display the dealt card
		cout << endl << "Dealt ACE to " << player_name << "!" << endl;
	}
	// for Non-ACE cards
	else
	{
		// add card value as is
		player_hand_score += cards[card_deal_index];


		// display the dealt card
		cout << endl << "Dealt " << cards[card_deal_index] << " to " << player_name << "!" << endl;
	}

	// go to next card in deck and wait
	card_deal_index++;
}


// deal a card to house
void BlackjackGame::dealToHouse()
{
	// deal a card
	// check for ACE card
	if (cards[card_deal_index] == 1)
	{
		// check if ace will bust the player
		if (house_hand_score + 11 > 21)
		{
			// if bust possibile, add 1
			house_hand_score += 1;
		}
		else
		{
			// if safe from bust, add 11
			house_hand_score += 11;
		}

		// display the dealt card
		cout << endl << "Dealt ACE to House!" << endl;
	}
	// for Non-ACE cards
	else
	{
		// add card value as is
		house_hand_score += cards[card_deal_index];

		// display the dealt card
		cout << endl << "Dealt " << cards[card_deal_index] << " to House!" << endl;
	}

	// go to next card in deck and wait
	card_deal_index++;
}


// the main game logic
void BlackjackGame::playGame()
{
	// shuffle cards and deal initial round
	resetGame();


	// welcome message
	cout << endl << "Welcome to Blackjack, " << player_name << "!" << endl;

	// player loop
	while (true)
	{
		// empty line 
		cout << endl;

		// display scores
		cout << player_name << " Hand score: " << player_hand_score << endl;
		cout << "House Hand score: " << house_hand_score << endl;

		// hit or stay menu
		cout << "Do you want to hit(h) or stay(s)? ";
		char ch;
		cin >> ch;
		if (ch != 'h' && ch != 'H' && ch != 'S' && ch != 's')
		{
			cout << "Invalid choice... Try again!" << endl;
			continue;
		}

		// deal with player choice
		if (ch == 'H' || ch == 'h')
		{
			dealToPlayer();
		}
		else if (ch == 'S' || ch == 's')
		{
			cout << "Player stayed!" << endl;
			break;
		}

		if (player_hand_score > 21)
		{
			cout << "Player " << player_name << " busted!" << endl;
			break;
		}
	}


	// dealer loop
	if (player_hand_score < 21 && house_hand_score < player_hand_score)
	{
		// empty line 
		cout << endl;

		cout << "House's turn!" << endl;
		while (house_hand_score < 21 && house_hand_score < player_hand_score)
		{
			dealToHouse();
			cout << player_name << " Hand score: " << player_hand_score << endl;
			cout << "House Hand score: " << house_hand_score << endl;

			// empty line 
			cout << endl;
		}

		if (house_hand_score > 21)
		{
			cout << "House Busted!" << endl;
		}
	}


	// check for winner and loser
	cout << endl << "Checking for winner ... " << endl;
	if (player_hand_score > 21)
	{
		PlayerLose();
	}
	else if (player_hand_score == 21 || player_hand_score > house_hand_score || house_hand_score > 21)
	{
		PlayerWin();
	}
	else
	{
		PlayerLose();
	}

}


// print the deck of cards 
void BlackjackGame::printDeck()
{
	for (int i = 0; i < 52; i++)
	{
		cout << cards[i] << endl;
	}
}


