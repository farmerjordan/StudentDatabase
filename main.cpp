#include <iostream>

using namespace std;

//#include "Student.h"

main()
{
	BST myStudentTree;
	BST myFacultyTree;
	bool analysis = true;
	while (analysis)
	{
		cout<<"Menu - please type a number"<<endl;
		cout<<"1 -- print all students and their info"<<endl;
		cout<<"2 -- print all faculty and their info"<<endl;
		cout<<"3 -- print student information from a provided ID"<<endl;
		cout<<"4 -- print faculty information from a provided ID"<<endl;
		cout<<"5 -- print name and info of advisor from provided student ID"<<endl;
		cout<<"6 -- print all advisee information given advisor ID"<<endl;
		cout<<"7 -- add a student"<<endl;
		cout<<"8 -- delete a student from a given ID#"<<endl;
		cout<<"9 -- add a faculty member"<<endl;
		cout<<"10 -- delete a faculty member from a given ID#"<<endl;
		cout<<"11 -- change a students advisor given student ID# and new advisor ID#">>endl;
		cout<<"12 -- remove an advisee from a faculty member from student and faculty ID#'s"<<endl;
		cout<<"13 -- undo last action"<<endl;
		cout<<"14 -- exit program"<<endl;
		int userSelection;
		cin >> userSelection;
		if (userSelection == 1)
		{
			myStudentTree.printInOrder(/*it says that we have to pass in a node? im not sure how to do that*/)
		}
		if (userSelection == 2)
		{
			myFacultyTree.printInOrder(/*it says that we have to pass in a node? im not sure how to do that*/)
		}
		if (userSelection == 3)
		{
			cout<<"what is the ID of the student whose information you would like to retrieve"
			int ID;
			cin >> ID;
			Student thisStudent = myStudentTree.search(ID);
			thisStudent.PrintStudentInfo();//im not 100% sure im calling this right
		}
		if (userSelection == 4)
		{
			cout<<"what is the ID of the faculty whose information you would like to retrieve"
			int ID;
			cin >> ID;
			Faculty thisFaculty = myFacultyTree.search(ID);
			thisFaculty.PrintFacultyInfo();//im not 100% sure im calling this right
		}
		if (userSelection == 5)
		{
			cout<<"what is the ID of the student whose advisor information you would like to retrieve"
			int ID;
			cin >> studentID;
			Student thisStudent = myStudentTree.search(studentID);
			int advisorID = thisStudent.getAdvisorID();
			Faculty thisFaculty = myFacultyTree.search(advisorID);
			thisFaculty.PrintFacultyInfo();//im not 100% sure im calling this right
		}
		if (userSelection == 6)
		{
			//print advisees
		}
		if (userSelection == 7)
		{
			//get input info
			cout<<"you have selected to create a student, please enter their information when prompted."<<endl;
			cout<<"Student ID# : "<<endl;
			int thisStudentID;
			cin >> thisStudentID;
			cout<< "/n"<<"Student Name : "<<endl;
			string thisStudentName;
			cin >> thisStudentName;
			cout<< "/n"<<"Student year/standing : "<<endl;
			string thisGrade;
			cin >> thisGrade;
			cout<< "/n"<<"Student Major : "<<endl;
			string thisMajor;
			cin >> thisMajor;
			cout<< "/n"<<"Student GPA : "<<endl;
			Int thisGPA;
			cin >> thisGPA;
			cout<< "/n"<<"Students advisor ID (if unknown enter -1) : "<<endl;
			string thisAdvisorID;
			cin >> thisAdvisorID;
			
			//create a student from the info
			new Student thisStudent;
			thisStudent =  Student(int thisStudentID, string thisName, string thisGrade, string thisMajor, double thisGPA, int thisAdvisorID)
			
			//add student to myStudentTree
			myStudentTree.insert(thisStudent);
			
			Faculty thisFaculty = myFacultyTree.search(thisAdvisorID);
			
			//still need to add this student to this advisors list of students
			
		}
		if (userSelection == 8)
		{
			//delete a student given the ID
			
			cout<<"What is the ID of the student you would like to delete : "<<endl;
			string thisStudentID;
			cin >> thisStudentID;
			myStudentTree.deleteNode(thisStudentID);
		}
		if (userSelection == 9)
		{
			//still working on this but gotta go do stuff with my fam
			
			//get input info
			cout<<"you have selected to create a faculty, please enter their information when prompted."<<endl;
			cout<<"Faculty ID# : "<<endl;
			int thisFacultyID;
			cin >> thisFacultyID;
			cout<< "/n"<<"FacultyName : "<<endl;
			string thisFacultyName;
			cin >> thisFacultyName;
			cout<< "/n"<<"Faculty Position : "<<endl;
			string thisFacultyPosition;
			cin >> thisFacultyPosition;
			cout<< "/n"<<"Faculty Department : "<<endl;
			string thisDepartment;
			cin >> thisDepartment;
			cout << "does this advisor have any advisees? y or n"<<endl;
			bool moreAdvisees = true;
			if (moreAdvisees)
			{
				cout<< "/n"<<"Student GPA : "<<endl;
				Int thisGPA;
				cin >> thisGPA;
				cout<< "/n"<<"Students advisor ID 
				
			(if unknown enter -1) : "<<endl;
			string thisAdvisorID;
			cin >> thisAdvisorID;
			
			//create a student from the info
			new Student thisStudent;
			thisStudent =  Student(int thisStudentID, string thisName, string thisGrade, string thisMajor, double thisGPA, int thisAdvisorID)
			
			//add student to myStudentTree
			myStudentTree.insert(thisStudent);
			
			Faculty thisFaculty = myFacultyTree.search(thisAdvisorID);
			
			//still need to add this student to this advisors list of students
			
			//
		}
		if (userSelection == 10)
		{
			//
		}
		if (userSelection == 11)
		{
			//
		}
		if (userSelection == 12)
		{
			//
		}
		if (userSelection == 13)
		{
			//
		}
		if (userSelection == 14)
		{
			break;
		}
	}
	//right here we have to figure out how to write to the disk
}
