#include "MultiPlayerGame.h"

void MultiPlayer::decideWinner()const {
	cout << board;
	if (playerOne.isOnturn()) {
		cout << "Player 1 with symbol " << playerOne.getSymbol() << " won!" << endl;

	}
	else {
		cout << "Player 2 with symbol " << playerTwo.getSymbol() << " won!" << endl;
	}
}

void MultiPlayer::startGame()
{
	system("CLS");
	
		cout << "Enter X or O: ";
		inputSymbol();
		system("CLS");
	
	while (!isGameOver()&&turnCount != MAX_TURNS) {
		cout << board ;
		cout << "Position: ";
		board.inputValidPositionInBoard();
		system("CLS");
		if (playerOne.isOnturn()) {			
			board.setSymbolAt(board.getPosition(), playerOne.getSymbol());
			cout << board;
		}
		else {			
			board.setSymbolAt(board.getPosition(), playerTwo.getSymbol());
			cout << board;
		}
		turnCount++;
		saveCurrentTurnInFile("game");
		system("CLS");
		outputWinnerOrDraw();
		switchTurns();
	}
	cout << "game is over!" << endl;
}





