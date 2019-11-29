#include "Board.h"

//outputs the whole board;

ostream & operator<<(ostream & out, const Board & other)
{
	cout << setw(5) << FIRST_ROW_OR_COLUM << setw(4) << SECOND_ROW_OR_COLUM << setw(4) << THIRD_ROW_OR_COLUM << endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		other.printGrid();
		other.printSymbols(i);
	}
	other.printGrid();
	return out;
}

//prints a row;

void Board::printGrid()const
{
	cout<<"  +---+---+---+" << endl;
}

void Board::printSymbols(int row) const
{
	
	cout <<row<<" | " << board[row][FIRST_ROW_OR_COLUM] << " | " << board[row][SECOND_ROW_OR_COLUM] << " | " << board[row][THIRD_ROW_OR_COLUM]<<" |"<<endl;
	
}



Board::Board()
{
	for (int rows = 0; rows < BOARD_SIZE; rows++)
	{
		for (int cols = 0; cols < BOARD_SIZE; cols++)
		{
			board[rows][cols] = BLANK_SPACE;
		}
	}
}

bool Board::isFull()const{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == BLANK_SPACE)
				return false;
		}
	}
	return true;
}

void Board::setSymbolAt(const Position& position,char symbol)
{
	if (board[position.getX()][position.getY()] == BLANK_SPACE) {
		board[position.getX()][position.getY()] = symbol;
	}
}

void Board::setSymbolAt(const char x, const char y, char symbol) {
	if (board[x][y] == BLANK_SPACE)
		board[x][y] = symbol;
}

//checks if a row is crossed;


bool Board::isRowCrossed()const
{
	for (int i = 0; i<BOARD_SIZE; i++)
	{
		if (board[i][FIRST_ROW_OR_COLUM] == board[i][SECOND_ROW_OR_COLUM] &&
			board[i][SECOND_ROW_OR_COLUM] == board[i][THIRD_ROW_OR_COLUM] &&
			board[i][FIRST_ROW_OR_COLUM] != BLANK_SPACE)
			return true;
	}
	return false;
}

//checks if colum is crossed;

bool Board::isColumCrossed()const
{
	for (int i = 0; i<BOARD_SIZE; i++)
	{
		if (board[FIRST_ROW_OR_COLUM][i] == board[SECOND_ROW_OR_COLUM][i] &&
			board[SECOND_ROW_OR_COLUM][i] == board[THIRD_ROW_OR_COLUM][i] &&
			board[0][i] != BLANK_SPACE)
			return true;
	}
	return false;
}


//check if diagonal is crossed;

bool Board::isDiagonalCrossed()const
{
	if (board[FIRST_ROW_OR_COLUM][FIRST_ROW_OR_COLUM] == board[SECOND_ROW_OR_COLUM][SECOND_ROW_OR_COLUM] &&
		board[SECOND_ROW_OR_COLUM][SECOND_ROW_OR_COLUM] == board[THIRD_ROW_OR_COLUM][THIRD_ROW_OR_COLUM] &&
		board[FIRST_ROW_OR_COLUM][FIRST_ROW_OR_COLUM] != BLANK_SPACE) {
		return true;
	}
	if (board[FIRST_ROW_OR_COLUM][THIRD_ROW_OR_COLUM] == board[SECOND_ROW_OR_COLUM][SECOND_ROW_OR_COLUM] &&
		board[SECOND_ROW_OR_COLUM][SECOND_ROW_OR_COLUM] == board[THIRD_ROW_OR_COLUM][FIRST_ROW_OR_COLUM] &&
		board[FIRST_ROW_OR_COLUM][THIRD_ROW_OR_COLUM] != BLANK_SPACE) {
		return true;
	}
	return false;
}

void Board::inputValidPositionInBoard()
{
	bool flag = false;
	do
	{
		if (flag) {
			system("cls");
			cout << *this;
			cout << "This position is invalid or already taken. Try again!" << endl;
			cout << "Position: ";
		}
		position.readXandY();
		flag = true;
	} while (position.getX() < MIN_POS || position.getX() >= MAX_POS 
	|| position.getY() < MIN_POS || position.getY() >= MAX_POS || board[position.getX()][position.getY()] != BLANK_SPACE);
}
