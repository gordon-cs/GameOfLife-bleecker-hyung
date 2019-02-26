// Determines the size of the board
static const int activeRows = 18;
static const int activeCols = 50;
static const int totalRows = activeRows + 2;
static const int totalCols = activeCols + 2;

enum class Organism { NONE, LIVING };

//RT: Generally a good design.  But improvement is possible :-)

// Board is an array of organisms.
class Board
{
  public:
    Board();
//RT: need blank space between methods for readability. It guides the eye,
//    and makes it clearer which comment goes with which code.
    // Prints the board's current state
    void printBoard();

    // Sets organisms to living based on given coordinates
    void setInitialBoard(int xValues[], int yValues[], int numOrg);

    // Gets the number of neighbors for the organism at coordinate xCoord,yCoord
    //RT: This should be private, since the user shouldn't need to use it
    int getNumNeighbors(int xCoord, int yCoord);

    // Runs one generation of the Game of Life on the board
    void generation();

    // Gets the state of the organism at coordinate xCoord, yCoord
    //RT: could this be private?  User doesn't need it
    Organism getState(int xCoord, int yCoord);

    // Sets the state of the organnism at coordinate xCoord, yCoord
    //RT: Could this just be setLive()?  Thats's all the user need.
    void setState(int xCoord, int yCoord, Organism state);

  private:
    Organism _board[totalRows][totalCols];
};
