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
/**
 * Class for saving org and txt files.
 */ 
class Save {
  public:
  static std::string breakLine() { return "\n***********\n"; }
/**
 * Saves a `ClassList`
 * @param The `ClassList` to be saved.
 */ 
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

/**
 * Saves the current `ClassList` as an org file.
 * @param The `ClassList` to be saved.
 */ 
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

/**
 * Functions for loading a `ClassList`.
 */ 
class Load {
/**
 * Reads the first line of a `mark` from a txt file
 * @param The file pointer to read the `Mark` from 
 */ 
  static std::string getMarkLine(std::ifstream& fin) {
    char ch;
    std::string currLine;
    while (fin.get(ch)) {
      if (ch == ':' || ch == '\n') {
        break; 
      }
      currLine += ch;
    }
    return currLine;
  }

public:
/**
 * Loads a `ClassList from a txt file.
 * @return The loaded `ClassList`.
 */ 
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
    classList.markTemplate = {};
    for (Mark mark : classList.students[0].marks)
      classList.markTemplate.push_back(Mark{mark.name, 0, mark.weight});

      
    return classList;
  }
};
#endif
