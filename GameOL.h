#include <iostream>

using namespace std;

class GameOL{

  public:
    //constructor and destructor
    GameOL();
    ~GameOL();

    //fuctions
    void outputBoard(char**  board, char** nextGenBoard, int count);
    void importFile();
    void randomFunction();
    void selectMode();
    void classicMode(char** board);
    void doughnutMode(char** board);
    void mirrorMode(char** board);

    //variables
    int row;
    int column;


}
