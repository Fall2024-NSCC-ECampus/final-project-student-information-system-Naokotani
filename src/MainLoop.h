#include <exception>
#include <iostream>
#include <stdexcept>
#include "../SIS.h"
#include "ClassList.h"
#include "Print.h"
#include "Save.h"

using namespace std;

#ifndef MAINLOOP_H
#define MAINLOOP_H
/**
 * Defines the main loops of the program including the main menu and the
 * Intro menu. 
 */ 
class MainLoop {
  ClassList classList;

  /**
   * Gets a name from the user.
   * @param the prompt to send to the user (i.e. 'detele' 'update', the action to be taken).
   * @return the name from user input.
   */ 
  string getName(string prompt) {
    cout << "Enter the last name of the student to " << prompt << ": ";
    string name;
    cin >> name;
    return name;
  }

  /**
   * Switch statement thaat controls the flow of the main menu.
   * 1) Lists all students
   * 2) Sorts the students alphabetically.
   * 3) Adds a new student to the class.
   * 4) Calculate the grade percentage and letter grade of all students and print.
   * 5) Change the information of a student, either name, grades or both.
   * 6) Print the data for a specific student by last name.
   * 7) Removes a student from the class.
   * 8) Deletes ALL student data!
   * 9) Change the grading scheme for the class for all students.
   * 10) Prints the grading scheme for the class.
   * 11) Saves the class.
   * 12) Creates an org formated file of the class details.
   * 13) Names or renames the class.
   * 14) Creates a new class.
   * 15) Loads a class from a .txt file
   * 16) exits the program.
   */ 
  int selectTask(int task) {
    switch (task) {
    case 1:
      this->classList.printStudents();
      break;
    case 2:
      this->classList.students =
        ClassList::sortStudentsByName(this->classList.students);
      break;
    case 3:
      this->classList.students.push_back(Student::inputStudent(this->classList.markTemplate));
      break;
    case 4:
      Student::printAllGrades(this->classList.students);
      break;
    case 5:
      try {
        classList.updateStudentByLastName(getName("update"));
      } catch (invalid_argument &e) {
        cout << e.what();
      }
      break;
    case 6:
      try {
        classList.printStudentByLastName(getName("dispaly"));
      } catch (invalid_argument &e) {
        cout << e.what();
      }
      break;
    case 7:
      try {
        classList.deleteStudentByLastName(getName("remove"));
      } catch (invalid_argument &e) {
        cout << e.what();
      }
      break;
    case 8:
      classList.deleteStudents();
      break;
    case 9:
      if (this->classList.markTemplate.empty()) {
        cout << "No class currently loaded.";
      } else {
        this->classList.markTemplate =
          Mark::updateMarkTemplate(this->classList.markTemplate);
      }
      break;
    case 10:
      Print::gradingScheme(this->classList.markTemplate);
      break;
    case 11:
      try {
        Save::classList(this->classList);
      } catch (runtime_error &e) {
        cout << e.what();
      }
      break;
		case 12:
      try {
        Save::orgClassList(this->classList);
      } catch (runtime_error &e) {
        cout << e.what();
      }
      break;
    case 13:
      classList.nameClass();
      break;
    case 14:
      this->classList = ClassList::newClass();
      break;
    case 15:
      this-> classList=Load::classList();
      break;
    case 16:
      return 1;
    default:
      cout << "Didn't recongine input. select a number between 1 and 10";
    }
    return 0;
  }

  /**
   * The handles the action selection for the intro menu. The intro menu
   * Ensures that a class is loaded for the operations in the main menu.
   */
    int loadClass(int input) {
    switch (input) {
    case 1:
      try {
        this->classList = ClassList::newClass();
        return 0;
      } catch (exception &e) {
        cout << "Failed to create class.";
        return -1;
      }
      break;
    case 2:
      try {
        this->classList = Load::classList();
        return 0;
      } catch (exception &e) {
        cout << "Failed to load class.";
        return -1;
      }
      break;
    case 3:
      return 1;
    }
    return 0;
  }

  /**
   * Gets user input for menu selection.
   * @return retuns an integer for action selection in the menu.
   */ 
  static int getUserInput() {
    int input;
    int valid = 0;
    while (!valid) {
      cout << "Enter a number to select an operation.\n";
      cout << "> ";
      try {
        input = Print::getInt();
        valid = 1;
      } catch(invalid_argument& e){
        cout << "Invalid argument, please enter a number.\n";
      }
    }
    return input;
  }

public:
  /**
   * Loop for the main menu
   * @return returns exit for for the program.
   */
  int mainLoop() {
    int exit = 0;
    int input = 0;
    while (!exit) {
      Print::mainMenu();
      input = getUserInput();
      exit = selectTask(input);
    }
    return 0;
  }

  //TODO Should this loop?
  /**
   * Controls the intro menu loop
   * @return an integer to determine whether to enter the main menu or
   * exit thie program.
   */ 
  int introLoop() {
    int input = 0;
    Print::introMenu();
    input = getUserInput();
    input = loadClass(input);
    return input;
  }
};
#endif




