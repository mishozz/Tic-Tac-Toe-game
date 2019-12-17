#include "MultiPlayerGame.h"
#include "SinglePlayerGame.hpp"
#include <string>
using namespace std;

const string RESTART = "restart";
const string EXIT = "exit";

void inputValidCommand(string& command) {
	do
	{
		cin >> command;
		if (command != EXIT && command != RESTART) {
			cout << "Please enter a valid command! ";
		}
	} while (command != EXIT && command != RESTART);
}

 
int main() {
	
	string command;
		while (command != EXIT) {
			string key;
			cout << "Press M to play Multiplayer or any other key to play vs the computer!: ";
			cin >> key;
			if (key == "M") {
				MultiPlayer* game = new MultiPlayer;
				game->startGame();
				delete game;
				cout << "Type exit in the console if you want to close the game or restart to play again! : ";
				inputValidCommand(command);
				system("CLS");
			}
			else {
				SinglePlayer* game = new SinglePlayer;
				game->startGame();
				delete game;
				cout << "Type exit in the console if you want to close the game or restart to play again! : ";
				inputValidCommand(command);
				system("CLS");
			}		
		}
	
	return 0;
}
