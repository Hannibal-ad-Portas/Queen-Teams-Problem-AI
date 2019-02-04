#ifndef BOARD_H
#define BOARD_H
#include <vector>
using namespace std;

struct Queen {
	int row;
	int col;
	void displayPosition();
};

class ChessBoard {
	public:
		int fit;
		int rows;
		int cols;
		vector<vector<int>> vectBoard;
		vector<Queen> whiteQueens;
		vector<Queen> blackQueens;
		ChessBoard (int row, int col);
		void displayQueens();
		void fitness();
		void setUp (int white, int black);
		void display();
};
#endif
