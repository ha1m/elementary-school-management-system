#ifndef _WORKER
#define _WORKER
#include "Person.h"
#define basis 5000
//����� �� ����� "����" ������ ������ "�� ���" �
//
class Worker :public Person{
	int seniority;
public:
	Worker(string n, string ln, int i, int s) :Person(n, ln, i), seniority(s){}
	//~Worker();
	//����� ��������� ������� �� ����� �� �����, ������ ��� ���� ���
	virtual void print(){ Person::print(); cout << "Salary: " << paycheck() << endl << "Seniority: " << seniority << endl; }
	//����� ������� ������� �� ���� ����� �� �����
	int get_seniority(){ return seniority; }
};
#endif