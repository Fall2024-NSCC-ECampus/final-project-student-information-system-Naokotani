#include <string>
#include <vector>

#ifndef STUDENT_H
#define STUDENT_H
struct MarkResult {
  double mark;
  char grade;

  MarkResult() {
    this->mark = 0;
    this->grade = 0;
  }

  MarkResult(double mark, char grade) {
    this->mark = mark;
    this->grade = grade;
  }
};

struct Mark {
  std::string name;
  double mark;
  double weight;
  static std::vector<Mark> newMarkTemplate();
  static std::vector<Mark> getMarkTemplate(int templateLength);
  static std::vector<Mark> newMarks(std::vector<Mark> marks);

  Mark() {
    this->name = "";
    this->mark = 0;
    this->weight = 0;
  }

  Mark(std::string name, double mark, double weight) {
    this->name = name;
    this->mark = mark;
    this->weight = weight;
  }
};

struct Student {
  std::string firstName;
  std::string lastName;
  std::vector<struct Mark> marks;

  Student() {
    this->firstName = "";
    this->lastName = "";
    this->marks = {};
  }

  Student(std::string firstName, std::string lastName,
          std::vector<Mark> marks) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->marks = marks;
  }

  static Student newName(Student student);
  static void printStudent(Student student);
  static Student inputStudent(std::vector<Mark> markTemplate);
  static void printAllGrades(std::vector<Student> students);
  MarkResult calculate_grade();
  static std::string lowerCase(std::string s);

  bool operator<(const Student &other) const {
    if (lowerCase(lastName) == lowerCase(other.lastName)) {
      if (lowerCase(firstName) < lowerCase(other.firstName)) {
        return true;
      }
    }
    return lowerCase(lastName) < lowerCase(other.lastName);
  }
};
#endif
