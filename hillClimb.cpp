/* This is the hill climb method of solving the team queens problem
 * It solves the problem by taking an initial state and moving a queen to a new
 * position. If the position improves the board's fitness value the change is kept
 * otherwise it is discarded and the queen moved to a new position.
 */

#include <iostream>
#include "board.h"
#include "util.h"

ChessBoard findBest (ChessBoard board);

ChessBoard hillClimb (int row, int col, int white, int black, int tmax) {
	using namespace std;
	//create a global 'best' with an initial random configuration
	//cout << "Creating board\n";
	ChessBoard best(row, col, white, black);
	//cout << "placing queens\n";
	//Display the Board
	//best.display();
	//cout << "Finding Fitness\n";
	//cout << "This board's fitness is " << best.findFitness() << endl;
	best = findBest(best);
	return best;
}

ChessBoard findBest (ChessBoard board) {
	using namespace std;
	ChessBoard bestBoard = board;
	int fitness = board.findFitness();
	//cout << "Inital Fitness: " << fitness << endl;
	int index = 0;
	while (fitness != 0) {
		//select a queen form the board
		Queen * selectedQueen;
		if (index > board.wQueens + board.bQueens)
			index = 0;
		if (index < board.wQueens) {
			selectedQueen = &board.whiteQueens[index];
		} else {
			selectedQueen = &board.blackQueens[index - board.wQueens];
		}
		//cout << "\nQueen " << index << " selected\n";
		//move the queen to new position checking the fitness each time
		int bestPosFitness = fitness;
		int tempPosFitness = fitness;
		int bestRow, bestCol, originalRow, originalCol;
		originalRow = selectedQueen->row;
		originalCol = selectedQueen->col;
		//cout << "Original Row Value " << originalRow << endl;
		//cout << "Original Col Value " << originalCol << endl;

		for (int i = 0; i < board.rows; i++) {
			for (int j = 0; j < board.cols; j++) {
				selectedQueen->row = i;
				selectedQueen->col = j;
				//cout << "Testing pos " << selectedQueen->row << " " << selectedQueen->col << endl;
				tempPosFitness = board.findFitness();
				//cout << "Temp Fitness is: " << tempPosFitness << endl;
				//cout << "Best Pos Fitness is: " << bestPosFitness << endl;
				if ( tempPosFitness < bestPosFitness) {
					bestPosFitness = tempPosFitness;
					bestRow = i;
					bestCol = j;
					//cout << "Better pos found at: " << i << " " << j << endl;
				}
			}
		}
		if (bestPosFitness < fitness) {
			selectedQueen->row = bestRow;
			selectedQueen->col = bestCol;
			fitness = bestPosFitness;
			//cout << "Better Configuration Found\n";
			board.fillBoard();
			bestBoard = board;
		} else {
			selectedQueen->row = originalRow;
			selectedQueen->col = originalCol;
		}
		//bestBoard.display();
		index++;
	}
	return bestBoard;
}
