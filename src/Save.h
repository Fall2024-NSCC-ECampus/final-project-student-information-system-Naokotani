#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "ClassList.h"

#ifndef SAVE_H
#define SAVE_H
class Save {

  public:
  static std::string breakLine() { return "\n***********\n"; }
  static std::string lineBreak() { return "-----------\n"; }
  static void classList(ClassList classList) {
		if(classList.className == "") {
      std::cout << "Class not named, please name (option 11)\n";
      return;
		}

    std:: string filename = "data/" + classList.className + ".txt";
    std::cout << "Saving files to: " << filename << std::endl;
    std::ofstream fout(filename);

    if(!fout.is_open()) {
      throw(std::runtime_error("Could not open save file"));
    }

    fout << classList.className;
    fout << Save::breakLine();
    fout << std::endl;
    for (Student s : classList.students) {
      fout << s.firstName << std::endl;
      fout << s.lastName << std::endl;
      for (Mark m : s.marks) {
        fout << m.name << ": " << m.weight << std::endl;
        fout << m.mark << std::endl;
      }
      fout << "\n";
    }
    fout << "\n";
    fout.close();
    std::cout << "File saved.\n";
  }

  static void orgClassList(ClassList classList) {
    if(classList.className == "") {
      std::cout << "Class not named, please name (option 11)\n";
      return;
    }

    std:: string filename = "data/" + classList.className + ".org";
    std::cout << "Saving org file to: " << filename << std::endl;
    std::ofstream fout(filename);

    if(!fout.is_open()) {
      throw(std::runtime_error("Could not open save file"));
    }

    fout << "* Class: " << classList.className << std::endl;
    fout << std::endl;
    for (Student student : classList.students) {
      fout << "** " << student.firstName << " " << student.lastName
           << std::endl;
      fout << "|------------+------+--------| " << std::endl;
      fout << "| assignemnt | mark | weight | " << std::endl;
      fout << "|------------+------+--------| " << std::endl;
      for (Mark mark : student.marks) {
        fout << "| " << mark.name << "| " << mark.mark << "| " << mark.weight << " |" << std::endl;
      }
      fout << "|------------+------+--------| " << std::endl;
      fout << std::endl;
    }
    fout.close();
    std::cout << "Org file saved succesfully.\n";
  }
};

class Load {

  static std::string trim(const std::string& str) {
    auto start = std::find_if_not(str.begin(), str.end(), ::isspace);
    auto end = std::find_if_not(str.rbegin(), str.rend(), ::isspace).base();
    return (start < end) ? std::string(start, end) : "";
  }

  static Mark readMarkLine(std::string markLine) {
    Mark mark;
    size_t colonPos = markLine.find(':');

    if(colonPos != std::string::npos) {
        std::string part1 = markLine.substr(0, colonPos);
        std::string part2 = markLine.substr(colonPos + 1);
        mark.name = trim(part1);
        mark.weight = stod(trim(part2));
    } else {
      throw(std::runtime_error("Coult not parse mark string, no colon."));
    }

    return mark;
  }

  static std::string getMarkLine(std::ifstream& fin) {
    char ch;
    std::string currLine;
    while (fin.get(ch)) {
      if (ch == ':' || ch == '\n') {
        break; // Stop when you encounter ':' or '\n'
      }
      currLine += ch; // Add the character to the string
    }
    return currLine;
  }

public:
  static ClassList classList() {
    std::string className;
    std::cout << "Enter class name: ";
    std::cin >> className;
    std::string filename = "data/" + className + ".txt";
    ClassList classList;
    std::ifstream fin(filename);
    std::string currLine;

    std::getline(fin, currLine);
    classList.className = currLine;
    fin.ignore(256, '\n');
    fin.ignore(256, '\n');
    
    std::getline(fin, currLine);
    std::vector<Student> students;
    while (!currLine.empty()) {
      Student student;
      student.firstName = currLine;
      std::getline(fin, currLine);
      student.lastName = currLine;

      std::vector<Mark> marks;
      while (!currLine.empty()) {
        std::string name;
        double weight;
        double mark;
        currLine = getMarkLine(fin);
        if (currLine.empty())
          break;
        name = currLine;
        std::getline(fin, currLine);
        weight = stod(currLine);
        std::getline(fin, currLine);
        mark = stod(currLine);
        marks.push_back(Mark{name, mark, weight});
      }
      student.marks = marks;
      students.push_back(student);
      std::getline(fin, currLine);
    }

    classList.students = students;
    for(Mark mark: classList.students[0].marks)
      classList.markTemplate.push_back(Mark{mark.name, 0, mark.weight});

    return classList;
  }
};
#endif
