#include "GameOL.cpp"
#include <iostream>

int main(int argc, **char argv){
  int response = 0;
  cout<< "for a random configuration enter 0 and to import a text file enter 1" <<endl;
  cin >> response;
  if(response==0){
    GameOL:: void randomFunction();
  }
  else if (response==1) {
    GameOL:: void importFile();
  }

  GameOL::void selectMode();
}
