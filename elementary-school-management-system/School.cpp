#include "School.h"
#include "Manager.h"
#include "Secretary.h"
//����� �����
School::School()
{
	layer_school = new Layer*[6];
	qaun_layers = 6;
	all_persons = NULL;
	qaun_all_persons = 0;
	manager_exsit = false;
}

School::~School()
{
	if (all_persons)
		delete[]all_persons;
	delete[]layer_school;
}
//������� ����� ������ �� ��������� ������
void School::Menu()
{
	//����� �� �� ������� ��������� �������
	char _layer_name;
	int ID, _num_of_class, index = 0, quan_class_made = 0, seniority, children,max=0;
	string first_name, last_name; 
	Class c[18], *pointer;
	bool exsit = false,person_exsit=false,tutor_exs=false;
	//����� �� ���� �������� �� ������ ������ ���� �����
	int choice;
	do
	{
		cout << "Please enter your choice:\n";
		cout << " 1 - Add pupil\n";
		cout << " 2 - Add teacher\n";
		cout << " 3 - Add tutor\n";
		cout << " 4 - Add manager\n";
		cout << " 5 - Add secretary\n";
		cout << " 6 - Print workers and pupil details\n";
		cout << " 7 - Print outstanding people\n";
		cout << " 8 - Print tutor's class \n";
		cout << " 9 - Print worker details with biggest salary\n";
		cout << "10 - Exit\n";
		cin >> choice;
		switch (choice)
		{
			//����� ����� ���� ����
		case 1:
			//���� ���� ������ �������
			cout << "Hello, please enter your details:\n";
			cout << "First name: ";
			cin >> first_name;
			cout << "Last name: ";
			cin >> last_name;
			cout << "ID: ";
			cin >> ID;
			cout << "Which layer?\t(a-f)";
			cin >> _layer_name;
			cout << "Which class in layer?\t(1-3)";
			cin >> _num_of_class;
			//����� ���� ����� ����� ������ ���� ����� ��� ������
			//����� ����� ����� ������ ������ �����
			//����� ���� ����� ������� ������ ���� ��� �����
			if (!qaun_all_persons)
			{
				all_persons = new Person*[1];
				all_persons[0] = new Pupil(first_name, last_name, ID, _num_of_class, _layer_name);
				Pupil *st = dynamic_cast<Pupil*>(all_persons[0]);
				if (st != NULL)
					st->add_grade();
				qaun_all_persons += 1;
				c[index].set_layer(_layer_name);
				c[index].set_class(_num_of_class);
				c[index].Add(st);
				quan_class_made += 1;
				index++;
			}
			//����� ���� ������ ����� ����� ������ ����� ��� ������ ��� ���� �����
			//����� ���� ���� ��� �� ���� �����
			else
			{
				for (int i = 0; i < qaun_all_persons; i++)
				{
					if (all_persons[i]->get_id() == ID)
					{
						cout << "Person already exsit\n";
						person_exsit = true; 
						break;
					}
				}
				if (person_exsit)
				{
					person_exsit = false;
					break;
				}
				//����� ������� �� ���� ����� ���� ���� ��� ���� ����� ������� �� ����� ���� �������� ��� ������ �� ������
				//����� ������ ���� ���� ����� ����� ���� ����
				//���� ������ ����� �������
				//���� ����� ���� ���� ����� ������� �����
				//����� ������ ����� , �� ����� ���� ���� ���� ���� ����� ����� ������
				//����� ����� ����� ���� ����� �� ����� ����� , ����� ���� ��� ���� ����� ���
				//����� ����� ����� ������ ������.
				Person **help = new Person*[qaun_all_persons + 1];
				for (int i = 0; i < qaun_all_persons; i++)
					help[i] = all_persons[i];
				help[qaun_all_persons] = new Pupil(first_name, last_name, ID, _num_of_class, _layer_name);
				Pupil *st = dynamic_cast<Pupil*>(help[qaun_all_persons]);
				if (st != NULL)
					st->add_grade();
				delete[]all_persons;
				all_persons = help;
				qaun_all_persons += 1;
				for (int i = 0; i < quan_class_made; i++)
				{
					if (c[i].get_class() == _num_of_class && c[i].get_layer() == _layer_name)
					{
						c[i].Add(st);
						exsit = true;
						break;
					}
				}
				if (!exsit)
				{
					c[index].set_layer(_layer_name);
					c[index].set_class(_num_of_class);
					c[index].Add(st);
					quan_class_made += 1;
					index++;
				}
			}
			break;
		case 2:	
			//����� ���� ����� ��� ����
			//���� ����� �� ����� ���� ���� ����
			cout << "Hello, please enter your details:\n";
			cout << "First name: ";
			cin >> first_name;
			cout << "Last name: ";
			cin >> last_name;
			cout << "ID: ";
			cin >> ID;
			cout << "Years of Seniority: ";
			cin >> seniority;
			//����� ��� ����� ����� ����� ����� ����� ���� ��� ��� ��� �����
			//����� ����� ����� ������ �����
			if (!qaun_all_persons)
			{
				all_persons = new Person*[1];
				all_persons[0] = new Teacher(first_name, last_name, ID, seniority);
				Teacher *st = dynamic_cast<Teacher*>(all_persons[0]);
				if (st != NULL)
					st->add_profession();
				qaun_all_persons += 1;
			}
			//����� ���� ���� ����� ����� ������ ����� �� �� ����� ���� ��� ����� ��� ���� ���� ����
			//����� ���� ���� ��� �� ���� ����� ������ ����� �����
			//����� ���� �� ���� ���� ���� ��� ���� ����� ������� �� ����� ����
			//��� ������ ���� ����� ���� , ����� ������ ���� ������ �� ����� ����
			//���� � ����� ����� �������
			else
			{
				for (int i = 0; i < qaun_all_persons; i++)
				{
					if (all_persons[i]->get_id() == ID)
					{
						cout << "Person already exsit\n";
						person_exsit = true;
						break;
					}
				}
				if (person_exsit)
				{
					person_exsit = false;
					break;
				}
				Person **help = new Person*[qaun_all_persons + 1];
				for (int i = 0; i < qaun_all_persons; i++)
					help[i] = all_persons[i];
				help[qaun_all_persons] = new Teacher(first_name, last_name, ID, seniority);
				Teacher *st = dynamic_cast<Teacher*>(help[qaun_all_persons]);
				if (st != NULL)
					st->add_profession();
				delete[]all_persons;
				all_persons = help;
				qaun_all_persons += 1;
			}
			break;
		case 3:
			//����� ���� ����� ��� ���� ������ �����
			//���� ���� ����� ���� ����� ���� ������ ���� ��� ����
			cout << "Hello, please enter your details:\n";
			cout << "First name: ";
			cin >> first_name;
			cout << "Last name: ";
			cin >> last_name;
			cout << "ID: ";
			cin >> ID;
			cout << "Which layer do you teach?\t(a-f)";
			cin >> _layer_name;
			cout << "Which class in layer do you teach?\t(1-3)";
			cin >> _num_of_class;
			cout << "Years of Seniority: ";
			cin >> seniority;
			//����� ��� ������ ����� ����� ����� ���� ��� ������
			//��� �� ����� ���� ����� ������ ���� ����� ���� ����� ����� �� �� ��� �����
			//������� ���� ������ �����
			//������� ���� ������ ������
			if (!qaun_all_persons)
			{
				all_persons = new Person*[1];
				all_persons[0] = new Tutor(first_name, last_name, ID, seniority);
				Tutor *st = dynamic_cast<Tutor*>(all_persons[0]);
				if (st != NULL)
					st->add_profession();
				qaun_all_persons += 1;
				c[index].set_layer(_layer_name);
				c[index].set_class(_num_of_class);
				c[index].Add_tutor(st);
				pointer = &c[index];
				st->Add_class(pointer);
				quan_class_made += 1;
				index++;
			}
			//����� ���� �� ����� ����� ������ ����� �� �� ������ ���� ��� ����� ���� �����
			//����� ��� ����� ����� ������ ���� �� ���� �����

			else
			{
				for (int i = 0; i < qaun_all_persons; i++)
				{
					if (all_persons[i]->get_id() == ID)
					{
						cout << "Person already exsit\n";
						person_exsit = true;
						break;
					}
				}
				if (person_exsit)
				{
					person_exsit = false;
					break;
				}
				//����� ���� �� ���� ����� ���� ���� ��� ����� ����� ���� ������� �� ����� ����
				//��� ������ ���� ����� ����
				//����� ���� ���� ������ �� ����� ����
				Person **help = new Person*[qaun_all_persons + 1];
				for (int i = 0; i < qaun_all_persons; i++)
					help[i] = all_persons[i];
				//������ ����� ��� ���� ����� ������ ����� ��� ����� ������
				//��� ����� ��� ����� ���� ��� ������ ���
				//������ ����� ���� ����� �������� ��� ��� ���� ���� ����� ��
				//����� ����� ������ �� �� ���� ����� ��
				for (int i = 0; i < quan_class_made; i++)
				{
					if (c[i].get_class() == _num_of_class && c[i].get_layer() == _layer_name)
					{
						if (c[i].tutor_exsit())
						{
							tutor_exs = true;
							cout << "There is a tutor to that class!\n";
							break;
						}
					}

				}
				//����� ����� ���� ����� �� ��� �� ���� �����
				if (tutor_exs)
					break;
				//����� ���� ��� ������
				help[qaun_all_persons] = new Tutor(first_name, last_name, ID, seniority);
				Tutor *st = dynamic_cast<Tutor*>(help[qaun_all_persons]);
				if (st != NULL)
					st->add_profession();
				delete[]all_persons;
				all_persons = help;
				qaun_all_persons += 1;
				//������ ����� ��� ���� ����� ������ ����� ��� ����� ������
				//��� ����� ��� ����� ���� ���
				//����� ��� ����� ���� ����� ������ ����� �����
				//��� ����� ����� �� ����� ������ �� ����� ���
				//������ �� ����� ������ �� ����� ����� ����
				for (int i = 0; i < quan_class_made; i++)
				{
					if (c[i].get_class() == _num_of_class && c[i].get_layer() == _layer_name)
					{
						c[i].Add_tutor(st);
						pointer = &c[i];
						st->Add_class(pointer);
						exsit = true;
						break;
					}
				}
				//����� ������ �� ����� ����� ����� ���� ��� �� ����� ������ ����� 
				//����� ����� ����� ������ ������
				//����� ���� �����
				//����� ����� �����
				if (!exsit && !tutor_exs)
				{
					c[index].set_layer(_layer_name);
					c[index].set_class(_num_of_class);
					c[index].Add_tutor(st);
					pointer = &c[index];
					st->Add_class(pointer);
					quan_class_made += 1;
					index++;
				}
			}
			break;
		case 4:
			//����� �� ���� ����� ��� ����
			//���� ���� ����� ���� ���� ����
			cout << "Hello, please enter Manager details:\n";
			cout << "First name: ";
			cin >> first_name;
			cout << "Last name: ";
			cin >> last_name;
			cout << "ID: ";
			cin >> ID;
			cout << "Years of Seniority: ";
			cin >> seniority;
			//����� ���� �� ���� ����� ��� ���� ��� ������ ������ ����� ����� � �����
			if (!qaun_all_persons)
			{
				all_persons = new Person*[1];
				all_persons[0] = new Manager(first_name, last_name, ID, seniority);
				qaun_all_persons += 1;
			}
			else
				//����� ������� ����� ����� ������ ����� �� �� ������ ���� ��� ���� �� �����
				//����� ��� ����� ����� ������ ������ �� ���� �����
			{
				for (int i = 0; i < qaun_all_persons; i++)
				{
					if (all_persons[i]->get_id() == ID)
					{
						cout << "Person already exsit\n";
						person_exsit = true;
						break;
					}
				}
				if (person_exsit)
				{
					person_exsit = false;
					break;
				}
				//����� ���� �� ���� ����� ���� ���� ��� ����� ����� ���� ����� ����� ����
				//��� ������ ���� �����
				//����� ���� ���� ������ �� ����� ����
				//����� ����� ����� ������ �����
				Person **help = new Person*[qaun_all_persons + 1];
				for (int i = 0; i < qaun_all_persons; i++)
					help[i] = all_persons[i];
				help[qaun_all_persons] = new Manager(first_name, last_name, ID, seniority);
				delete[]all_persons;
				all_persons = help;
				qaun_all_persons += 1;
			}
			break;
		case 5:
			//����� ������ �����
			//���� ���� ������� ���� ���� ���� ����� ����� ���� ����
			cout << "Hello, please enter Secretary details:\n";
			cout << "First name: ";
			cin >> first_name;
			cout << "Last name: ";
			cin >> last_name;
			cout << "ID: ";
			cin >> ID;
			cout << "Years of Seniority: ";
			cin >> seniority;
			cout << "how many children in school?";
			cin >> children;
			//����� ���� ����� ����� ������� ����� ��� ������ ������ ����� ����� ������
			if (!qaun_all_persons)
			{
				all_persons = new Person*[1];
				all_persons[0] = new Secretary(first_name, last_name, ID, seniority, children);
				qaun_all_persons += 1;
			}
			//����� ������� ����� ����� ������ ����� �� �� ����� ���� ����� ��� ���� �� ��� �����
			//����� ��� ����� ����� ������ �������� �� ����� �����
			else
			{
				for (int i = 0; i < qaun_all_persons; i++)
				{
					if (all_persons[i]->get_id() == ID)
					{
						cout << "Person already exsit\n";
						person_exsit = true;
						break;
					}
				}
				if (person_exsit)
				{
					person_exsit = false;
					break;
				}
				//����� �������� �� ����� ����� ���� ���� ��� ����� ����� ���� ����� ����� ����
				//��� ������ ����� �������
				//����� ���� ���� ������ �� ����� ����
				//����� ����� ����� ������ �����
				Person **help = new Person*[qaun_all_persons + 1];
				for (int i = 0; i < qaun_all_persons; i++)
					help[i] = all_persons[i];
				help[qaun_all_persons] = new Secretary(first_name, last_name, ID, seniority, children);
				delete[]all_persons;
				all_persons = help;
				qaun_all_persons += 1;
			}
			break;
		case 6:
			//����� �� �� ���� ������ ������� ����� ��� ����
			//�������, ������ ���
			for (int i = 0; i < qaun_all_persons; i++)
				all_persons[i]->print();
			break;
		case 7:
			//����� �� �� ������ ���������
			//����� �� ����� �������� ���� ������ ���������
			cout << "Out Standing list:\n";
			for (int i = 0; i < qaun_all_persons; i++)
			{
				if (all_persons[i]->Outstanding())
					all_persons[i]->print();
			}
			break;
		case 8:
			//����� ���� ���� ��� ����� ���
			//���� ����� ���� �� �����
			cout << "Hello , please enter Tutor id: ";
			cin >> ID;
			//����� ��� ���� ����� ��� �� ����� ���� ���
			//����� ����� ������ ����� ��� ��� ����
			//����� ���� �� ���� ����� ����� ������
			//����� ���� ��� ���� ����� ����� ���� ����� ��� ���� ���� �������� ������� �����
			for (int i = 0; i < qaun_all_persons; i++)
			{
				if (all_persons[i]->get_id() == ID)
				{
					Tutor *st = dynamic_cast<Tutor*>(all_persons[i]);
					if (st != NULL)
						st->print_class_info();
					else
						cout << "The ID is not belong to Tutor\n";
					break;
				}
			}
			break;
		case 9:
			//����� ���� ���� �� ������ ��� ��� �� ������� ��� �����
			//����� ��� ������ ��� ������� ��� �����
			for (int i = 0; i < qaun_all_persons; i++)
			{
				if (max < all_persons[i]->paycheck())
					max = all_persons[i]->paycheck();
			}
			//����� ������ ����� ��� �� �� ������� ��� ����� ������ �����
			//����� ������ ����� ��� ����� ����� �� ���� ������ (���� ��� �����) ���� ����� �� ����� �� �����
			cout << "Worker details with the biggest salary is:\n\n";
			for (int i = 0; i < qaun_all_persons; i++)
			{
				if (max == all_persons[i]->paycheck() && max != 0)
					all_persons[i]->print();
			}
			break;
		case 10://��� ����
			system("cls");
			cout << "Have a Great Day :)\n";
			break;
		default: system("cls"); cout << "Try again\n";
		}
	} while (choice != 10);
}