#ifndef _PUPIL
#define _PUPIL
#include "Person.h"
//����� �� ����� "�����" ������ ������ "�� ���" �
//����� ������ ������ ��� ���� ������
class Pupil :public Person{
	int *grade, Quantity_grades,num_class;
	char layer_name;
public:
	Pupil(string n, string ln, int i, int c, char l);
	~Pupil();
	float GPA();
	virtual bool Outstanding();
	virtual void print();
	//����� ������� ������ ����� ������� �� ������
	void add_grade();
	//����� ������� 0 ����� ������� �� ���� ������ �� ��� ���� ���� �� ������ �� ��� ������ ����� ������ ��� ���� ������� ������
	virtual float paycheck(){ return 0; }

};
#endif