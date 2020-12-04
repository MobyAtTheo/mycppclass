#include <iostream>
#include "Student.h"
#include "Roster.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    cout << " Scripting and Programming | C++ " << endl;
    cout << " - Andrew Silkroski " << endl << endl << endl;

    const string studentData[] =
    {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Andrew,Silkroski,andrewsemail@gmail.om,34,30,51,28,SOFTWARE",
    };
    int sizeSD = sizeof(studentData)/sizeof(studentData[0]);

    Roster roster;

    for (int i = 0; i < sizeSD; i++) 
        roster.parse(studentData[i]);

    cout << "Listing all students: " << endl;
    roster.printAll();
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Listing students by degree program: " << degreeProgramStrings[i] << endl;
        // Turn number corresponding to enum DegreeProgram to actual string
        roster.printByDegreeProgram((DegreeProgram)i);
    }

    cout << "Listing students with invalid email addresses" << endl;
    roster.printInvalidEmails();
    cout << endl;

    cout << "Providing average days per course by ID: " << endl;
    for (int i = 0; i < 5; i++)
    {
        string id = roster.classRosterArray[i]->GetID();
        roster.printAverageDaysInCourse(id);
    }

    cout << "Removing student with ID A3" << endl;
    roster.remove("A3"); // Expect to execute
    cout << endl;

    cout << "Removing student with ID A3" << endl;
    roster.remove("A3"); // Expect to return error for not found
    cout << endl;

    system("pause");
    return 0;
}
