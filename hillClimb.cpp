/* This is the hill climb method of solving the team queens problem
 * It solves the problem by taking an initial state and moving a queen to a new
 * position. If the position improves the board's fitness value the change is kept
 * otherwise it is discarded and the queen moved to a new position.
 */

#include <iostream>
#include <stdlib.h>
#include "board.h"
#include "util.h"

ChessBoard findBest (ChessBoard &board);
ChessBoard moveQueens (ChessBoard board, int index);
int findFitness(ChessBoard &board);

void hillClimb (int row, int col, int white, int black, int tmax) {
	using namespace std;
	//create a global 'best' with an initial random configuration
	cout << "Creating board\n";
	ChessBoard best(row, col);
	cout << "placing queens\n";
	best.setUp (white, black);
	//Display the Board
	best.display();
	cout << "Finding Fitness\n";
	cout << "This board's fitness is " << findFitness(best) << endl;
	//split off a number of child processes to calculate the solution independently
	best = findBest(best);
	best.display();

}

ChessBoard findBest (ChessBoard &board) {
	int fitness = findFitness(board);
	int index = 0;
	while (fitness != 0) {
		int numQueens = board.blackQueens.size() + board.whiteQueens.size();
		ChessBoard tempBoard = moveQueens(board, index);
		int tempFitness = findFitness(board);
		cout << "Temp Fitness is " << tempFitness << endl;
		if (tempFitness > fitness) {
			fitness = tempFitness;
			board = tempBoard;
			board.display();
		}
	}
	return board;
}

int findFitness (ChessBoard &board) {
	int fitness = 0;
	for (auto &i: board.whiteQueens) {
		for (auto &j : board.blackQueens) {
			//Find all horisontal attacks
			if (i.row == j.row)
				fitness++;
			//Find all vertical attacks
			if (i.col == j.col)
				fitness++;
			//find all diagonal attacks
			if (abs(i.row - j.row) == abs(i.col - j.col))
				fitness++;
		}
	}
	return fitness;
}

ChessBoard moveQueens (ChessBoard board, int index) {
	Queen * tempQueen;
	if (selection < board.whiteQueens.size()) {
		tempQueen = &board.whiteQueens[selection];
	} else {
		tempQueen = &board.blackQueens[selection - board.whiteQueens.size()];
	}
	int randRow = rand() % board.rows;
	int randCol = rand() % board.cols;
	if (board.vectBoard[randRow][randCol] == 0) {
		board.vectBoard[randRow][randCol] = board.vectBoard[tempQueen->row][tempQueen->col];
		tempQueen->row = randRow;
		tempQueen->col = randCol;
	}
	return board;
}
