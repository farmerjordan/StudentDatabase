#include <iostream>

using namespace std;

//student functionality
//constructor
#include "Faculty.h"
Faculty::Faculty(int ID, str name, str position,str dept, alistsomehowofallofthestudents)
{
	facultyID = ID;
	facultyName = name;
	facultyPosition = position;
	facultyDepartment = dept;
	whatdowewantthestudentlisttolooklike?!;
}
Faculty::Faculty(char compare)
{
// this is supposed to take in >, < or =
}
void Faculty::Print()
{
	cout<<"Faculty # : "<<facultyID<<endl;
	cout<<"Name : " <<facultyName<<endl;
	cout<<"Position : " <<facultyPosition<<endl;
	cout<<"Department : " <<facultyDepartment<<endl;
	cout<<"Advisees : " <<endl;
	for advisees in advisee list print 4 spaces then print ID# <<endl;
	print a new line
	//to put space between them when were listing them
}
int Faculty::GetFacultyID()
{
	return facultyID;
}
int Faculty::GetAdviseeID()
{
	//return adviseelist;
}
void Faculty::RemoveAdvisee(int ID)
{
	//gotta take them out of the linked list or tree
}
