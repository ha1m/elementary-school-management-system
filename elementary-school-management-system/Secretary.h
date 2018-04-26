#ifndef _SECRETARY
#define _SECRETARY
#include "Worker.h"
//����� �� ����� "������" ������ ������ "���� ����" ������ �� ������ ������� ���������
class Secretary :public Worker{
	int quan_children_in_school;
public:
	//����� �����. ���� ������ ��������
	Secretary(string n, string ln, int i, int s, int children) :Worker(n, ln, i, s), quan_children_in_school(children){}
	~Secretary();
	//����� ������� �� ������� �� ������� �� �� ����� ������� ��
	virtual float paycheck(){ return (basis + quan_children_in_school* 200); }
	//����� �������� ������ ��� ������� ������� �� �� ������ ��������
	virtual bool Outstanding(){ return get_seniority() > 10; }
	//����� ������� �� ����� �� ������� ���� ������ �����
	virtual void print(){ cout<<"Secretary information:\n"; Worker::print(); }
};
#endif