#include "Student.h"
#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

int getValidInput() {
  int validInput = 0;
  string s;
  int input;
  
  do {
    cin >> s;
    try {
      input =  stoi(s);
    } catch (invalid_argument &e) {
      cout << "Could not parse a number from '" <<
        s << "' Please enter a valid number\n";
    }
  } while (!validInput);
  return input;
}

vector<Mark> Mark::getMarkTemplate(int templateLength) {
  vector<Mark> markTemplate;
  for (int i = 0; i < templateLength; i++) {
    int valid_input = 0;
    string s;
    double weight;
    string name;

    do {
      cout << "Enter the assignment name: ";
      cin >> name;
      cout << "enter first assignment weight: ";
      cin >> s;
      try {
        weight = stod(s);
        valid_input = 1;
        markTemplate.push_back(Mark{name, 0.0, weight});
      } catch (invalid_argument &e) {
        cout << "Couln't parse input: " << s << endl;
        cout << "please re-enter mark\n";
      }
    } while(valid_input == 0);
  }
  return markTemplate;
}

vector<Mark> Mark::newMarkTemplate() {
  string s;
  int templateLength;
  cout << "How many marks in the template?\n";
  templateLength = getValidInput();
  return Mark::getMarkTemplate(templateLength);
}


