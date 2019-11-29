#include "MultiPlayerGame.h"
#include "SinglePlayerGame.hpp"
#include <cstring>
#include <string>
using namespace std;

const string RESTART = "restart";
const string EXIT = "exit";

void inputValidCommand(string& command) {
	do
	{
		cin >> command;
		if (command != EXIT || command != RESTART) {
			cout << "Please enter a valid command! ";
		}
	} while (command != EXIT && command != RESTART);
}


int main() {
	
	string command;
		while (command != EXIT) {
			MultiPlayer* game = new MultiPlayer;
			game->startGame();
			delete game;
			cout << "Type exit in the console if you want to close the game or restart to play again! : ";
			inputValidCommand(command);
		}
	
	
	

	SinglePlayer game;
	game.startGame();

	return 0;
}