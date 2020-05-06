//student functionality
//constructor
Student::Student(int ID, str name, str grade, int advisor)
{
	studentID = n1;
	studentName = name;
	studentStanding = grade;
	studentAdvisorID = advisor;
}
Student::Student(char compare)
{
// this is supposed to take in >, < or =
}
Student::Print()
{
	cout<<"Student # : "<<studentID<<endl;
	cout<<"Name : " <<studentName<<endl;
	cout<<"Standing : " <<studentStanding<<endl;
	cout<<"Advisor ID : " <<studentAdvisorID<<endl;
}
Student:UpdateAdvisor(int ID)
{
	studentAdvisorID = ID;
}
	