#include "Student.h"
#include <vector>

#ifndef CLASSLIST_H
#define CLASSLIST_H
struct ClassList {
  std::string class_name;
  std::vector<Mark> mark_template;
  std::vector<Student> students;
  
  ClassList() {
    this->class_name = "";
    this->mark_template = {
      Mark{"Midterm 1", 0.0, 25},
      Mark{"Midterm 2", 0.0, 25},
      Mark{"Final", 0.0, 50}};
    this->students = {};
  }

  ClassList(std::string class_name, std::vector<Mark> mark_template,
            std::vector<Student> students) {
    this->class_name = class_name;
    this->mark_template = mark_template;
    this->students = students;
  }

  static ClassList input_class();
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
