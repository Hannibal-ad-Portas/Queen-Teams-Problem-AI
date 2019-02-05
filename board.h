#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
using namespace std;

struct Queen {
	int row;
	int col;
	void displayPosition();
};

class ChessBoard {
	int fitness;
	bool solved;
	public:
	int wQueens;
	int bQueens;
	int rows;
	int cols;
	vector<vector<int>> vectBoard;
	vector<Queen> whiteQueens;
	vector<Queen> blackQueens;
	ChessBoard (int row, int col, int white, int black);
	int findFitness();
	void setUp ();
	void fillBoard();
	void display();
	void printToFile(string file);
};
#endif
