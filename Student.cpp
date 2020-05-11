#include <iostream>

using namespace std;

#include "Student.h"

//student functionality
//constructor

Student::Student(){
	studentID = 0;
	studentName = "";
	studentGrade = "";
	studentMajor = "";
	studentGPA = 0.0;
	advisorID = 0;
}

//Student::~Student(<) i cant tell if this needs to be a method
bool operator < (const Student& studentA, const Student& studentB)
{
	return(studentA.GetStudentID() < studentB.GetStudentID());
}
bool operator > (const Student& studentA, const Student& studentB)
{
	return(studentA.GetStudentID() > studentB.GetStudentID());
}
bool operator == (const Student& studentA, const Student& studentB)
{
	return(studentA.GetStudentID() == studentB.GetStudentID());
}



Student::Student(int thisStudentID, string thisName, string thisGrade, string thisMajor, double thisGPA, int thisAdvisorID)
{
	studentID = thisStudentID;
	studentName = thisName;
	studentGrade = thisGrade;
	studentMajor = thisMajor;
	studentGPA = thisGPA;
	advisorID = thisAdvisorID;
}

Student::Student(char compare, int thisStudentID1, int thisStudentID2)
{
// this is supposed to take in >, < or =
}

//Number 3 - Find and display student information given the students ID
void Student::PrintStudentInfo(int thisStudentID) //I think we might need to call get methods here, but I am not sure until we try to run the whole program
{
	cout << "Student ID : " << studentID << endl;
	cout << "Name : " << studentName << endl;
	cout << "Grade : " << studentGrade << endl;
	cout << "Major : " << studentMajor << endl;
	cout << "GPA : " << studentGPA << endl;
	cout << "Advisor ID : " << advisorID << endl;
	cout << " " << endl;
}

int Student::GetStudentID() //Not sure if this method is particularly needed
{
	return studentID;
}

//Number 5 - Given a student's ID, print the name and info of their faculty advisor
void Student::GetStudentAdvisorInfo(int thisStudentID)
{
	//Return all info about that specific faculty
}

void Student::UpdateAdvisorID(int thisAdvisorID)
{
	advisorID = thisAdvisorID;
	//Update the node in the tree, must also update in faculty tree to remove student from one advisor and move to another
}
