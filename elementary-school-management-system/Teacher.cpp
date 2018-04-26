#include "Teacher.h"
//���� ������ ���� �� "���� ����" ������ �� ����
//����� ������ ��������
Teacher::Teacher(string n, string ln, int i, int s) :Worker(n, ln, i, s)
{
	quan_professions = 0;
	profession_name = NULL;
}

Teacher::~Teacher()
{
	if (profession_name)
		delete profession_name;
}
//����� ������� �� ������� �� ����� �� �� ����� ������� ������� ��
float Teacher::paycheck()
{
	float x, y, paycheck;
	x = quan_professions;
	y = Teacher::get_seniority();
	paycheck = basis * (1 + x / 10) + 300 * y;
	return paycheck;
}
//����� �������� ��� ���� ��� ����� ������ �� �� ������� �������
bool Teacher::Outstanding()
{
	return(quan_professions > 5);
}
//����� ������� �� ����� �������� ������ ����
void Teacher::print_professions()const
{
	cout << "Professions: \n";
	for (int i = 0; i < quan_professions; i++)
	{
		cout << profession_name[i] << endl;
	}
}
//����� ������� �� ����� �� ����� ���� �������� ���� ����
void Teacher::print()
{
	cout << "Teacher information:\n";
	Worker::print();
	print_professions();
}
//����� ������� ������� ������ �������� �� �����
void Teacher::add_profession()
{
	char c;
	cout << "How many professions do you teach? ";
	cin >> quan_professions;
	profession_name = new string[quan_professions];
	cout << "Enter list of proffesions: \n";
	for (int i = 0; i < quan_professions; i++)
	{
		cout << "profession " << i+1 << ": ";
		cin >> profession_name[i];
		cout << endl;
	}
}