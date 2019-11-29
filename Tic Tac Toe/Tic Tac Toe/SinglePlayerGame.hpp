#include "Game.h"
using namespace std;

/*
class SinglePlayer:public Game {
private:	
	int evaluate(Board board);
	int minimax(Board board, int depth, bool isMax);
	Position findBestMove(Board board);
public:
	void startGame();
};


int SinglePlayer::evaluate(Board board) {
	Position pos;
	for (int row = 0; row<3; row++)
	{
		if (board.getSymbolAt(row, 0) == board.getSymbolAt(row, 1) &&
			board.getSymbolAt(row, 1) == board.getSymbolAt(row, 2))
		{
			if (board.getSymbolAt(row, 0) == playerTwo.getSymbol())
				return +10;
			else if (board.getSymbolAt(row, 0) == playerOne.getSymbol())
				return -10;
		}
	}

	// Checking for Columns for X or O victory. 
	for (int col = 0; col<3; col++)
	{
		
		if (board.getSymbolAt(0,col) == board.getSymbolAt(1, col) &&
			board.getSymbolAt(1, col) == board.getSymbolAt(2, col))
		{
			if (board.getSymbolAt(0, col) == playerTwo.getSymbol())
				return +10;

			else if (board.getSymbolAt(0, col) == playerOne.getSymbol())
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory. 
	if (board.getSymbolAt(0, 0) == board.getSymbolAt(1, 1) && board.getSymbolAt(1, 1) == board.getSymbolAt(2, 2))
	{
		if (board.getSymbolAt(0, 0) == playerTwo.getSymbol())
			return +10;
		else if (board.getSymbolAt(0, 0) == playerOne.getSymbol())
			return -10;
	}

	if (board.getSymbolAt(0, 2) == board.getSymbolAt(1, 1) && board.getSymbolAt(1, 1) == board.getSymbolAt(2, 0))
	{
		if (board.getSymbolAt(0, 2) == playerTwo.getSymbol())
			return +10;
		else if (board.getSymbolAt(0, 2) == playerOne.getSymbol())
			return -10;
	}

	// Else if none of them have won then return 0 
	return 0;
}

int SinglePlayer::minimax(Board board, int depth, bool isMax)
{
	int score = evaluate(board);

	// If Maximizer has won the game return his/her 
	// evaluated score 
	if (score == 10)
		return score;

	// If Minimizer has won the game return his/her 
	// evaluated score 
	if (score == -10)
		return score;

	// If there are no more moves and no winner then 
	// it is a tie 
	if (board.isFull())
		return 0;

	// If this maximizer's move 
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells 
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				Position pos(i, j);
				// Check if cell is empty 
				if (board.getSymbolAt(pos) == BLANK_SPACE)
				{
					
					// Make the move 
					board.setSymbolAt(pos,playerTwo.getSymbol());

					// Call minimax recursively and choose 
					// the maximum value 
					best = max(best,
						minimax(board, depth + 1, !isMax));

					// Undo the move 
					board.setSymbolAt(pos, BLANK_SPACE);
				}
			}
		}
		return best;
	}

	// If this minimizer's move 
	else
	{
		int best = 1000;

		// Traverse all cells 
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				Position pos(i, j);
				// Check if cell is empty 
				if (board.getSymbolAt(pos) == BLANK_SPACE)
				{
					// Make the move 
					board.setSymbolAt(pos, playerOne.getSymbol());

					// Call minimax recursively and choose 
					// the minimum value 
					best = min(best,
						minimax(board, depth + 1, !isMax));

					// Undo the move 
					board.setSymbolAt(pos, BLANK_SPACE);
				}
			}
		}
		return best;
	}
}


Position SinglePlayer::findBestMove(Board board) {
	int bestVal = -1000;
	Position bestMove(-1,-1);

	// Traverse all cells, evaluate minimax function for 
	// all empty cells. And return the cell with optimal 
	// value. 
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			Position pos(i, j);
			// Check if cell is empty 
			if (board.getSymbolAt(pos) == BLANK_SPACE)
			{
				// Make the move 
				board.setSymbolAt(pos, playerTwo.getSymbol());

				// compute evaluation function for this 
				// move. 
				int moveVal = minimax(board, 0, false);

				// Undo the move 
				board.setSymbolAt(pos, BLANK_SPACE);

				// If the value of the current move is 
				// more than the best value, then update 
				// best/ 
				if (moveVal > bestVal)
				{
					bestMove.setX (i);
					bestMove.setY(j);
					bestVal = moveVal;
				}
			}
		}
	}

	printf("The value of the best Move is : %d\n\n",
		bestVal);

	return bestMove;
}


void SinglePlayer::startGame() {
	

	turnCount = 0;
	system("CLS");

	cout << "Enter X or O: ";
	inputSymbol();
	system("CLS");
	Position move;
	while (!isGameOver() && turnCount != MAX_TURNS) {

		system("CLS");
		if (playerOne.isOnturn()) {
			cout << board;
			cout << "Position: ";
			board.inputValidPositionInBoard();
			system("CLS");
			board.setSymbolAt(board.getPosition(),playerOne.getSymbol());
			cout << board;
		}
		else {
			move = findBestMove(board);
			board.setSymbolAt(move, playerTwo.getSymbol());
			cout << board;
		}
		turnCount++;
		saveCurrentTurnInFile("game");
		system("CLS");
		outputWinnerOrDraw();
		switchTurns();
	}
}
*/

/*
class SinglePlayer: public Game {
private:
	
	

	int evaluate(Board board);
	int minimax(Board board, int depth, bool isMax);
	Position findBestMove(Board board);
	
public:
	void startGame();
};






int SinglePlayer::evaluate(Board board) {
	// Checking for Rows for X or O victory. 
	for (int row = 0; row<3; row++)
	{
		if (board.getSymbolAt(row,0) == board.getSymbolAt(row, 1) &&
			board.getSymbolAt(row, 1) == board.getSymbolAt(row, 2))
		{
			if (board.getSymbolAt(row, 0) == playerTwo.getSymbol())
				return +10;
			else if (board.getSymbolAt(row, 0) == playerOne.getSymbol())
				return -10;
		}
	}

	// Checking for Columns for X or O victory. 
	for (int col = 0; col<3; col++)
	{
		if (board.getSymbolAt(0, col) == board.getSymbolAt(1, col) &&
			board.getSymbolAt(1, col) == board.getSymbolAt(2, col))
		{
			if (board.getSymbolAt(0, col) == playerTwo.getSymbol())
				return +10;

			else if (board.getSymbolAt(0, col) == playerOne.getSymbol())
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory. 
	if (board.getSymbolAt(0, 0) == board.getSymbolAt(1, 1) && board.getSymbolAt(1, 1) == board.getSymbolAt(2, 2))
	{
		if (board.getSymbolAt(0, 0) == playerTwo.getSymbol())
			return +10;
		else if (board.getSymbolAt(0, 0) == playerOne.getSymbol())
			return -10;
	}

	if (board.getSymbolAt(0, 2) == board.getSymbolAt(1, 1) && board.getSymbolAt(1, 1) == board.getSymbolAt(2, 0))
	{
		if (board.getSymbolAt(0, 2) == playerTwo.getSymbol())
			return +10;
		else if (board.getSymbolAt(0, 2) == playerOne.getSymbol())
			return -10;
	}

	// Else if none of them have won then return 0 
	return 0;
}

int SinglePlayer::minimax(Board board, int depth, bool isMax)
{
	int score = evaluate(board);

	// If Maximizer has won the game return his/her 
	// evaluated score 
	if (score == 10)
		return score;

	// If Minimizer has won the game return his/her 
	// evaluated score 
	if (score == -10)
		return score;

	// If there are no more moves and no winner then 
	// it is a tie 
	if (board.isFull())
		return 0;

	// If this maximizer's move 
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells 
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty 
				if (board.getSymbolAt(i, j) == BLANK_SPACE)
				{
					// Make the move 
					board.setSymbolAt(i, j, playerTwo.getSymbol());

					// Call minimax recursively and choose 
					// the maximum value 
					best = max(best,
						minimax(board, depth + 1, !isMax));

					// Undo the move 
					board.setSymbolAt(i, j, BLANK_SPACE);
				}
			}
		}
		return best;
	}

	// If this minimizer's move 
	else
	{
		int best = 1000;

		// Traverse all cells 
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty 
				if (board.getSymbolAt(i,j) == BLANK_SPACE)
				{
					// Make the move 
					board.setSymbolAt(i, j, playerOne.getSymbol());

					// Call minimax recursively and choose 
					// the minimum value 
					best = min(best,
						minimax(board, depth + 1, !isMax));

					// Undo the move 
					board.setSymbolAt(i, j, BLANK_SPACE);
				}
			}
		}
		return best;
	}
}


Position SinglePlayer::findBestMove(Board board) {
	int bestVal = -1000;
	Position bestMove(-1, -1);

	// Traverse all cells, evaluate minimax function for 
	// all empty cells. And return the cell with optimal 
	// value. 
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			// Check if cell is empty 
			if (board.getSymbolAt(i,j) == BLANK_SPACE)
			{
				// Make the move 
				board.setSymbolAt(i,j, playerTwo.getSymbol());

				// compute evaluation function for this 
				// move. 
				int moveVal = minimax(board, 0, false);

				// Undo the move 
				board.setSymbolAt(i, j, BLANK_SPACE);

				// If the value of the current move is 
				// more than the best value, then update 
				// best/ 
				if (moveVal > bestVal)
				{
					bestMove.setX(i);
					bestMove.setY(j);
					bestVal = moveVal;
				}
			}
		}
	}

	printf("The value of the best Move is : %d\n\n",
		bestVal);

	return bestMove;
}




void SinglePlayer::startGame() {
	

	//turnCount = 0;
	system("CLS");

	cout << "Enter X or O: ";
	inputSymbol();
	system("CLS");
	Position move;
	while (turnCount != MAX_TURNS) {

		//board.inputValidPositionInBoard();
		system("CLS");
		if (playerOne.isOnturn()) {

			cout << board;
			cout << "Position: ";
			board.inputValidPositionInBoard();
			board.setSymbolAt(board.getPosition(), playerOne.getSymbol());
			cout << board;
		}
		else {
			move = findBestMove(board);
			board.setSymbolAt(move.getX(),move.getY(), playerTwo.getSymbol());
			
			cout << board;
		}
		turnCount++;
		//saveCurrentTurnInFile("game");
		system("CLS");
		//outputWinnerOrDraw();
		switchTurns();
	}
}
*/



class SinglePlayer : public Game {
private:
	bool isFull(char board[3][3])
	{
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
	int evaluate(Board board);
	int minimax(Board board, int depth, bool isMax);
	Position findBestMove(Board board);
	void decideWinner()const;
public:
	void startGame();
};

void SinglePlayer::decideWinner()const {
	cout << board;
	if (playerOne.isOnturn()) {
		cout << "You with symbol " << playerOne.getSymbol() << " won!" << endl;

	}
	else {
		cout << "The Computer with symbol " << playerTwo.getSymbol() << " won!" << endl;
	}
}




int SinglePlayer::evaluate(Board board) {
	// Checking for Rows for X or O victory. 
	for (int row = 0; row<3; row++)
	{
		if (board.board[row][0] == board.board[row][1] &&
			board.board[row][1] == board.board[row][2])
		{
			if (board.board[row][0] == playerTwo.getSymbol())
				return +10;
			else if (board.board[row][0] == playerOne.getSymbol())
				return -10;
		}
	}

	// Checking for Columns for X or O victory. 
	for (int col = 0; col<3; col++)
	{
		if (board.board[0][col] == board.board[1][col] &&
			board.board[1][col] == board.board[2][col])
		{
			if (board.board[0][col] == playerTwo.getSymbol())
				return +10;

			else if (board.board[0][col] == playerOne.getSymbol())
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory. 
	if (board.board[0][0] == board.board[1][1] && board.board[1][1] == board.board[2][2])
	{
		if (board.board[0][0] == playerTwo.getSymbol())
			return +10;
		else if (board.board[0][0] == playerOne.getSymbol())
			return -10;
	}

	if (board.board[0][2] == board.board[1][1] && board.board[1][1] == board.board[2][0])
	{
		if (board.board[0][2] == playerTwo.getSymbol())
			return +10;
		else if (board.board[0][2] == playerOne.getSymbol())
			return -10;
	}

	// Else if none of them have won then return 0 
	return 0;
}

int SinglePlayer::minimax(Board board, int depth, bool isMax)
{
	int score = evaluate(board);

	// If Maximizer has won the game return his/her 
	// evaluated score 
	if (score == 10)
		return score;

	// If Minimizer has won the game return his/her 
	// evaluated score 
	if (score == -10)
		return score;

	// If there are no more moves and no winner then 
	// it is a tie 
	if (board.isFull())
		return 0;

	// If this maximizer's move 
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells 
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty 
				if (board.board[i][j] == BLANK_SPACE)
				{
					// Make the move 
					board.board[i][j] = playerTwo.getSymbol();

					// Call minimax recursively and choose 
					// the maximum value 
					best = max(best,
						minimax(board, depth + 1, !isMax));

					// Undo the move 
					board.board[i][j] = BLANK_SPACE;
				}
			}
		}
		return best;
	}

	// If this minimizer's move 
	else
	{
		int best = 1000;

		// Traverse all cells 
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty 
				if (board.board[i][j] == ' ')
				{
					// Make the move 
					board.board[i][j] = playerOne.getSymbol();

					// Call minimax recursively and choose 
					// the minimum value 
					best = min(best,
						minimax(board, depth + 1, !isMax));

					// Undo the move 
					board.board[i][j] = BLANK_SPACE;
				}
			}
		}
		return best;
	}
}


Position SinglePlayer::findBestMove(Board board) {
	int bestVal = -1000;
	Position bestMove(-1, -1);

	// Traverse all cells, evaluate minimax function for 
	// all empty cells. And return the cell with optimal 
	// value. 
	for (int i = 0; i<BOARD_SIZE; i++)
	{
		for (int j = 0; j<BOARD_SIZE; j++)
		{
			// Check if cell is empty 
			if (board.board[i][j] == BLANK_SPACE)
			{
				// Make the move 
				board.board[i][j] = playerTwo.getSymbol();

				// compute evaluation function for this 
				// move. 
				int moveVal = minimax(board, 0, false);

				// Undo the move 
				board.board[i][j] = BLANK_SPACE;

				// If the value of the current move is 
				// more than the best value, then update 
				// best/ 
				if (moveVal > bestVal)
				{
					bestMove.setX(i);
					bestMove.setY(j);
					bestVal = moveVal;
				}
			}
		}
	}

	printf("The value of the best Move is : %d\n\n",
		bestVal);

	return bestMove;
}




void SinglePlayer::startGame() {	
	system("CLS");
	cout << "Enter X or O: ";
	inputSymbol();
	system("CLS");
	Position move;
	while (!isGameOver() && turnCount != MAX_TURNS) {

		//board.inputValidPositionInBoard();
		system("CLS");
		if (playerOne.isOnturn()) {	
			cout << board;		
			cout << "Position: ";
			board.inputValidPositionInBoard();
			board.setSymbolAt(board.getPosition(), playerOne.getSymbol());
			cout << board;
		}
		else {
			move = findBestMove(board);
			board.board[move.getX()][move.getY()] = playerTwo.getSymbol();
			cout << board;
		}
		turnCount++;
		saveCurrentTurnInFile("game");
		system("CLS");
		outputWinnerOrDraw();
		switchTurns();
	}
}
