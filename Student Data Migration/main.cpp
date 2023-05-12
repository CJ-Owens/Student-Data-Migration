#include <iostream>
#include "roster.h"


using namespace std;

int main() {
	//Title, language, Id, Name
	cout << "C867 Scripting and Programming Applicaitons" << endl
		<< "C++" << endl
		<< "Student ID 010682412" << endl
		<< "Christopher Owens" << endl;

	Roster classRoster;
	const int numStudents{ 5 };

	//Student information
	const string studentData[]{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,CJ,Owens,cowe301@wgu.edu,33,8,3,24,SOFTWARE" 
	};
	cout << endl;
	//Parse each element in studentData array, store as pointers
	
	
	for (int i = 0; i < numStudents; ++i) {
		classRoster.parse(studentData[i]);
	}

	cout << "All Students :" << endl;;
	classRoster.printAll();

	
	cout << "Invalid Emails:" << endl;
	classRoster.printInvalidEmail();


	cout << "Average Days In Course: " << endl;
	for (int i = 0; i < numStudents; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
	}
	cout << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << "Removing A3:" << endl;
	classRoster.remove("A3");

	cout << endl;
	cout << "All Students: " << endl;
	classRoster.printAll();

	cout << endl << "Removing A3 Again:" << endl;
	classRoster.remove("A3");
	cout << endl;

	return 0;
}
