#pragma once
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster {
public:
	Roster();
	~Roster();

	void parse(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void printAll();	
	void printInvalidEmail();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreePogram);
	void remove(string studentID);
	static const int numStudents{ 5 };
	Student* classRosterArray[numStudents];
	


private:
	Student student;
	int arrIndex = -1;
	DegreeProgram degreeProgram;
};