#include<iostream>
using namespace std;
class Node{
    private:
	  int rollNo;
	  string studentName;
	  string fatherName;
	  string departmentName;
	  string semester;
	  string dateOfJoining;
	  string grade;
	  Node* next;	
		
	public:	
	Node();
	int GetRollNo();
	string GetStudentName();
	string GetFatherName();
	string GetdepartmentName();
	string GetSemester();
	string GetDateOfJoining();
	string GetGrade();
	Node* GetNext();
	void SetRollNo(int);
	void SetStudentName(string);
	void SetFatherName(string);
	void SetdepartmentName(string);
	void SetSemester(string);
	void SetDateOfJoining(string);
	void SetGrade(string);
	void SetNext(Node*);
};
Node::Node(){
	
}
int Node::GetRollNo(){
	return rollNo;
}
string Node::GetStudentName(){
    return studentName;
}
string Node::GetFatherName(){
	return fatherName;
}
string Node::GetdepartmentName(){
	return departmentName;
}
string Node::GetSemester(){
	return semester;
}
string Node::GetDateOfJoining(){
	return dateOfJoining;	 
}
string Node::GetGrade(){
	return grade;
}
Node* Node::GetNext(){
	return next;
}
void Node::SetRollNo(int roll){
	rollNo=roll;
}
void Node::SetStudentName(string sName){
	studentName = sName;
}
void Node::SetFatherName(string fName){
	fatherName = fName;
}
void Node::SetdepartmentName(string dName){
	departmentName = dName;
}
void Node::SetSemester(string sem){
	semester = sem;
}
void Node::SetDateOfJoining(string date){
    dateOfJoining = date;
}
void Node::SetGrade(string grd){
	grade = grd;
}
void Node::SetNext(Node* Next){
	next=Next;
}
