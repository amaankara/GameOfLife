#include "GameOL.cpp"
#include "GameOL.h"
#include <iostream>

int main(int argc, char** argv){
  GameOL gOL;
  int response = 0;
  cout<< "for a random configuration enter 0 and to import a text file enter 1" <<endl;
  cin >> response;
  if(response==0){
    gOL.randomFunction();
  }
  else if (response==1) {
    gOL.importFile();
  }
}
