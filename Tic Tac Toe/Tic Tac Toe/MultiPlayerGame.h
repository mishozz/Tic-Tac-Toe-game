#ifndef MultiPlayerGame_H_
#define MultiPlayerGame_H_

#include "Game.h"

class MultiPlayer:public Game {
private:
	void decideWinner()const;
public:
	void startGame();	
};
#endif