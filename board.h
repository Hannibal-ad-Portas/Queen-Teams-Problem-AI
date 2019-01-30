#ifndef BOARD_H
#define BOARD_H
#include <vector>

class ChessBoard {
	int fit;
	int rows;
	int cols;
	std::vector<std::vector<int>> vectBoard;
	public:
	ChessBoard (int row, int col);
	void fitness ();
	void setUp (int white, int black);
	void display();
};
#endif
