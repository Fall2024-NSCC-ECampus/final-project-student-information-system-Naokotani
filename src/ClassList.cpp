#include "Student.h"
#include "ClassList.h"
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Print.h"

using namespace std;

/*
 * Local Structs
 */

/**
 * Used to store a student and its index in a vector.
 */
struct FoundStudent {
      size_t index;
      Student student;
};

/*
 * Local methods
 */

int getInt();
int getMarkQuantity();
int chooseStudent(vector<FoundStudent> students);
void printStudentVector(vector<Student> students);
void printMarkResult(MarkResult markResult);
string getClassname();
vector<Mark> getMarkTemplate();

/*
 * ClassList implementations
 */

/**
 * Prints the students in a classList
 */
void ClassList::printStudents() {
  printStudentVector(this->students);
}

/**
 * Sorts a vector of students alphabetically by last name and then first name.
 * @param a vector of stuents.
 * @return The sorted vector
 */
vector<Student> ClassList::sortStudentsByName(vector<Student> s) {
  vector<Student> sortedStudents = s;
  sort(sortedStudents.begin(), sortedStudents.end());
  return sortedStudents;
}

/**
 * Input a get inputs for a new class.
 * @return A newly created `ClassList`
 */
ClassList ClassList::inputClass() {
  ClassList classList;
  classList.className = getClassname();
  return classList;
}

/**
 * Adds a `Student` to the `ClassList`
 * @return The newly added `Student`
 */
Student ClassList::addStudent() {
  Student student = Student::inputStudent(this->markTemplate);
  this->students.push_back(student);
  return student;
}

/**
 * Updates the information for a student. Will update either name, marks or both.
 * @param The last name of the `Student` to be updated
 * @return the updated `Student`
 */
Student ClassList::updateStudentByLastName(string lastName) {
  int studentIndex = findStudentByLastName(lastName);
  Student student = this->students[studentIndex];
  Student::printStudent(student);
  Print::breakLine();

  int valid = 0;
  int input = 0;
  while (!valid) {
    cout << "1) update name.\n";
    cout << "2) update marks.\n";
    cout << "3) update name and marks.\n";
    cout << "Choose an option: ";
    try {
      input = Print::getInt();
      valid = 1;
    } catch (invalid_argument &e) {
      cout << "Invalid input, please enter 1-3\n";
    }
  }
  
  Student newStudent;
  switch (input) {
  case 1:
    newStudent = Student::newName(newStudent);
    newStudent.marks = student.marks;
    break;
  case 2:
    newStudent.firstName = student.firstName;
    newStudent.lastName = student.lastName;
    newStudent.marks = Mark::newMarks(student.marks);
    break;
  case 3:
    newStudent = Student::inputStudent(this->markTemplate);
    break;
  default:
    valid = 0;
  }

  if (valid) {
    this->deleteStudentByLastName(lastName);
    this->students.push_back(newStudent);
  } else {
    cout << "Error updating student\n";
  }

  return newStudent;
}

/**
 * Prints the information for a `Student` by their last name.
 * @param The last name of the `Student` to be printed.
 */
void ClassList::printStudentByLastName(string lastName) {
  Student student;
  try {
    student = this->students[findStudentByLastName(lastName)];
  } catch (invalid_argument &e) {
    cout << e.what();
    return;
  }

  cout << "First Name: " << student.firstName << endl;
  cout << "Last Name: " << student.lastName << endl;

  for (Mark m : student.marks) {
    cout << m.name << ": " << m.mark << endl;
  }
}

/**
 * Finds a `Student` in the `ClassList` by their last name.
 * @param The last name of the `Student` to find.
 * @return the index of the student in the students vector.
 */ 
int ClassList::findStudentByLastName(string lastName) {
  vector<FoundStudent> foundStudents = {};

  for(size_t i = 0; i < this->students.size(); i++) {
    if (lastName == this->students[i].lastName) {
      foundStudents.push_back(FoundStudent{i, this->students[i]});
    };
  }

  int index;
  if (foundStudents.empty()) {
    throw(invalid_argument("Student not found"));
  } else if(foundStudents.size() > 1) {
    index = chooseStudent(foundStudents);
  } else {
    index = foundStudents[0].index;
  };
  return index;
}

/**
 * Delete a `Student` by their last name.
 * @param The last name of the `Student` to delete.
 */ 
void ClassList::deleteStudentByLastName(string lastName) {
  int index = findStudentByLastName(lastName);
  this->students.erase(this->students.begin()+ index);
}

/**
 * Creates a new class.
 * @return a newly created `ClassList`
 */
ClassList ClassList::newClass() {
  ClassList classList;
  classList.nameClass();

  string input;
  while (input != "y" && input != "n") {
    cout << "Use the default marking scheme?\n";
    cout << "y/n\n";
    cin >> input;
  }

  if(input == "n") {
    cout << "How many tests and assignemnts in the class? ";
    classList.markTemplate = Mark::getMarkTemplate(getInt());    
  }

  return classList;
}

/**
 * Sets the name for a `ClassList`
 */ 
void ClassList::nameClass() {
  string name;
  cout << "Enter new class name: ";
  cin >> name;
  this->className = name;
}

/**
 * Selects a `Student` from a `vector<Student>`
 * @param A vector of `foundStduent` to select from.
 */
int chooseStudent(vector<FoundStudent> students) {
  cout << "Multiple students with the same last name\n";
  cout << "Which student would you like to delete?\n";

  for (size_t i = 0; i < students.size(); i++) {
    cout << i << ") " << students[i].student.firstName << " " << students[i].student.lastName << endl;
  }

  int validArgument = 0;
  int index;
  while (validArgument) {
    try {
      index = Print::getInt();
      validArgument = 1;
    } catch (invalid_argument &e) {
      cout << "Invalid entry, please enter a number correspoding to the student you want to delete";
    }
  }
  return index;
}

/**
 * Gets the number of `Mark` to put in a vector of `Mark` from the user.
 */
int getMarkQuantity() {
  int mark_quantity;
  cout << "Number of test and assignemnts: ";
  cin >> mark_quantity;
  return mark_quantity;
}

/**
 * Creates a vector of `Mark`
 * @param The number of `Mark` to put in the vector.
 * @return the newly created vector of `Mark`
 */ 
vector<Mark> getMarkVector(int markQuantity) {
  vector<Mark> mark_template;
  for (int i = 0; i < markQuantity; i++) {
      int valid_input = 0;
      string s;
      double weight;
      string name;
      do {
        cout << "Enter the first assignemnt name: ";
        cin >> name;
        cout << "enter first assignment weight: ";
        cin >> s;
        try {
          weight = stod(s);
          valid_input = 1;
          mark_template.push_back(Mark{name, 0.0, weight});
        } catch (invalid_argument &e) {
          cout << "Couln't parse input: " << s << endl;
          cout << "please re-enter mark\n";
        }
      } while(valid_input == 0);
    }
  return mark_template;
}

/**
 * Creates a mark template with the name and weight of a mark.
 * @return a newly created vector of `Mark`.
 */
vector<Mark> getMarkTemplate() {
  int markQuantity = getMarkQuantity();
  return getMarkVector(markQuantity);
}

/**
 * Gets the name of a class from the user.
 * @return The new class name.
 */
string getClassname() {
  string s;
  cout << "Classname: ";
  cin >> s;
  return s;
}

/**
 * Get an integer from the user.
 * @return the integer input by the user.
 */ 
int getInt() {
  string s;
  do {
    cin >> s;
    try {
      return stoi(s);
    } catch (invalid_argument &e) {
      cout << "Please enter a whole number.";
    }
  } while (1);
}

/**
 * Prints a `MarkResult` which is a graded mark.
 * @param the `MarkResult` to be printed.
 */
void printMarkResult(MarkResult markResult) {
  cout << "Final mark percentage: " << markResult.mark << endl;
  cout << "Final letter grade: " << markResult.grade << endl;
}

/**
 * Prints a vector of `Student`.
 * @param The vector of `Student` to print.
 */
void printStudentVector(vector<Student> students) {
  for (Student &s : students) {
    Print::breakLine();
    Student::printStudent(s);
  };
}

