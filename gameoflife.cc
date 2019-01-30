// The Game of Life Simulation
// Written by Isaac Bleecker and Anthony Aardvark

#include <iostream>
using std::cout;
using std::cin;


//provides for clearing the screen before displaying the board
static const char ESC = 27;

//establishes the size of the board and its borders
static const int activeRows = 18;
static const int activeCols = 50;
static const int totalRows = activeRows + 2;
static const int totalCols = activeCols + 2;

//establishes characters for the live cells and blank spaces
static const char LIVECELL = '*';
static const char NOCELL = ' ';

//definines the enumeration Organism, which represents each square of the board
enum Organism { NONE, LIVING, DYING, GESTATING };

Organism _board[totalRows][totalCols];

int main() {
	int startingOrgs; //number of organisms to begin with
	cout << "How many organisms at the start: "; 
	cin >> startingOrgs;
	cout << startingOrgs;
}

//Before displaying the initial board, clears the screen
//cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;

//After displaying a board, waits for user to press return to load next
//cout << ESC << "[23;1H" << ESC << "[K"  << "Press RETURN to continue"; 
//while (cin.get() != '\n') {}

//Before displaying the next board, moves the cursor to the top of the screen. 
//Makes the changing boards appear as an animation
//TODO: replace some variable with the generationCount
//cout << ESC << "[H" << "Generation " << some variable << ":" << endl;




