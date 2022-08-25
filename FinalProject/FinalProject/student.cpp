#pragma once
#include <iostream>
#include <string>
#include "student.h"

using namespace std;


// Constructors
Student::Student() {
	return;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < classes; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degree = degree;
}



// Destructor
Student::~Student() {
	return;
}

// Setters
void Student::setID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
		this->lastName = lastName;
	}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysToComplete(int days[]) {
	for (int i = 0; i < classes; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}
void Student::setDegree(DegreeProgram degree) {
	this->degree = degree;
}

// Getters
string Student::getID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return email;
}
int Student::getAge() {
	return age;
}
int* Student::getDaysToComplete() {
	return daysToComplete;
}
DegreeProgram Student::getDegree() {
	return degree;
}

void Student::print() {
	cout << getID() << '\t';
	cout << "First Name: " << getFirstName() << '\t';
	cout << "Last Name: " << getLastName() << '\t';
	/*cout << "Email: " << getEmail() << '\t';*/
	cout << "Age: " << getAge() << '\t';
	cout << "Days/Course: {";
	for (int i = 0; i < classes; ++i) {
		cout << getDaysToComplete()[i];
		if (i < classes - 1) {
			cout << ", ";
		}
	}
	cout << "}" << '\t';
	cout << "Degree Program: " << degreeProgramStrings[getDegree()] << endl;

}