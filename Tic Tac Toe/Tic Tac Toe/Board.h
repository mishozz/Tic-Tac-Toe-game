#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
#include <iomanip>
#include "Position.h"
using namespace std;

const int BOARD_SIZE = 3;
const int FIRST_ROW_OR_COLUM = 0;
const int SECOND_ROW_OR_COLUM = 1;
const int THIRD_ROW_OR_COLUM = 2;
const char BLANK_SPACE = ' ';

class Board{
private:
	
	Position position;
	void printGrid()const;
	void printSymbols(int row)const;
public:
	char board[BOARD_SIZE][BOARD_SIZE];
	Board();

	friend ostream& operator<<(ostream& out, const Board& other);
	void setSymbolAt(const Position& position,char symbol);
	void setSymbolAt(const char x, const char y, char symbol);
	char getSymbolAt(const Position& position) const { return board[position.getX()][position.getY()]; }
	char getSymbolAt(const char x, const char y) const { return board[x][y]; }
	bool isGameOver()const { return  isColumCrossed() || isRowCrossed() || isDiagonalCrossed(); }
	Position getPosition() const { return position; }
	char& operator()(int i, int j) {
		return board[i][j];
	}
	bool isFull()const;
	bool isRowCrossed()const;
	bool isColumCrossed()const;
	bool isDiagonalCrossed()const;
	void inputValidPositionInBoard();
};


#endif
