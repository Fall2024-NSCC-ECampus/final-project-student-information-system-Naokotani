#include "tests.h"
#include <catch2/catch_test_macros.hpp>
#include <climits>

using namespace std;

char gradeCalculation(vector<Mark> marks) {
  Student student{"Chris", "Hughes", marks};
  char grade = student.calculateGrade().grade;
  return grade;
}

TEST_CASE("Single mark grades computed", "calculate grades") {
  vector<Mark> mark = vector<Mark>{Mark{"Test 1",91, 100}};
  REQUIRE(gradeCalculation(mark) == 'A');
  mark =  vector<Mark>{Mark{"Test 1",85, 100}};
  REQUIRE(gradeCalculation(mark) == 'B');
  mark =  vector<Mark>{Mark{"Test 1", 74, 100}};
  REQUIRE(gradeCalculation(mark) == 'C');
  mark =  vector<Mark>{Mark{"Test 1",68, 100}};
  REQUIRE(gradeCalculation(mark) == 'D');
  mark = vector<Mark>{Mark{"Test 1",59, 100}};
  REQUIRE(gradeCalculation(mark) == 'F');
}

TEST_CASE("Double mark grades computer", "calculate grades") {
  vector<Mark> mark = vector<Mark>{Mark{"test 1", 75, 40}, Mark{"Test 2", 81, 60}};
  REQUIRE(gradeCalculation(mark) == 'C');
  mark = vector<Mark>{Mark{"test 1", 65, 40}, Mark{"Test 2", 71, 60}};
  REQUIRE(gradeCalculation(mark) == 'D');
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
vector<Student> createStudentVector() {
      return vector<Student> {
        {"John", "Doe", { Mark {"test1",85, 0.5}, Mark{"Test", 90, 0.5}}},
        {"Alice", "Smith", {Mark{"Test", 95, 0.6}, Mark{"Test",88, 0.4}}},
        {"Bob", "Brown", {Mark{"Test",72, 0.5}, Mark{"Test",60, 0.5}}},
         {"Charlie", "Davis", {Mark{"Test",100, 0.4},Mark{"Test",90, 0.6}}},
         {"Eve", "Williams",{Mark{"Test",80, 0.7}, Mark{"Test",75, 0.3}}},
         {"Frank", "Miller",{Mark{"Test",65, 0.5},Mark{"Test",70, 0.5}}},
         {"Grace", "Wilson",{Mark{"Test",90, 0.6},Mark{"Test",80, 0.4}}},
         {"Hannah", "Moore",{Mark {"Test",92, 0.5},Mark{"Test",85, 0.5}}},
         {"Jack", "Taylor",{Mark{"Test",78, 0.5},Mark{"Test",85, 0.5}}},
         {"Jack", "Taylor",{Mark{"Test",78, 0.5},Mark{"Test",85, 0.5}}},
         {"Zoe", "Anderson",{Mark{"Test",100, 0.5},Mark{"Test",95, 0.5}}}
    };
}

ClassList createClass() {
  ClassList classList;
  classList.className = "Gym";
  classList.students = createStudentVector();
  return classList;
}

TEST_CASE("Sort student names alphabetically", "sorting") {
  vector<Student> students = createStudentVector();
  vector<Student> sorted = ClassList::sortStudentsByName(students);

  SECTION("First name") { REQUIRE(sorted[0].lastName == "Anderson"); }

  SECTION("Middle names") {
    REQUIRE(sorted[1].lastName == "Brown");
    REQUIRE(sorted[2].lastName == "Davis");
    REQUIRE(sorted[3].lastName == "Doe");
    REQUIRE(sorted[4].lastName == "Miller");
    REQUIRE(sorted[5].lastName == "Moore");
    REQUIRE(sorted[6].lastName == "Smith");
    REQUIRE(sorted[7].lastName == "Taylor");
    REQUIRE(sorted[8].lastName == "Taylor");
    REQUIRE(sorted[9].lastName == "Williams");
  }

    SECTION("Final name") {
      REQUIRE(sorted[10].lastName == "Wilson");    
    }
}

TEST_CASE("Delete a student", "delete") {
  SECTION("Delete one name") {
    ClassList classList = createClass();
    classList.deleteStudentByLastName("Moore");
    REQUIRE(classList.students[7].lastName == "Taylor");
  }
 }


