#ifndef _TUTOR
#define _TUTOR
#include "Teacher.h"
class Class;
//����� �� ����� �� "����" ���� ���� �� "����" ���� ������ �������� ������� ��� �����

class Tutor :public Teacher{
	Class *c;
public:
	//���� ����� ���� ������ ��������
	Tutor(string n, string ln, int i, int s) :Teacher(n, ln, i, s){}
	~Tutor();
	virtual float paycheck();
	virtual bool Outstanding();
	void print_students();
	virtual void print();
	//����� ������� ������ ����� ���� ���� ������� ���� �����
	void Add_class(Class *t){ c = t; }
	//����� ������� ������� �� ���� ����� �� ����� ����
	void print_class_info();


};
#endif
