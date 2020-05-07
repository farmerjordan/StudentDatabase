#include <iostream>

using namespace std;

// student class
class Student
{
	public:
		Student(char compare);
		Student(int ID, string name, string grade, int advisor);
		void Print();
		int GetStudentID();
		int GetStudentAdvisorID();
		void UpdateAdvisorID();

	private:
		int studentID = 0;
		string studentName = NULL;
		string studentStanding = NULL;
		int studentAdvisorID = 0;
}
