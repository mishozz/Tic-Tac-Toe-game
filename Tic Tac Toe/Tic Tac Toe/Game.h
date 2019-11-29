#ifndef Game_H_
#define Game_H_
#include "Board.h"
#include "Player.h"
#include <algorithm>
#include "Position.h"
#include <stdlib.h>
#include <fstream>

const char SYMBOL_X = 'X';
const char SYMBOL_O = 'O';
const int MAX_TURNS = 9;
const int FIRST_TURN = 1;

class Game {
protected:
	Board board;
	Player playerOne;
	Player playerTwo;
	int turnCount;
	void saveCurrentTurnInFile(const char* path)const;
	void inputSymbol();
	void setSymbolsAndTurns(char symbol);
	void switchTurns();
	bool isGameOver()const;
	virtual void decideWinner()const = 0;
	void outputWinnerOrDraw()const;
	int getTurnCount()const { return turnCount; }
public:
	Game():turnCount(0){}
};

#endif 

