static const int activeRows = 18;
static const int activeCols = 50;
static const int totalRows = activeRows + 2;
static const int totalCols = activeCols + 2;

enum class Organism { NONE, LIVING };

class Board
{
  public:
    Board();
    void printBoard();
    void setInitialBoard(int xValues[], int yValues[], int numOrg);
    int getNumNeighbors(int x, int y);
    void generation();
    Organism getState(int x, int y);
    void setState(int x, int y, Organism state);

  private:
    Organism _board[totalRows][totalCols];
};
