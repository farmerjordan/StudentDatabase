#include <iostream>

using namespace std;

class Faculty
{
	public:
		Faculty();
		~Faculty();
		Faculty(int facultyID, string name, string position, string department /*, alistsomehowofallofthestudents*/); //Overload initialize a new faculty advisor
		Faculty(char compare, int facultyID1, int facultyID2); //Overload Comparison Operator

		void PrintFacultyInfo(int facultyID); //Number 4 - Find and display faculty information given the faculty ID
		int GetFacultyID();
		int GetAdvisees(int facultyID); //We will need to change this once we decide if we use a list or BST for students so that it returns that type instead of int
		void RemoveAdvisee(int facultyID, int studentID); //Number 12 - Remove an advisee from a faculty member given the IDs


	private:
		int facultyID ;
		string facultyName;
		string facultyPosition;
		string facultyDepartment;
		//int whatdowewantthestudentlisttolooklike?! = NULL or 0;

};
