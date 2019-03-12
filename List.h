#include<iostream>
#include<insertform.h>
#include"Node.h"

using namespace std;

class List{
private:
    Node* currentLocation;

public:
    List();
    void InsertNode(int,string,string,string,string,string,string);
    void UpdateNode(int,string,string,string,string,string,string);
    void DeleteNode(int);
    //        void DeleteLast();
    void PrintList();
    void AscendingSort();
    void searchElement(int);
    //        void insertAt(int,int);
};
List::List(){
    currentLocation = NULL;
}
void List::InsertNode(int rollno,string sname,string fname,string dname,string sem,string grade,string dateofjoin){

    Node* newNode = new Node();
    newNode->SetRollNo(rollno);
    newNode->SetStudentName(sname);
    newNode->SetFatherName(fname);
    newNode->SetSemester(sem);
    newNode->SetdepartmentName(dname);
    newNode->SetDateOfJoining(dateofjoin);
    newNode->SetGrade(grade);
    newNode->SetNext(NULL);

    // Check if the list is empty if its empty then insert it as a Ist element
    Node* temp = currentLocation;
    if(temp==NULL){
        currentLocation = newNode;
    }
    // if the list is not empty then Insert it as the last element
    else{

        while(temp->GetNext()!=NULL){
            if(temp->GetRollNo()==rollno){
                throw "Record of this Id aleady exists";
                return;
            }
            temp = temp->GetNext();
        }
        if(temp->GetRollNo()==rollno){
            throw "Record of this Id aleady exists";
            return;
        }
        temp = currentLocation;
        while(temp->GetNext()!=NULL){
            temp = temp->GetNext();
        }
        temp->SetNext(newNode);
        cout<<"New Student Record is entered successfully\n\n";
    }
}


void List::PrintList(){
    Node* temp = currentLocation;
    if(temp==NULL){
        throw "The list is blank/empty\n";
        return;

    }
    else{
        cout<<"The list contains:\n";
        while(temp!=NULL){
            cout<<temp->GetRollNo()<<endl;
            cout<<temp->GetStudentName()<<endl;
            cout<<temp->GetFatherName()<<endl;
            cout<<temp->GetdepartmentName()<<endl;
            cout<<temp->GetSemester()<<endl;
            cout<<temp->GetGrade()<<endl;
            cout<<temp->GetDateOfJoining()<<endl;

            cout<<" ------------------------------\n ";
            temp=temp->GetNext();

        }
        cout<<"END"<<endl;
    }
}
void List::DeleteNode(int roll){
    Node* temp = currentLocation;
    Node* prev = NULL;
    if(temp==NULL){
        throw "The list is blank/empty\n So no record deleted\n";
        return;
    }
    else if(temp->GetNext()==NULL){
        if(temp->GetRollNo()==roll){
            delete temp;
            currentLocation = NULL;
            cout<<"The Only present first record deleted successfully\n";
            return;
        }
        else{
            throw "No any record deleted\n";
            return;
        }
    }
    else if(temp->GetRollNo()==roll){
        Node* sec = temp->GetNext();
        currentLocation= sec;
        delete temp;
        cout<<"First element deleted successfully\n";
        return;
    }
    else{
        do	{
            if(temp->GetNext()!=NULL){

                prev = temp;
                temp = temp->GetNext();

            }
            else{
                break;
            }

        }while(temp->GetRollNo()!=roll);

        if(temp->GetRollNo()==roll){
            prev->SetNext(temp->GetNext());
            delete temp;
            cout<<"Element deleted successfully\n";
        }
        else{
            throw "The given element not found in the list\n";
        }
    }

}
void List::UpdateNode(int rollno,string sname,string fname,string dname,string sem,string grade,string dateofjoin){
    Node* temp = currentLocation;
    if(temp==NULL){
        throw "The list is blank/empty\n So no record found\n";
        return;
    }
    else{
        while(temp->GetNext()!=NULL){
            if(temp->GetRollNo()==rollno){
                if(sname.empty()==false)
                    temp->SetStudentName(sname);
                if(fname.empty()==false)
                    temp->SetFatherName(fname);
                if(sem.empty()==false)
                    temp->SetSemester(sem);
                if(dname.empty()==false)
                    temp->SetdepartmentName(dname);
                if(dateofjoin.empty()==false)
                    temp->SetDateOfJoining(dateofjoin);
                if(grade.empty()==false)
                    temp->SetGrade(grade);
                return;
            }
            else{
                temp=temp->GetNext();
            }
        }
        if(temp->GetRollNo()==rollno){
            if(sname.empty()==false)
                temp->SetStudentName(sname);
            if(fname.empty()==false)
                temp->SetFatherName(fname);
            if(sem.empty()==false)
                temp->SetSemester(sem);
            if(dname.empty()==false)
                temp->SetdepartmentName(dname);
            if(dateofjoin.empty()==false)
                temp->SetDateOfJoining(dateofjoin);
            if(grade.empty()==false)
                temp->SetGrade(grade);
            return;
        }
        else{
            throw "Record of this id not found";
        }
    }
}
void List::AscendingSort(){

    Node* temp = currentLocation;
    int total = 1;
    if(temp==NULL){
        throw "The list is empty, No any Record";
        return;
    }
    else{
        while(temp->GetNext()!=NULL){
            temp = temp->GetNext();
            ++total;
        }
    }
    if(total==1){
        throw "The linked list contains only a single element so there is no need to sort\n";
        return;
    }

    //Bubble Sort
    Node* sec;
    int rollno;
    string stname,fthname,sem,dename,grade,dateofjoin;
    for(Node* node1 = currentLocation;node1->GetNext()!= NULL ;node1 = node1->GetNext()) {

        for(Node* node2 = currentLocation ; node2->GetNext()!= NULL; node2 = node2->GetNext()) {
            sec = node2->GetNext();
            if(node2->GetRollNo() > sec->GetRollNo()) {
                rollno = node2->GetRollNo();
                node2->SetRollNo(sec->GetRollNo());
                sec->SetRollNo(rollno);
                stname = node2->GetStudentName();
                node2->SetStudentName(sec->GetStudentName());
                sec->SetStudentName(stname);
                fthname = node2->GetFatherName();
                node2->SetFatherName(sec->GetFatherName());
                sec->SetFatherName(fthname);
                sem = node2->GetSemester();
                node2->SetSemester(sec->GetSemester());
                sec->SetSemester(sem);
                dename = node2->GetdepartmentName();
                node2->SetdepartmentName(sec->GetdepartmentName());
                sec->SetdepartmentName(dename);
                grade = node2->GetGrade();
                node2->SetGrade(sec->GetGrade());
                sec->SetGrade(grade);
                dateofjoin = node2->GetDateOfJoining();
                node2->SetDateOfJoining(sec->GetDateOfJoining());
                sec->SetdepartmentName(dateofjoin);
            }

        }
    }
    cout<<"The linked list is sorted Ascendingly according to Student Id\n";
}
void List::searchElement(int value){
    Node* temp = currentLocation;
    if(temp==NULL){
        throw "The list is blank/empty\n";
        return;
    }
    else{
        while(temp->GetNext()!=NULL){
            if(temp->GetRollNo()==value){
                cout<<"Student Record found in the linked list\n";
                cout<<temp->GetRollNo()<<endl;
                cout<<temp->GetStudentName()<<endl;
                cout<<temp->GetFatherName()<<endl;
                cout<<temp->GetdepartmentName()<<endl;
                cout<<temp->GetSemester()<<endl;
                cout<<temp->GetGrade()<<endl;
                cout<<temp->GetDateOfJoining()<<endl;

                cout<<" ------------------------------\n ";
                return;
            }
            else{
            }
            temp = temp->GetNext();
        }
        if(temp->GetRollNo()!=value){
            throw "Student Record not found in the linked list\n";
            return;
        }
        else{
            cout<<"Student Record found in the linked list\n";
            cout<<temp->GetRollNo()<<endl;
            cout<<temp->GetStudentName()<<endl;
            cout<<temp->GetFatherName()<<endl;
            cout<<temp->GetdepartmentName()<<endl;
            cout<<temp->GetSemester()<<endl;
            cout<<temp->GetGrade()<<endl;
            cout<<temp->GetDateOfJoining()<<endl;

            cout<<" ------------------------------\n ";
            return;
        }
    }

}
//void List::insertAt(int data,int loc){
//	
//	int total=1;
//	int temploc=0;
//	Node* prev=NULL;
//	Node* newNode = new Node();
//	newNode->SetData(data);
//	Node* temp = currentLocation;
//	
//	if(temp!=NULL){
//	
//	while(temp->GetNext()!=NULL){
//		
//		temp = temp->GetNext();
//		++total;
//	}
//}
//	temp = currentLocation;
//	
//	if(loc+1>total){
//		cout<<"The selected index is not present in the linked list\n";
//		return;
//	}
//	
//  else if(loc==0){
//	if(temp==NULL)
//	{
//		newNode->SetNext(NULL);
//		currentLocation=newNode;
//		cout<<"Data inserted successfully at index 0\n";
//		
//	}
//	else{
//		newNode->SetNext(temp);
//		currentLocation=newNode;
//		cout<<"Data inserted successfully at index 0\n";
//	}
//	
// }
//else{
//	
//	temp=currentLocation;
//	temploc=loc+1;
//	loc=1;
//	while(loc<temploc){
//	  prev = temp;
//	  temp = temp->GetNext();
//	  loc++;
//	}
//	newNode->SetNext(temp);
//	prev->SetNext(newNode);
//	cout<<"New Element is successfully inserted at index "<<(loc-1)<<":\n";
//}
//
//
//}
//void List::DeleteLast(){
//	Node* temp = currentLocation;
//	if(temp==NULL){
//		cout<<"The list is empty"<<endl;
//		return;
//	}
//	else if(temp->GetNext()==NULL){
//		currentLocation = NULL;
//		temp=NULL;      //this step can be skipped
//		delete temp;
//		cout<<"The first element in the linked list is deleted successfully\n";
//		return;
//		
//	}
//	else{
//		Node* prev;
//		while(temp->GetNext()!=NULL){
//			prev = temp;
//			temp=temp->GetNext();
//		}
//		prev->SetNext(temp->GetNext());
//		delete temp;
//		cout<<"The last element in the linked list is deleted successfully!"<<endl;
//		
//	}
//	
//	
//	
//}
