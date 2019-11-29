#include "Game.h"

void Game::switchTurns() {
	if (playerOne.isOnturn()) {
		playerOne.setTurn(false);
	}
	else {
		playerOne.setTurn(true);
	}
	if (playerTwo.isOnturn()) {
		playerTwo.setTurn(false);
	}
	else {
		playerTwo.setTurn(true);
	}
}

void Game::saveCurrentTurnInFile(const char * path) const
{
	ofstream ofs(path, ios::app);
	if (!ofs) {
		cout << "Error while saving the game!" << endl;
		return;
	}

	if (turnCount == FIRST_TURN) {
		ofs << "  New Game!" << endl;
	}

	if (playerOne.isOnturn()) {
		ofs << playerOne.getSymbol() << ": ";
		board.getPosition().savePositionInFile(ofs);
	}
	else {
		ofs << playerTwo.getSymbol() << ": ";
		board.getPosition().savePositionInFile(ofs);
	}

	if (turnCount == MAX_TURNS || isGameOver()) {
		ofs << "  Game over!" << endl;
		ofs << "-------------" << endl;
	}

	if (!ofs.good()) {
		cout << "Error while saving the game!" << endl;
	}
	ofs.close();
}

void Game::outputWinnerOrDraw() const
{
	if (isGameOver()) {
		decideWinner();
	}
	else if (turnCount == MAX_TURNS) {
		cout << board;
		cout << "Draw!" << endl;
	}
}

void Game::setSymbolsAndTurns(char symbol)
{
	if (symbol == SYMBOL_X) {
		playerTwo.setSymbol(SYMBOL_O);
		playerOne.setTurn(true);
		playerTwo.setTurn(false);
	}
	else {
		playerTwo.setSymbol(SYMBOL_X);
		playerTwo.setTurn(true);
		playerTwo.setTurn(false);
	}
}

bool Game::isGameOver()const
{
	return  board.isColumCrossed() || board.isRowCrossed() || board.isDiagonalCrossed();
}

void Game::inputSymbol()
{
	char symbol;
	do
	{
		cin >> symbol;
		if (symbol != SYMBOL_X && symbol != SYMBOL_O) {
			cout << "Only X or O are allowed." << endl;
			cout << "Enter X or Y: ";
		}
	} while (symbol != SYMBOL_X && symbol != SYMBOL_O);

	playerOne.setSymbol(symbol);
	setSymbolsAndTurns(symbol);
}