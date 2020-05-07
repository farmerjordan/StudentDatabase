#include <iostream>

using namespace std;

//student functionality
//constructor
#include "Student.h"
Student::Student(int ID, string name, string grade, int advisor)
{
	studentID = ID;
	studentName = name;
	studentStanding = grade;
	studentAdvisorID = advisor;
}
Student::Student(char compare)
{
// this is supposed to take in >, < or =
}
void Student::Print()
{
	cout<<"Student # : "<<studentID<<endl;
	cout<<"Name : " <<studentName<<endl;
	cout<<"Standing : " <<studentStanding<<endl;
	cout<<"Advisor ID : " <<studentAdvisorID<<endl<<endl;//to seperate the students when we print them
}
int Student::GetStudentID()
{
	return studentID;
}
int Student::GetStudentAdvisorID()
{
	return studentAdvisorID;
}
void Student::UpdateAdvisorID(int ID)
{
	studentAdvisorID = ID;
}
