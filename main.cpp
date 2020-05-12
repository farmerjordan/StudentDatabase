#include <iostream>

using namespace std;

//Do we need to include everything idk?
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "DoublyLinkedList.h"
#include "ListNode.h"
#include "TreeNode.h"

main()
{

	BST<Student> myStudentTree; //instance of BST to make a tree of students
	BST<Faculty> myFacultyTree; //instance of BST to make a tree of faculty
	bool analysis = true;
	while (analysis == true)
	{
		cout << "Menu - Please type the number of the function you would like to complete " << endl;
		cout << "1 -- Print all students and their info" << endl;
		cout << "2 -- Print all faculty and their info" << endl;
		cout << "3 -- Print student information from a provided ID" << endl;
		cout << "4 -- Print faculty information from a provided ID" << endl;
		cout << "5 -- Print name and info of advisor from provided student ID" << endl;
		cout << "6 -- Print information of all advisees from provided advisor ID" << endl;
		cout << "7 -- Add a student"<< endl;
		cout << "8 -- Delete a student given their ID" << endl;
		cout << "9 -- Add a faculty member" << endl;
		cout << "10 -- Delete a faculty member given their ID" << endl; //Either prompt for a new faculty member to assign advisees to or assign at random
		cout << "11 -- Change a students advisor given student ID and new advisor ID" << endl;
		cout << "12 -- Remove an advisee from a faculty member given student ID and faculty ID" << endl;
		cout << "13 -- Undo last action " << endl;
		cout << "14 -- Exit program" << endl; //And write to a file

		int userSelection;
		cin >> userSelection;

		if (userSelection == 1)
		{
			//myStudentTree.printInOrder(myStudentTree.root);
			//I commented this out for the moment because more errors were showing up and it was cluttering up the console
		}
		if (userSelection == 2)
		{
			//myFacultyTree.printInOrder(myFacultyTree.root);
			//I commented this out for the moment because more errors were showing up and it was cluttering up the console

		}
		if (userSelection == 3)
		{
			cout << "What is the ID of the student whose information you would like to retrieve?" << endl;
			int thisStudentID = 0;
			cin >> thisStudentID;

			Student dummy = Student();
			dummy.SetStudentID(thisStudentID);
			if(myStudentTree.search(dummy) == true)
			{
				myStudentTree.getNode(dummy)->data.PrintStudentInfo();
			}
		}
		if (userSelection == 4)
		{
			cout<<"What is the ID of the faculty whose information you would like to retrieve?" << endl;
			int thisFacultyID = 0;
			cin >> thisFacultyID;

			Faculty dummy = Faculty();
			dummy.SetFacultyID(thisFacultyID);
			if(myFacultyTree.search(dummy) == true)
			{
				myFacultyTree.getNode(dummy)->data.PrintFacultyInfo();
			}
		}
		if (userSelection == 5)
		{
			cout<< "What is the ID of the student whose advisor information you would like to retrieve?";
			int thisStudentID;
			cin >> thisStudentID;

			Student dummyStud = Student();
			dummyStud.SetStudentID(thisStudentID);
			if(myStudentTree.search(dummyStud) == true)
			{
				int thisAdvisorID = myStudentTree.getNode(dummyStud)->data.GetAdvisorID();
				Faculty dummyFac = Faculty();
				dummyFac.SetFacultyID(thisAdvisorID);
				if(myFacultyTree.search(dummyFac) == true)
				{
					myFacultyTree.getNode(dummyFac)->data.PrintFacultyInfo();
				}
			}else
			{
				cout << "This student does not have an advisor assigned. Please assign an advisor." << endl;
			}
		}
		if (userSelection == 6)
		{
			cout<< "What is the ID of the faculty whose advisees information you would like to retrieve?";
			int thisStudentID;
			cin >> thisStudentID;
			//get advisee IDs
			//while(adviseeCount != 0)
				//{
					//print
		}
		if (userSelection == 7) //Add error checking for if student ID already exists
		{
			//get input info
			cout << "You have selected to create a student, please enter their information when prompted." << endl;
			cout << "Student ID : " << endl;
			int thisStudentID;
			cin >> thisStudentID;
			cout << "/n" << "Student Name : " << endl;
			string thisStudentName;
			cin >> thisStudentName;
			cout << "/n" << "Student year/standing : " << endl;
			string thisGrade;
			cin >> thisGrade;
			cout << "/n" << "Student Major : " << endl;
			string thisMajor;
			cin >> thisMajor;
			cout << "/n" << "Student GPA : " << endl;
			double thisGPA;
			cin >> thisGPA;
			cout << "/n" << "Students advisor ID : " << endl;
			int thisAdvisorID;
			cin >> thisAdvisorID;

			//create a student from the info
			Student newStudent =  Student(thisStudentID, thisStudentName, thisGrade, thisMajor, thisGPA, thisAdvisorID);

			//add student to myStudentTree
			myStudentTree.insert(newStudent);


		  //Need to add the student to the list of ID's for the specified faculty advisor
			//Faculty thisFaculty = myFacultyTree.search(thisAdvisorID);



		}
		if (userSelection == 8) //Need to remove the student from a faculty list
		{
			//delete a student given the ID
			cout<<"Enter the ID of the student you would like to delete : "<<endl;
			string thisStudentID;
			cin >> thisStudentID;
			Student dummy = Student();
			dummy.SetStudentID(thisStudentID);
			if(myStudentTree.search(dummy) == true)
			{
				myStudentTree.deleteNode(dummy);
			}else
			{
				cout << "A student does not exist with that ID. " << endl;
			}
		}
		if (userSelection == 9) //Add a new faculty member.
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
			string thisFacultyDepartment;
			cin >> thisFacultyDepartment;
      /* I want to wait on this part just because this would require removing an advisee from another advisor and reassigning, we should do this last I think

	  // i don think we would have to remove advisees from other people but we may have to confirm that they dont belong to anyone else


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
			cin >> thisAdvisorID;*/

			//create a faculty from the info
			//new Faculty thisFaculty;
			//Faculty thisFaculty =  Faculty(thisFacultyID, thisFacultyName, thisFacultyPosition, thisFacultyDepartment /*, empty studentlist*/)

			//add faculty to myFacultyTree
			//myFacultyTree.insert(thisFaculty);

      //IDK what this line is for
			//Faculty thisFaculty = myFacultyTree.search(thisAdvisorID);


		}
		if (userSelection == 10)
		{
			cout<< "What is the ID of the faculty you would like deleted?";
			int thisFacultyID;
			cin >> thisFacultyID;

			Faculty dummy = Faculty();
			dummy.SetFacultyID(thisFacultyID);
			if(myFacultyTree.search(dummy) == true)
			{
				myFacultyTree.deleteNode(dummy);
			}else
			{
				cout << "A faculty does not exist with that ID. " << endl;
			}
		}
		if (userSelection == 11)
		{
			cout<< "What is the ID of the student whose advisor you would like to change?";
			int thisStudentID;
			cin >> thisStudentID;

			cout<< "What is the ID of their new advisor (faculty)?";
			int thisFacultyID;
			cin >> thisFacultyID;

		//	myStudentTree.UpdateAdvisorID(thisFacultyID);

			//also need to remove from list of advisees of old advisor and add to new advisor
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
			//Should write to the file here before we close the program entirely
			//break;
			exit(0);
		}
	}
	//right here we have to figure out how to write to the disk
}
