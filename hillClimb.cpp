/* This is the hill climb method of solving the team queens problem
 * It solves the problem by taking an initial state and moving a queen to a new
 * position. If the position improves the board's fitness value the change is kept
 * otherwise it is discarded and the queen moved to a new position.
 */

#include <iostream>
#include "util.h"

void hillClimb (int row, int col, int white, int black, int tmax) {
	using namespace std;
	//create a global 'best' with an initial random configuration
	cout << "Creating board\n";
	ChessBoard best(row, col);
	cout << "placing queens\n";
	best.setUp (white, black);
	//Display the Board
	best.display();
	//split off a number of child processes to calculate the solution independently
}
