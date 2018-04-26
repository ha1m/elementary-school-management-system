#include "Class.h"


Class::Class(char l, int n) :Layer_name(l), num_of_class(n)
{
	Quan_pupil = 0;

}

Class::~Class()
{
	if (pupil != NULL)
	delete[]pupil;
}
//����� ������ ����� ���� "�����" ������� ���� �����
bool Class::Add(Pupil *p)
{
	//����� ��� ������ ������� ���� ������ ������ ��� ���� ��� ������ ����� ��������
	if (!Quan_pupil)
	{
		pupil = new Pupil*[1];
		pupil[0] = p;
		Quan_pupil += 1;
		return true;
	}
	//����� ������� ������� ����� ���� ���� ��� ����� ������ (+1) ���� ����� ����� ���� ���� ������ ����� ������ ����
	//����� ����� �� ���� ��������
	//������ ����� ����� ������ ������ ���� ����� ����
	else
	{
		Pupil **help;
		help = new Pupil*[Quan_pupil + 1];
		for (int i = 0; i < Quan_pupil; i++)
			help[i] = pupil[i];
		delete[]pupil;
		help[Quan_pupil] = p;
		Quan_pupil += 1;
		pupil = help;
		return true;
	}
}
//����� ������ ������ ������� �� ������ ����� ����� ������� ���
Pupil *Class::index(int index)
{
	return pupil[index];
}
//����� �������� ������ ��� ����� �� ����� ������
bool Class::tutor_is_excellent()
{
	int cnt = 0;
	//����� ������ �� ���� �������� ��������� �����
	for (int i = 0; i < Quan_pupil; i++)
	{
		if (pupil[i]->Outstanding())
			cnt++;
	}
	//����� ����� �������� �������� ����� ���� �50 ���� ����� ��� ���
	if (cnt > Quan_pupil / 2)
	{
		tutor->print();
		return true;
	}
	else return false;
}
//����� ������� �� ���� �������� ������� �����
//����� ��� ����� ������ �� ����� �� �� �����
void Class::print_students()
{
	for (int i = 0; i < Quan_pupil; i++)
	{
		pupil[i]->print();
		if (pupil[i]->Outstanding())
			cout << "This Student is Out Standing!!" << endl;
	}
}
//����� ������� ���� �����
//����� ����� ����� �� �����
void Class::Add_tutor(Tutor *t)
{
	tutor = t;
}



