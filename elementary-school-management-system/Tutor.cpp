#include "Tutor.h"
#include "Class.h"
//����� ������� ������ �� ���� �� �� ����� ������� ��
float Tutor::paycheck()
{
	return Teacher::paycheck() + 1000;
	
}
//����� ������ ��� ����� ��� ������ �� �� ������� ��������
bool Tutor::Outstanding()
{
	//������ ���� �� ��� ������� ���� ������ ���� ����� �� "����" ������ �����
	if (c)
	if (c->tutor_is_excellent())
		return true;
	else return false;

}
//������� ������� �� ���� �������� ������� ����� �� ������
//�������� ������ �� ��� ������� ����� ������ ���� ������ �� "����" ������ �����
void Tutor::print_students()
{
	if (c)
	c->print_students();
}
//����� ���� ����� ���� ���� ���� ��� ���� ����� ����
//��� �� ����� �� ���������/������� ������� ������
void Tutor::print()
{
	cout << "Tutor information:\n";
	Teacher::print();
	if (c)
	{
		cout << "Tutor of class number: " << c->get_class() << endl;
		cout << "in Layer: " << c->get_layer() << endl;
	}
	print_students();
}
//����� ���� ���� �� ����� ���� ������� ������� ��
void Tutor::print_class_info()
{

	cout << "Tutor of class number: " << c->get_class() << endl;
	cout << "in Layer: " << c->get_layer() << endl;
	cout << "List of students in class:\n";
	c->print_students();

}