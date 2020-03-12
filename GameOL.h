#include <iostream>
#include <fstream>

using namespace std;

class GameOL
{

  public:
    //constructor and destructor
    GameOL();
    ~GameOL();

    //fuctions
    void outputBoard(char**& board, char**& nextGenBoard, int count);
    void importFile();
    void randomFunction();
    void selectMode(char**& board);
    void classicMode(char**& board,int displayOption);
    void doughnutMode(char**& board,int displayOption);
    void mirrorMode(char**& board,int displayOption);
    void printBoard(char**& board, char**& nextGenBoard, int displayOption)

  private:
    int row;
    int column;
    char **board;


};
