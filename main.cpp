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

void doAction(BST <Student> myStudentTree, BST <Faculty> myFacultyTree, int historic, int actionCount)
{
	cout<<historic;
	cout<<actionCount;
	actionCount +=1;
	ifstream studentFile;
	ifstream facultyFile;
	//write to files that are are named historic name
	string facultyFileName = "historicFacultyTree" + to_string(actionCount%5 + 1) + ".txt";
	facultyFile.open(facultyFileName);

	string studentFileName = "historicStudentTree" + to_string(actionCount%5 + 1) + ".txt";
	studentFile.open(studentFileName);

	myStudentTree.printTreeToFile(myStudentTree.root, studentFileName);
	myFacultyTree.printTreeToFile(myFacultyTree.root, facultyFileName);


}
void recallInfo(BST <Student> myStudentTree, BST <Faculty> myFacultyTree, int historic, int actionCount)
{
	string StudentFile;
	string FacultyFile;
	ifstream facultyFile;
	ifstream studentFile;

	string currString;
	cout << "enters recallinfo" << endl;
	if (historic == 0 && actionCount == 0)
	{
	
	}else
	{
		cout << "enters second if" << endl;
		string facultyFileName = "historicFacultyTree" + to_string(actionCount%5) + ".txt";
		facultyFile.open(facultyFileName);
		string studentFileName = "historicStudentTree" + to_string(actionCount%5) + ".txt";
		studentFile.open(studentFileName);
	}
	while(studentFile)
	{
		cout << "enters if(studentFile)" << endl;
		//studentReadIn(studentFile);
		int linecount = 0;
		int tempID;
		string tempName;
		string tempGrade;
		string tempMajor;
		double tempGPA;
		int tempAdvisorID;
		while(getline(studentFile, currString) && currString != "")
		{
			linecount +=1;
			if (linecount == 1)
			{
				cout << "linecount == 1" << endl;
				tempID = stoi(currString);
			}
			if (linecount == 2)
			{
				cout << "linecount == 2" << endl;
				tempName = currString;
			}
			if (linecount == 3)
			{
				cout << "linecount == 3" << endl;
				tempGrade = currString;
			}
			if (linecount == 4)
			{
				cout << "linecount == 4" << endl;
				tempMajor = currString;
			}
			if (linecount == 5)
			{
				cout << "linecount == 5" << endl;
				tempGPA = stoi(currString);
			}
			if (linecount == 6)
			{
				cout << "linecount == 6" << endl;
				tempAdvisorID = stoi(currString);
				cout << "right before student object" << endl;

				Student thisStudent = Student(tempID, tempName, tempGrade, tempMajor, tempGPA, tempAdvisorID);
				myStudentTree.insert(thisStudent);
				linecount = 0;

				cout << "adds student object" << endl;
			}
		}
	}
	//facultyFile.open("facultyTable.txt");
	//}

	/*if (studentFile)
	{
		cout << "enters if(studentFile)" << endl;
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
	}*/
	/*facultyFile.open("facultyTable.txt");
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
	}*/
}

main()
{

	BST<Student> myStudentTree; //instance of BST to make a tree of students
	BST<Faculty> myFacultyTree; //instance of BST to make a tree of faculty



    string StudentFile;
	string FacultyFile;
	ifstream facultyFile;
	ifstream studentFile;

	string currString;
	
	studentFile.open("studentTable.txt");

	facultyFile.open("facultyTable.txt");
	
	while(studentFile)
	{
		//studentReadIn(studentFile);
		int linecount = 0;
		int tempID;
		string tempName;
		string tempGrade;
		string tempMajor;
		double tempGPA;
		int tempAdvisorID;
		while(getline(studentFile, currString) && currString != "")
		{
			linecount +=1;
			if (linecount == 1)
			{
				cout << "linecount == 1" << endl;
				tempID = stoi(currString);
			}
			if (linecount == 2)
			{
				cout << "linecount == 2" << endl;
				tempName = currString;
			}
			if (linecount == 3)
			{
				cout << "linecount == 3" << endl;
				tempGrade = currString;
			}
			if (linecount == 4)
			{
				cout << "linecount == 4" << endl;
				tempMajor = currString;
			}
			if (linecount == 5)
			{
				cout << "linecount == 5" << endl;
				tempGPA = stoi(currString);
			}
			if (linecount == 6)
			{
				cout << "linecount == 6" << endl;
				tempAdvisorID = stoi(currString);
				cout << "right before student object" << endl;

				Student thisStudent = Student(tempID, tempName, tempGrade, tempMajor, tempGPA, tempAdvisorID);
				myStudentTree.insert(thisStudent);
				linecount = 0;

				cout << "adds student object" << endl;
			}
		}
	}




	/*if( remove( "facultyTable.txt" ) != 0 )
	{}
	if( remove( "studentTable.txt" != 0 ))
	{}*/
	//count what action number were on
	int actionCount = 0;
	int historic = 0;
	bool analysis = true;
	recallInfo(myStudentTree, myFacultyTree, historic, actionCount);
	while (analysis == true)
	{
		actionCount+=1;
		historic+=1;
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
		doAction(myStudentTree, myFacultyTree, historic, actionCount);
		}
		if (userSelection == 2)
		{
			myFacultyTree.printTree(myFacultyTree.root);
			//I commented this out for the moment because more errors were showing up and it was cluttering up the console

		doAction(myStudentTree, myFacultyTree, historic, actionCount);
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
		doAction(myStudentTree, myFacultyTree, historic, actionCount);
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
		doAction(myStudentTree, myFacultyTree, historic, actionCount);
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
		doAction(myStudentTree, myFacultyTree, historic, actionCount);
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

		doAction(myStudentTree, myFacultyTree, historic, actionCount);
		}
		if (userSelection == 7) //Add error checking for if student ID already exists
		{
			//get input info
			cout << "You have selected to create a student, please enter their information when prompted. (Use an underscore if providing more than one word.)" << endl;
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

		doAction(myStudentTree, myFacultyTree, historic, actionCount);
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


		doAction(myStudentTree, myFacultyTree, historic, actionCount);
		}
		if (userSelection == 9) //Add a new faculty member.
		{
			//still working on this but gotta go do stuff with my fam

			//get input info
			cout << "You have selected to create a new faculty member, please enter their information when prompted. (Use an underscore if you are providing more than one word.)" << endl;
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
		doAction(myStudentTree, myFacultyTree, historic, actionCount);
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
		doAction(myStudentTree, myFacultyTree, historic, actionCount);
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
		doAction(myStudentTree, myFacultyTree, historic, actionCount);


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
			doAction(myStudentTree, myFacultyTree, historic, actionCount);
		}
		if (userSelection == 13)
		{
			//clear trees
			recallInfo(myStudentTree, myFacultyTree, historic, actionCount);
		}
		if (userSelection == 14)
		{
			myStudentTree.printTreeToFile(myStudentTree.root, "studentTable.txt");
			myFacultyTree.printTreeToFile(myFacultyTree.root, "facultyTable.txt");
			//Should write to the file here before we close the program entirely
			//break;
			exit(0);
			analysis = false;
		}
	}
	//right here we have to figure out how to write to the disk
}
