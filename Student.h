#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using std::endl;
using std::string;

class Student {

  private:
    int age;
    int numdays[3];
    string firstname;
    string lastname;
    string emailaddress;
    string id;
    DegreeProgram degree;
  public:
    Student(); // default constructor
   
    Student(string, string, string, string, int, int, int, int, DegreeProgram);
    ~Student();

    string GetID(); //Accessor (Getter)
    void SetID(string); //Mutator (Setter)

    string GetFirstName(); //Accessor (Getter)
    void SetFirstName(string); //Mutator (Setter)

    string GetLastName(); //Accessor (Getter)
    void SetLastName(string); //Mutator (Setter)

    string GetEmailAddress(); //Accessor (Getter)
    void SetEmailAddress(string); //Mutator (Setter)

    int GetStudentAge(); //Accessor (Getter)
    void SetStudentAge(int); //Mutator (Setter)

     // Don't need to getDaysInCourse for array (Accessor/Getter)
    void setDaysInCourse(int []); //Mutator (Setter)

    DegreeProgram GetDegree(); //Accessor (Getter)
    void SetDegree(DegreeProgram); //Mutator (Setter)

    int GetDaysInCourse1(); //Accessor (Getter)
    void SetDaysInCourse1(int); //Mutator (Setter)

    int GetDaysInCourse2(); //Accessor (Getter)
    void SetDaysInCourse2(int); //Mutator (Setter)

    int GetDaysInCourse3(); //Accessor (Getter)
    void SetDaysInCourse3(int); //Mutator (Setter) 

    static void printTitle(); // Outputs the table labels for Student data

    void print();
};
