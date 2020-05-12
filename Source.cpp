#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void displayInstructions();
void showBoard(char board[]);
int getMove(char board[]);
bool checkWin(char board[]);
bool checkDraw(char board[]);

const int SIZE = 9;
const char SPACE = ' ';
const char X = 'X';
const char O = 'O';

void displayInstructions()
{
	cout << "When the game starts, O will go first.\n"
		 << "Left to Right, Top to Bottom, Positions are numbered 0-8.\n"
		 << "First player to have 3 consecutive places vertically, horizontally or diagonally wins\n" << endl;
}
//Checks to see if a player has won
bool checkWin(char board[])
{
	bool win = false;
	if (board[0] == board[1] && board[1] == board[2] && board[0] != SPACE) //first row win
		win = true;
	else if (board[3] == board[4] && board[4] == board[5] && board[3] != SPACE) //second row win
		win = true;
	else if (board[6] == board[7] && board[7] == board[8] && board[6] != SPACE) //third row win
		win = true;
	else if (board[0] == board[3] && board[3] == board[6] && board[0] != SPACE) //first cloumn win
		win = true;
	else if (board[1] == board[4] && board[4] == board[7] && board[1] != SPACE) //second column win
		win = true;
	else if (board[2] == board[5] && board[5] == board[8] && board[2] != SPACE) //third column win
		win = true;
	else if (board[0] == board[4] && board[4] == board[8] && board[0] != SPACE) //first cross win
		win = true;
	else if (board[2] == board[4] && board[4] == board[6] && board[2] != SPACE) //second cross win
		win = true;
	
	return win;
}

//Checks to see if there is a draw(No spaces left with no win)
bool checkDraw(char board[])
{
	bool draw = true;
	for (int i = 0; i < SIZE; i++)
		if (board[i] == SPACE)
		{
			i = 10;
			draw = false; //If a space does not have an X or O then function returns false (no draw)
		}
		

	return draw;
}

//Prints board out on the window
void showBoard(char board[])
{
	for(int j = 0 ,i = 1; j < SIZE; i++,j++ )
	{ 
		cout << "|" << board[j] << "|"; //Prints out each element of the board array with proper spacing
		if (i % 3 == 0 && i != 9)
			cout << '\n' << "---------" << endl;

	}
		
}

//Acquires move from predetermined player
int getMove(char board[])
{
	int position;
	cout << '\n' << "Where would you like to play?" << endl;
	cin >> position;
	if ((position >= 9 || position < 0) || board[position] != SPACE  )
	{
		while ((position > 8 || position < 0) || (board[position] == X || board[position] == O))
		{
			cout << "\nCannot place there, try again:" << endl;
			cin >> position;
		}

		//inputs position desired to play at, if not a valid number or already taken then it asks for input again
	}
		

	return position;
}

int main() 
{
	char play = 'y';
	while(play == 'y')
	{
		char board[SIZE]; //create the board as a character array
		for (int i = 0; i < SIZE; i++)
			board[i] = SPACE;
		bool win = false;
		bool draw = false;
		int turn = 0; //turn increments, mod 2 = 0 is O's turn, mod 2 = 1 is X's turn
		displayInstructions();
		do
		{
			showBoard(board);
			if (turn % 2 == 0)
			{
				cout << "\n\nO's turn" << endl;
				int position = getMove(board);
					board[position] = O;
			}
		
			else
			{
				cout << "\n\nX's turn" << endl;
				int position = getMove(board);
				board[position] = X;
			}
			turn++; //increment turn, switches between players
			win = checkWin(board);
			draw = checkDraw(board);
			//checks if game has been won or draw
			
		} while (win == false && draw == false);
		showBoard(board);
		if (win == true)
		{
			if (turn % 2 == 0)
				cout << "\n\nX's Win!" << endl;
			else
				cout << "\n\nO's Win!" << endl;
		}
		else
			cout << "\nCat's Game :P" << endl;
			


		cout << "Would you like to play again? (y or n) " << endl;
		cin >> play;
	}
	
	return 0;
}