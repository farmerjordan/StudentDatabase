#include <iostream>

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
		int GetAdvisees(int facultyID); //We will need to change this once we decide if we use a list or BST for students so that it returns that type instead of int
		void RemoveAdvisee(int facultyID, int studentID); //Number 12 - Remove an advisee from a faculty member given the IDs

		//bool operator==(const Faculty& faculty1, const Facult& faculty2);
		//bool operator!=(const Faculty& faculty1, const Facult& faculty2);
		//bool operator<(const Faculty& faculty1, const Facult& faculty2);
		//bool operator>(const Faculty& faculty1, const Facult& faculty2);


		int facultyID ;

	private:
		string facultyName;
		string facultyPosition;
		string facultyDepartment;
		//int whatdowewantthestudentlisttolooklike?! = NULL or 0;

};
