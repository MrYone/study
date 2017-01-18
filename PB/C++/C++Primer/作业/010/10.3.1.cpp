#include "iostream"
#include "stdio.h"

using namespace std;

class person{
public:
	person(int id = 0,char *name = nullptr)
	:m_id(id),m_name(name){}

	void operator()(int id,char *name){
		m_id = id;
		m_name = name;
	}

	void show(){
		cout << "================================================================" << endl;
		printf("%t[ID:%d]:[NAME:%s] -> ",m_id,m_name);
	}

private:
	int m_id;
	char *m_name;
};

class teacher:public person{
public:
	teacher(){}

	teacher(int id,char *name,char *position,char *department)
	:m_position(position),m_department(department),person(id,name){}

	void operator()(int id,char *name,char *position,char *department){
		person::operator()(id,name);
		m_position = position;
		m_department = department;
	}

	void show(){
		person::show();
		printf("[POSITIONE:%s],[DEPARTMENT:%s]\n",m_position,m_department);
	}

private:
	char *m_position;
	char *m_department;
};

class student:public person{
public:
	student(){}

	student(int id,char *name,int classid,int score)
	:m_classid(classid),m_score(score),person(id,name){}

	void operator()(int id,char *name,int classid,int score){
		person::operator()(id,name);
		m_classid = classid;
		m_score = score;
	}

	void show(){
		person::show();
		printf("[CLASSID:%d],[SCORE:%d]\n",m_classid,m_score);
	}

private:
	int m_classid;
	int m_score;
};

int main(){
	teacher tea1(456,"Mr.Wei","Master","CTO");
	student stu1;

	tea1.show();
	stu1(123,"xiaoming",31,80);
	stu1.show();
	
	cout << "================================================================" << endl;
	return 0;
}