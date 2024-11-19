#include "Student.h"
#include "ClassList.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Print.h"

using namespace std;

/*
 * Local Structs
 */

struct deleteStudent {
      size_t index;
      Student student;
};

/*
 * Local methods
 */

int getMarkQuantity();
int chooseStudent(vector<deleteStudent> students);
void printStudentVector(vector<Student> students);
void printMarkResult(MarkResult markResult);
string getClassname();
vector<Mark> getMarkTemplate();

/*
 * ClassList implementations
 */

void ClassList::printStudents() {
  printStudentVector(this->students);
}

vector<Student> ClassList::sortStudentsByName(vector<Student> s) {
  vector<Student> sortedStudents = s;
  sort(sortedStudents.begin(), sortedStudents.end());
  return sortedStudents;
}

void ClassList::printStudentsAlphabetic() {
  vector<Student> s = this->students;
  printStudentVector(s);
}

ClassList ClassList::input_class() {
  ClassList classList;
  classList.class_name = getClassname();
  return classList;
}

Student ClassList::addStudent() {
  Student student = Student::inputStudent(this->mark_template);
  this->students.push_back(student);
  return student;
}

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
    newStudent.first_name = student.first_name;
    newStudent.last_name = student.last_name;
    newStudent.marks = Mark::newMarks(student.marks);
    break;
  case 3:
    newStudent = Student::inputStudent(this->mark_template);
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

void ClassList::printStudentByLastName(string lastName) {
  Student student = this->students[findStudentByLastName(lastName)];
  cout << "First Name: " << student.first_name << endl;
  cout << "Last Name: " << student.last_name << endl;
  
  for (Mark m : student.marks) {
    cout << m.name << ": " << m.mark;
  }
}

int ClassList::findStudentByLastName(string lastName) {
  vector<deleteStudent> foundStudents = {};
  
  for(size_t i = 0; i < this->students.size(); i++) {
    if (lastName == this->students[i].last_name) {
      foundStudents.push_back(deleteStudent{i, this->students[i]});
    };
  }

  int index;
  if (foundStudents.empty()) {
    cout << "Student not found.";
    throw(runtime_error("Student not found"));
  } else if(foundStudents.size() > 1) {
    index = chooseStudent(foundStudents);
  } else {
    index = foundStudents[0].index;
  };
  return index;
}

void ClassList::deleteStudentByLastName(string lastName) {
  int index = findStudentByLastName(lastName);
  this->students.erase(this->students.begin()+ index);
}

void ClassList::nameClass() {
  string name;
  cout << "Enter new class name: ";
  cin >> name;
  this->class_name = name;
}

int chooseStudent(vector<deleteStudent> students) {
  cout << "Multiple students with the same last name\n";
  cout << "Which student would you like to delete?\n";

  for (size_t i = 0; i < students.size(); i++) {
    cout << i << ") " << students[i].student.first_name << " " << students[i].student.last_name << endl;
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

int getMarkQuantity() {
  int mark_quantity;
  cout << "Number of test and assignemnts: ";
  cin >> mark_quantity;
  return mark_quantity;
}

vector<Mark> getMarkVector(int mark_quantity) {
  vector<Mark> mark_template;
  for (int i = 0; i < mark_quantity; i++) {
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

vector<Mark> getMarkTemplate() {
  int markQuantity = getMarkQuantity();
  return getMarkVector(markQuantity);
}

string getClassname() {
  string s;
  cout << "Classname: ";
  cin >> s;
  return s;
}

void printMarkResult(MarkResult markResult) {
  cout << "Final mark percentage: " << markResult.mark << endl;
  cout << "Final letter grade: " << markResult.grade << endl;
}

void printStudentVector(vector<Student> students) {
  for (Student &s : students) {
    Print::breakLine();
    Student::printStudent(s);
  };
}

