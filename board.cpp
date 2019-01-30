#include <vector>
#include <iostream>
#include "board.h"
#include "util.h"

// This creates a chess board of rows by col
ChessBoard::ChessBoard (int row, int col) {
	vectBoard.resize (row, std::vector<int> (col, 0));
	rows = row;
	cols = col;
}

/* This function calculates and sets the fitness of the board state
 * The fitness is better the fewer number of threats
 */
void ChessBoard::fitness () {
	fit = 0;
	//TODO
}

/* This function places the desired number of white and black queens in the board */
void ChessBoard::setUp ( int white, int black) {
	int queens = white + black;
	while (queens > 0) {
		//randomly find index
		int tempRow = rand() % rows;
		int tempCol = rand() % cols;
		//determine if index is empty, if value is 0
		if (vectBoard[tempRow][tempCol] == 0) {
			//if index is empty decrement num of queens and change value to either 1 or -1
			queens--;
			if (black > 0 || white > 0)  {
				if (black > 0 && black >= white) {
					vectBoard[tempRow][tempCol] = -1;
					black--;
				} else if (white > 0) {
					vectBoard[tempRow][tempCol] = 1;
					white--;
				}
			}
		}
	}
}

/* This function prints the chess board to a terminal screen */
void ChessBoard::display () {
	cls();
	for (int i = 0; i < rows; i++) {
		std::cout << "\t|";
		for (int j = 0; j < cols; j++) {
			std::cout << " ";
			if ( vectBoard[i][j] == 1) {
				std::cout << "W";
			} else if (vectBoard[i][j] == -1) {
				std::cout << "B";
			} else {
				std::cout << " ";
			}
			std::cout << " |";
		}
		std::cout << std::endl;
	}
}



