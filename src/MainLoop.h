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
class MainLoop {
  ClassList classList;

  string getName() {
    cout << "Enter the last name of the student to remove: ";
    string name;
    cin >> name;
    return name;
  }

  int selectTask(int task) {
    switch (task) {
    case 1:
      // List all students
      this->classList.printStudents();
      break;
    case 2:
      // Sort alphabetically
      this->classList.students =
        ClassList::sortStudentsByName(this->classList.students);
      break;
    case 3:
      // Add new student      
      this->classList.students.push_back(Student::inputStudent(this->classList.markTemplate));
      break;
    case 4:
      // Calculate the letter grade of all students      
      Student::printAllGrades(this->classList.students);
      break;
    case 5:
      // Change the information of a student.      
      classList.updateStudentByLastName(getName());
      break;
    case 6:
      // Print the data of a specific student
      classList.printStudentByLastName(getName());
      break;
    case 7:
      // Remove a student      
      classList.deleteStudentByLastName(getName());
      break;
    case 8:
      // Delete ALL students      
      classList.deleteStudents();
      break;
    case 9:
      // Change the grading sceheme
      if (this->classList.markTemplate.empty()) {
        cout << "No class currently loaded.";
      } else {
        this->classList.markTemplate =
          Mark::updateMarkTemplate(this->classList.markTemplate);
      }
      break;
    case 10:
      // Save      
      try {
        Save::classList(this->classList);
      } catch (runtime_error &e) {
        cout << e.what();
      }
      break;
		case 11:
      // Save      
      try {
        Save::orgClassList(this->classList);
      } catch (runtime_error &e) {
        cout << e.what();
      }
      break;
    case 12:
      //Name class      
      classList.nameClass();
      break;
    case 13:
      // Create a new class
      this->classList = ClassList::newClass();
      break;
    case 14:
      // Load class      
      this-> classList=Load::classList();
      break;
    case 15:
      // Exit      
      return 1;
    default:
      cout << "Didn't recongine input. select a number between 1 and 10";
    }
    return 0;
  }

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

  int introLoop() {
    int input = 0;
      Print::introMenu();
      input = getUserInput();
      input = loadClass(input);
    return input;
  }
};
#endif




