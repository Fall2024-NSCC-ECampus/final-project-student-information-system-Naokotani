#include <iostream>
#include <stdexcept>
#include "../SIS.h"
#include "ClassList.h"
#include "Print.h"
#include "Save.h"

using namespace std;

#ifndef MAINLOOP_H
#define MAINLOOP_H
class MainLoop {
  ClassList classList;

  string getName() {
      cout << "Enter the last name of the student to remove: ";
      string name;
      cin >> name;
      return name;
  }

  //FIXME This is breaking on improper inuts. Doesn't loop around
  int selectTask(int task) {
    switch (task) {
      // List all students
    case 1:
      this->classList.printStudents();
      break;
      // Sort alphabetically
    case 2:
      this->classList.students =
          ClassList::sortStudentsByName(this->classList.students);
      break;
      // Add new student
    case 3:
      this->classList.students.push_back(
      Student::inputStudent(this->classList.mark_template));
      break;
      // Calculate the letter grade of all students
    case 4:
      Student::printAllGrades(this->classList.students);
      break;
      // Change the information of a student.
    case 5:
      classList.updateStudentByLastName(getName());
      break;
      // Print the data of a specific student
    case 6:
      classList.printStudentByLastName(getName());
      break;
      // Rmove a student
    case 7:
      classList.deleteStudentByLastName(getName());
      break;
      // Delete ALL students
    case 8:
      classList.deleteStudents();
      break;
      // Change the grading sceheme
    case 9:
      this->classList.mark_template =
      Mark::getMarkTemplate(this->classList.mark_template.size());
      break;
      // Save
    case 10:
      try {
        Save::classList(this->classList);
      } catch (runtime_error &e) {
        cout << e.what();
      }
      break;
      //Name class
    case 11:
      classList.nameClass();
      break;
      // Load class
    case 12:
      this-> classList=Load::classList();
      break;
      // Exit
    case 13:
      return 1;
    default:
      cout << "Didn't recongine input. select a number between 1 and 10";
    }
    return 0;
  }

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

};
#endif




