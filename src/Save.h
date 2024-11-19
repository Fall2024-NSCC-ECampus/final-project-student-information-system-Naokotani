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

    if (classList.class_name == "") {
      std::cout << "Class not named, please name (option 11)\n";
      return;
    }
      
    std:: string filename = "data/" + classList.class_name + ".txt";
    std::cout << "Saving files to: " << filename << std::endl;
    std::ofstream fout(filename);

    if (!fout.is_open()) {
      throw(std::runtime_error("Could not open save file"));
    }

    fout << classList.class_name;
    fout << Save::breakLine();
    fout << std::endl;
    for (Student s : classList.students) {
      fout << s.first_name << std::endl;
      fout << s.last_name << std::endl;
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
    
    if (colonPos != std::string::npos) {
        std::string part1 = markLine.substr(0, colonPos);
        std::string part2 = markLine.substr(colonPos + 1);
        mark.name = trim(part1);
        mark.weight = stod(trim(part2));
    } else {
      throw(std::runtime_error("Coult not parse mark string, no colon."));
    }
    
    return mark;
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
    fin >> currLine;
    classList.class_name = currLine;
    fin >> currLine >> currLine;
    std::vector<Student> students;
    
    while (!currLine.empty()) {
      Student student;
      student.first_name = currLine;
      fin >> currLine;
      student.last_name = currLine;
      std::vector<Mark> marks;

      fin.ignore();
      std::getline(fin, currLine);
      while (!currLine.empty()) {
        Mark mark = readMarkLine(currLine);
        fin >> currLine;
        classList.mark_template.push_back(Mark{
            mark.name,
            0, mark.weight});
        mark.mark = stod(currLine);
        marks.push_back(mark);
        fin.ignore();
        std::getline(fin, currLine);
      }
      student.marks = marks;
      std::getline(fin, currLine);
  
      students.push_back(student);
    }
    classList.students = students;
    return classList;
  }
};
#endif
