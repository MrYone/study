#include "person_teach_student.h"
#include "iostream"
#include "string.h"

using namespace std;

void person::setinfo(int id, const char * name){
	//if(name == nullptr){
//		cout << "no name!" << endl;
//		return;
	//}
	
	m_sName = new char[strlen(name) + 1];
	strcpy(m_sName, name);
	//strcpy_s(m_sName, strlen(name) + 1, name);

	m_nId = id;
}

void person::show(){
	if(m_sName == nullptr){
		cout << "no this person" << endl;
		return;
	}

	cout << "	[ Name: " << m_sName << "	ID: " << m_nId;
}

void teacher::setinfo(
		int id,
		const char * name,
		const char * department,
		const char * position
		){
	if(name == nullptr){
		cout << "no name!" << endl;
		return;
	}
	
	person::setinfo(id, name);

	m_sDepartment = new char[strlen(department) + 1];
	strcpy(m_sDepartment, department);
	//strcpy_s(m_sDepartment, strlen(department) + 1, department);

	m_sPosition = new char[strlen(position) + 1];
	strcpy(m_sPosition, position);
	//strcpy_s(m_sPosition, strlen(position) + 1, position);
}

void teacher::show(){
	if (m_sName == nullptr){
		cout << "no this person" << endl;
		return;
	}
	
	person::show();
	
	cout << "	Department: " << m_sDepartment
		 << "	Position: " << m_sPosition
		 << " ]" << endl;
}

void student::setinfo(
		int id,
		const char * name,
		int classid,
		int score
		){
	if(name == nullptr){
		cout << "no name!" << endl;
		return;
	}
	
	person::setinfo(id, name);
	
	m_nClassId = classid;
	m_nScore = score;
}

void student::show(){
	if(m_sName == nullptr){
		cout << "no this person" << endl;
		return;
	}
	
	person::show();
	
	cout << "	ClassId: " << m_nClassId
		 << "	Score: " << m_nScore
		 << " ]" << endl;
}

int main(int argc, char * argv[]){
	student s;
	teacher t;

	s.setinfo(1201050111, "Yone", 31, 100);
	t.setinfo(1111111100, "Jack", "Cisco", "Exp");

	s.show();
	t.show();

	return 0;
}













