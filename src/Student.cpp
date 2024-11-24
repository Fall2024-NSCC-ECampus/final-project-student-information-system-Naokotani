#include <cstddef>
#include <iostream>
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

/**
 * Gets user input and creates a new `Student`.
 * @param The mark template to detemine the mark names and their number.
 * @return The newly created `Student`.
 */ 
Student Student::inputStudent(vector<Mark> markTemplate) {
  Student student;
  cout << "First name: ";
  cin >> student.firstName;
  cout << "Last name: ";
  cin >> student.lastName;

  for (size_t i = 0; i < markTemplate.size(); i++) {
    string s;
    cout << markTemplate[i].name << ": ";
    double mark;
    mark = Mark::getMarkDouble();

    student.marks.push_back(Mark{markTemplate[i].name, mark, markTemplate[i].weight});
  }
  return student;
}

/**
 * Creates a new name for a `Student`
 * @param The `Student` to be updated.
 * @return the `Stduent` with updated names.
 */ 
Student Student::newName(Student student) {
  cout << "First name: ";
  cin >> student.firstName;
  cout << "Last name: ";
  cin >> student.lastName;
  return student;
}

/**
 * Calculates the grade average and letter grade of a student.
 * @return The `MarkResult` of the graded student.
 */
MarkResult Student::calculateGrade() {
  const vector<double> weighted_marks = applyWeight(this->marks);
  const double sum = sumMark(weighted_marks);
  return MarkResult {
    sum,
    getLetterGrade(sum)
  };
}

/**
 * Prints the grades for all students.
 * @param vector of `Student` to print the marks for.
 */ 
void Student::printAllGrades(std::vector<Student> students) {
  for (Student s : students) {
    MarkResult markResult = s.calculateGrade();
    Print::names(s);
    Print::marks(s.marks);
    Print::markResult(markResult);
    Print::breakLine();
  }
}

/**
 * Makes a lowercase string
 * @param The string to lowercase
 * @return a string in all lower case.
 */ 
string Student::lowerCase(std::string s) {
  string lowerString = s;
  for (char& c : lowerString) {
    c = tolower(c);
  }
  return lowerString;
}

/**
 * Prints a students marks and names.
 * @param The student to print.
 */ 
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

/**
 * Sums all the marks in vector of `Mark`
 * @param The `Mark` vector to be summed.
 * @return A sum of all `Mark` in the vector.
 */ 
double sumMark(const vector<double> marks) {
  double sum = 0;
  for (size_t i = 0; i < marks.size(); i++) {
    sum += marks[i];
  }
  return sum;
}

/**
 * Determines the letter grade based on a summed `Mark` vector
 * @param The sum of marks.
 * @return The letter grade based on the students average weighted mark.
 */ 
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

