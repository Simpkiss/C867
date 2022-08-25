#pragma once
#include <iostream>
#include"degree.h"
using namespace std;

class Student
{

protected:

	const static int classes = 3;
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[classes];
	DegreeProgram degree;

public:

	// Constructors
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degree);
	
	// Destructor
	~Student();

	// Setters
	void setID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int days[]);
	void setDegree(DegreeProgram degree);

	// Getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegree();

	void print();
};
