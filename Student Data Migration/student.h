#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student
{
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, const int numDaysToComplete[], DegreeProgram degreeProgram);
	~Student();

	void setStudentID(string studentID);
	string getStudentId();

	void setFirstName(string firstName);
	string getFirstName();

	void setLastName(string lastName);
	string getLastName();

	void setEmailAddress(string emailAddress);
	string getEmailAddress();

	void setStudentAge(int studentAge);
	int getStudentAge();

	void setDegreeProgram(DegreeProgram degreeProgram);
	DegreeProgram getDegreeProgram();

	void setNumDaysToComplete(int numDaysToComplete[]);
	int* getNumDaysToComplete();

	void print();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	DegreeProgram degreeProgram;
	const static int numDaysEntered{ 3 };
	int numDaysToComplete[numDaysEntered];

};
