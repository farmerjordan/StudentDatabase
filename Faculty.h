#include <iostream>

using namespace std;

struct Faculty
{
	public:

		Faculty();
		~Faculty();
		Faculty(int facultyID, string name, string position, string department /*, alistsomehowofallofthestudents*/); //Overload initialize a new faculty advisor

		void PrintFacultyInfo(int facultyID); //Number 4 - Find and display faculty information given the faculty ID
		int GetFacultyID();
		int GetAdvisees(int facultyID); //We will need to change this once we decide if we use a list or BST for students so that it returns that type instead of int
		void RemoveAdvisee(int facultyID, int studentID); //Number 12 - Remove an advisee from a faculty member given the IDs

		bool operator==(const Faculty& faculty);
		bool operator!=(const Faculty& faculty);
		bool operator<(const Faculty& faculty);
		bool operator>(const Faculty& faculty);


<<<<<<< HEAD
=======

>>>>>>> 6a4b4edc98f0e75f2ba691b3a52eb2ff19d74b43

		int facultyID ;

	private:
<<<<<<< HEAD


=======
		
>>>>>>> 6a4b4edc98f0e75f2ba691b3a52eb2ff19d74b43
		string facultyName;
		string facultyPosition;
		string facultyDepartment;
		//int whatdowewantthestudentlisttolooklike?! = NULL or 0;

};
