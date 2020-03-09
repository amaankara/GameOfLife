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

}

GameOL::doughnutMode(char** board){

}

GameOL::mirrorMode(char** board){

}
