#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

struct Faculty
{
	public:

		Faculty();
		~Faculty();
		Faculty(int facultyID, string name, string position, string department /*, alistsomehowofallofthestudents*/); //Overload initialize a new faculty advisor

		void PrintFacultyInfo(); //Number 4 - Find and display faculty information given the faculty ID
		int GetFacultyID();
		void SetFacultyID(int facultyID);
		void AddAdvisee(int adviseeID);
		int GetAdvisees(int facultyID); //We will need to change this once we decide if we use a list or BST for students so that it returns that type instead of int
		void RemoveAdvisee(int studentID); //Number 12 - Remove an advisee from a faculty member given the IDs

		bool operator==(const Faculty& faculty);
		bool operator!=(const Faculty& faculty);
		bool operator>(const Faculty& faculty);
		bool operator<(const Faculty& faculty);
		friend std::ostream& operator<< (std::ostream& out, const Faculty& faculty);
		friend std::ostream& operator>> (std::ostream& out, const Faculty& faculty);


		int facultyID ;
		string facultyName;
		string facultyPosition;
		string facultyDepartment;
		DoublyLinkedList<int>* advisees;
		//int whatdowewantthestudentlisttolooklike?! = NULL or 0;

};
