// The Game of Life Simulation
// Written by Isaac Bleecker and Anthony Aardvark

#include <iostream>
#include <string>
//TODO make sure these are necessary
using namespace std;
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
	int startNumOrgs; //number of organisms to begin with
	int locationCount = 0;
	cout << "How many organisms at the start: "; 
	cin >> startNumOrgs;
	string startingCoords[startNumOrgs];
	for (int i = 1; i < startNumOrgs + 1; i += 1) {
		cout << "Enter comma separated location " << i << ": ";
		cin >> startingCoords[i-1];
	}
	string startingX[startNumOrgs];
	string startingY[startNumOrgs];
	for (int i = 1; i < startNumOrgs + 1; i += 1) {
		startingX[i-1] = startingCoords[i-1][0];
		//if next coordinate is a number add it
			//then skip the comme and add the next
				//check if the next character exists
					//if it does add it
		//else skip the comma and add the next
			//check if next character exists
				//if it does add it
		cout << startingCoords[i-1];
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




