#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include "degree.h"
#include "Student.h"
#include "Roster.h"

using namespace std;


Roster::Roster() {
    numStudents = 0;
}

Roster::~Roster() {
    cout << "Running destructor, please wait." << endl << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Removing student with ID: " << classRosterArray[i]->GetID() << endl;
        delete(classRosterArray[i]);
        classRosterArray[i] = nullptr;
    }
}

void Roster::parse(string studentData) {
    stringstream sdata(studentData);
    string id, fname, lname, email, age, dC1, dC2, dC3, dp;
    getline(sdata, id, ',');
    getline(sdata, fname, ',');
    getline(sdata, lname, ',');
    getline(sdata, email, ',');
    getline(sdata, age, ',');
    getline(sdata, dC1, ',');
    getline(sdata, dC2, ',');
    getline(sdata, dC3, ',');
    getline(sdata, dp, ',');
    DegreeProgram _dp;
    if (dp.compare("NETWORK") == 0)
        _dp = NETWORK;
    if (dp.compare("SECURITY") == 0)
        _dp = SECURITY;
    if (dp.compare("SOFTWARE") == 0)
        _dp = SOFTWARE;
    add(id, fname, lname, email, stoi(age), stoi(dC1), stoi(dC2), stoi(dC3), _dp);
}

void Roster::add(string id, string firstname, string lastname, string emailaddress, 
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dp) {

    classRosterArray[numStudents] = new Student(id, firstname, lastname, emailaddress, age, 
                                        daysInCourse1, daysInCourse2, daysInCourse3, dp);
    numStudents++;
};

void Roster::printAll() {
//    Student::printTitle();
    for (int i = 0; i < numStudents; i++) {
        cout << classRosterArray[i]->GetID() << '\t';
        cout << "First Name: " << classRosterArray[i]->GetFirstName() << '\t';
        cout << "Last Name: " << classRosterArray[i]->GetLastName() << '\t';
        cout << "Age: " << classRosterArray[i]->GetStudentAge() << '\t';
        cout << "daysInCourse: {" << classRosterArray[i]->GetDaysInCourse1() << ", ";
        cout << classRosterArray[i]->GetDaysInCourse2() << ", ";
        cout << classRosterArray[i]->GetDaysInCourse3() << "} ";
        cout << "Degree Program: ";
        DegreeProgram dp = classRosterArray[i]->GetDegree();
        cout << degreeProgramStrings[dp] << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram dp) {
    Student::printTitle();
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->GetDegree() == dp) {
            classRosterArray[i]->print();
        }
        cout << endl;
    }
}

void Roster::printInvalidEmails() {
    regex emailpattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    for (int i = 0; i < numStudents; i++) {
        string emailaddress;
        emailaddress = classRosterArray[i]->GetEmailAddress();
        if (!regex_match(emailaddress, emailpattern)) {
            cout << emailaddress << ": " << classRosterArray[i]->GetID() << endl;
        }
    }
}

// This worked for outputting all students, but didn't use studentID as parameter
/*void Roster::printAverageDaysInCourse() {
    int sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += classRosterArray[i]->GetDaysInCourse1();
        sum += classRosterArray[i]->GetDaysInCourse2();
        sum += classRosterArray[i]->GetDaysInCourse3();
        cout << classRosterArray[i]->GetID() << ": " << sum / 3 << endl;
        sum = 0;
    }
    cout << endl;
};*/

void Roster::printAverageDaysInCourse(string id) {
    int sum = 0;
    for (int i = 0; i < numStudents; i++)
    {
        if (classRosterArray[i]->GetID() == id)
        {
            sum += classRosterArray[i]->GetDaysInCourse1();
            sum += classRosterArray[i]->GetDaysInCourse2();
            sum += classRosterArray[i]->GetDaysInCourse3();
            cout << classRosterArray[i]->GetID() << ": " << sum / 3.0 << endl << endl;
        }
    }
};

void Roster::remove(string id) {
    int i, j, found = 0;
    for (i = 0; i < numStudents; i++) {
        string _id = classRosterArray[i]->GetID();
        if (_id.compare(id) == 0) {
            found = 1;
            delete(classRosterArray[i]);
            for (j = i; j < numStudents-1; j++) {
                classRosterArray[j] = classRosterArray[j+1];
            }
            numStudents--;
            classRosterArray[numStudents] = nullptr;
            cout << id << " removed from roster." << endl << endl;
            break;
        }
    }
    if (found == 0)
        cout << id << " was not found and may have been removed." << endl << endl;
}
