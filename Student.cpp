#include <string>
#include <iostream>
#include "Student.h"
#include "degree.h"

using std::cout;
using std::endl;
using std::string;


// Default constructor
Student::Student() {
    id = "";
    firstname = "";
    lastname = "";
    emailaddress = "";
    age = 0;
    for (int i = 0; i < 3; i++) 
        numdays[i] = 0;
}

// Actual constructor to do stuff
Student::Student(string _id, string _firstname, string _lastname, string _emailaddress, 
                int _age, int _daysInCourse1, int _daysInCourse2, int _daysInCourse3, 
                DegreeProgram _degree) {
    id = _id;
    firstname = _firstname;
    lastname = _lastname;
    emailaddress = _emailaddress;
    age = _age;
    numdays[0] = _daysInCourse1;
    numdays[1] = _daysInCourse2;
    numdays[2] = _daysInCourse3;
    degree = _degree;
}

// Array for days in course is manually set in Student.h, so this destructor is less important
Student::~Student() = default;

// Accessors (Getters)
string Student::GetID() { return id; }

string Student::GetFirstName() { return firstname; }

string Student::GetLastName() { return lastname; }

string Student::GetEmailAddress() { return emailaddress; }

int Student::GetStudentAge() { return age; }

DegreeProgram Student::GetDegree() { return degree; }

int Student::GetDaysInCourse1() { return numdays[0]; }

int Student::GetDaysInCourse2() { return numdays[1]; }

int Student::GetDaysInCourse3() { return numdays[2]; }

// Mutators (Setters)
void Student::SetID(string _id) { id = _id; }

void Student::SetFirstName(string _firstname) { firstname = _firstname; }

void Student::SetLastName(string _lastname) { lastname = _lastname; }

void Student::SetEmailAddress(string _emailaddress) { emailaddress = _emailaddress; }

void Student::SetStudentAge(int _studentAge) { age = _studentAge; }

void Student::SetDegree(DegreeProgram _degree) { degree = _degree; }

void Student::SetDaysInCourse1(int _days) { numdays[0] = _days; }

void Student::SetDaysInCourse2(int _days) { numdays[1] = _days; }

void Student::SetDaysInCourse3(int _days) { numdays[2] = _days; }

// Header might not align perfectly due to tabs, this is ok
void Student::printTitle() {
    cout << "StudentID  |  First  |  Last  |  Email  |  Age  |    Days in Courses    |  Degree Program  " << endl;
}

void Student::print() {
    cout << id << '\t';
    cout << firstname << '\t';
    cout << lastname << '\t';
    cout << emailaddress << '\t';
    cout << age << '\t';
    cout << numdays[0] << '\t';
    cout << numdays[1] << '\t';
    cout << numdays[2] << '\t';
    cout << degreeProgramStrings[degree] << endl;
}
