#include <string>
#include <vector>

#ifndef STUDENT_H
#define STUDENT_H
/**
 * The Result from summing and appling a letter grade to a vector of `Mark`
 */
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

/**
 * A single mark for a student that includes it's name, weight and percentage grade.
 */ 
struct Mark {
  std::string name;
  double mark;
  double weight;
  static std::vector<Mark> newMarkTemplate();
  static std::vector<Mark> updateMarkTemplate(std::vector<Mark> markTemplate);
  static std::vector<Mark> getMarkTemplate(int templateLength);
  static std::vector<Mark> newMarks(std::vector<Mark> marks);
  static double getMarkDouble();

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

/**
 * A student including their first, last names and a vector of `Mark`.
 */ 
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
  MarkResult calculateGrade();
  static std::string lowerCase(std::string s);

/**
 * Over rides the < operator for a Student so that they can be sorted
 * based on their last and then first name in the case that both of
 * their names are the same.
 */ 
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
