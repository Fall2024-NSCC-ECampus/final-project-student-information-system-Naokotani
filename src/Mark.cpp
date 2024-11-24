#include "Student.h"
#include "Print.h"
#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

/**
 * Gets integer input from the user.
 * @return the integer from user input
 */
int getIntInput() {
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

/**
 * Select a `Mark` to update and then update it from a vector of `Mark`
 * @param The vector of `Mark` that will be updated.
 * @return the newly updated `Mark` vector.
 */
vector<Mark> Mark::newMarks(vector<Mark> marks) {
  cout << "Which mark to update?\n";

  for (size_t i = 0; i < marks.size(); i++) {
    cout << i + 1 << ") " << marks[i].mark << endl;
  }

  int valid = 0;
  size_t input;
  while (!valid) {
    try {
      input = Print::getInt();
      valid = 1;
    } catch (invalid_argument &e) {
      cout << "Input a nubmer corresponding to a mark.\n";
    }

    if (input <= marks.size()) {
      int validMark = 0;
      double mark;
      string s;
      while (!validMark) {
        cout << "Enter a mark: ";
        cin >> s;
        try {
          mark = stod(s);
          validMark = 1;
        } catch (invalid_argument &e) {
          cout << "Invalid mark. Enter number between 0 and 100\n";
        }
        marks[input - 1].mark = mark;
      }
    } else {
      valid = 0;
      cout << "Number should correspond to a mark.\n";
    }
  }
  return marks;
}
/**
 * Gets a double for a mark value.
 * @return a double from user input.
 */ 
double Mark::getMarkDouble() {
  string s;
  cin.ignore();
  do {
    cin >> s;
    try{
      return stod(s);
    } catch (invalid_argument &e) {
      cout << "Couln't parse input: " << s << endl;
      cout << "please re-enter mark\n";
    }
  } while(1);
}

/**
 * Updates the mark template with new values
 * @param the old template to be updated.
 * @return the newly updated template.
 */ 
vector<Mark> Mark::updateMarkTemplate(vector<Mark> markTemplate) {
  for (size_t i = 0; i < markTemplate.size(); i++) {
    cout << "Enter mark for " << markTemplate[i].name << ": ";
    markTemplate[i].weight = getMarkDouble();
  }
  return markTemplate;
}

/**
 * Creates an entirely new mark template.
 * @param The length of the template to be created
 * @return The newly created mark template.
 */ 
vector<Mark> Mark::getMarkTemplate(int templateLength) {
  vector<Mark> markTemplate;
  for (int i = 0; i < templateLength; i++) {
    Mark mark;
    cout << "Enter the assignment name: ";
    cin >> mark.name;
    cin.ignore();
    cout << "enter first assignment weight: ";
    mark.weight = getMarkDouble();
    markTemplate.push_back(mark);
  }
  return markTemplate;
}

/**
 * Creates a new mark template, gets user input to determine its length.
 * @return The new mark template from `getMarkTemplate()'
 */ 
vector<Mark> Mark::newMarkTemplate() {
  string s;
  int templateLength;
  cout << "How many marks in the template?\n";
  templateLength = getIntInput();
  return Mark::getMarkTemplate(templateLength);
}
