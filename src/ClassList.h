#include "Student.h"
#include <vector>

#ifndef CLASSLIST_H
#define CLASSLIST_H
/**
 * struct that proviced the data structure to store information about a class.
 * This information includes the classes name, the mark template and a vector of
 * `Student` in the class.
 */
struct ClassList {
  std::string className;
  std::vector<Mark> markTemplate;
  std::vector<Student> students;

  ClassList() {
    this->className = "";
    this->markTemplate = {
      Mark{"Midterm 1", 0.0, 25},
      Mark{"Midterm 2", 0.0, 25},
      Mark{"Final", 0.0, 50}};
    this->students = {};
  }

  ClassList(std::string class_name, std::vector<Mark> mark_template,
            std::vector<Student> students) {
    this->className = class_name;
    this->markTemplate = mark_template;
    this->students = students;
  }

  static ClassList newClass();
  static ClassList inputClass();
  static std::vector<Student> sortStudentsByName(std::vector<Student> students);
  void printStudents();
  void printStudentsAlphabetic();
  void deleteStudents() { this->students = {}; }
  void deleteStudentByLastName(std::string lastName);
  int findStudentByLastName(std::string lastName);
  void printStudentByLastName(std::string lastName);
  Student updateStudentByLastName(std::string lastName);
  Student addStudent();
  void nameClass();
};
#endif
