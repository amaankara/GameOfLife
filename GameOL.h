//Amaan Karachiwala & Ben Bartol
//student id: 2326810 & 2315721
//email: karachiwala@chapman.edu & bartol@chapman.edu
//CPSC 350-01 & CPSC 350-02

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
    void outputBoard(char**& board, char**& nextGenBoard, int count, int i, int j);
    void importFile();
    void randomFunction();
    void classicMode(char**& board, int displayOption);
    void doughnutMode(char**& board, int displayOption);
    void mirrorMode(char**& board, int displayOption);
    void printBoard(char**& board, int displayOption);

  private:
    int row;
    int column;
    char **board;


};
