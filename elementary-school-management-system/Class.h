#ifndef _CLASS
#define _CLASS
//���� �� ������ ������
#include "Pupil.h"
#include "Tutor.h"
//����� �� ����� "����" ��� �� ������ ��������� + ������ ��� �����
class Class{
	char Layer_name;
	int num_of_class;
	Pupil **pupil;
	int Quan_pupil;
	Tutor *tutor;
public:
	Class(){ Quan_pupil = 0; tutor = NULL; pupil = NULL; }
	Class(char, int);
	~Class();
	bool Add(Pupil *p);
	Pupil *index(int index);
	//����� ������� ����� ��� ����� �� ����� ��� ������
	bool tutor_is_excellent();
	//����� �������� ������� �����
	void print_students();
	//����� �� ����
	void set_layer(char l){ Layer_name = l; }
	//����� �� ����
	void set_class(int c){ num_of_class = c; }
	//������ ����
	char get_layer(){ return Layer_name; }
	//������ ����
	int get_class(){ return num_of_class; }
	//����� ������ ����� ����� ������ ���� �����
	void Add_tutor(Tutor *t);
	//����� ������ ��� ���� ���� �����
	bool tutor_exsit(){ return tutor!=NULL; }
};
#endif