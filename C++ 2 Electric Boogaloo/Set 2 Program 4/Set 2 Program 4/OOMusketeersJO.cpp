// Author: Jerry Olds
#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<time.h>
using namespace std;

class Musketeers
{
public:
	void displayBoard(char board[][5], string start, string end, char player_choice, int token);
	bool checkInput(string start, string end, char player_choice, char board[][5]);
	bool gameOverCheck(char board[][5], int token);
};

void Musketeers::displayBoard(char board[][5], string start, string end, char player_choice, int token)
{
// Variables
	char letter;
	char letter2;
	string number;
	string number2;
	int num;
	int num2;
	int column;
	int column2;
	int count;
	int counter;
	int move;
	bool swap = false;
	bool game_over;
// Assign Variables
	if (player_choice == 'M')
	{
	// User Move
		if (token == 0)
		{
			letter = start.at(0);
			letter2 = end.at(0);
			letter = toupper(letter);
			letter2 = toupper(letter2);
			number = start.at(1);
			number2 = end.at(1);
			num = stoi(number);
			num2 = stoi(number2);
			switch (letter)
			{
			case 'A':
				column = 0;
				break;
			case 'B':
				column = 1;
				break;
			case 'C':
				column = 2;
				break;
			case 'D':
				column = 3;
				break;
			case 'E':
				column = 4;
				break;
			default:		// Default case should never be used
				column = 9;
				break;
			}
			switch (letter2)
			{
			case 'A':
				column2 = 0;
				break;
			case 'B':
				column2 = 1;
				break;
			case 'C':
				column2 = 2;
				break;
			case 'D':
				column2 = 3;
				break;
			case 'E':
				column2 = 4;
				break;
			default:			// Default case should never be used
				column2 = 9;
				break;
			}
			board[num - 1][column] = ' ';
			board[num2 - 1][column2] = 'M';
		}
		game_over = gameOverCheck(board, token);
	// CPU Move
		if (token == 1 && !game_over)
		{
			srand(time(NULL));
			count = rand() % 5;
			while (!swap)
			{
				for (count; count < 5; count++)
				{
					for (counter = 0; counter < 5; counter++)
					{
						if (board[count][counter] == ' ')
							{
								if (counter - 1 > -1 && !swap)
								{
									if (board[count][counter - 1] == 'R')
									{
										board[count][counter - 1] = ' ';
										board[count][counter] = 'R';
										swap = true;
									}
								}
								if (count - 1 > -1 && !swap)
								{
									if (board[count - 1][counter] == 'R')
									{
										board[count - 1][counter] = ' ';
										board[count][counter] = 'R';
										swap = true;
									}
								}
								if (counter + 1 < 5 && !swap)
								{
									if (board[count][counter + 1] == 'R')
									{
										board[count][counter + 1] = ' ';
										board[count][counter] = 'R';
										swap = true;
									}
								}
								if (count + 1 < 5 && !swap)
								{
									if (board[count + 1][counter] == 'R')
									{
										board[count + 1][counter] = ' ';
										board[count][counter] = 'R';
										swap = true;
									}
								}
							}
						}
		if (count == 4 && !swap)
			count = 0;
					}
				}
			}
		}
	if (player_choice == 'R')
	{
		if (token == 0)
		{
			srand(time(NULL));
			count = rand() % 5;
			while (!swap)
			{
				for (count; count < 5; count++)
				{
					for (counter = 0; counter < 5; counter++)
					{
						if (board[count][counter] == 'M')
						{
							srand(time(NULL));
							move = rand() % 4;
							if (move == 0 && counter + 1 != 5 && board[count][counter + 1] == 'R' && !swap)
							{
								board[count][counter + 1] = 'M';
								board[count][counter] = ' ';
								swap = true;
							}
							if (move == 1 && counter - 1 != -1 && board[count][counter - 1] == 'R' && !swap)
							{
								board[count][counter - 1] = 'M';
								board[count][counter] = ' ';
								swap = true;
							}
							if (move == 2 && count + 1 != 5 && board[count + 1][counter] == 'R' && !swap)
							{
								board[count + 1][counter] = 'M';
								board[count][counter] = ' ';
								swap = true;
							}
							if (move == 3 && count - 1 != -1 && board[count - 1][counter] == 'R' && !swap)
							{
								board[count - 1][counter] = 'M';
								board[count][counter] = ' ';
								swap = true;
							}
						}
					}
					if (count == 4 && !swap)
						count = 0;
				}
			}
		}
		game_over = gameOverCheck(board, token);
		if (token == 1 && !game_over)
		{
			letter = start.at(0);
			letter2 = end.at(0);
			letter = toupper(letter);
			letter2 = toupper(letter2);
			number = start.at(1);
			number2 = end.at(1);
			num = stoi(number);
			num2 = stoi(number2);
			switch (letter)
			{
			case 'A':
				column = 0;
				break;
			case 'B':
				column = 1;
				break;
			case 'C':
				column = 2;
				break;
			case 'D':
				column = 3;
				break;
			case 'E':
				column = 4;
				break;
			default:		// Default case should never be used
				column = 9;
				break;
			}
			switch (letter2)
			{
			case 'A':
				column2 = 0;
				break;
			case 'B':
				column2 = 1;
				break;
			case 'C':
				column2 = 2;
				break;
			case 'D':
				column2 = 3;
				break;
			case 'E':
				column2 = 4;
				break;
			default:			// Default case should never be used
				column2 = 9;
				break;
			}
			board[num - 1][column] = ' ';
			board[num2 - 1][column2] = 'R';
		}
	}
	if (game_over || (player_choice == 'M' && token == 1) || (player_choice == 'R' && token == 0))
	{
	// Display board
		cout << endl;
		cout << "    A B C D E" << endl;
		cout << "  ------------" << endl;
		for (int count = 0; count < 5; count++)
		{
			cout << count + 1 << " | ";
			for (int counter = 0; counter < 5; counter++)
			{
				cout << board[count][counter] << " ";
				if (counter == 4)
					cout << endl;
			}
		}
	}
}

bool Musketeers::checkInput(string start, string end, char player, char board[][5])
{
// Variables
	char letter;
	char letter2;
	string number;
	string number2;
	int num;
	int num2;
	int column;
	int column2;
	int column_difference;
	int row_difference;
// Check to see length of input is 2
	if (end.length() != 2)
	{
		cout << "\nINVALID ENDING INPUT." << endl;
		return false;
	}
// Assign Variables
	letter = start.at(0);
	letter2 = end.at(0);
	letter = toupper(letter);
	letter2 = toupper(letter2);
	number = start.at(1);
	number2 = end.at(1);
	num = stoi(number);
	num2 = stoi(number2);
	switch (letter)
	{
		case 'A':
			column = 0;
			break;
		case 'B':
			column = 1;
			break;
		case 'C':
			column = 2;
			break;
		case 'D':
			column = 3;
			break;
		case 'E':
			column = 4;
			break;
		default:		// Default case should never be used
			column = 9;
			break;
	}
	switch (letter2)
	{
	case 'A':
		column2 = 0;
		break;
	case 'B':
		column2 = 1;
		break;
	case 'C':
		column2 = 2;
		break;
	case 'D':
		column2 = 3;
		break;
	case 'E':
		column2 = 4;
		break;
	default:			// Default case should never be used
		column2 = 9;
		break;
	}
// Check Input
	if (letter2 != 'A' && letter2 != 'B' && letter2 != 'C' && letter2 != 'D' && letter2 != 'E')
	{
		cout << "INVALID ENDING POSITION." << endl;
		return false;
	}
	if (num2 < 1 || num2 > 5)
	{
		cout << "INVALID ENDING POSITION." << endl;
		return false;
	}
	if (player == 'M')
	{
		column_difference = column - column2;
		column_difference = abs(column_difference);
		row_difference = num - num2;
		row_difference = abs(row_difference);
		if (board[num2 - 1][column2] != 'R')
		{
			cout << "INVALID INPUT. ENDING POSITION IS NOT OCCUPIED BY A RICHELIEU PIECE." << endl;
			return false;
		}
		if (row_difference > 1)
		{
			cout << "INVALID MOVE. MUSKETEER PIECE MUST TAKE AN ADJACENT RICHELIEU PIECE." << endl;
			return false;
		}
		if (column_difference > 1)
		{
			cout << "INVALID MOVE. MUSKETEER PIECE MUST TAKE AN ADJACENT RICHELIEU PIECE." << endl;
			return false;
		}
		if (row_difference == 1 && column_difference == 1)
		{
			cout << "INVALID DIAGONAL MOVE." << endl;
			return false;
		}
	}
	if (player == 'R')
	{
		column_difference = column - column2;
		column_difference = abs(column_difference);
		row_difference = num - num2;
		row_difference = abs(row_difference);
		if (board[num2 - 1][column2] != ' ')
		{
			cout << "INVALID INPUT. ENDING POSITION IS OCCUPIED." << endl;
			return false;
		}
		if (row_difference > 1)
		{
			cout << "INVALID MOVE. RICHELIEU PIECE MUST GO TO AN ADJACENT UNOCCUPIED SPOT." << endl;
			return false;
		}
		if (column_difference > 1)
		{
			cout << "INVALID MOVE. RICHELIEU PIECE MUST GO TO AN ADJACENT UNOCCUPIED SPOT." << endl;
			return false;
		}
		if (row_difference == 1 && column_difference == 1)
		{
			cout << "INVALID DIAGONAL MOVE." << endl;
			return false;
		}
	}
		return true;
}

bool Musketeers::gameOverCheck(char board[][5], int token)
{
// Variable
	int token2 = 0;
	int token3 = 0;
// Check to see if Musketeers win
	if (token == 0)
	{
		for (int count = 0; count < 5; count++)
		{
			for (int counter = 0; counter < 5; counter++)
			{
				if (board[count][counter] == 'M')
				{
					if (counter == 0)
						token3++;
					if (count == 0)
						token3++;
					if (counter == 4)
						token3++;
					if (count == 4)
						token3++;
					if (count != 0)
					{
						if (board[count - 1][counter] == ' ' || board[count - 1][counter] == 'M')
							token3++;
					}
					if (count != 4)
					{
						if (board[count + 1][counter] == ' ' || board[count + 1][counter] == 'M')
							token3++;
					}
					if (counter != 0)
					{
						if (board[count][counter - 1] == ' ' || board[count][counter - 1] == 'M')
							token3++;
					}
					if (counter != 4)
					{
						if (board[count][counter + 1] == ' ' || board[count][counter + 1] == 'M')
							token3++;
					}
					if (token3 == 4)
						token2++;
					token3 = 0;
				}
			}
		}
		if (token2 == 3)
			return true;
	}
// Check to see if Cardinal Richelieu's men won
	if (token == 1)
	{
		for (int count = 0; count < 5; count++)
		{
			token2 = 0;
			for (int counter = 0; counter < 5; counter++)
			{
				if (board[count][counter] == 'M')
					token2++;
				if (token2 == 3)
					return true;
			}
		}
		for (int counter = 0; counter < 5; counter++)
		{
			token2 = 0;
			for (int count = 0; count < 5; count++)
			{
				if (board[count][counter] == 'M')
					token2++;
				if (token2 == 3)
					return true;
			}
		}
	}
		return false;
}

int main()
{
// Variables
	Musketeers game;
	string start;
	string end;
	char letter;
	string number;
	int num;
	string player;
	char player_choice;
	bool game_over = false;
	bool invalid_input;
	int token;
	int column;
// Array
	const int MAX_ROW = 5;
	const int MAX_COLUMN = 5;
	char board[MAX_ROW][MAX_COLUMN];
// Initalize board
	for (int count = 0; count < MAX_ROW; count++)
	{
		for (int counter = 0; counter < MAX_COLUMN; counter++)
			board[count][counter] = 'R';
	}
	board[0][4] = 'M';
	board[2][2] = 'M';
	board[4][0] = 'M';
// Body
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t  Three Muskeeters Game" << endl;
	cout << "-----------------------------------------------------------------------------------------";
	CHOICE:cout << "\nWould you like to play as the Musketeers (M) or as Cardinal Richelieu's men (R)?: ";
	cin >> player;
	while (player.length() != 1)
	{
		cout << "INVALID INPUT." << endl;
		cout << "\nWould you like to play as the Musketeers (M) or as Cardinal Richelieu's men (R)?: ";
		cin >> player;
	}
	player_choice = player.at(0);
	player_choice = toupper(player_choice);
	if (player_choice != 'M' && player_choice != 'R')
	{
		cout << "INVALID INPUT." << endl;
		goto CHOICE;
	}
	if (player_choice == 'M')
	{
		cout << endl;
		cout << "    A B C D E" << endl;
		cout << "  ------------" << endl;
		for (int count = 0; count < 5; count++)
		{
			cout << count + 1 << " | ";
			for (int counter = 0; counter < 5; counter++)
			{
				cout << board[count][counter] << " ";
				if (counter == 4)
					cout << endl;
			}
		}
		while (!game_over)
		{
			token = 0;
		PROMPT:cout << "\nPlease enter the piece you would like to move: ";
			cin >> start;
			while (start.length() != 2)
			{
				cout << "INVALID STARTING POSITION." << endl;
				cout << "\nPlease enter the piece you would like to move: ";
				cin >> start;
			}
			letter = start.at(0);
			letter = toupper(letter);
			if (letter != 'A' && letter != 'B' && letter != 'C' && letter != 'D' && letter != 'E')
			{
				cout << "INVALID STARTING POSITION." << endl;
				goto PROMPT;
			}
			number = start.at(1);
			num = stoi(number);
			if (num < 1 || num > 5)
			{
				cout << "INVALID STARTING POSITION." << endl;
				goto PROMPT;
			}
			switch (letter)
			{
			case 'A':
				column = 0;
				break;
			case 'B':
				column = 1;
				break;
			case 'C':
				column = 2;
				break;
			case 'D':
				column = 3;
				break;
			case 'E':
				column = 4;
				break;
			default:		// Default case should never be used
				column = 9;
				break;
			}
			if (board[num - 1][column] != 'M')
			{
				cout << "INVALID INPUT. STARTING POSITION IS NOT OCCUPIED BY MUSKETEER PEICE." << endl;
				goto PROMPT;
			}
			cout << "\nPlease enter where you would like to move the piece: ";
			cin >> end;
			invalid_input = game.checkInput(start, end, player_choice, board);
			while (!invalid_input)
			{
				cout << "\nPlease enter where you would like to move the piece: ";
				cin >> end;
				invalid_input = game.checkInput(start, end, player_choice, board);
			}
			game.displayBoard(board, start, end, player_choice, token);
			game_over = game.gameOverCheck(board, token);
			if (game_over)
				cout << "\nCONGRATULATIONS! MUSKETEERS WIN!" << endl;
			else
			{
				token++;
				game.displayBoard(board, start, end, player_choice, token);
				game_over = game.gameOverCheck(board, token);
				if (game_over)
					cout << "\nCARDINAL RICHELIEU'S MEN WIN! BETTER LUCK NEXT TIME!" << endl;
			}
			if (!game_over)
			{
				token = 0;
				game_over = game.gameOverCheck(board, token);
				if (game_over)
					cout << "\nCONGRATULATIONS! MUSKETEERS WIN!" << endl;
			}
		}
	}
	if (player_choice == 'R')
	{
		while (!game_over)
		{
			token = 0;
			game.displayBoard(board, start, end, player_choice, token);
			game_over = game.gameOverCheck(board, token);
			if (game_over)
				cout << "MUSKETEERS WIN! BETTER LUCK NEXT TIME!" << endl;
			else
			{
				token++;
				game_over = game.gameOverCheck(board, token);
			}
			if (game_over)
				cout << "\nCONGRATULATIONS! CARDINAL RICHELIEU'S MEN WIN!" << endl;
			else
			{
				PROMPT2:cout << "\nPlease enter the peice you would like to move: ";
				cin >> start;
				while (start.length() != 2)
				{
					cout << "INVALID STARTING POSITION." << endl;
					cout << "\nPlease enter the piece you would like to move: ";
					cin >> start;
				}
				letter = start.at(0);
				letter = toupper(letter);
				if (letter != 'A' && letter != 'B' && letter != 'C' && letter != 'D' && letter != 'E')
				{
					cout << "INVALID STARTING POSITION." << endl;
					goto PROMPT2;
				}
				number = start.at(1);
				num = stoi(number);
				if (num < 1 || num > 5)
				{
					cout << "INVALID STARTING POSITION." << endl;
					goto PROMPT2;
				}
				switch (letter)
				{
				case 'A':
					column = 0;
					break;
				case 'B':
					column = 1;
					break;
				case 'C':
					column = 2;
					break;
				case 'D':
					column = 3;
					break;
				case 'E':
					column = 4;
					break;
				default:		// Default case should never be used
					column = 9;
					break;
				}
				if (board[num - 1][column] != 'R')
				{
					cout << "INVALID INPUT. STARTING POSITION IS NOT OCCUPIED BY RICHELIEU PEICE." << endl;
					goto PROMPT2;
				}
				cout << "\nPlease enter where you would like to move the piece: ";
				cin >> end;
				invalid_input = game.checkInput(start, end, player_choice, board);
				while (!invalid_input)
				{
					cout << "\nPlease enter where you would like to move the piece: ";
					cin >> end;
					invalid_input = game.checkInput(start, end, player_choice, board);
				}
				game.displayBoard(board, start, end, player_choice, token);
				token = 0;
				game_over = game.gameOverCheck(board, token);
				if (game_over)
					cout << "\nMUSKETEERS WIN! BETTER LUCK NEXT TIME!" << endl;
			}
		}
	}
// End of program
	cout << endl;
	return 0;
}