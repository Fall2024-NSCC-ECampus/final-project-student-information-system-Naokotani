#include <iostream>
#include "Student.h"
#include "ClassList.h"

using namespace std;

#ifndef PRINT_H
#define PRINT_H
/**
 * Utiltiy class for printing common strings/patterns
 */ 
struct Print {
  /**
   * Gets an int from user input.
   */ 
  static int getInt() {
    string s;
    cin >> s;
    return stoi(s);
  }
  /**
   * Prints the main menu.
   */ 
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
    cout << "10) View the grading scheme\n";
    cout << "11) Save current Class.\n";
    cout << "12) Create org file.\n";
    cout << "13) Name class.\n";
    cout << "14) create a new class.\n";
    cout << "15) Load class.\n";
    cout << "16) Exit.\n";
    breakLine();
  }

  /**
   * Prints the into menu.
   */ 
  static void introMenu() {
    breakLine();
    cout << "Please enter one of the following options:\n";
    cout << "1) create a new class.\n";
    cout << "2) Load class.\n";
    cout << "3) Exit.\n";
    breakLine();
  }

/**
 * Prints the grading scheme.
 */ 
  static void gradingScheme(vector<Mark> markTemplate) {
    for (Mark mark : markTemplate) {
      cout << mark.name <<": " << mark.weight << endl;
    }
  }

/**
 * Prints a line break of *
 */ 
  static void breakLine() {
    cout << "\n**************************************\n";
  }

/**
 * Prints a `Student` name.
 */ 
  static void names(Student s) {
    cout << "First name: " << s.firstName << endl;
    cout << "Last name: " << s.lastName << endl;
  }

/**
 * Prints a vector of `Mark`
 */ 
  static void marks(vector<Mark> marks) {
    for (const Mark& m : marks) {
      cout << m.name << ": " << m.mark << endl;
    }
  }

/**
 * Prings a `MarkResults.
 */ 
  static void markResult(MarkResult markResult) {
    cout << markResult.mark << ": " << markResult.grade << endl;
  }
};
#endif
