#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->studentAge = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
	for (int i = 0; i < numDaysEntered; ++i) this->numDaysToComplete[i] = 0;
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, const int numDaysToComplete[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	for (int i = 0; i < numDaysEntered; ++i) this->numDaysToComplete[i] = numDaysToComplete[i];
	this->degreeProgram = degreeProgram;
}
Student::~Student() {

}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

string Student::getStudentId() {
	return studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

string Student::getFirstName() {
	return firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

string Student::getLastName() {
	return lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

string Student::getEmailAddress() {
	return emailAddress;
}

void Student::setStudentAge(int studentAge) {
	this->studentAge = studentAge;
}

int Student::getStudentAge() {
	return studentAge;
}

void Student::setNumDaysToComplete(int numDaysToComplete[]) {
	for (int i = 0; i < numDaysEntered; ++i) {
		this->numDaysToComplete[i] = numDaysToComplete[i];
	}
}

int* Student::getNumDaysToComplete() {
	return this->numDaysToComplete;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

void Student::print() { 
	degreeProgram = getDegreeProgram();

	cout << this->getStudentId() << "\t"
		<< this->getFirstName() << "\t"
		<< this->getLastName() << "\t"
		<< this->getStudentAge() << "\t" << "{"
		<< this->numDaysToComplete[0] << ","
		<< this->numDaysToComplete[1] << ","
		<< this->numDaysToComplete[2] << "}\t";
	
	if (degreeProgram == DegreeProgram::SECURITY) {
		cout << "SECURITY" << endl;
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		cout << "NETWORK" << endl;
	}
	else if (degreeProgram == DegreeProgram::SOFTWARE) {
		cout << "SOfTWARE" << endl;
	}
}
