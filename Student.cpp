#include <iostream>

using namespace std;

#include "Student.h"


Student::Student(){
	studentID = 0;
	studentName = "";
	studentGrade = "";
	studentMajor = "";
	studentGPA = 0.0;
	advisorID = 0;
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

Student::~Student()
{

}

//Boolean overloaded operators

bool Student::operator==(const Student& student)
{
	return(this->studentID == student.studentID);
}
bool Student::operator!=(const Student& student)
{
	return(this->studentID != student.studentID);
}
bool Student::operator>(const Student& student)
{
	return(this->studentID > student.studentID);
}
bool Student::operator<(const Student& student)
{
	return(this->studentID < student.studentID);
}

std::ostream& operator<< (std::ostream& out, const Student& student)
{
		out << "ID: " << student.studentID << "\n" << "Name: " << student.studentName << "\n" << "Grade: " << student.studentGrade << "\n" << "Major: " << student.studentMajor << "\n" << "GPA: " << student.studentGPA << "\n" << "Advisor: " << student.advisorID << "\n" << " " << endl;
    return out;
}
std::ostream& operator >> (std::ostream& out, const Student& student)
{
		out << student.studentID << "\n"  << student.studentName << "\n" << student.studentGrade << "\n" << student.studentMajor << "\n" << student.studentGPA << "\n" << student.advisorID << endl;
    return out;
}

//Number 3 - Find and display student information given the students ID
void Student::PrintStudentInfo() //I think we might need to call get methods here, but I am not sure until we try to run the whole program
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

void Student::SetStudentID(int thisStudentID)
{
	studentID = thisStudentID;
}

//Number 5 - Given a student's ID, print the name and info of their faculty advisor
void Student::GetStudentAdvisorInfo(int thisStudentID)
{
	//Return all info about that specific faculty
}

int Student::GetAdvisorID()
{
	return advisorID;
}

void Student::UpdateAdvisorID(int thisAdvisorID)
{
	advisorID = thisAdvisorID;
	//Update the node in the tree, must also update in faculty tree to remove student from one advisor and move to another
}
