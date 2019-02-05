/* ============================================================================
 * This is a simple AI program designed to solve the Team Queens Problem.
 * The problem is a variation of the Queens Problem. In this variation the goal
 * is to place the queens on a chess board in such a was so that no white queen
 * is threatening a black queen, or vice versa.
 *
 * The number of queens on each team and the size of the board is provided by
 * the user as command line arguments. The program should be called as:
 *
 *		queens R C W B tmax solution.txt method
 *
 * The meaning of arguments
 * R:				number of rows in the game board
 * C:				number of columns in the game board
 * W:				number of white queens
 * B:				number of black queens
 * tmax:			the max time the program can search for a solution (in seconds)
 * solution.txt:	file to print the output to
 * method:			how the program finds the solution
 *
 * The avalable solutions are:
 *		HC
 *		SA
 *		extra
 *
 * All arguments are required
 *
 * James Conroy
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
#include "board.h"
#include "hillClimb.h"
#include "util.h"

using namespace std;

static void show_usage(string name) {
	/* initialize random seed: */

	cerr<< "Usage: " << name << " R C W B tmax solution.txt method" << endl
		<< "Required\n"
		<< "\tR\t\tNumber of rows in the game board\n"
		<< "\tC\t\tNumber of columns in the game board\n"
		<< "\tW\t\tNumber of white queens\n"
		<< "\tB\t\tNumber of black queens\n"
		<< "\ttmax\t\tMax runtime, in seconds\n"
		<< "\tsolution.txt\tFile to print the results to\n"
		<< "\tmethod\t\tHC SA extra\n"
		<< endl;
}

int main (int argc, char* argv[]) {

	string output;
	if ( argc < 7 ) {
		show_usage(argv[0]);
		return 1;
	}
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);
	int white = atoi(argv[3]);
	int black = atoi(argv[4]);
	int tmax = atoi(argv[5]);
	string outFile = argv[6];
	string method = argv[7];

	srand (time(NULL));

	if (method == "HC" || method == "hc") {
		cout << "Hill Climb Method\n";
		ChessBoard best = hillClimb (row, col, white, black, tmax);
		best.printToFile(outFile);

	} else if ( method == "SA" || method == "sa") {
		cout << "Simulated Annealing Method\n";
	} else if ( method == "extra" || method == "EXTRA") {
		cout << "Extra Credit\n";
	} else {
		cout << method;
		cout << " is not a valid method\n"
			<< "Please us HC, SA, or extra\n";
	}

	return 0;
}
