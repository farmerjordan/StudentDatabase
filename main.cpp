#include <iostream>
#include <fstream>

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

	string StudentFile;
	string FacultyFile;
	//open the files we want to read and call methods to read them
	ifstream studentFile;
	studentFile.open("studentTable.txt");
	if (studentFile)
	{
		string currString;
		//studentReadIn(studentFile);
		int linecount = 0;
		int tempID;
		string tempName;
		string tempGrade;
		string tempMajor;
		double tempGPA;
		int tempAdvisorID;
		while(getline(studentFile, currString))
		{
			linecount +=1;
			if (linecount == 1)
			{
				tempID = stoi(currString);
			}
			if (linecount == 2)
			{
				tempName = currString;
			}
			if (linecount == 3)
			{
				tempGrade = currString;
			}
			if (linecount == 4)
			{
				tempMajor = currString;
			}
			if (linecount == 5)
			{
				tempGPA = stoi(currString);
			}
			if (linecount == 6)
			{
				tempAdvisorID = stoi(currString);

				Student thisStudent = Student(tempID, tempName, tempGrade, tempMajor, tempGPA, tempAdvisorID);
				myStudentTree.insert(thisStudent);
				linecount = 0;
			}
		}
	}
	ifstream facultyFile;
	facultyFile.open("facultyTable.txt");
	if (facultyFile)
	{
		//facultyReadIn(studentFile);
		string currString;
		int linecount = 1;
		int tempID = 0;
		string tempName = NULL;
		string tempPosition = NULL;
		string tempDepartment = NULL;
		DoublyLinkedList<int> tempAdvisees;
		Faculty thisFaculty;

		while(getline(facultyFile, currString))
		{

			if (linecount == 1)
			{
				linecount +=1;
				tempID = stoi(currString);
			}
			if (linecount == 2)
			{
				linecount +=1;
				tempName = currString;
			}
			if (linecount == 3)
			{
				linecount +=1;
				tempPosition = currString;
			}
			if (linecount == 4)
			{
				linecount +=1;
				tempDepartment = currString;
				Faculty thisFaculty = Faculty(tempID, tempName, tempPosition, tempDepartment);
			}
			if (linecount == 5)
			{
				if (currString == "---")
				{
					linecount =1;
					myFacultyTree.insert(thisFaculty);
				}
				else
				{
					thisFaculty.AddAdvisee(stoi(currString));
				}
			}
		}
	}
	if( remove( "facultyTable.txt" ) != 0 )
	{}
	if( remove( "studentTable.txt" != 0 )
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
			myStudentTree.printTree(myStudentTree.root);
			//I commented this out for the moment because more errors were showing up and it was cluttering up the console
		}
		if (userSelection == 2)
		{
			myFacultyTree.printTree(myFacultyTree.root);
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
			int thisFacultyID;
			cin >> thisFacultyID;

			Faculty dummy = Faculty();
			dummy.SetFacultyID(thisFacultyID);
			if(myFacultyTree.search(dummy) == true)
			{
				DoublyLinkedList<int>* tempAdvisees = myFacultyTree.getNode(dummy)->data.advisees;

				ListNode<int> *temp = tempAdvisees->front;

				while(temp != NULL)
				{

					Student studDummy = Student();
					studDummy.SetStudentID(temp->data);
					if(myStudentTree.search(studDummy) == true)
					{
						myStudentTree.getNode(studDummy)->data.PrintStudentInfo();
					}
					temp = temp->next;
				}
			}

		}
		if (userSelection == 7) //Add error checking for if student ID already exists
		{
			//get input info
			cout << "You have selected to create a student, please enter their information when prompted." << endl;
			cout << "Student ID : " << endl;
			int thisStudentID;
			cin >> thisStudentID;
			cout << "\n" << "Student Name : " << endl;
			string thisStudentName;
			cin >> thisStudentName;
			cout << "\n" << "Student year/standing : " << endl;
			string thisGrade;
			cin >> thisGrade;
			cout << "\n" << "Student Major : " << endl;
			string thisMajor;
			cin >> thisMajor;
			cout << "\n" << "Student GPA : " << endl;
			double thisGPA;
			cin >> thisGPA;
			cout << "\n" << "Students advisor ID : " << endl;
			int thisAdvisorID;
			cin >> thisAdvisorID;

			//create a student from the info
			Student newStudent =  Student(thisStudentID, thisStudentName, thisGrade, thisMajor, thisGPA, thisAdvisorID);

			//add student to myStudentTree
			myStudentTree.insert(newStudent);

			Faculty dummy = Faculty();
			dummy.SetFacultyID(thisAdvisorID);
			if(myFacultyTree.search(dummy) == true)
			{
				myFacultyTree.getNode(dummy)->data.AddAdvisee(thisStudentID);
			}

		}
		if (userSelection == 8) //Need to remove the student from a faculty list
		{
			//delete a student given the ID
			cout<<"Enter the ID of the student you would like to delete : "<<endl;
			int thisStudentID;
			cin >> thisStudentID;
			Student dummy = Student();
			dummy.SetStudentID(thisStudentID);
			if(myStudentTree.search(dummy) == true)
			{
				int tempFacID = myStudentTree.getNode(dummy)->data.GetAdvisorID();
				myStudentTree.deleteNode(dummy);

				Faculty dummyFac = Faculty();
				dummyFac.SetFacultyID(tempFacID);
				if(myFacultyTree.search(dummyFac) == true)
				{
					myFacultyTree.getNode(dummyFac)->data.RemoveAdvisee(thisStudentID);
				}

			}else
			{
				cout << "A student does not exist with that ID. " << endl;
			}


		}
		if (userSelection == 9) //Add a new faculty member.
		{
			//still working on this but gotta go do stuff with my fam

			//get input info
			cout << "You have selected to create a new faculty member, please enter their information when prompted." << endl;
			cout << "Faculty ID : " << endl;
			int thisFacultyID;
			cin >> thisFacultyID;
			cout << "\n" << "FacultyName : " << endl;
			string thisFacultyName;
			cin >> thisFacultyName;
			cout << "\n" << "Faculty Position : " << endl;
			string thisFacultyPosition;
			cin >> thisFacultyPosition;
			cout << "\n"<<"Faculty Department : " << endl;
			string thisFacultyDepartment;
			cin >> thisFacultyDepartment;

			Faculty newFaculty = Faculty(thisFacultyID, thisFacultyName, thisFacultyPosition, thisFacultyDepartment);

			cout << "Does this advisor have any advisees? Enter 'y' or 'n' "<< endl;
			string anyAdvisees;
			cin >> anyAdvisees;
			bool moreAdvisees;
			string choice = "n";
			if(anyAdvisees == "y" || anyAdvisees == "Y")
			{
					moreAdvisees = true;
			}else
			{
				moreAdvisees = false;
			}
			while(moreAdvisees == true)
			{
				cout<< "\n"<< "Enter the students ID: " << endl;
				int thisStudentID;
				cin >> thisStudentID;

				newFaculty.AddAdvisee(thisStudentID);

				cout << "Does the faculty have more advisees? Enter 'y' or 'n' " << endl;
				cin >> choice;

				if(choice == "n" || choice == "N")
				{
					moreAdvisees = false;
				}
			}

			myFacultyTree.insert(newFaculty);
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

			Student dummy = Student();
			dummy.SetStudentID(thisStudentID);
			if(myStudentTree.search(dummy) == true)
			{
				int oldAdviseeID = myStudentTree.getNode(dummy)->data.GetAdvisorID();
				myStudentTree.getNode(dummy)->data.UpdateAdvisorID(thisFacultyID);

				//Removing student from old advisee
				Faculty dummyFac = Faculty();
				dummyFac.SetFacultyID(oldAdviseeID);
				if(myFacultyTree.search(dummyFac) == true)
				{
					myFacultyTree.getNode(dummyFac)->data.RemoveAdvisee(thisStudentID);
				}

				//Adding student to new advisee
				Faculty newDummyFac = Faculty();
				newDummyFac.SetFacultyID(thisFacultyID);
				if(myFacultyTree.search(newDummyFac) == true)
				{
					myFacultyTree.getNode(newDummyFac)->data.AddAdvisee(thisStudentID);
				}

			}


		//	myStudentTree.UpdateAdvisorID(thisFacultyID);

			//also need to remove from list of advisees of old advisor and add to new advisor
		}
		if (userSelection == 12)
		{
			cout << "What is the ID of the advisor (faculty) that you would like to remove a student from?" << endl;
			int thisFacultyID;
			cin >> thisFacultyID;

			cout << "What is the ID of the student you would like to remove?" << endl;
			int thisStudentID;
			cin >> thisStudentID;

			Faculty dummy = Faculty();
			dummy.SetFacultyID(thisFacultyID);
			if(myFacultyTree.search(dummy) == true)
			{
				myFacultyTree.getNode(dummy)->data.RemoveAdvisee(thisStudentID);
			}
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
