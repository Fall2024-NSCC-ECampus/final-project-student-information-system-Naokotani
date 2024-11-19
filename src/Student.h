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
  std::string first_name;
  std::string last_name;
  std::vector<struct Mark> marks;

  Student() {
    this->first_name = "";
    this->last_name = "";
    this->marks = {};
  }

  Student(std::string first_name, std::string last_name,
          std::vector<Mark> marks) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->marks = marks;
  }

  static Student newName(Student student);
  static void printStudent(Student student);
  static Student inputStudent(std::vector<Mark> markTemplate);
  static void printAllGrades(std::vector<Student> students);
  MarkResult calculate_grade();
  static std::string lowerCase(std::string s);
  
  bool operator<(const Student &other) const {
    if (lowerCase(last_name) == lowerCase(other.last_name)) {
      if (lowerCase(first_name) < lowerCase(other.first_name)) {
        return true;
      }
    }
    return lowerCase(last_name) < lowerCase(other.last_name);
  }
};
#endif
