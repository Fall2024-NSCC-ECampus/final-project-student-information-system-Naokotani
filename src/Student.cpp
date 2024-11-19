#include <cstddef>
#include <iostream>
#include <stdexcept>
#include "Student.h"
#include "Print.h"
#include "ClassList.h"

using namespace std;

/*
 * Local methods
 */

vector<double> applyWeight(vector<Mark>);
double sumMark(vector<double>);
char getLetterGrade(double);

/*
 * Student implementations
 */

Student Student::inputStudent(vector<Mark> markTemplate) {
  Student student;
  cout << "First name: ";
  cin >> student.first_name;
  cout << "Last name: ";
  cin >> student.last_name;

  for (size_t i = 0; i < markTemplate.size(); i++) {
    string s;
    cout << markTemplate[i].name << ": ";
    cin >> s;

    double mark;
    try {
      mark = stod(s);
    } catch (invalid_argument &e) {
      throw("Invalid mark input. must be a number");
    }

    student.marks.push_back(Mark{markTemplate[i].name, mark, markTemplate[i].weight});
  }
  return student;
}

Student Student::newName(Student student) {
  cout << "First name: ";
  cin >> student.first_name;
  cout << "Last name: ";
  cin >> student.last_name;
  return student;
}

MarkResult Student::calculate_grade() {
  const vector<double> weighted_marks = applyWeight(this->marks);
  const double sum = sumMark(weighted_marks);
  return MarkResult {
    sum,
    getLetterGrade(sum)
  };
}

void Student::printAllGrades(std::vector<Student> students) {
  for (Student s : students) {
    MarkResult markResult = s.calculate_grade();
    Print::names(s);
    Print::marks(s.marks);
    Print::markResult(markResult);
    Print::breakLine();
  }
}

string Student::lowerCase(std::string s) {
  string lowerString = s;
  for (char& c : lowerString) {
    c = tolower(c);
  }
  return lowerString;
}

void Student::printStudent(Student student) {
  Print::names(student);
  Print::marks(student.marks);
}

/*
 * Local implementions
 */

vector<double> applyWeight(const vector<Mark> marks) {
  vector<double> weighted_marks;

  for (size_t i = 0; i < marks.size(); i++) {
    weighted_marks.push_back(marks[i].mark/100*marks[i].weight);
  }

  return weighted_marks;
}

double sumMark(const vector<double> marks) {
  double sum = 0;
  for (size_t i = 0; i < marks.size(); i++) {
    sum += marks[i];
  }
  return sum;
}

char getLetterGrade(double mark) {
  char letter_grade;
  if (mark >= 90.0) {
    letter_grade = 'A';
  } else if (mark >= 80.0) {
    letter_grade = 'B';
  } else if (mark >= 70.0) {
    letter_grade = 'C';
  } else if (mark >= 60.0) {
    letter_grade = 'D';
  } else {
    letter_grade = 'F';
  }
  return letter_grade;
}
