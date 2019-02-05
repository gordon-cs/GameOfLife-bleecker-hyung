// The Game of Life Simulation
// Written by Isaac Bleecker and Anthony Aardvark

#include <iostream>
#include <string>
#include <algorithm>
//TODO make sure these are necessary
using std::string;
using std::cout;
using std::cin;
using std::endl;

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

//defines the enumeration Organism, which represents each square of the board
enum Organism { NONE, LIVING, DYING, GESTATING };

void drawBoard(Organism board[][totalCols]);
int checkNumNeighbors(Organism board[][totalCols], int xValue, int yValue);
void generation(Organism checkedboard[][totalCols], Organism board[][totalCols]);
void initialBoard(Organism board[][totalCols], int xValues[], int yValues[], int numOrg);
void copyBoard(Organism board[][totalCols], Organism newboard[][totalCols]);

int main() {
	int startNumOrgs; //number of organisms to begin with
	cout << "How many organisms at the start: ";
	cin >> startNumOrgs;
	int startingX[startNumOrgs];
	int startingY[startNumOrgs];
	//string startingCoords[startNumOrgs];
	for (int i = 0; i < startNumOrgs; i += 1) {
		cout << "Enter coordinates for organism " << i + 1 << ": ";
		cin >> startingX[i];
		cin >> startingY[i];
	}
	int numGen;
	cout <<"Generations? ";
	cin >> numGen;
	while (cin.get() != '\n') {}
	//creates a board of Organisms
	enum Organism board[totalRows][totalCols];
	//creates another version of board of Organisms
	enum Organism newboard[totalRows][totalCols];
	//initilize cells to living or not based on coordinates
	initialBoard(board, startingX, startingY, startNumOrgs);
	//clears screen
	cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
	//prints out initial board
	drawBoard(board);
	//waits till you press return to continue
	cout << ESC << "[23;1H" << ESC << "[K"
	<< "Press RETURN to continue";
	while(cin.get() != '\n') {}
	//iterates through all generations
	for(int i=1; i<=numGen; i++)
	{
		//copy board to newboard
		copyBoard(board, newboard);
		//change board by referencing newboard
		generation(board, newboard);
		//clears screen and prints generation number
		cout << ESC << "[H" << ESC << "[J" << "Generation " << i << ":" << endl;
		//display changed board
		drawBoard(board);
		//waits till you press return to continue
		cout << ESC << "[23;1H" << ESC << "[K"
		<< "Press RETURN to continue";
		while(cin.get() != '\n') {}
	}

}

//copy board to newboard
void copyBoard(Organism board[][totalCols], Organism newboard[][totalCols])
{
	//iterates through all the rows
	for (int y = 0; y < totalRows; y++)
	{
		//iterates through all the columns
		for (int x = 0; x < totalCols; x++)
		{
			//copies each cell from board to newboard
			newboard[y][x] = board[y][x];
		}
}
}
//Initilizes every cell as living or not
void initialBoard(Organism board[][totalCols], int xValues[], int yValues[], int numOrg ) {
	//iterates through all the rows
	for (int y = 0; y < totalRows; y++)
	{
		//iterates through all the columns
		for (int x = 0; x < totalCols; x++)
		{
			//first initilize every row to none
			board[y][x] = NONE;
			//then initilize if the cell is living or not
			for(int i = 0; i < numOrg; i++)
			{
				if(xValues[i]==x && yValues[i] == y)
				{
					board[y][x] = LIVING;
				}
			}
		}
	}
}
//draws the board
void drawBoard(Organism board[][totalCols]) {
	//iterates through all the rows
	for (int y = 0; y < totalRows; y++) {
		//iterates through all the columns
		for (int x = 0; x < totalCols; x++) {

			//draws left border and left corners
			if (x == 0) {
				if (y == 0 || y == totalRows-1) {
					cout << "+";
					continue;
				}
				cout << "|";
			}

			//draws right border and right corners, creates newline
			else if (x == totalCols-1) {
				if (y == 0 || y == totalRows-1) {
					cout << "+" << endl;
					continue;
				}
				cout << "|" << endl;
			}

			//draws top and bottom borders
			else if (y == 0 || y == totalRows-1) {
				cout << "-";
			}
			//draws * or " " depending on state of cell
			else {
				if(board[y][x] == LIVING)
				{
					cout << LIVECELL;
				}
				else{
					cout << NOCELL;
				}
			}
		}
}
}

//checks number of living neighbors at a single point
int checkNumNeighbors(Organism board[][totalCols], int xValue, int yValue)
{
				int count = 0;
				//iterate through all the rows
				for (int y = yValue-1; y<=yValue+1; y++)
				{
					//iterate through all the columns
					for(int x = xValue-1; x<=xValue+1; x++)
					{
						//exclude counting yourself
						if(y==yValue && x==xValue)
						{
							continue;
						}
						//if neighbor is living, count them up
						else if(board[y][x] == LIVING)
						{
							count++;
						}
					}
				}
				return count;
}

//changes the board according to the rules
void generation(Organism board[][totalCols], Organism newboard[][totalCols])
{
	//iterate through all the rows
	for (int y = 1; y < totalRows-1; y++) {
		//iterates through all the columns
		for (int x = 1; x < totalCols-1; x++) {
			if(newboard[y][x] == LIVING)
			{
				//kills if too few or too many neighbors
				if(checkNumNeighbors(newboard, x, y) < 2 || checkNumNeighbors(newboard, x, y) >3)
				{
					board[y][x] = NONE;
				}
			}
			else
			{
				//creates living organism if 3 neighbors
				if(checkNumNeighbors(newboard, x, y) == 3)
				{
					board[y][x] = LIVING;
				}
			}
		}
}
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
