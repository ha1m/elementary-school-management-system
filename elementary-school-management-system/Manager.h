#ifndef _MANAGER
#define _MANAGER
#include "Worker.h"
//������ �� ����� "����" ������ ������ "���� ����" ��� ������ ���������

class Manager :public Worker{
public:
	//���� ����� ���� ������ ��������
	Manager(string n, string ln, int i, int s) :Worker(n, ln, i, s){}
	~Manager();
	//����� ������� ������ �� �� ����� ������� ������� �����
	virtual float paycheck(){ return (basis * 2 + get_seniority() * 500); }
	//����� �������� ����� ��� ����� ������ �� �� ������ ��������
	virtual bool Outstanding(){ return get_seniority() > 3; }
	//����� ������� �� ����� �� ����� ���� ������ ����
	virtual void print(){ cout << "Manager information:\n";  Worker::print(); }
};
#endif
