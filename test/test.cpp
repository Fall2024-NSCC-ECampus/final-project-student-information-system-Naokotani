#include "../src/ClassList.h"
#include "../src/Student.h"
#include "tests.h"
#include <catch2/catch_test_macros.hpp>
#include <climits>

char grade_calculation(std::vector<Mark> marks) {
  Student student{"Chris", "Hughes", marks};
  return student.calculate_grade().grade;
}

TEST_CASE("Single mark grades computed", "calculate grades") {
  std::vector<Mark> mark = std::vector<Mark>{Mark{91, 100}};
  REQUIRE(grade_calculation(mark) == 'A');
  mark =  std::vector<Mark>{Mark{85, 100}};
  REQUIRE(grade_calculation(mark) == 'B');
  mark =  std::vector<Mark>{Mark{74, 100}};
  REQUIRE(grade_calculation(mark) == 'C');
  mark =  std::vector<Mark>{Mark{68, 100}};
  REQUIRE(grade_calculation(mark) == 'D');
  mark = std::vector<Mark>{Mark{59, 100}};
  REQUIRE(grade_calculation(mark) == 'F');
}

TEST_CASE("Double mark grades computer", "calculate grades") {
  std::vector<Mark> mark = std::vector<Mark>{Mark{75, 40}, Mark{81, 60}};
  REQUIRE(grade_calculation(mark) == 'C');
  mark = std::vector<Mark>{Mark{65, 40}, Mark{71, 60}};
  REQUIRE(grade_calculation(mark) == 'D');
}

// Expected sorting outcome.
// Zoe Anderson
// Bob Brown
// Charlie Davis
// John Doe
// Frank Miller
// Hannah Moore
// Alice Smith
// Jack Taylor
// Eve Williams
// Grace Wilson
std::vector<Student> createStudentVector() {
      return std::vector<Student> {
        {"John", "Doe", {{85, 0.5}, {90, 0.5}}},
            {"Alice", "Smith", {{95, 0.6}, {88, 0.4}}},
            {"Bob", "Brown", {{72, 0.5}, {60, 0.5}}},
            {"Charlie", "Davis", {{100, 0.4}, {90, 0.6}}},
            {"Eve", "Williams", {{80, 0.7}, {75, 0.3}}},
            {"Frank", "Miller", {{65, 0.5}, {70, 0.5}}},
            {"Grace", "Wilson", {{90, 0.6}, {80, 0.4}}},
            {"Hannah", "Moore", {{92, 0.5}, {85, 0.5}}},
            {"Jack", "Taylor", {{78, 0.5}, {85, 0.5}}},
            {"Jack", "Taylor", {{78, 0.5}, {85, 0.5}}},
            {"Zoe", "Anderson", {{100, 0.5}, {95, 0.5}}}
    };
}

ClassList createClass() {
  ClassList classList;
  classList.class_name = "Gym";
  classList.students = createStudentVector();
  return classList;
}

TEST_CASE("Sort student names alphabetically", "sorting") {
  std::vector<Student> students = createStudentVector();
  std::vector<Student> sorted = sortStudentsByName(students);

  SECTION("First name") { REQUIRE(sorted[0].last_name == "Anderson"); }
  
  SECTION("Middle names") {
    REQUIRE(sorted[1].last_name == "Brown");
    REQUIRE(sorted[2].last_name == "Davis");
    REQUIRE(sorted[3].last_name == "Doe");
    REQUIRE(sorted[4].last_name == "Miller");
    REQUIRE(sorted[5].last_name == "Moore");
    REQUIRE(sorted[6].last_name == "Smith");
    REQUIRE(sorted[7].last_name == "Taylor");
    REQUIRE(sorted[8].last_name == "Taylor");
    REQUIRE(sorted[9].last_name == "Williams");
  }

    SECTION("Final name") {
      REQUIRE(sorted[10].last_name == "Wilson");    
    }
}

TEST_CASE("Delete a student", "delete") {
  SECTION("Delete one name") {
    ClassList classList = createClass();
    classList.deleteStudentByLastName("Moore");
    REQUIRE(classList.students[7].last_name == "Taylor");
  }
 }


