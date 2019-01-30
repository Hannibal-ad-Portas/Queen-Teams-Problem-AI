#include <iostream>


/* This function clears the terminal screen */
void cls()  {
	std::cout << "\033[H\033[2J";
	return;
}
