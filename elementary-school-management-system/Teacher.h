#ifndef _TEACHER
#define _TEACHER
//#include "Person.h"
#include "Worker.h"
//����� �� ����� "����" ������ ������ "���� ����" ��� �� ������� ��������� ��������
//������ ����� ������� ������ ������� ������ �������� �� �����
class Teacher :public Worker{
	string *profession_name;
	int quan_professions;
public:
	Teacher(string n, string ln, int i, int s);
	~Teacher();
	virtual float paycheck();
	virtual bool Outstanding();
	void print_professions()const;
	virtual void print();
	//����� ������� ������� ������ �������� ������ ����
	void add_profession();

};
#endif