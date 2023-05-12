#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

Roster::Roster() {
	for (int i = 0; i < numStudents; ++i) this->classRosterArray[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;

}

//Parse string of student data and call add function that sets each object to index of roster array
void Roster::parse(string studentData) {

	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, (rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, (rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, (rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, (rhs - lhs)));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, (rhs - lhs)));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, (rhs - lhs)));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, (rhs - lhs)));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string strDegreeProgram = studentData.substr(lhs, (rhs - lhs));
	
	if (strDegreeProgram == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
	}
	else if (strDegreeProgram == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
	}
	else if (strDegreeProgram == "SOFTWARE") {
			degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

//Sets index of roster array as objects for each student
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int arrDaysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	
	++arrIndex;
	classRosterArray[arrIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arrDaysInCourse, degreeProgram);

	classRosterArray[arrIndex]->setStudentID(studentID);
	classRosterArray[arrIndex]->setFirstName(firstName);
	classRosterArray[arrIndex]->setLastName(lastName);
	classRosterArray[arrIndex]->setEmailAddress(emailAddress);
	classRosterArray[arrIndex]->setStudentAge(age);
	classRosterArray[arrIndex]->setNumDaysToComplete(arrDaysInCourse);
	classRosterArray[arrIndex]->setDegreeProgram(degreeProgram);

};

//Print all info from accessors for each element in array
void Roster::printAll() {
	

	for (int i = 0; i <= arrIndex; ++i) {
		classRosterArray[i]->print();
	}
	cout << endl;
}

//Determine what emails contain valid domain
void Roster::printInvalidEmail() { 
	
	for (int i = 0; i <= arrIndex; ++i) {
		string studentEmail = classRosterArray[i]->getEmailAddress();

		if (studentEmail.find('@') == string::npos || studentEmail.find('.') == string::npos || studentEmail.find(' ') != string::npos) {
			cout << studentEmail << " - is invalid." << endl;
		}
	}
	cout << endl;
}

//Print average days in course by student ID from array
void Roster::printAverageDaysInCourse(string studentID) {
	int avgDays{ 0 };

	for (int i = 0; i <= arrIndex; ++i) {
		if (classRosterArray[i]->getStudentId() == studentID) {
			avgDays = (classRosterArray[i]->getNumDaysToComplete()[0] + classRosterArray[i]->getNumDaysToComplete()[1] + classRosterArray[i]->getNumDaysToComplete()[2]) / 3;
			cout << "Student ID: " << studentID << ", avergade days in course is: " << avgDays << endl;
			
		}
	}
}

//Print roster elements containing certain enumerated data type 
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	cout << "Students In Program: ";
	if (degreeProgram == DegreeProgram::SECURITY) {
		cout << "SECURITY" << endl;
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		cout << "NETWORK" << endl;
	}
	else if (degreeProgram == DegreeProgram::SOFTWARE) {
		cout << "SOfTWARE" << endl;
	}
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print(); 
		}
	}
	cout << endl;
}


void Roster::remove(string studentID) {

	if (classRosterArray[numStudents - 1]->getStudentId() != studentID) {
		for (int i = 0; i <= arrIndex; ++i) { 
			if (classRosterArray[i]->getStudentId() == studentID) {

				if (i < numStudents - 1) {
					Student* tempVal1 = classRosterArray[i];
					Student* tempVal2 = classRosterArray[i + 1];
					classRosterArray[i] = tempVal2;
					classRosterArray[i + 1] = tempVal1;
				}
				
			}
						
		}
		--arrIndex;
	}
	else {
		cout << endl << "Student with the ID " << studentID << " was not found.";
	}
}

//Destructor
Roster::~Roster() {
	for (int i = 0; i < numStudents; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}




