// Author: Jerry Olds
// Course: COSC 1437
// Final Exam
#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;

// Class
class Poker 
{
private:
	string player1;
	string player2;
public:
	string cards2;
	void setPlayers(string p1, string p2);
	void makeDeck(string cards[][4]);
	string makeDeck2();
	void makeHand1(string hand[], string deck);
	void makeHand2(string hand1[], string hand2[], string deck);
	void setValues(string hand[], int values[]);
	void setSuit(string hand[], int suit[]);
	void sort(int values[]);
	string flushSuit(int suit[]);
	bool royalFlush(int values[], int suit[]);
	bool straightFlush(int values[], int suit[]);
	int tieBreaker(int values1[], int values2[]);
	char highCard(int value);
	bool fourKind(int values[]);
	bool fullHouse(int values[]);
	bool flush(int suits[]);
	bool straight(int values[]);
	bool threeKind(int values[]);
	bool twoPair(int values[]);
	bool pair(int values[]);
};

void Poker::setPlayers(string p1, string p2)
{
	player1 = p1;
	player2 = p2;
}

void Poker::makeDeck(string cards[][4])
{
// Counters
	int count;
	int counter;
// Input File
	ifstream inputFile;
// Open Input File
	inputFile.open("deck.txt");
// Read in Deck
	for (count = 0; count < 13; count++)
	{
		for (counter = 0; counter < 4; counter++)
		{
			inputFile >> cards[count][counter];
		}
	}
// Close File
	inputFile.close();
}

string Poker::makeDeck2()
{
// Input File
	ifstream inputFile;
// Open File
	inputFile.open("deck2.txt");
// Read in File
	inputFile >> cards2;
// Close File
	inputFile.close();
// Return
	return cards2;
}

void Poker::makeHand1(string hand[], string deck)
{
// Variables
	int count;
	int counter;	
	int a;
	int x = 2;
	char y;
	string card;
// Loop
	for (count = 0; count < 5; count++)
	{
		PROMPT:cout << "Enter a card: ";
		getline(cin, card);
		for (counter = 0; counter < 2; counter++) // Lowercase -> Uppercase
		{
			y = card.at(counter);
			if (islower(y))
			{
				y = toupper(y);
				card.erase(counter, 1);
				card.insert(counter, 1, y);
			}
		}
		if (card == hand[0] || card == hand[1] || card == hand[2] || card == hand[3])
		{
			cout << "Duplicate Card. Try Again.\n";
			goto PROMPT;
		}
		a = deck.find(card, 0);
		if (a == -1)
		{
			cout << "Invalid Card. Try Again.\n";
			goto PROMPT;
		}
		else
			hand[count] = card;
	}
}

void Poker::makeHand2(string hand1[], string hand2[], string deck)
{
	// Variables
	int count;
	int counter;
	int a;
	int x = 2;
	char y;
	string card;
	// Loop
	for (count = 0; count < 5; count++)
	{
	PROMPT:cout << "Enter a card: ";
		getline(cin, card);
		for (counter = 0; counter < 2; counter++) // Lowercase -> Uppercase
		{
			y = card.at(counter);
			if (islower(y))
			{
				y = toupper(y);
				card.erase(counter, 1);
				card.insert(counter, 1, y);
			}
		}
		if (card == hand1[0] || card == hand1[1] || card == hand1[2] || card == hand1[3] || card == hand1[4] ||
			card == hand2[0] || card == hand2[1] || card == hand2[2] || card == hand2[3])
		{
			cout << "Duplicate Card. Try Again.\n";
			goto PROMPT;
		}
		a = deck.find(card, 0);
		if (a == -1)
		{
			cout << "Invalid Card. Try Again.\n";
			goto PROMPT;
		}
		else
			hand2[count] = card;
	}
}

void Poker::setValues(string hand[], int values[])
{
	int count;
	char a;
	for(count = 0; count < 5; count++)
	{
		string card = hand[count];
		a = card.at(0);
		if (a == '2')
			values[count] = 2;
		else if (a == '3')
			values[count] = 3;
		else if (a == '4')
			values[count] = 4;
		else if (a == '5')
			values[count] = 5;
		else if (a == '6')
			values[count] = 6;
		else if (a == '7')
			values[count] = 7;
		else if (a == '8')
			values[count] = 8;
		else if (a == '9')
			values[count] = 9;
		else if (a == 'T')
			values[count] = 10;
		else if (a == 'J')
			values[count] = 11;
		else if (a == 'Q')
			values[count] = 12;
		else if (a == 'K')
			values[count] = 13;
		else
			values[count] = 14;
	}
}

void Poker::setSuit(string hand[], int suit[])
{
	int count;
	char a;
	for (count = 0; count < 5; count++)
	{
		string card = hand[count];
		a = card.at(1);
		if (a == 'C')
			suit[count] = 1;
		else if (a == 'D')
			suit[count] = 2;
		else if (a == 'H')
			suit[count] = 3;
		else
			suit[count] = 4;
	}
}

void Poker::sort(int values[])
{
	bool swap;
	int temp;
	do
	{
		swap = false;
		for (int count = 0; count < 4; count++)
		{
			if (values[count] > values[count + 1])
			{
				temp = values[count];
				values[count] = values[count + 1];
				values[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

bool Poker::royalFlush(int values[], int suit[])
{
	int count;
	int counter = 0;
	int number = 10;
	for (count = 0; count < 5; count++)
	{
		if (values[count] == number)
			number++;
		else
			return false;
	}
	for (count = 1; count < 5; count++)
	{
		if (suit[count] = suit[count - 1])
			counter++;
		else
			return false;
	}
	return true;
}

string Poker::flushSuit(int suit[])
{
	if (suit[0] == 1)
		return "Clubs";
	else if (suit[0] == 2)
		return "Diamonds";
	else if (suit[0] == 3)
		return "Hearts";
	else
		return "Spades";
}

bool Poker::straightFlush(int values[], int suit[])
{
// Variables
	int count;
	int counter = 0;
	int counter2 = 0;
	int number;
// Ace Low
	if (values[0] == 2 && values[1] == 3 && values[2] == 4 && values[3] == 5 && values[4] == 14)
	{
		values[0] = 14;
		values[1] = 2;
		values[2] = 3;
		values[3] = 4;
		values[4] = 5;
		for (count = 1; count < 5; count++)
		{
			if (suit[count] == suit[count - 1])
				counter++;
			else
				return false;
		}
		if (counter == 4)
			return true;
	}
	counter = 0;
	for (count = 0; count < 4; count++)
	{
		number = values[count];
		if (values[count + 1] == number + 1)
			counter++;
		else
			return false;
	}
	for (count = 1; count < 5; count++)
	{
		if (suit[count] == suit[count - 1])
			counter2++;
		else
			return false;
	}
	if (counter == 4 && counter2 == 4)
		return true;
}

int Poker::tieBreaker(int values1[], int values2[])
{
	if (values1[4] > values2[4])
		return 10;
	else if (values2[4] > values1[4])
		return 9;
	if (values1[3] > values2[3])
		return 8;
	else if (values2[3] > values1[3])
		return 7;
	if (values1[2] > values2[2])
		return 6;
	else if (values2[2] > values1[2])
		return 5;
	if (values1[1] > values2[1])
		return 4;
	else if (values2[1] > values1[1])
		return 3;
	if (values1[0] > values2[0])
		return 2;
	else if (values2[0] > values1[0])
		return 1;
	else
		return 0;
}

char Poker::highCard(int value)
{
	if (value == 2)
		return '2';
	else if (value == 3)
		return '3';
	else if (value == 4)
		return '4';
	else if (value == 5)
		return '5';
	else if (value == 6)
		return '6';
	else if (value == 7)
		return '7';
	else if (value == 8)
		return '8';
	else if (value == 9)
		return '9';
	else if (value == 10)
		return 'T';
	else if (value == 11)
		return 'J';
	else if (value == 12)
		return 'Q';
	else if (value == 13)
		return 'K';
	else
		return 'A';
}

bool Poker::fourKind(int values[])
{
	int counter = 0;
	int quad;
	int number = values[0];
	int number2 = values[1];
	int number3 = values[2];
	if (number == number2)
		quad = number;
	else
		quad = number3;
	if (values[0] == quad)
		counter++;
	if (values[1] == quad)
		counter++;
	if (values[2] == quad)
		counter++;
	if (values[3] == quad)
		counter++;
	if (values[4] == quad)
		counter++;
	if (counter == 4)
		return true;
	else
		return false;
}

bool Poker::fullHouse(int values[])
{
	int count;
	int count2 = 0;
	int counter = 0;
	int number = values[0];
	int number2;
	if (number != values[1])
		number2 = values[1];
	else if (number != values[2])
		number2 = values[2];
	else 
		number2 = values[3];
	for (count = 0; count < 5; count++)
	{
		if (values[count] == number)
			counter++;
		else if (values[count] == number2)
			count2++;
		else
			return false;
	}
	if (counter == 3 && count2 == 2 || counter == 2 && count2 == 3)
		return true;
	else
		return false;
}

bool Poker::flush(int suits[])
{
// Counters
	int count;
	int counter = 0;
// Loop
	for (count = 1; count < 5; count++)
	{
		if (suits[count] == suits[count - 1])
			counter++;
		else
			return false;
	}
	if (counter == 4)
		return true;
	else 
		return false;
}

bool Poker::straight(int values[])
{
// Variables
	int count;
	int counter = 0;
	int counter2 = 0;
	int number;
	// Ace Low
	if (values[0] == 2 && values[1] == 3 && values[2] == 4 && values[3] == 5 && values[4] == 14)
	{
		values[0] = 14;
		values[1] = 2;
		values[2] = 3;
		values[3] = 4;
		values[4] = 5;
		return true;
	}
	for (count = 0; count < 4; count++)
	{
		number = values[count];
		if (values[count + 1] == number + 1)
			counter++;
		else
			return false;
	}
	if (counter == 4)
		return true;
}

bool Poker::threeKind(int values[])
{
// Variables
	int number = values[0];
	int number2 = values[1];
	int number3 = values[2];
	int count;
	int counter = 0;
	int count2 = 0;
	int counter2 = 0;
// Loop
	for (count = 0; count < 5; count++)
	{
		if (values[count] == number)
			counter++;
		if (values[count] == number2)
			count2++;
		if (values[count] == number3)
			counter2++;
	}
	if (counter == 3 || count2 == 3 || counter2 == 3)
		return true;
	else
		return false;
}

bool Poker::twoPair(int values[])
{
	int number = values[0];
	int number2 = values[2];
	int number3 = values[4];
	int pair1;
	int pair2;
	int count;
	int count2 = 0;
	int counter = 0;
	if (values[1] == number)
	{
		pair1 = number;
		if (values[3] == number2)
			pair2 = number2;
		else
			pair2 = number3;
	}
	else if (values[1] == number2)
	{
		pair1 = number2;
		pair2 = number3;
	}
	else
		return false;
	for (count = 0; count < 5; count++)
	{
		if (pair1 == values[count])
			count2++;
		if (pair2 == values[count])
			counter++;
	}
	if (count2 == 2 && counter == 2)
		return true;
	else
		return false;
}

bool Poker::pair(int values[])
{
	int count;
	for (count = 0; count < 5; count++)
	{
		if (values[count] == values[count + 1])
			return true;
	}
	return false;
}

int main()
{
START:
// Object
	Poker game;
// Variables
	string player1;
	string player2;
	string flushSuit1;
	string flushSuit2;
	char hand1High;
	char hand2High;
	char hand1High2;
	char hand2High2;
	char hand1High3;
	char hand2High3;
	char playAgain;
	bool a;
	int hand1Power = 0;
	int hand2Power = 0;
	int tieBreaker = 0;
	int count;
	int counter = 0;
	int count2 = 0;
	int counter2 = 0;
	int counter3 = 0;
	int number;
	int number2;
	int number3;
	int digit;
	int digit2;
	int digit3;
	int hand1four;
	int hand2four;
	int hand1three;
	int hand2three;
	int fullHouse1;
	int fullHouse2;
	int fullOf1;
	int fullOf2;
	int hand1pair1;
	int hand1pair2;
	int hand2pair1;
	int hand2pair2;
	int winner;
// Deck Arrays
	string deck[13][4];
	string deck2;
// Player Hands
	string hand1[5];
	int hand1Values[5];
	int hand1suits[5];
	string hand2[5];
	int hand2Values[5];
	int hand2suits[5];
// Title
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\tPoker Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
// Enter Names
	cout << "Please enter player 1 name: ";
	getline(cin, player1);
	cout << "Please enter player 2 name: ";
	getline(cin, player2);
	game.setPlayers(player1, player2);
	cout << endl;
// Make Decks
	game.makeDeck(deck);
	deck2 = game.makeDeck2();
// Player 1
	cout << player1 << ":" << endl;
// Make Player 1 Hand
	game.makeHand1(hand1, deck2);
	cout << endl;
// Player 2
	cout << player2 << ":" << endl;
// Make Player 2 Hand
	game.makeHand2(hand1, hand2, deck2);
	cout << endl;
// Set Value Functions
	game.setValues(hand1, hand1Values);
	game.setValues(hand2, hand2Values);
// Set Suit Functions
	game.setSuit(hand1, hand1suits);
	game.setSuit(hand2, hand2suits);
// Find Flush Suit
	flushSuit1 = game.flushSuit(hand1suits);
	flushSuit2 = game.flushSuit(hand2suits);
// Sort Values
	game.sort(hand1Values);
	game.sort(hand2Values);
// Royal Flush
	a = game.royalFlush(hand1Values, hand1suits);
	if (a == 1)
		hand1Power = 10;
	a = game.royalFlush(hand2Values, hand2suits);
	if (a == 1)
		hand2Power = 10;
	if (hand1Power == 10 && hand2Power == 10)
	{
		cout << player1 << ": ";
		for (string val : hand1)
			cout << val << " ";
		cout << ": ROYAL FLUSH, " << flushSuit1 << endl;
		cout << player2 << ": ";
		for (string val : hand2)
			cout << val << " ";
		cout << ": ROYAL FLUSH, " << flushSuit2 << endl;
		cout << "\nTie: Split Pot.";
		cout << "\n\nPlay Again (Y/N)? ";
		cin >> playAgain;
		if (playAgain == 'y' || playAgain == 'Y')
		{
			cin.ignore();
			goto START;
		}
		else
			return 0;
	}
// Straight Flush
	a = game.straightFlush(hand1Values, hand1suits);
	if (a == 1 && hand1Power == 0)
		hand1Power = 9;
	a = game.straightFlush(hand2Values, hand2suits);
	if (a == 1 && hand2Power == 0)
		hand2Power = 9;
	if (hand1Power == 9 && hand2Power == 9)
	{
		tieBreaker = game.tieBreaker(hand1Values, hand2Values);
		if (tieBreaker == 0)
		{
			hand1High = game.highCard(hand1Values[4]);
			hand2High = game.highCard(hand2Values[4]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "STRAIGHT FLUSH, " << flushSuit1 << ", " << hand1High << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "STRAIGHT FLUSH, " << flushSuit2 << ", " << hand2High << " high" << endl;
			cout << "\nTie: Split Pot.";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else if (tieBreaker % 2 == 0)
		{
			hand1High = game.highCard(hand1Values[(tieBreaker / 2) - 1]);
			hand2High = game.highCard(hand2Values[(tieBreaker / 2) - 1]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "STRAIGHT FLUSH, " << flushSuit1 << ", " << hand1High << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "STRAIGHT FLUSH, " << flushSuit2 << ", " << hand2High << " high" << endl;
			cout << "\n" << player1 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else
		{
			hand1High = game.highCard(hand1Values[tieBreaker / 2]);
			hand2High = game.highCard(hand2Values[tieBreaker / 2]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "STRAIGHT FLUSH, " << flushSuit1 << ", " << hand1High << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "STRAIGHT FLUSH, " << flushSuit2 << ", " << hand2High << " high" << endl;
			cout << "\n" << player2 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
	}
// Four of a Kind
	a = game.fourKind(hand1Values);
	if (a == 1 && hand1Power == 0)
		hand1Power = 8;
	a = game.fourKind(hand2Values);
	if (a == 1 && hand2Power == 0)
		hand2Power = 8;
	if (hand1Power == 8 && hand2Power == 8)
	{
		number = hand1Values[0];
		number2 = hand1Values[1];
		number3 = hand1Values[2];
		if (number == number2)
			hand1four = number;
		else
			hand1four = number3;
		digit = hand2Values[0];
		digit2 = hand2Values[1];
		digit3 = hand2Values[2];
		if (digit == digit2)
			hand2four = digit;
		else
			hand2four = digit3;
		if (hand1four > hand2four)
		{
			hand1High = game.highCard(hand1four);
			hand2High = game.highCard(hand2four);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": FOUR OF A KIND, " << hand1High << "'s" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": FOUR OF A KIND, " << hand2High << "'s" << endl;
			cout << "\n" << player1 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else
		{
			hand1High = game.highCard(hand1four);
			hand2High = game.highCard(hand2four);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": FOUR OF A KIND, " << hand1High << "'s" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": FOUR OF A KIND, " << hand2High << "'s" << endl;
			cout << "\n" << player2 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
	}
// Full House
	a = game.fullHouse(hand1Values);
	if (a == 1 && hand1Power == 0)
		hand1Power = 7;
	a = game.fullHouse(hand2Values);
	if (a == 1 && hand2Power == 0)
		hand2Power = 7;
	if (hand1Power == 7 && hand2Power == 7)
	{
	// Hand 1
		int number = hand1Values[0];
		if (number != hand1Values[1])
			number2 = hand1Values[1];
		else if (number != hand1Values[2])
			number2 = hand1Values[2];
		else
			number2 = hand1Values[3];
		for (count = 0; count < 5; count++)
		{
			if (hand1Values[count] == number)
				counter++;
			else if (hand1Values[count] == number2)
				count2++;
		}
		if (counter == 3)
		{
			fullHouse1 = number;
			fullOf1 = number2;
		}
		else
		{
			fullHouse1 = number2;
			fullOf1 = number;
		}
		hand1High = game.highCard(fullHouse1);
		hand1High2 = game.highCard(fullOf1);
	// Hand 2
		int digit = hand2Values[0];
		if (digit != hand2Values[1])
			digit2 = hand2Values[1];
		else if (digit != hand2Values[2])
			digit2 = hand2Values[2];
		else
			digit2 = hand2Values[3];
		for (count = 0; count < 5; count++)
		{
			if (hand2Values[count] == digit)
				counter2++;
			else if (hand2Values[count] == digit2)
				counter3++;
		}
		if (counter2 == 3)
		{
			fullHouse2 = digit;
			fullOf2 = digit2;
		}
		else
		{
			fullHouse2 = digit2;
			fullOf2 = digit;
		}
		hand2High = game.highCard(fullHouse2);
		hand2High2 = game.highCard(fullOf2);
		if (fullHouse1 > fullHouse2)
		{
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": FULL HOUSE, " << hand1High << "'s full of " << hand1High2 << "'s" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": FULL HOUSE, " << hand2High << "'s full of " << hand2High2 << "'s" << endl;
			cout << "\n" << player1 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else
			cout << player1 << ": ";
		for (string val : hand1)
			cout << val << " ";
		cout << ": FULL HOUSE, " << hand1High << "'s full of " << hand1High2 << "'s" << endl;
		cout << player2 << ": ";
		for (string val : hand2)
			cout << val << " ";
		cout << ": FULL HOUSE, " << hand2High << "'s full of " << hand2High2 << "'s" << endl;
		cout << "\n" << player2 << " wins!";
		cout << "\n\nPlay Again (Y/N)? ";
		cin >> playAgain;
		if (playAgain == 'y' || playAgain == 'Y')
		{
			cin.ignore();
			goto START;
		}
		else
			return 0;
	}
// Flush
	a = game.flush(hand1suits);
	if (a == 1 && hand1Power == 0)
		hand1Power = 6;
	a = game.flush(hand2suits);
	if (a == 1 && hand2Power == 0)
		hand2Power = 6;
	if (hand1Power == 6 && hand2Power == 6)
	{
		tieBreaker = game.tieBreaker(hand1Values, hand2Values);
		if (tieBreaker == 0)
		{
			hand1High = game.highCard(hand1Values[4]);
			hand2High = game.highCard(hand2Values[4]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "FLUSH, " << flushSuit1 << ", " << hand1High << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "FLUSH, " << flushSuit2 << ", " << hand2High << " high" << endl;
			cout << "\nTie: Split Pot.";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else if (tieBreaker % 2 == 0)
		{
			hand1High = game.highCard(hand1Values[(tieBreaker / 2) - 1]);
			hand2High = game.highCard(hand2Values[(tieBreaker / 2) - 1]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "FLUSH, " << flushSuit1 << ", " << hand1High << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "FLUSH, " << flushSuit2 << ", " << hand2High << " high" << endl;
			cout << "\n" << player1 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else
		{
			hand1High = game.highCard(hand1Values[tieBreaker / 2]);
			hand2High = game.highCard(hand2Values[tieBreaker / 2]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "FLUSH, " << flushSuit1 << ", " << hand1High << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "FLUSH, " << flushSuit2 << ", " << hand2High << " high" << endl;
			cout << "\n" << player2 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
	}
// Straight
	a = game.straight(hand1Values);
	if (a == 1 && hand1Power == 0)
		hand1Power = 5;
	a = game.straight(hand2Values);
	if (a == 1 && hand2Power == 0)
		hand2Power = 5;
	if (hand1Power == 5 && hand2Power == 5)
	{
		tieBreaker = game.tieBreaker(hand1Values, hand2Values);
		if (tieBreaker == 0)
		{
			hand1High = game.highCard(hand1Values[4]);
			hand2High = game.highCard(hand2Values[4]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "STRAIGHT, "<< hand1High << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "STRAIGHT, " << hand2High << " high" << endl;
			cout << "\nTie: Split Pot.";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else if (tieBreaker % 2 == 0)
		{
			hand1High = game.highCard(hand1Values[(tieBreaker / 2) - 1]);
			hand2High = game.highCard(hand2Values[(tieBreaker / 2) - 1]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "STRAIGHT, " << hand1High << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "STRAIGHT, " << hand2High << " high" << endl;
			cout << "\n" << player1 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else
		{
			hand1High = game.highCard(hand1Values[tieBreaker / 2]);
			hand2High = game.highCard(hand2Values[tieBreaker / 2]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "STRAIGHT, "<< hand1High << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "STRAIGHT, "<< hand2High << " high" << endl;
			cout << "\n" << player2 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
	}
// Three of a Kind
	a = game.threeKind(hand1Values);
	if (a == 1 && hand1Power == 0)
		hand1Power = 4;
	a = game.threeKind(hand2Values);
	if (a == 1 && hand2Power == 0)
		hand2Power = 4;
	if (hand1Power == 4 && hand2Power == 4)
	{
	  // Hand 1
		 number = hand1Values[0];
		 number2 = hand1Values[1];
		 number3 = hand1Values[2];
		 for (count = 0; count < 5; count++)
		 {
			 if (hand1Values[count] == number)
				 counter++;
			 if (hand1Values[count] == number2)
				 count2++;
			 if (hand1Values[count] == number3)
				 counter2++;
		 }
			 if (counter == 3)
				 hand1three = number;
			 else if (count2 == 3)
				 hand1three = number2;
			 else
				 hand1three = number3;
			 counter = 0;
			 count2 = 0;
			 counter2 = 0;
		// Hand 2
			 digit = hand2Values[0];
			 digit2 = hand2Values[1];
			 digit3 = hand2Values[2];
			 for (count = 0; count < 5; count++)
			 {
				 if (hand2Values[count] == digit)
					 counter++;
				 if (hand2Values[count] == digit2)
					 count2++;
				 if (hand2Values[count] == digit3)
					 counter2++;
			 }
				 if (counter == 3)
					 hand2three = digit;
				 else if (count2 == 3)
					 hand2three = digit2;
				 else
					 hand2three = digit3;
		if (hand1three > hand2three)
		{
			hand1High = game.highCard(hand1three);
			hand2High = game.highCard(hand2three);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": THREE OF A KIND, " << hand1High << "'s" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": THREE OF A KIND, " << hand2High << "'s" << endl;
			cout << "\n" << player1 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else
		{
			hand1High = game.highCard(hand1three);
			hand2High = game.highCard(hand2three);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": THREE OF A KIND, " << hand1High << "'s" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": THREE OF A KIND, " << hand2High << "'s" << endl;
			cout << "\n" << player2 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
	}
// Two Pair
	a = game.twoPair(hand1Values);
	if (a == 1 && hand1Power == 0)
		hand1Power = 3;
	a = game.twoPair(hand2Values);
	if (a == 1 && hand2Power == 0)
		hand2Power = 3;
	if (hand1Power == 3 && hand2Power == 3)
	{
	// Hand 1
		int number = hand1Values[0];
		int number2 = hand1Values[2];
		int number3 = hand1Values[4];
		if (hand1Values[1] == number)
		{
			hand1pair1 = number;
			if (hand1Values[3] == number2)
				hand1pair2 = number2;
			else
				hand1pair1 = number3;
		}
		else if (hand1Values[1] == number2)
		{
			hand1pair1 = number2;
			hand1pair2 = number3;
		}
	// Hand 2
		int digit = hand2Values[0];
		int digit2 = hand2Values[2];
		int digit3 = hand2Values[4];
		if (hand2Values[1] == digit)
		{
			hand2pair1 = digit;
			if (hand2Values[3] == digit2)
				hand2pair2 = digit2;
			else
				hand2pair1 = digit3;
		}
		else if (hand2Values[1] == digit2)
		{
			hand2pair1 = digit2;
			hand2pair2 = digit3;
		}
		if (hand1pair2 > hand2pair2)
		{
			hand1High = game.highCard(hand1pair2);
			hand1High2 = game.highCard(hand1pair1);
			hand2High = game.highCard(hand2pair2);
			hand2High2 = game.highCard(hand2pair1);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": TWO PAIR, " << hand1High << "'s and " << hand1High2 << "'s" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": TWO PAIR, " << hand2High << "'s and " << hand2High2 << "'s" << endl;
			cout << "\n" << player1 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else if (hand2pair2 > hand1pair2)
		{
			hand1High = game.highCard(hand1pair2);
			hand1High2 = game.highCard(hand1pair1);
			hand2High = game.highCard(hand2pair2);
			hand2High2 = game.highCard(hand2pair1);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": TWO PAIR, " << hand1High << "'s and " << hand1High2 << "'s" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": TWO PAIR, " << hand2High << "'s and " << hand2High2 << "'s" << endl;
			cout << "\n" << player2 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else
			if (hand1pair1 > hand2pair1)
			{
				hand1High = game.highCard(hand1pair2);
				hand1High2 = game.highCard(hand1pair1);
				hand2High = game.highCard(hand2pair2);
				hand2High2 = game.highCard(hand2pair1);
				cout << player1 << ": ";
				for (string val : hand1)
					cout << val << " ";
				cout << ": TWO PAIR, " << hand1High << "'s and " << hand1High2 << "'s" << endl;
				cout << player2 << ": ";
				for (string val : hand2)
					cout << val << " ";
				cout << ": TWO PAIR, " << hand2High << "'s and " << hand2High2 << "'s" << endl;
				cout << "\n" << player1 << " wins!";
				cout << "\n\nPlay Again (Y/N)? ";
				cin >> playAgain;
				if (playAgain == 'y' || playAgain == 'Y')
				{
					cin.ignore();
					goto START;
				}
				else
					return 0;
			}
			else if (hand2pair1 > hand1pair1)
			{
				hand1High = game.highCard(hand1pair2);
				hand1High2 = game.highCard(hand1pair1);
				hand2High = game.highCard(hand2pair2);
				hand2High2 = game.highCard(hand2pair1);
				cout << player1 << ": ";
				for (string val : hand1)
					cout << val << " ";
				cout << ": TWO PAIR, " << hand1High << "'s and " << hand1High2 << "'s" << endl;
				cout << player2 << ": ";
				for (string val : hand2)
					cout << val << " ";
				cout << ": TWO PAIR, " << hand2High << "'s and " << hand2High2 << "'s" << endl;
				cout << "\n" << player2 << " wins!";
				cout << "\n\nPlay Again (Y/N)? ";
				cin >> playAgain;
				if (playAgain == 'y' || playAgain == 'Y')
				{
					cin.ignore();
					goto START;
				}
				else
					return 0;
			}
			else
				tieBreaker = game.tieBreaker(hand1Values, hand2Values);
				if (tieBreaker == 0)
				{
					hand1High = game.highCard(hand1pair2);
					hand1High2 = game.highCard(hand1pair1);
					hand2High = game.highCard(hand2pair2);
					hand2High2 = game.highCard(hand2pair1);
					cout << player1 << ": ";
					for (string val : hand1)
						cout << val << " ";
					cout << ": " << "TWO PAIR, " << hand1High << "'s and " << hand1High2 << "'s" << endl;
					cout << player2 << ": ";
					for (string val : hand2)
						cout << val << " ";
					cout << ": " << "TWO PAIR, " << hand2High << "'s and " << hand2High2 << "'s" << endl;
					cout << "\nTie: Split Pot.";
					cout << "\n\nPlay Again (Y/N)? ";
					cin >> playAgain;
					if (playAgain == 'y' || playAgain == 'Y')
					{
						cin.ignore();
						goto START;
					}
					else
						return 0;
				}
				else if (tieBreaker % 2 == 0)
				{
					hand1High = game.highCard(hand1pair2);
					hand1High2 = game.highCard(hand1pair1);
					hand2High = game.highCard(hand2pair2);
					hand2High2 = game.highCard(hand2pair1);
					hand1High3 = game.highCard(hand1Values[(tieBreaker / 2) - 1]);
					hand2High3 = game.highCard(hand2Values[(tieBreaker / 2) - 1]);
					cout << player1 << ": ";
					for (string val : hand1)
						cout << val << " ";
					cout << ": " << "TWO PAIR, " << hand1High << "'s and " << hand1High2 <<"'s, " << hand1High3 << " high" << endl;
					cout << player2 << ": ";
					for (string val : hand2)
						cout << val << " ";
					cout << ": " << "TWO PAIR, " << hand2High << "'s and " << hand2High2 << "'s, " << hand2High3 << " high" << endl;
					cout << "\n" << player1 << " wins!";
					cout << "\n\nPlay Again (Y/N)? ";
					cin >> playAgain;
					if (playAgain == 'y' || playAgain == 'Y')
					{
						cin.ignore();
						goto START;
					}
					else
						return 0;
				}
				else
					hand1High = game.highCard(hand1pair2);
					hand1High2 = game.highCard(hand1pair1);
					hand2High = game.highCard(hand2pair2);
					hand2High2 = game.highCard(hand2pair1);
					hand1High3 = game.highCard(hand1Values[tieBreaker / 2]);
					hand2High3 = game.highCard(hand2Values[tieBreaker / 2]);
					cout << player1 << ": ";
					for (string val : hand1)
						cout << val << " ";
					cout << ": " << "TWO PAIR, " << hand1High << "'s and " << hand1High2 << "'s, " << hand1High3 << " high" << endl;
					cout << player2 << ": ";
					for (string val : hand2)
						cout << val << " ";
					cout << ": " << "TWO PAIR, " << hand2High << "'s and " << hand2High2 << "'s, " << hand2High3 << " high" << endl;
					cout << "\n" << player2 << " wins!";
					cout << "\n\nPlay Again (Y/N)? ";
					cin >> playAgain;
					if (playAgain == 'y' || playAgain == 'Y')
					{
						cin.ignore();
						goto START;
					}
					else
						return 0;
	}
// Pair
	a = game.pair(hand1Values);
	if (a == 1 && hand1Power == 0)
		hand1Power = 2;
	a = game.pair(hand2Values);
	if (a == 1 && hand2Power == 0)
		hand2Power = 2;
	if (hand1Power == 2 && hand2Power == 2)
	{
		for (count = 0; count < 4; count++)
		{
			if (hand1Values[count] == hand1Values[count + 1])
				hand1pair1 = hand1Values[count];
		}
		for (count = 0; count < 4; count++)
		{
			if (hand2Values[count] == hand2Values[count + 1])
				hand2pair1 = hand2Values[count];
		}
		if (hand1pair1 > hand2pair1)
		{
			hand1High = game.highCard(hand1pair1);
			hand2High = game.highCard(hand2pair1);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "PAIR, " << hand1High << "'s" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "PAIR, " << hand2High << "'s" << endl;
			cout << "\n" << player1 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else if (hand2pair1 > hand1pair1)
		{
			hand1High = game.highCard(hand1pair1);
			hand2High = game.highCard(hand2pair1);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "PAIR, " << hand1High << "'s" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "PAIR, " << hand2High << "'s" << endl;
			cout << "\n" << player2 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else
			tieBreaker = game.tieBreaker(hand1Values, hand2Values);
		if (tieBreaker == 0)
		{
			hand1High = game.highCard(hand1pair1);
			hand2High = game.highCard(hand2pair1);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "PAIR, " << hand1High << "'s" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "PAIR, " << hand2High << "'s" << endl;
			cout << "\nTie: Split Pot.";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else if (tieBreaker % 2 == 0)
		{
			hand1High = game.highCard(hand1pair1);
			hand2High = game.highCard(hand2pair1);
			hand1High2 = game.highCard(hand1Values[(tieBreaker / 2) - 1]);
			hand2High2 = game.highCard(hand2Values[(tieBreaker / 2) - 1]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "PAIR, " << hand1High << "'s" << hand1High2 << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "PAIR, " << hand2High << "'s" << hand2High2 << " high" << endl;
			cout << "\n" << player1 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else
		hand1High = game.highCard(hand1pair1);
		hand2High = game.highCard(hand2pair1);
		hand1High2 = game.highCard(hand1Values[tieBreaker / 2]);
		hand2High2 = game.highCard(hand2Values[tieBreaker / 2]);
		cout << player1 << ": ";
		for (string val : hand1)
			cout << val << " ";
		cout << ": " << "PAIR, " << hand1High << "'s" << hand1High2 << " high" << endl;
		cout << player2 << ": ";
		for (string val : hand2)
			cout << val << " ";
		cout << ": " << "PAIR, " << hand2High << "'s" << hand2High2 << " high" << endl;
		cout << "\n" << player2 << " wins!";
		cout << "\n\nPlay Again (Y/N)? ";
		cin >> playAgain;
		if (playAgain == 'y' || playAgain == 'Y')
		{
			cin.ignore();
			goto START;
		}
		else
			return 0;
	}
// High Card
	if (hand1Power == 0 && hand2Power == 0)
	{
		tieBreaker = game.tieBreaker(hand1Values, hand2Values);
		if (tieBreaker == 0)
		{
			hand1High = game.highCard(hand1Values[4]);
			hand2High = game.highCard(hand2Values[4]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "HIGH CARD, " << hand1High << " high"<< endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "HIGH CARD, " << hand2High << " high" << endl;
			cout << "\nTie: Split Pot.";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else if (tieBreaker % 2 == 0)
		{
			hand1High = game.highCard(hand1Values[(tieBreaker / 2) - 1]);
			hand2High = game.highCard(hand2Values[(tieBreaker / 2) - 1]);
			cout << player1 << ": ";
			for (string val : hand1)
				cout << val << " ";
			cout << ": " << "HIGH CARD, " << hand1High << " high" << endl;
			cout << player2 << ": ";
			for (string val : hand2)
				cout << val << " ";
			cout << ": " << "HIGH CARD, " << hand2High << " high" << endl;
			cout << "\n" << player1 << " wins!";
			cout << "\n\nPlay Again (Y/N)? ";
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				cin.ignore();
				goto START;
			}
			else
				return 0;
		}
		else
		hand1High = game.highCard(hand1Values[tieBreaker / 2]);
		hand2High = game.highCard(hand2Values[tieBreaker / 2]);
		cout << player1 << ": ";
		for (string val : hand1)
			cout << val << " ";
		cout << ": " << "HIGH CARD, " << hand1High << " high" << endl;
		cout << player2 << ": ";
		for (string val : hand2)
			cout << val << " ";
		cout << ": " << "HIGH CARD, " << hand2High << " high" << endl;
		cout << "\n" << player2 << " wins!";
		cout << "\n\nPlay Again (Y/N)? ";
		cin >> playAgain;
		if (playAgain == 'y' || playAgain == 'Y')
		{
			cin.ignore();
			goto START;
		}
		else
			return 0;
	}
	if (hand1Power > hand2Power)
		winner = 1;
	else
		winner = 2;
// Output
// Player 1
	cout << player1 << ": ";
	for (string val : hand1)
		cout << val << " ";
	if (hand1Power == 10)
		cout << ": ROYAL FLUSH, " << flushSuit1 << endl;
	else if (hand1Power == 9)
	{
		hand1High = game.highCard(hand1Values[4]);
		cout << ": " << "STRAIGHT FLUSH, " << flushSuit1 << ", " << hand1High << " high" << endl;
	}
	else if (hand1Power == 8)
	{
		number = hand1Values[0];
		number2 = hand1Values[1];
		number3 = hand1Values[2];
		if (number == number2)
			hand1four = number;
		else
			hand1four = number3;
		hand1High = game.highCard(hand1four);
		cout << ": FOUR OF A KIND, " << hand1High << "'s" << endl;
	}
	else if (hand1Power == 7)
	{
		int number = hand1Values[0];
		if (number != hand1Values[1])
			number2 = hand1Values[1];
		else if (number != hand1Values[2])
			number2 = hand1Values[2];
		else
			number2 = hand1Values[3];
		for (count = 0; count < 5; count++)
		{
			if (hand1Values[count] == number)
				counter++;
			else if (hand1Values[count] == number2)
				count2++;
		}
		if (counter == 3)
		{
			fullHouse1 = number;
			fullOf1 = number2;
		}
		else
		{
			fullHouse1 = number2;
			fullOf1 = number;
		}
		hand1High = game.highCard(fullHouse1);
		hand1High2 = game.highCard(fullOf1);
		cout << ": FULL HOUSE, " << hand1High << "'s full of " << hand1High2 << "'s" << endl;
	}
	else if (hand1Power == 6)
	{
		hand1High = game.highCard(hand1Values[4]);
		cout << ": " << "FLUSH, " << flushSuit1 << ", " << hand1High << " high" << endl;
	}
	else if (hand1Power == 5)
	{
		hand1High = game.highCard(hand1Values[4]);
		cout << ": " << "STRAIGHT, " << hand1High << " high" << endl;
	}
	else if (hand1Power == 4)
	{
		counter = 0;
		count2 = 0;
		counter2 = 0;
		number = hand1Values[0];
		number2 = hand1Values[1];
		number3 = hand1Values[2];
		for (count = 0; count < 5; count++)
		{
			if (hand1Values[count] == number)
				counter++;
			if (hand1Values[count] == number2)
				count2++;
			if (hand1Values[count] == number3)
				counter2++;
		}
		if (counter == 3)
			hand1three = number;
		else if (count2 == 3)
			hand1three = number2;
		else
			hand1three = number3;
		hand1High = game.highCard(hand1three);
		cout << ": THREE OF A KIND, " << hand1High << "'s" << endl;
	}
	else if (hand1Power == 3)
	{
		int number = hand1Values[0];
		int number2 = hand1Values[2];
		int number3 = hand1Values[4];
		if (hand1Values[1] == number)
		{
			hand1pair1 = number;
			if (hand1Values[3] == number2)
				hand1pair2 = number2;
			else
				hand1pair1 = number3;
		}
		else if (hand1Values[1] == number2)
		{
			hand1pair1 = number2;
			hand1pair2 = number3;
		}
		hand1High = game.highCard(hand1pair2);
		hand1High2 = game.highCard(hand1pair1);
		cout << ": TWO PAIR, " << hand1High << "'s and " << hand1High2 << "'s" << endl;
	}
	else if (hand1Power == 2)
	{
		for (count = 0; count < 4; count++)
		{
			if (hand1Values[count] == hand1Values[count + 1])
				hand1pair1 = hand1Values[count];
		}
			hand1High = game.highCard(hand1pair1);
			cout << ": " << "PAIR, " << hand1High << "'s" << endl;

	}
	else
	{
		hand1High = game.highCard(hand1Values[4]);
		cout << ": " << "HIGH CARD, " << hand1High << " high" << endl;
	}
// Player 2
	cout << player2 << ": ";
	for (string val : hand2)
		cout << val << " ";
	if (hand2Power == 10)
		cout << ": ROYAL FLUSH, " << flushSuit2 << endl;
	else if (hand2Power == 9)
	{
		hand2High = game.highCard(hand2Values[4]);
		cout << ": " << "STRAIGHT FLUSH, " << flushSuit2 << ", " << hand2High << " high" << endl;
	}
	else if (hand2Power == 8)
	{
		digit = hand2Values[0];
		digit2 = hand2Values[1];
		digit3 = hand2Values[2];
		if (digit == digit2)
			hand2four = digit;
		else
			hand2four = digit3;
		hand2High = game.highCard(hand2four);
		cout << ": FOUR OF A KIND, " << hand2High << "'s" << endl;
	}
	else if (hand2Power == 7)
	{
		counter = 0;
		count2 = 0;
		int digit = hand2Values[0];
		if (digit != hand2Values[1])
			digit2 = hand2Values[1];
		else if (digit != hand2Values[2])
			digit2 = hand2Values[2];
		else
			digit2 = hand2Values[3];
		for (count = 0; count < 5; count++)
		{
			if (hand2Values[count] == digit)
				counter++;
			else if (hand2Values[count] == digit2)
				count2++;
		}
		if (counter == 3)
		{
			fullHouse2 = digit;
			fullOf2 = digit2;
		}
		else
		{
			fullHouse2 = digit2;
			fullOf2 = digit;
		}
		hand2High = game.highCard(fullHouse2);
		hand2High2 = game.highCard(fullOf2);
		cout << ": FULL HOUSE, " << hand2High << "'s full of " << hand2High2 << "'s" << endl;
	}
	else if (hand2Power == 6)
	{
		hand2High = game.highCard(hand2Values[4]);
		cout << ": " << "FLUSH, " << flushSuit2 << ", " << hand2High << " high" << endl;
	}
	else if (hand2Power == 5)
	{
		hand2High = game.highCard(hand2Values[4]);
		cout << ": " << "STRAIGHT, " << hand2High << " high" << endl;
	}
	else if (hand2Power == 4)
	{
		counter = 0;
		count2 = 0;
		counter2 = 0;
		digit = hand2Values[0];
		digit2 = hand2Values[1];
		digit3 = hand2Values[2];
		for (count = 0; count < 5; count++)
		{
			if (hand2Values[count] == digit)
				counter++;
			if (hand2Values[count] == digit2)
				count2++;
			if (hand2Values[count] == digit3)
				counter2++;
		}
		if (counter == 3)
			hand2three = digit;
		else if (count2 == 3)
			hand2three = digit2;
		else
			hand2three = digit3;
		hand2High = game.highCard(hand2three);
		cout << ": THREE OF A KIND, " << hand2High << "'s" << endl;
	}
	else if (hand2Power == 3)
	{
		int digit = hand2Values[0];
		int digit2 = hand2Values[2];
		int digit3 = hand2Values[4];
		if (hand2Values[1] == digit)
		{
			hand2pair1 = digit;
			if (hand2Values[3] == digit2)
				hand2pair2 = digit2;
			else
				hand2pair2 = digit3;
		}
		else if (hand2Values[1] == digit2)
		{
			hand2pair1 = digit2;
			hand2pair2 = digit3;
		}
		hand2High = game.highCard(hand2pair2);
		hand2High2 = game.highCard(hand2pair1);
		cout << ": TWO PAIR, " << hand2High << "'s and " << hand2High2 << "'s" << endl;
	}
	else if (hand2Power == 2)
	{
		for (count = 0; count < 4; count++)
		{
			if (hand2Values[count] == hand2Values[count + 1])
				hand2pair1 = hand2Values[count];
		}
		hand2High = game.highCard(hand2pair1);
		cout << ": " << "PAIR, " << hand2High << "'s" << endl;

	}
	else
	{
		hand2High = game.highCard(hand2Values[4]);
		cout << ": " << "HIGH CARD, " << hand2High << " high" << endl;
	}
	if (winner == 1)
	{
		cout << "\n" << player1 << " wins!";
		cout << "\n\nPlay Again (Y/N)? ";
		cin >> playAgain;
		if (playAgain == 'y' || playAgain == 'Y')
		{
			cin.ignore();
			goto START;
		}
		else
			return 0;
	}
	else
		cout << "\n" << player2 << " wins!";
	cout << "\n\nPlay Again (Y/N)? ";
	cin >> playAgain;
	if (playAgain == 'y' || playAgain == 'Y')
	{
		cin.ignore();
		goto START;
	}
	else
		return 0;
}