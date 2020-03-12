//Amaan Karachiwala & Ben Bartol
//student id: 2326810 & 2315721
//email: karachiwala@chapman.edu & bartol@chapman.edu
//CPSC 350-01 & CPSC 350-02



#include "GameOL.h"
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>

//default constructor
GameOL::GameOL(){
  int row = 0;
  int column = 0;
  char **board;
}

//destructor
GameOL::~GameOL(){
}


//function to print the board
void GameOL::printBoard(char**& board, int displayOption){
  //display all together
  if(displayOption==1){
    for(int i=0;i<row;++i){
      for(int j=0;j<column;++j){
        //display each cell
        cout<<board[i][j]<<"   ";
      }
      //skip to next line
      cout << endl;
    }
  }
  //display on the press of enter
  else if(displayOption==2){
    bool enter = false;
    //loop until enter is press
    while(enter==false){
      char nextGen = '_';
      cout<<"press enter to view the next simulation "<<endl;
      cin>> nextGen;
      //checks if enter is press
      if(nextGen=='_'){
        for(int i=0;i<row;++i){
          for(int j=0;j<column;++j){
            //display individual cells
            cout<<board[i][j]<<"   ";
          }
          //skip to next line
          cout << endl;
        }
        enter = true;
      }
      else{
        cout<<"press enter to view the simulation " <<endl;
      }
    }
  }
  //print to a file
  else if(displayOption==3){
    string filename = "";
    cout<<"Eneter the name of the file (with the extension) " <<endl;
    cin>>filename;

    ofstream outStream;
    outStream.open(filename);

    for(int i=0;i<row;++i){
      for(int j=0;j<column;++j){
        //print individual cell to file
        outStream<<board[i][j]<<"   ";
      }
      //next line in file
      outStream << endl;
    }

  }
}

//function to check classic mode
void GameOL::classicMode(char **board, int displayOption){

  bool stable = false;
  //loop until it is stable
  while(stable==false){
    int sameGens = 0;                                                 //keeps track of same generations
    char nextGenBoard[row][column];
    for(int i =0; i<row;++i){
      for(int j=0; j<column;++j){
        nextGenBoard[i][j]=='-';
      }
    }
    for(int i=0; i<row; ++i){
      for(int j=0; j<column;++j){
        int count = 0;

        //top left corner
        if(i==0&&j==0){
          if(board[i][j]==board[i][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j]){
            ++count;
          }
        }

        //top right corner
        else if(i==0&&j==column-1){
          if(board[i][j]==board[i][j-1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j-1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j]){
            ++count;
          }
        }

        //bottom right corner
        else if(i==row-1&&j==column-1){
          if(board[i][j]==board[i-1][j-1]){
            ++count;
          }
          if(board[i][j]==board[i-1][j]){
            ++count;
          }
          if(board[i][j]==board[i][j-1]){
            ++count;
          }
        }

        //bottom left corner
        else if(i==row-1&&j==0){
          if(board[i][j]==board[i-1][j]){
              ++count;
            }
            if(board[i][j]==board[i-1][j+1]){
              ++count;
            }
            if(board[i][j]==board[i][j+1]){
              ++count;
            }
        }

        //top row
        else if(i=0){
          if(board[i][j]==board[i][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j]){
            ++count;
          }
          if(board[i][j]==board[i+1][j-1]){
            ++count;
          }
          if(board[i][j]==board[i][j-1]){
            ++count;
          }
        }

        //bottom row
        else if(i==row-1){
          if(board[i][j]==board[i-1][j-1]){
            ++count;
          }
          if(board[i][j]==board[i-1][j]){
            ++count;
          }
          if(board[i][j]==board[i-1][j+1]){
            ++count;
          }
          if(board[i][j]==board[i][j+1]){
            ++count;
          }
          if(board[i][j]==board[i][j-1]){
            ++count;
          }
        }

        //left column
        else if(j==0){
          if(board[i][j]==board[i-1][j]){
            ++count;
          }
          if(board[i][j]==board[i-1][j+1]){
            ++count;
          }
          if(board[i][j]==board[i][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j]){
            ++count;
          }
        }

        //right column
        else if(j==column-1){
          if(board[i][j]==board[i-1][j-1]){
            ++count;
          }
          if(board[i][j]==board[i-1][j]){
            ++count;
          }
          if(board[i][j]==board[i+1][j]){
            ++count;
          }
          if(board[i][j]==board[i+1][j-1]){
            ++count;
          }
          if(board[i][j]==board[i][j-1]){
            ++count;
          }
        }

        //without boundary conditions
        else{
          if(board[i][j]==board[i-1][j-1]){
            ++count;
          }
          if(board[i][j]==board[i-1][j]){
            ++count;
          }
          if(board[i][j]==board[i-1][j+1]){
            ++count;
          }
          if(board[i][j]==board[i][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j]){
            ++count;
          }
          if(board[i][j]==board[i+1][j-1]){
            ++count;
          }
          if(board[i][j]==board[i][j-1]){
            ++count;
          }
        }

        //calling output function
        //outputBoard(board, nextGenBoard, count,i,j);

        if(board[i][j]=='X'){
          if(count==2){
            nextGenBoard[i][j]='X';
          }
          else if(count==3){
            nextGenBoard[i][j]='X';
          }
          else{
            nextGenBoard[i][j]='-';
          }
        }
        //if cell has - and checks conditions to output X or -
        else if(board[i][j]=='-'){
          if(count==3){
            nextGenBoard[i][j]='X';
          }
          else{
            nextGenBoard[i][j]='-';
          }
        }
      }
    }

    //check if stable
    //stable = isStable(board,nextGenBoard,sameGens);
    int emptyCount=0;
    int simCount = 0;
    for(int i =0;i<row;++i){
      for(int j=0; j<column; ++j){
        //count if all cells are -s
        if(nextGenBoard[i][j]=='-'){
          ++emptyCount;
        }
        //count if cells are the same as previous gen
        if(nextGenBoard[i][j]==board[i][j]){
          ++simCount;
        }
      }
    }

    //change stable to true if game over
    int numCells = row*column;
    if(emptyCount==numCells){
      stable = true;
    }
    if(simCount==numCells){
      ++sameGens;
    }
    if(sameGens==10){
      stable = true;
    }


    for(int i =0; i<row;++i){
      for(int j=0; j,column;++j){
        //update value in current board
        board[i][j]=nextGenBoard[i][j];
      }
    }

    printBoard(board,displayOption);

  }
  return 0;
}

//fucntion to check doughnut mode
void GameOL::doughnutMode(char**& board, int displayOption){
  int sameGens=0;                                                //keeps track of same generations
  bool stable = false;
  while(stable==false){
    char nextGenBoard[row][column];
    for(int i=0;i<row;++i){
      for(int j=0;j<column;++j){
        nextGenBoard[i][j]='-';
      }
    }

    for(int i=0; i <row;++i){
      for(int j=0; j<column;++j){
        int count =0;

        //top left corner
        if(i==0&&j==0){
          if(board[i][j]==board[i][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j]){
            ++count;
          }
          if(board[i][j]==board[row-1][column-1]){
            ++count;
          }
          if(board[i][j]==board[i][column-1]){
            ++count;
          }
          if(board[i][j]==board[row-1][j]){
            ++count;
          }
          if(board[i][j]==board[row-1][j+1]){
            ++count;
          }
          if(board[i][j]==board[i+1][column-1]){
            ++count;
          }
        }

        //top right corner
        else if(i==0&&j==(column-1)){
          if(board[i][j]==board[i][j-1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j-1]){
            ++count;
          }
          if(board[i][j]==board[i+1][j]){
            ++count;
          }
          if(board[i][j]==board[row-1][j]){
            ++count;
          }
          if(board[i][j]==board[row-1][j-1]){
            ++count;
          }
          if(board[i][j]==board[row-1][0]){
            ++count;
          }
          if(board[i][j]==board[i][0]){
            ++count;
          }
          if(board[i][j]==board[i+1][0]){
            ++count;
          }
        }

        //right borrom corner
        else if(i == (row-1) && j == (column-1)){
          if(board[i][j] == board[i-1][j]){
            ++count;
          }
          if(board[i][j] == board[i][j-1]){
            ++count;
          }
          if(board[i][j] == board[i+1][j-1]){
            ++count;
          }
          if(board[i][j] == board[0][j-1]){
            ++count;
          }
          if(board[i][j] == board[0][j]){
            ++count;
          }
          if(board[i][j] == board[0][0]){
            ++count;
          }
          if(board[i][j] == board[i][0]){
            ++count;
          }
          if(board[i][j] == board[i-1][0]){
            ++count;
          }
        }

        //left bottom corner
        else if(i == (row - 1) && j == 0){
          if(board[i][j] == board[i][j+1]){
            ++count;
          }
          if(board[i][j] == board[i-1][j]){
            ++count;
          }
          if(board[i][j] == board[i-1][j+1]){
            ++count;
          }
          if(board[i][j] == board[0][j]){
            ++count;
          }
          if(board[i][j] == board[0][j+1]){
            ++count;
          }
          if(board[i][j] == board[0][column-1]){
            ++count;
          }
          if(board[i][j] == board[i][column-1]){
            ++count;
          }
          if(board[i][j] == board[i+1][column-1]){
            ++count;
          }
          if(board[i][j] == board[i-1][column-1]){
            ++count;
          }
        }

        //left column
        else if(j == 0){
          if(board[i][j] == board[i-1][j]){
            ++count;
          }
          if(board[i][j] == board[i+1][j]){
            ++count;
          }
          if(board[i][j] == board[i][j+1]){
            ++count;
          }
          if(board[i][j] == board[i+1][j+1]){
            ++count;
          }
          if(board[i][j] == board[i-1][j+1]){
            ++count;
          }
          if(board[i][j] == board[i-1][column-1]){
            ++count;
          }
          if(board[i][j] == board[i][column-1]){
            ++count;
          }
          if(board[i][j] == board[i+1][column-1]){
            ++count;
          }
        }

        //top row
        else if(i == 0){
          if(board[i][j] == board[i][j+1]){
            ++count;
          }
          if(board[i][j] == board[i][j-1]){
            ++count;
          }
          if(board[i][j] == board[i+1][j-1]){
            ++count;
          }
          if(board[i][j] == board[i+1][j]){
            ++count;
          }
          if(board[i][j] == board[i+1][j+1]){
            ++count;
          }
          if(board[i][j] == board[row-1][j-1]){
            ++count;
          }
          if(board[i][j] == board[row-1][j]){
            ++count;
          }
          if(board[i][j] == board[row-1][j+1]){
            ++count;
          }
        }

        //bottom row
        else if(i == (row-1)){
          if(board[i][j] == board[i][j+1]){
            ++count;
          }
          if(board[i][j] == board[i][j-1]){
            ++count;
          }
          if(board[i][j] == board[i-1][j-1]){
            ++count;
          }
          if(board[i][j] == board[i-1][j]){
            ++count;
          }
          if(board[i][j] == board[i-1][j+1]){
            ++count;
          }
          if(board[i][j] == board[0][j-1]){
            ++count;
          }
          if(board[i][j] == board[0][j]){
            ++count;
          }
          if(board[i][j] == board[0][j+1]){
            ++count;
          }
        }

        //right column
        else if(j == (column - 1)){
          if(board[i][j] == board[i-1][j]){
            ++count;;
          }
          if(board[i][j] == board[i-1][j-1]){
            ++count;;
          }
          if(board[i][j] == board[i+1][j]){
            ++count;;
          }
          if(board[i][j] == board[i+1][j-1]){
            ++count;;
          }
          if(board[i][j] == board[i+1][0]){
            ++count;;
          }
          if(board[i][j] == board[i-1][0]){
            ++count;;
          }
          if(board[i][j] == board[i][0]){
            ++count;;
          }
          if(board[i][j] == board[i][j-1]){
            ++count;;
          }
          if(board[i][j] == board[i][j+1]){
            ++count;;
          }
        }
        //middle cells
        else{

          if(board[i][j] == board[i+1][j+1]){
            ++count;
          }
          if(board[i][j] == board[i+1][j-1]){
            ++count;
          }
          if(board[i][j] == board[i+1][j]){
            ++count;
          }
          if(board[i][j] == board[i-1][j+1]){
            ++count;
          }
          if(board[i][j] == board[i-1][j-1]){
            ++count;
          }
          if(board[i][j] == board[i-1][j]){
            ++count;
          }
          if(board[i][j] == board[i][j+1]){
            ++count;
          }
          if(board[i][j] == board[i][j-1]){
            ++count;
          }
        }

        //outputBoard(board, nextGenBoard, count,i,j);

        if(board[i][j]=='X'){
          if(count==2){
            nextGenBoard[i][j]='X';
          }
          else if(count==3){
            nextGenBoard[i][j]='X';
          }
          else{
            nextGenBoard[i][j]='-';
          }
        }
        //if cell has - and checks conditions to output X or -
        else if(board[i][j]=='-'){
          if(count==3){
            nextGenBoard[i][j]='X';
          }
          else{
            nextGenBoard[i][j]='-';
          }
        }

      }
    }

    //stable = isStable(board,nextGenBoard,sameGens);
    int emptyCount=0;
    int simCount = 0;
    for(int i =0;i<row;++i){
      for(int j=0; j<column; ++j){
        //count if all cells are -s
        if(nextGenBoard[i][j]=='-'){
          ++emptyCount;
        }
        //count if cells are the same as previous gen
        if(nextGenBoard[i][j]==board[i][j]){
          ++simCount;
        }
      }
    }

    //change stable to true if game over
    int numCells = row*column;
    if(emptyCount==numCells){
      stable = true;
    }
    if(simCount==numCells){
      ++sameGens;
    }
    if(sameGens==10){
      stable = true;
    }

    for(int i =0; i<row;++i){
      for(int j=0; j,column;++j){
        board[i][j]=nextGenBoard[i][j];
      }
    }

    printBoard(board,displayOption);

  }
}

//function to check mittor mode
void GameOL::mirrorMode(char**& board, int displayOption){
  int sameGens = 0;
  bool stable = false;
  while(stable==false){

    char nextGenBoard[row][column];
    for(int i=0;i<row;++i){
      for(int j=0;j<column;++j){
        nextGenBoard[i][j]='-';
      }
    }

    for(int i=0;i<row;++i){
      for(int j=0;j<column;++i){

        int count =0;
          //top left corner
          if(i==0&&j==0){
            if(board[i][j]==board[i][j]){
              count = count+3;
            }
            if(board[i][j] == board[i][j+1]){
              count = count+2;
            }
            if(board[i][j] == board[i+1][j+1]){
              count = count+1;
            }
            if(board[i][j] == board[i+1][j]){
              count = count+2;
            }
          }

          //top left corner
          else if((i == 0) && (j == (column-1))){
            if(board[i][j] == board[i][j]){
              count = count+3;
            }
            if(board[i][j] == board[i][j-1]){
              count = count+2;
            }
            if(board[i][j] == board[i+1][j-1]){
              count = count+1;
            }
            if(board[i][j] == board[i+1][j]){
              count = count+2;
            }
          }

          //bottom right corner
          else if((i == (row - 1) && (j == (column - 1)))){
            if(board[i][j] == board[i][j]){
              count = count+3;
            }
            if(board[i][j] == board[i-1][j]){
              count = count+2;
            }
            if(board[i][j] == board[i-1][j-1]){
              count = count+1;
            }
            if(board[i][j] == board[i][j-1]){
              count = count+2;
            }
          }

          //bottom left corner
          else if((i == (row - 1) && (j == 0))){
            if(board[i][j] == board[i][j]){
              count = count+3;
            }
            if(board[i][j] == board[i-1][j]){
              count = count+2;
            }
            if(board[i][j] == board[i-1][j+1]){
              count = count+1;
            }
            if(board[i][j] == board[i][j+1]){
              count = count+2;
            }
          }

          //top row
          else if(i == 0){
            if(board[i][j] == board[i][j]){
              count = count+1;
            }
            if(board[i][j] == board[i][j-1]){
              count = count+2;
            }
            if(board[i][j] == board[i][j+1]){
              count = count+2;
            }
            if(board[i][j] == board[i+1][j+1]){
              count = count+1;
            }
            if(board[i][j] == board[i+1][j]){
              count = count+1;
            }
            if(board[i][j] == board[i+1][j-1]){
              count = count+1;
            }
          }

          //bottom row
          else if(i == (row - 1)){
            if(board[i][j] == board[i][j]){
              count = count+1;
            }
            if(board[i][j] == board[i][j-1]){
              count = count+2;
            }
            if(board[i][j] == board[i][j+1]){
              count = count+2;
            }
            if(board[i][j] == board[i-1][j-1]){
              count = count+1;
            }
            if(board[i][j] == board[i-1][j]){
              count = count+1;
            }
            if(board[i][j] == board[i-1][j+1]){
              count = count+1;
            }
          }

          //left column
          else if(j = 0){
            if(board[i][j] == board[i][j]){
              count = count+1;
            }
            if(board[i][j] == board[i-1][j]){
              count = count+2;
            }
            if(board[i][j] == board[i+1][j]){
              count = count+2;
            }
            if(board[i][j] == board[i+1][j+1]){
              count = count+1;
            }
            if(board[i][j] == board[i][j+1]){
              count = count+1;
            }
            if(board[i][j] == board[i-1][j]){
              count = count+1;
            }
          }

          //right column
          else if(j == (column - 1)){
            if(board[i][j] == board[i][j]){
              count = count+1;
            }
            if(board[i][j] == board[i+1][j]){
              count = count+2;
            }
            if(board[i][j] == board[i-1][j]){
              count = count+2;
            }
            if(board[i][j] == board[i-1][j-1]){
              count = count+1;
            }
            if(board[i][j] == board[i][j-1]){
              count = count+1;
            }
            if(board[i][j] == board[i+1][j-1]){
              count = count+1;
            }
          }


          //middle cells
          else{
            if(board[i][j] == board[i+1][j+1]){
              ++count;
            }
            if(board[i][j] == board[i+1][j-1]){
              ++count;
            }
            if(board[i][j] == board[i+1][j]){
              ++count;
            }
            if(board[i][j] == board[i-1][j+1]){
              ++count;
            }
            if(board[i][j] == board[i-1][j-1]){
              ++count;
            }
            if(board[i][j] == board[i-1][j]){
              ++count;
            }
            if(board[i][j] == board[i][j+1]){
              ++count;
            }
            if(board[i][j] == board[i][j-1]){
              ++count;
            }
          }
          //outputBoard(board, nextGenBoard, count,i,j);

          if(board[i][j]=='X'){
            if(count==2){
              nextGenBoard[i][j]='X';
            }
            else if(count==3){
              nextGenBoard[i][j]='X';
            }
            else{
              nextGenBoard[i][j]='-';
            }
          }
          //if cell has - and checks conditions to output X or -
          else if(board[i][j]=='-'){
            if(count==3){
              nextGenBoard[i][j]='X';
            }
            else{
              nextGenBoard[i][j]='-';
            }
          }

        }
      }
      //stable = isStable(board,nextGenBoard,sameGens);
      int emptyCount=0;
      int simCount = 0;
      for(int i =0;i<row;++i){
        for(int j=0; j<column; ++j){
          //count if all cells are -s
          if(nextGenBoard[i][j]=='-'){
            ++emptyCount;
          }
          //count if cells are the same as previous gen
          if(nextGenBoard[i][j]==board[i][j]){
            ++simCount;
          }
        }
      }

      //change stable to true if game over
      int numCells = row*column;
      if(emptyCount==numCells){
        stable = true;
      }
      if(simCount==numCells){
        ++sameGens;
      }
      if(sameGens==10){
        stable = true;
      }

      for(int i =0; i<row;++i){
        for(int j=0; j,column;++j){
          board[i][j]=nextGenBoard[i][j];
        }
      }

      printBoard(board,displayOption);

    }
}

//function to create random board
void GameOL::randomFunction(){
  int rValue = 0;
  cout << "enter the number of rows " << endl;
  cin >> row;
  cout <<"enter the number of columns" << endl;
  cin >> column;
  double density = 0.0;
  char cont = 'y';
  //loop until density between 0 and 1
  while(cont == 'y'){
    cout << "enter a number between 0-1 for the density of population for the cells " << endl;
    cin >> density;
    if(density > 1 && density <0){
      cont = 'n';
    }
  }
  //creating a board
  char board[row][column];

  //calculating number of occupied Cells
  int occupiedCells = round((row*column)*density);

  int occupiedCount = 0;

  //loops until board is populated with sufficent density.
  while(occupiedCount<occupiedCells){
    for(int i = 0; i<row;++i){
      for(int j =0; j<column;++j){
        //create random number between 0 and 1
        double ranNum = ((double) rand() / (RAND_MAX));
        //output X is random number greater than 0.5 and there is not already a X there
        if(ranNum>0.5 && board[i][j]!='X'){
          board[i][j]='X';
          occupiedCount++;
        }
        //output - if no X in cell
        else if(board[i][j]!='X'){
          board[i][j]='-';
        }
      }
    }
  }
  //call select mode
  //selectMode(board);
  int mode = 5;
  int displayOption = 0;
  //asks user what display option required
  cout<<"Select how you want display your simulations "<<endl;
  cout<<"Enter 1 to view all the simulations together "<<endl;
  cout<<"Enter 2 to press Enter to display the next simulations "<<endl;
  cout<<"Enter 3 to view all the simulations in a file "<<endl;
  cin>>displayOption;

  //loop until current number selected
  while(mode!=0){
    cout << "Enter 1 for classic mode; 2 for doughnut mode; and 3 for mirror mode" << endl;
    cin >> mode;
    if(mode == 1){
      mode = 0;
      classicMode(board, displayOption);
    }else if(mode == 2){
      mode =0;
      doughnutMode(board, displayOption);
    }
    else if(mode ==3){
      mode = 0;
      mirrorMode(board, displayOption);
    }
  }
}

//fucntion to import a board
void GameOL::importFile(){
  string filename = "";
  cout << "Enter the name of the file you want to import. (Make sure it is in the same directory and include the file extension)" <<endl;
  cin >> filename;
  ifstream inputStream(filename);
  char cont = 'y';
  string input;
  //read file line by line
  while(getline(inputStream, input)&& cont == 'y'){
    int i =0;
    stringstream degree(input);
    //input rows
    if(i==0){
      degree>>row;
    }
    //input columns
    else if(i==1){
      degree>>column;
      cont = 'n';
    }
    i++;
  }

  //creat new board
  char board[row][column];
  while(getline(inputStream, input)){
    int i = 0;
    int tempRow = 0;
    if(i>1){
      for(int j = 0; j<column;++j){
        //input values from file to board
        board[tempRow][j] = input[j];
      }
    }
    i++;
    tempRow++;
  }
  //call select mode
  //selectMode(board);
  int mode = 5;
  int displayOption = 0;
  //asks user what display option required
  cout<<"Select how you want display your simulations "<<endl;
  cout<<"Enter 1 to view all the simulations together "<<endl;
  cout<<"Enter 2 to press Enter to display the next simulations "<<endl;
  cout<<"Enter 3 to view all the simulations in a file "<<endl;
  cin>>displayOption;

  //loop until current number selected
  while(mode!=0){
    cout << "Enter 1 for classic mode; 2 for doughnut mode; and 3 for mirror mode" << endl;
    cin >> mode;
    if(mode == 1){
      mode =0;
      classicMode(board, displayOption);
    }else if(mode == 2){
      mode =0;
      doughnutMode(board, displayOption);
    }
    else if(mode ==3){
      mode = 0;
      mirrorMode(board, displayOption);
    }
  }
}
