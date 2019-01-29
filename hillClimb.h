/* This is a structure to contain the game board
 * It consists of a 2d array of intigers and an int tracking the
 * fitness of the board state
 */
#ifndef HILLCLIMB_H
#define HILLCLIMB_H

#include <vector>

class ChessBoard {
	int fitness;
	std::vector<std::vector<int>> board;

	public:
	ChessBoard( int row, int col);
};

#endif
