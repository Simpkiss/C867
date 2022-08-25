#pragma once
#include "student.h"

class Roster {

public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* studentRosterArray[numStudents];

public:

	void parse(string row);
	void add(string ID, string firstName, string lastName, string email, int age, int dayCount1, int dayCount2, int dayCount3, DegreeProgram degree);
	void printAll();
	void printByDegreeProgram(DegreeProgram degree);
	void printInvalidEmails();
	void printAverageDaysInCourse(string ID); // Function modified to print by ID
	void remove(string ID);
	~Roster();

};