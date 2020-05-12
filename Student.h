#include <iostream>

using namespace std;

// student class
struct Student
{
	public:
		Student();
		~Student();
		Student(int studentID, string name, string grade, string major, double gpa, int advisorID); //Overload initialize a new student
		void PrintStudentInfo(int studentID); //Number 3 - Find and display student information given the students ID
		int GetStudentID();
		void GetStudentAdvisorInfo(int studentID); //Number 5 - Given a student's ID, print the name and info of their faculty advisor
		void GetAdvisorID(int thisStudentID);
		void UpdateAdvisorID(int studentID, int advisorID); //Number 11 - Change a student's advisor given the student ID and the new faculty ID. Must have a counterpart in faculty to remove a student from a faculty
		bool operator==(const Student& student1);
		bool operator!=(const Student& student1);
		bool operator<(const Student& student1);
		bool operator>(const Student& student1);


		int studentID;
		string studentName;
		string studentGrade;
		string studentMajor;
		double studentGPA;
		int advisorID;
};
