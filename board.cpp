#include <vector>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <fstream>
#include <string>
#include "board.h"
#include "util.h"

// This creates a chess board of rows by col
ChessBoard::ChessBoard (int row, int col, int white, int black) {
	solved = false;
	rows = row;
	cols = col;
	wQueens = white;
	bQueens = black;
	vector<Queen> whiteQueens;
	vector<Queen> blackQueens;
	vectBoard.resize (rows, std::vector<int> (cols, 0));
	ChessBoard::setUp();
	ChessBoard::fillBoard();
}

/* This function calculates and sets the fitness of the board state
 * The fitness is better the fewer number of threats
 */
int ChessBoard::findFitness() {
	fitness = 0;
	//incriment fitness if any queen shares a square witrh another
	for (int i = 0; i < bQueens; i++ ) {
		for (int j = i+1; j < bQueens; j++) {
			if ((blackQueens.at(i).row == blackQueens.at(j).row) && (blackQueens.at(j).col == blackQueens.at(j).col))
				fitness++;
		}
	}
	for (int i = 0; i < wQueens; i++ ) {
		for (int j = i+1; j < wQueens; j++) {
			if ((whiteQueens.at(i).row == whiteQueens.at(j).row) && (whiteQueens.at(j).col == whiteQueens.at(j).col))
				fitness++;
		}
	}
	//Incriment fitness if any queen is threatened by a queen on the other team
	for (auto &i : whiteQueens) {
		for (auto &j : blackQueens) {
			if (i.row == j.row)
				fitness++;
			if (i.col == j.col)
				fitness++;
			if (abs(i.row - j.row) == abs(i.col - j.col))
				fitness++;
		}
	}
	if (fitness == 0)
		solved = true;
	return fitness;
}

void ChessBoard::fillBoard() {
	//std::cout << "Filling Board with 0's\n";
	for (int i = 0; i < rows; i++) {
		for (int j =0; j < cols; j++) {
			vectBoard[i][j] = 0;
		}
	}
	//std::cout << "Setting W pos\n";
	int i = 0;
	for (auto &w : whiteQueens) {
		//std::cout << "Queen "<< i << std::endl;
		//std::cout << w.row << " " << w.col << endl;
		i++;
		vectBoard[w.row][w.col] = 1;
	}
	//std::cout << "Setting B pos\n";
	i = 0;
	for (auto &b : blackQueens) {
		//std::cout << "Queen " << i << std::endl;
		//std::cout << b.row << " " << b.col << endl;
		i++;
		vectBoard[b.row][b.col] = -1;
	}
}

/* This function places the desired number of white and black queens in the board */
void ChessBoard::setUp () {
	for (int i = 0; i < rows; i++) {
		if (i < wQueens) {
			whiteQueens.push_back(Queen());
			whiteQueens.back().row = i;
			whiteQueens.back().col = rand() % cols;
		} else {
			blackQueens.push_back(Queen());
			blackQueens.back().row = i;
			blackQueens.back().col = rand() % cols;
		}
	}
}
/* This method prints the chess board to the terminal */
void ChessBoard::display () {
	//cls();
	std::cout << "\n\t    ";
	for (int i = 0; i < cols; i++)
		std::cout << i << "   ";
	std::cout << std::endl;
	for (int i = 0; i < rows; i++) {
		std::cout << "\t" << i << " |";
		for (int j = 0; j  < cols; j++) {
			std::cout << " ";
			if (vectBoard[i][j] == 1)
				std::cout << "W";
			if (vectBoard[i][j] == -1)
				std::cout << "B";
			if (vectBoard[i][j] == 0)
				std::cout << " ";
			std::cout << " |";
		}
		std::cout << endl;
	}
	std::cout << "\t   ";
	for (int i = 0; i < cols; i++)
		std::cout << "--- ";
	std::cout << endl;
}

void ChessBoard::printToFile (string file) {
	using namespace std;
	ofstream ofile;
	ofile.open(file);
	ofile << "\n\t    ";
	for (int i = 0; i < cols; i++)
		ofile << i << "   ";
	ofile << std::endl;
	for (int i = 0; i < rows; i++) {
		ofile << "\t" << i << " |";
		for (int j = 0; j  < cols; j++) {
			ofile << " ";
			if (vectBoard[i][j] == 1)
				ofile << "W";
			if (vectBoard[i][j] == -1)
				ofile << "B";
			if (vectBoard[i][j] == 0)
				ofile << " ";
			ofile << " |";
		}
		ofile << endl;
	}
	ofile << "\t   ";
	for (int i = 0; i < cols; i++)
		ofile << "--- ";
	ofile << endl;
	ofile << "\tSolved: ";
	if (solved)
		ofile << "Yes\n";
	if (!solved)
		ofile << "No\n";
}
/* This function prints out the position of a queen in the row col format */
void Queen::displayPosition () {
	std::cout << " " << row << " " << col << std::endl;
}
