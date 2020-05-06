// student class
class Student
{
	public:
		Student(char compare);
		Student(int ID, str name, str grade, int advisor);
		void Print();
		int GetStudentID();
		int GetStudentAdvisorID();
		void UpdateAdvisorID();
		
	private:
		int studentID = 0;
		str studentName = NULL;
		str studentStanding = NULL;
		int studentAdvisorID = 0;
}