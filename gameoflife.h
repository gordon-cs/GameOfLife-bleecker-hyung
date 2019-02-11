// Determines the size of the board
static const int activeRows = 18;
static const int activeCols = 50;
static const int totalRows = activeRows + 2;
static const int totalCols = activeCols + 2;

enum class Organism { NONE, LIVING };

// Board is an array of organisms.
class Board
{
  public:
    Board();
    // Prints the board's current state
    void printBoard();
    // Sets organisms to living based on given coordinates
    void setInitialBoard(int xValues[], int yValues[], int numOrg);
    // Gets the number of neighbors for the organism at coordinate xCoord,yCoord
    int getNumNeighbors(int xCoord, int yCoord);
    // Runs one generation of the Game of Life on the board
    void generation();
    // Gets the state of the organism at coordinate xCoord, yCoord
    Organism getState(int xCoord, int yCoord);
    // Sets the state of the organnism at coordinate xCoord, yCoord
    void setState(int xCoord, int yCoord, Organism state);

  private:
    Organism _board[totalRows][totalCols];
};
