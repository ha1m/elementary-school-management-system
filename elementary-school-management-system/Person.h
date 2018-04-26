#ifndef _PERSON
#define _PERSON
#include <string>
#include <iostream>
using namespace std;
//����� �� ����� "�� ���" ���� ����� ���������. ����� ������ ������ �� ����� ��������� �� ������ ����� �����
//������ ������ ����� ��������� ������� ����� ���� �� �� ���
class Person{
	string name, last_name;
	int id;
public:
	Person(string n, string ln, int i) :name(n), last_name(ln), id(i){}
	//~Person();
	virtual void print(){ cout << "Name: " << name << "\nLast name: " << last_name << "\nID: " << id << endl; }
	virtual bool Outstanding() = 0;
	//����� ��������� ������� ����� ����
	virtual int get_id(){ return id; }
	//����� ��������� ����� ������� ������
	virtual float paycheck()=0;

};
#endif