#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include "Board.h"
using namespace std;


class Player {
private:
	char symbol;
	bool isOnTurn;	
public:
	Player(char s = BLANK_SPACE, bool isOnTurn=true);
	void setSymbol(char s){ symbol = s; }
	bool isOnturn()const { return isOnTurn; }
	void setTurn(bool turn) { isOnTurn = turn; }
	char getSymbol()const { return symbol; }
};
#endif