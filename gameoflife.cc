// Conway's Game of Life
// Programmed by Sehee Hyung and Isaac Bleecker

#include <iostream>
#include <string>
#include <algorithm>

// Header file
#include "gameoflife.h"

// I/O declarations
using std::cout;
using std::cin;
using std::endl;

// Provides for clearing the screen before displaying the board
static const char ESC = 27;

// Establishes characters for the live cells and blank spaces
static const char LIVECELL = '*';
static const char NOCELL = ' ';



// Runs Conway's Game of Life
int main() {

	int startNumOrgs; // Number of organisms to begin with
	
	// User inputs initial number of organisms
	cout << "How many organisms initially? ";
	cin >> startNumOrgs;
	
	int startingX[startNumOrgs];
	int startingY[startNumOrgs];

	// User inputs coordinates of starting locations for each organism
	cout << "Locations? ";
	for (int i = 0; i < startNumOrgs; i += 1) {
		cin >> startingX[i];
		cin >> startingY[i];
	}

	int numGen; // Number of generations the game will run

	// User inputs number of generations
	cout <<"Generations? ";
	cin >> numGen;

	// Creates the board of organisms
	Board board;
	while (cin.get() != '\n') {}
	
	// Initilize cells in board to living or not based on coordinates
	board.setInitialBoard(startingX, startingY, startNumOrgs);
	// Clears screen
	cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
	// Prints out initial board
	board.printBoard();

	// Waits till you press return to continue
	cout << ESC << "[23;1H" << ESC << "[K"
	<< "Press RETURN to continue";
	while(cin.get() != '\n') {}
	
	// Iterates through all generations
	for(int i=1; i<=numGen; i++)
	{
		// Advances the Game of Life one generation, updates the board
		board.generation();
		// Clears screen and prints generation number
		cout << ESC << "[H" << ESC << "[J" << "Generation " << i << ":" << endl;
		// Display changed board
		board.printBoard();
		// Waits till you press return to continue, unless it is the final generation
    	if(i!=numGen)
    	{
		    cout << ESC << "[23;1H" << ESC << "[K"
		    << "Press RETURN to continue";
		    while(cin.get() != '\n') {}
    	}
	}
}




// The board object initializes to an array of organisms, all with value NONE
Board::Board()
{
  // Iterates through all the rows
	for (int y = 0; y < totalRows; y++)
	{
		// Iterates through all the columns
		for (int x = 0; x < totalCols; x++)
		{
			// Initilize every row to NONE
			_board[y][x] = Organism::NONE;
		}
	}
}


// Places living organisms on the board according to coordinates
// xValues is an array of the x coordinates
// yValues is an array of the y coordinates
// numOrg is the number of organisms (also the size of the x and y arrays)
void Board::setInitialBoard(int xValues[], int yValues[], int numOrg)
{
	for(int i = 0; i < numOrg; i++)
	{
		_board[yValues[i]][xValues[i]] = Organism::LIVING;
	}
}


// Prints out the board and border according to the values in the array of organisms
void Board::printBoard()
{
	//iterates through each row
	for (int y = 0; y < totalRows; y++) {

		//iterates through each column
		for (int x = 0; x < totalCols; x++) {

			//draws left side border and corners
			if (x == 0) {
				if (y == 0 || y == totalRows-1)
				{
					cout << "+";
					continue;
				}
				cout << "|";
			}

			//draws right side border and corners, creates newline
			else if (x == totalCols-1) {
				if (y == 0 || y == totalRows-1)
				{
					cout << "+" << endl;
					continue;
				}
				cout << "|" << endl;
			}

			//draws top and bottom borders
			else if (y == 0 || y == totalRows-1)
			{
				cout << "-";
			}

			//draws non-border (area of gameplay)
			else
			{
				if(_board[y][x] == Organism::LIVING)
				{
					//draws live cell
					cout << LIVECELL;
				}
				else{
					//draws blank space (no cell)
					cout << NOCELL;
				}
			}
		}
	}
}


// Runs through a generation of Conway's Game of Life
// Clones the initial board, and uses that to check the rules of creating and destroying organisms
void Board::generation()
{
	//creates a new board to store a copy of the original board in
	Board newboard;

	//iterates through all the rows
	for (int y = 0; y < totalRows; y++)
	{
		//iterates through all the columns
		for (int x = 0; x < totalCols; x++)
		{
			//copies each cell from board to newboard
			newboard.setState(x,y,_board[y][x]);
		}
	}
	//iterate through all the rows
	for (int y = 1; y < totalRows-1; y++) 
	{
		//iterates through all the columns
		for (int x = 1; x < totalCols-1; x++) 
		{
			//handles living organism
			if(newboard.getState(x,y) == Organism::LIVING)
			{
				//kills if too few or too many neighbors
				if(newboard.getNumNeighbors(x, y) < 2 || newboard.getNumNeighbors(x, y) >3)
				{
					_board[y][x] = Organism::NONE;
				}
			}
			//handles spaces with no organisms
			else
			{
				//creates living organism if 3 neighbors
				if(newboard.getNumNeighbors(x, y) == 3)
				{
					_board[y][x] = Organism::LIVING;
				}
			}
		}
	}
}


// Sets the state of an organism in a board
// x is the x coordinate of the organism
// y is the y coordinate of the organism
// state is the enumeration state to set the organism to
void Board::setState(int xCoord, int yCoord, Organism state)
{
	_board[yCoord][xCoord] = state;
}


// Gets the number of living neighbors around an organism
// xCoord is the x coordinate of the organism
// yCoord is the y coordinate of the organism
// Returns the number of living neighbors around a central organism
int Board::getNumNeighbors(int xCoord, int yCoord)
{
	// initalizes counter for live neighbors
	int liveCount = 0;
	// iterate through all the rows
	for (int y = yCoord-1; y<=yCoord+1; y++)
	{
		// iterate through all the columns
		for(int x = xCoord-1; x<=xCoord+1; x++)
		{
			// excludes counting the middle organism (not a neighbor)
			if(y==yCoord && x==xCoord)
			{
				continue;
			}
			// if neighbor is living, increment count
			else if(_board[y][x] == Organism::LIVING)
			{
				liveCount++;
			}
		}
	}
	return liveCount;
}


// Gets the state of an organism within a board
// xCoord is the x coordinate of the organism
// yCoord is the y coordinate of the organism
// Returns the state of the organism enumeration in a board
Organism Board::getState(int xCoord, int yCoord)
{
	return _board[yCoord][xCoord];
}
