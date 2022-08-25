#include "roster.h"
#include <iostream>
using namespace std;

void Roster::parse(string studentData) {

	int rhs = studentData.find(","); // Finds first comma
	string ID = studentData.substr(0, rhs);

	int lhs = rhs + 1; // Indexes lhs to after first comma
	rhs = studentData.find(",", lhs); // finds next comma
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string email = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dayCount1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dayCount2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dayCount3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	DegreeProgram degree = SECURITY;
	if (studentData.substr(lhs) == "SECURITY") {
		degree = SECURITY;
	}
	else if (studentData.substr(lhs) == "NETWORK") {
		degree = NETWORK;
	}
	else {
		degree = SOFTWARE;
	}

	add(ID, firstName, lastName, email, age, dayCount1, dayCount2, dayCount3, degree);

  }

void Roster::add(string ID, string firstName, string lastName, string email, int age, int dayCount1, int dayCount2, int dayCount3, DegreeProgram degree) {
	int dayArray[3] = { dayCount1, dayCount2, dayCount3 };
	studentRosterArray[++lastIndex] = new Student(ID, firstName, lastName, email, age, dayArray, degree);
}

void Roster::printAll() {
	cout << "Displaying all students:" << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		studentRosterArray[i]->print();
	}
	cout << '\n';
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
	cout << "Displaying " << degreeProgramStrings[degree] << " students:" << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (studentRosterArray[i]->getDegree() == degree) {
			studentRosterArray[i]->print();
		}
	}
	cout << endl;
}

void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << '\n' << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string email = studentRosterArray[i]->getEmail();
		//cout << email.size() << "@" << email.find("@") << "." << email.find(".") << " " << email.find(" ") << endl;
		if (email.find(" ") < email.size()) {
			cout << email << " - no spaces allowed." << endl;
		}
		else if (email.find(".") > email.size()) {
			cout << email << " - missing period." << endl;
		}
		else if (email.find("@") > email.size()) {
			cout << email << " - missing @ symbol." << endl;
		}
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string ID) { // Now has in ID to print
	// cout << "Displaying average days per course:" << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (studentRosterArray[i]->getID() == ID) { // Now looks for a matching ID
			cout << "Student ID: " << studentRosterArray[i]->getID() << ", averages ";
			cout << (studentRosterArray[i]->getDaysToComplete()[0]
				+ studentRosterArray[i]->getDaysToComplete()[1]
				+ studentRosterArray[i]->getDaysToComplete()[2]) / 3;
			cout << " days in a course." << endl;
		}
	}
	// cout << endl;
}
void Roster::remove(string ID) {
	cout << "Removing " << ID << ":" << endl;
	bool deleted = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (studentRosterArray[i]->getID() == ID) {
			deleted = true;
			if (i < numStudents - 1) {
				Student* temp = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[numStudents - 1];
				studentRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (deleted) {
		cout << ID << " removed from roster." << endl << endl;
	}
	else cout << ID << " not found in roster." << endl << endl;
}

Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}

}