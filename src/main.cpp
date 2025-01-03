#include <iostream>
#include "../SIS.h"
#include "ClassList.h"
#include "MainLoop.h"

using namespace std;

int main() {
  ClassList classList;
  MainLoop mainLoop;
  cout << "Welcome to Student Information System version " << SIS_VERSION_MAJOR
       << "." << SIS_VERSION_MAJOR << endl;
  int exit = -1;
  while (exit == -1) {
    exit = mainLoop.introLoop();    
  }
  if (!exit) {
    mainLoop.mainLoop();    
  }

  return 0;
}
