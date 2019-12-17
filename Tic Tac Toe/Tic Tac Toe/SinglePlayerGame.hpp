#include "Game.h"
using namespace std;

class SinglePlayer : public Game {
private:
	int evaluate(Board board);
	int minimax(Board board, int depth, bool isMax, int alpha, int beta);
	Position findBestMove(Board board, int turnCount);
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
		if (board(row,0) == board(row, 1) &&
			board(row, 1) == board(row, 2))
		{
			if (board(row, 0) == playerTwo.getSymbol())
				return +10;
			else if (board(row, 0) == playerOne.getSymbol())
				return -10;
		}
	}

	// Checking for Columns for X or O victory. 
	for (int col = 0; col<3; col++)
	{
		if (board(0,col) == board(1, col) &&
			board(1, col) == board(2, col))
		{
			if (board(0, col) == playerTwo.getSymbol())
				return +10;

			else if (board(0, col) == playerOne.getSymbol())
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory. 
	if (board(0, 0) == board(1, 1) && board(1, 1) == board(2, 2))
	{
		if (board(0, 0) == playerTwo.getSymbol())
			return +10;
		else if (board(0, 0) == playerOne.getSymbol())
			return -10;
	}

	if (board(0, 2) == board(1, 1) && board(1, 1) == board(2, 0))
	{
		if (board(0, 2) == playerTwo.getSymbol())
			return +10;
		else if (board(0, 2) == playerOne.getSymbol())
			return -10;
	}

	// Else if none of them have won then return 0 
	return 0;
	
}



int SinglePlayer::minimax(Board board, int depth, bool isMax,int alpha ,int beta)
{
	
	int score = evaluate(board);

	// If Maximizer has won the game return his/her 
	// evaluated score 
	if (score == 10)
		return score - depth;

	// If Minimizer has won the game return his/her 
	// evaluated score 
	if (score == -10)
		return score + depth;

	// If there are no more moves and no winner then 
	// it is a tie 
	if (board.isFull())
		return 0;

	// If this maximizer's move 
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells 
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				// Check if cell is empty 
				if (board(i, j) == BLANK_SPACE)
				{
					// Make the move 
					board(i, j) = playerTwo.getSymbol();

					int val = minimax(board, depth + 1, !isMax, alpha, beta);
					best = max(best, val);
					alpha = max(alpha, val);

					board(i, j) = BLANK_SPACE;
					if (beta <= alpha)
						break;
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
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				// Check if cell is empty 
				if (board(i, j) == BLANK_SPACE)
				{
					// Make the move 
					board(i, j) = playerOne.getSymbol();

					int val = minimax(board, depth + 1, isMax, alpha, beta);
					best = min(best, val);
					alpha = min(alpha, val);

					board(i, j) = BLANK_SPACE;
					if (beta <= alpha)
						break;

					// Undo the move 
					board(i, j) = BLANK_SPACE;
				}
			}
		}
		return best;
	}
}


Position SinglePlayer::findBestMove(Board board,int turnCount) {
	int bestVal = -1000;
	Position bestMove(-1, -1);

	if(board(1, 1) == BLANK_SPACE && turnCount == 1){
		bestMove.setX(1);
		bestMove.setY(1);
		return bestMove;
	}
	// Traverse all cells, evaluate minimax function for 
	// all empty cells. And return the cell with optimal 
	// value. 
	for (int i = 0; i<BOARD_SIZE; i++)
	{
		for (int j = 0; j<BOARD_SIZE; j++)
		{
			// Check if cell is empty 
			if (board(i, j) == BLANK_SPACE)
			{
				// Make the move 
				board(i, j) = playerTwo.getSymbol();

				// compute evaluation function for this 
				// move. 
				int moveVal = minimax(board, 0, false,INT_MIN,INT_MAX);

				// Undo the move 
				board(i, j) = BLANK_SPACE;

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

	return bestMove;
}

