#include <iostream>
#include <string>
#include <algorithm>
#include "gameoflife.h"
using std::cout;
using std::cin;
using std::endl;

//provides for clearing the screen before displaying the _board
static const char ESC = 27;

//establishes characters for the live cells and blank spaces
static const char LIVECELL = '*';
static const char NOCELL = ' ';

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
  Board board;
  while (cin.get() != '\n') {}
	//initilize cells to living or not based on coordinates
	board.setInitialBoard(startingX, startingY, startNumOrgs);
	//clears screen
	cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
	//prints out initial board
	board.printBoard();
	//waits till you press return to continue
	cout << ESC << "[23;1H" << ESC << "[K"
	<< "Press RETURN to continue";
	while(cin.get() != '\n') {}
	//iterates through all generations
	for(int i=1; i<=numGen; i++)
	{
		//change board by referencing newboard
		board.generation();
		//clears screen and prints generation number
		cout << ESC << "[H" << ESC << "[J" << "Generation " << i << ":" << endl;
		//display changed board
		board.printBoard();
		//waits till you press return to continue
		cout << ESC << "[23;1H" << ESC << "[K"
		<< "Press RETURN to continue";
		while(cin.get() != '\n') {}
	}

}

Board::Board()
{
  //iterates through all the rows
	for (int y = 0; y < totalRows; y++)
  {
		//iterates through all the columns
		for (int x = 0; x < totalCols; x++)
    {
			//first initilize every row to none
			_board[y][x] = Organism::NONE;
    }
  }
}

//places living organisms on the board according to coordinates
void Board::setInitialBoard(int xValues[], int yValues[], int numOrg)
{
	for(int i = 0; i < numOrg; i++)
	{
		_board[yValues[i]][xValues[i]] = Organism::LIVING;
	}
}


void Board::printBoard()
{
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
				if(_board[y][x] == Organism::LIVING)
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
void Board::generation()
{
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
	for (int y = 1; y < totalRows-1; y++) {
		//iterates through all the columns
		for (int x = 1; x < totalCols-1; x++) {
			
			if(newboard.getState(x,y) == Organism::LIVING)
			{
				//kills if too few or too many neighbors
				if(newboard.getNumNeighbors(x, y) < 2 || newboard.getNumNeighbors(x, y) >3)
				{
					_board[y][x] = Organism::NONE;
				}
			}
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

void Board::setState(int x, int y, Organism state)
{
  _board[y][x] = state;
}
int Board::getNumNeighbors(int xValue, int yValue)
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
      else if(_board[y][x] == Organism::LIVING)
      {
        count++;
      }
    }
  }
  return count;
}
Organism Board::getState(int x, int y)
{
  return _board[y][x];
}
