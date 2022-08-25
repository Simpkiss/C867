#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "roster.h"
#include "degree.h"

int main() {
	int x = 0;

	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001473307" << endl;
	cout << "Name: Aaron Simpkiss" << '\n' << endl;

	// Big string array imput to studentData
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Aaron,Simpkiss,asimpk4@wgu.edu,33,36,24,36,SOFTWARE"
	};
	const int numStudents = 5;
	Roster roster;

	// Parse
	for (int i = 0; i < numStudents; i++) {
		roster.parse(studentData[i]);
	}
	// Print all students
	roster.printAll();

	// Print invalid emails
	roster.printInvalidEmails();

	// Print average days // Tweaked to loop and print by ID
	cout << "Displaying average days per course:" << endl;
	for (int i = 0; i < numStudents; i++) {
		roster.printAverageDaysInCourse(roster.studentRosterArray[i]->getID());
	}
	cout << endl;

	// Print SOFTWARE students
	roster.printByDegreeProgram(SOFTWARE);

	// Remove A3
	roster.remove("A3");

	// Print all students again
	roster.printAll();

	// Remove A3 again
	roster.remove("A3");

	return 0;
}
// Self Destruct
