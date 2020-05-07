#include <iostream>

using namespace std;

class Faculty
{
	public:
		Faculty(int ID, string name, string position, string dept, alistsomehowofallofthestudents);
		Faculty(char compare);
		void Print();
		int GetFacultyID();
		int GetAdviseeID();
		void RemoveAdvisee(int ID);
	private:
		int facultyID = 0;
		string facultyName = NULL;
		string facultyPosition = NULL;
		string facultyDepartment = NULL;
		int whatdowewantthestudentlisttolooklike?! = NULL or 0;
}
