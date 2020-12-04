#pragma once
#include <string>
#include <iostream>
#include "Student.h"
#include "degree.h"


using std::endl;
using std::string;

class Roster {
private:
    Student* classRosterArray[5];
    int numStudents;

public:
    Roster();
    ~Roster();
    void parse(string);
    void add(string, string, string, string, int, int, int, int, DegreeProgram);

    void printAll();
    void printByDegreeProgram(DegreeProgram);
    void printInvalidEmails(); // Need to check for spaces, and have @ and . characters
    void printAverageDaysInCourse(string id); // Prints the average time for all courses for each student
    void remove(string); // Remove student by ID and print error when it's not found
};
