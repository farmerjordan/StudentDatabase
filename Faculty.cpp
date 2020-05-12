#include <iostream>

using namespace std;

#include "Faculty.h"
#include "DoublyLinkedList.h"

Faculty::Faculty()
{
	facultyID = 0;
	facultyName = "";
	facultyPosition = "";
	facultyDepartment = "";
	advisees = new DoublyLinkedList<int>();
}

Faculty::~Faculty()
{

}

Faculty::Faculty(int thisFacultyID, string thisName, string thisPosition, string thisDepartment)
{
	facultyID = thisFacultyID;
	facultyName = thisName;
	facultyPosition = thisPosition;
	facultyDepartment = thisDepartment;
	advisees = new DoublyLinkedList<int>();
}

bool Faculty::operator==(const Faculty& faculty)
{
	return(this->facultyID == faculty.facultyID);
}
bool Faculty::operator!=(const Faculty& faculty)
{
	return(this->facultyID != faculty.facultyID);
}
bool Faculty::operator>(const Faculty& faculty)
{
	return(this->facultyID > faculty.facultyID);
}
bool Faculty::operator<(const Faculty& faculty)
{
	return(this->facultyID < faculty.facultyID);
}

std::ostream& operator<< (std::ostream& out, const Faculty& faculty)
{
		out << "ID: " << faculty.facultyID << "\n" << "Name: " << faculty.facultyName << "\n" << "Position: " << faculty.facultyPosition << "\n" << "Department: " << faculty.facultyDepartment << "\n" << " " << endl;
    return out;
}


//Number 4 - Find and display faculty information given the faculty ID
void Faculty::PrintFacultyInfo()
{
	cout << "Faculty ID : " << facultyID << endl;
	cout << "Name : " << facultyName << endl;
	cout << "Position : " << facultyPosition << endl;
	cout << "Department : " << facultyDepartment << endl;
	cout << "Advisees : " << endl;
	/*for advisees in advisee list print 4 spaces then print all of their info <<endl;
	print a new line*/
	//to put space between them when were listing them
}
int Faculty::GetFacultyID()
{
	return facultyID;
}

void Faculty::SetFacultyID(int thisFacultyID)
{
	facultyID = thisFacultyID;
}

//Number 6 - Given a faculty ID, print ALL the names and info of their advisees
int Faculty::GetAdvisees(int thisFacultyID)
{
	//return adviseelist;
}

void Faculty::AddAdvisee(int adviseeID)
{
	advisees->insertFront(adviseeID);
}

void Faculty::RemoveAdvisee(int thisFacultyID, int thisStudentID)
{
	//i think we also need to randomly assign the student we remove to a new advisee, or prompt user to enter a new advisee ID
	//gotta take them out of the linked list or tree
}
