#include <iostream>
#include "Student.h"
#include "ClassList.h"

using namespace std;

#ifndef PRINT_H
#define PRINT_H
struct Print {
  static int getInt() {
    string s;
    cin >> s;
    return stoi(s);
  }

  static void mainMenu() {
    breakLine();
    cout << "Please enter one of the following options:\n";
    cout << "1) Print all student data.\n";
    cout << "2) Sort the list of students in alphabetical order of last name.\n";
    cout << "3) Add a new student.\n";
    cout << "4) Calculate the letter grade of all students.\n";
    cout << "5) Change the information of a student.\n";
    cout << "6) Print the data of a specific student.\n";
    cout << "7) Remove a student from the list.\n";
    cout << "8) Delete ALL student data.\n";
    cout << "9) Change the grading scheme.\n";
    cout << "10) Save current Class.\n";
    cout << "11) Create org file.\n";
    cout << "12) Name class.\n";
    cout << "13) create a new class.\n";
    cout << "14) Load class.\n";
    cout << "15) Exit.\n";
    breakLine();
  }
  
  static void introMenu() {
    breakLine();
    cout << "Please enter one of the following options:\n";
    cout << "1) create a new class.\n";
    cout << "2) Load class.\n";
    cout << "3) Exit.\n";
    breakLine();
  }

  static void breakLine() {
    cout << "\n**************************************\n";
  }

  static void names(Student s) {
    cout << "First name: " << s.firstName << endl;
    cout << "Last name: " << s.lastName << endl;
  }

  static void marks(vector<Mark> marks) {
    for (const Mark& m : marks) {
      cout << m.name << ": " << m.mark << endl;
    }
  }

  static void markResult(MarkResult markResult) {
    cout << markResult.mark << ": " << markResult.grade << endl;
  }
};
#endif
