class Faculty
{
	public:
		Faculty(int ID, str name, str position,str dept/*, alistsomehowofallofthestudents*/);
		Faculty(char compare);
		void Print();
		int GetFacultyID();
		int GetAdviseeID();
		void RemoveAdvisee(int ID);
	private:
		int facultyID = 0;
		str facultyName = NULL;
		str facultyPosition = NULL;
		str facultyDepartment = NULL;
		//int whatdowewantthestudentlisttolooklike?! = NULL or 0;
}