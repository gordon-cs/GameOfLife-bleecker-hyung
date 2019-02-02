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

//definines the enumeration Organism, which represents each square of the board
enum Organism { NONE, LIVING, DYING, GESTATING };


void drawBoard2(Organism board[][totalCols]);

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
	//creates a board of Organisms
	
	enum Organism _board[totalRows][totalCols];
	//alternatively
	//cin >> y;
	//cin >> y;
	//string startingX[startNumOrgs];
	//string startingY[startNumOrgs];
	//for (int i = 1; i < startNumOrgs + 1; i += 1) {
		//adds the first character to the X-coord array
	//	startingX[i-1] = startingCoords[i-1][0];

	//	int commaLocation = startingCoords[i-1].find(',');
	//	int coordLength = startingCoords[i-1].length();

		//checks to see if the x-coord is only one digit
	//	if (commaLocation == 1) {
	//		startingY[i-1] = startingCoords[i-1][2];
			//two digit y-coord
	//		if (coordLength == 4) {
	//			startingY[i-1] += startingCoords[i-1][3];
	//		}
			
	//	}
		//two digit x-coord
	//	else {
	//		startingX[i-1] += startingCoords[i-1][1];
	//		startingY[i-1] += startingCoords[i-1][3];
			//two digit y-coord
	//		if (coordLength == 5) {
	//			startingY[i-1] += startingCoords[i-1][4];
	//		}
	//	}
	//}
	drawBoard2(_board);
}

//draws the board V2
void drawBoard2(Organism board[][totalCols]) {
	//iterates through all the rows
	for (int y = 0; y < totalRows; y++) {
		//iterates through all the columns
		for (int x = 0; x < totalCols; x++) {


			//draws left border and left corners
			if (x == 0) {
				if (y == 0 or y == totalRows-1) {
					cout << "+";
					continue;
				}
				cout << "|";
			}

			//draws right border and right corners, creates newline
			else if (x == totalCols-1) {
				if (y == 0 or y == totalRows-1) {
					cout << "+" << endl;
					continue;
				}
				cout << "|" << endl;
			}

			//draws top and bottom borders
			else if (y == 0 or y == totalRows-1) {
				cout << "-";
			}



			//draws empty space
			else {
				cout << NOCELL;
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




