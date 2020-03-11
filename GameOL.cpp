#include "GameOL.h"
#include <fstream>

//default constructor
GameOL::GameOL(){
  int row = 0;
  int column = 0;
}

//destructor
GameOL::~GameOL(){
  delete row;
  delete column;
}

GameOL::randomFunction(){
  cout << "enter the number of rows " << endl;
  cin >> row;
  cout <<"enter the number of columns" << endl;
  cin >> column;
  double density = 0.0;
  char cont = 'y';
  while(cont == 'y'){
    cout << "enter a number between 0-1 for the density of population for the cells " << endl;
    cin >> density;
    if(density > 1 && density <0)
      cont = 'n'
  }

  char[][] board = new char [row][column];

  int occupiedCells = round((row*column)*density);

  for(int i =0; i<row; ++i){
    for(int j =0; j<column;++j){
      if(occupiedCells>0){
        board[i][j] = 'X';
        --occupiedCells;
      }
      else{
        board[i][j] = '-';
      }
    }
  }
}

GameOL::importFile(){
  string filename = "";
  cout << "Enter the name of the file you want to import. (Make sure it is in the same directory and include the file extension)" <<endl;
  cin >> filename;
  ifstream inputStream(filename);
  char cont = 'y';
  string input;
  while(getline(inputStream, input)&& cont = 'y'){
    int i =0;
    if(i==0){
      row = input;
    }
    else if(i==1){
      column = input;
      cont = 'n';
    }
    ++i;
  }

  while(getline(inputStream, input)){
    int i = 0;
    int tempRow = 0;
    char[][] board == new board[row][column];
    if(i>1){
      for(int j = 0; j<column;++j){
        board[tempRow][j] = input[j];
      }
    }
    ++i;
    ++tempRow;
  }
}

GameOL::outputBoard(char** board, char** nextGenBoard, int count){
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
  else if(board[i][j]=='-'){
    if(count==3){
      nextGenBoard[i][j]='X';
    }
    else{
      nextGenBoard[i][j]='-';
    }
  }

}

GameOL::selectMode(){
  int mode = 5;
  while(mode!=0){
    cout << "Enter 1 for classic mode; 2 for doughnut mode; and 3 for mirror mode"; << endl;
    if(mode == 1){
      //initiate classic mode
      mode =0;
    }else if(mode == 2){
      //initiate doughnut mode
      mode =0;
    }
    else if(mode ==3){
      //initiate mirror mode
      mode = 0;
    }
  }
}

GameOL::classicMode(char** board){
  //initilize count to 0 and a new board for next transformation
  //first check for boundary conditions
  //then check for all the other conditions
  //then run an if statement to print on the new board created
  //check if it is stable, if the board stays the same for 10 conditions or if all cells are empty

  bool stable = false;
  while(stable==false){
    int sameGens = 0;

    for(int i=0; i<row; ++i){
      for(int j=0; j<column;++j){
        int count = 0;
        char[][] nextGenBoard = new char[row][column];

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

        outputBoard(board, nextGenBoard, count);
      }
    }

    int emptyCount=0;
    int simCount = 0;
    for(int i =0;i<row;++i){
      for(int j=0; j<column; ++j){
        //display cells
        cout<< nextGenBoard[i][j] <<end;
        //count if all cells are -s
        if(nextGenBoard[i][j]=='-'){
          ++emptyCount;
        }
        //count if cells are the same as previous gen
        if(nextGenBoard[i][j]==board[i][j]){
          ++simCount;
        }
      }
      cout<< << endl;
    }

    //change stable to true if game over
    int numCells = row*column
    if(emptyCount==numCells{
      stable = true;
    }
    if(simCount==numCells){
      ++sameGens;
    }

    if(sameGens==10){
      stable = true;
    }
    board = nextGenBoard;

  }
}

GameOL::doughnutMode(char** board){

  bool stable = false;
  while(stable==false){
    for(int i=0; i <row;++i){
      for(int j=0; j<column;++j){

        int count =0;
        char[][] nextGenBoard = new char[][];

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
          if(board[i][j] == board[0][columns-1]){
            ++count;
          }
          if(board[i][j] == board[i][columns-1]){
            ++count;
          }
          if(board[i][j] == board[i+1][columns-1]){
            ++count;
          }
          if(board[i][j] == board[i-1][columns-1]){
            ++count;
          }
        }
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
        //finish mode


      }
    }
  }

}

GameOL::mirrorMode(char** board){

}
