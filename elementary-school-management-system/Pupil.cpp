#include "Pupil.h"
//בנאי המפעיל את הבנאי של "בן אדם" וכמובן את הבנאי של "תלמיד" מקבל משתנים רלוונטים
Pupil::Pupil(string n, string ln, int i, int c, char l) :Person(n, ln, i), num_class(c), layer_name(l)
{
	grade = NULL;
	Quantity_grades = 0;
}

Pupil::~Pupil()
{
	if (grade)
		delete grade;
}
//מתודה המחזירה את מומצע הציונים של התלמיד
float Pupil::GPA()
{
	
	int sum = 0;
	for (int i = 0; i < Quantity_grades; i++)
	{
		sum += grade[i];
	}
	if (sum)
		return sum / Quantity_grades;
}
//מתודה בוליאנית על מנת לדעת האם התלמיד הינו מצטיין על פי דרישות ספציפיות
bool Pupil::Outstanding()
{
	for (int i = 0; i < Quantity_grades; i++)
	{
		if (grade[i] < 65)
			return false;
	}
	if (GPA()>85)
		return true;
	else return false;
}
//מתודה המדפיסה את הפרטים של הסטודנט , הציונים של הסטודנט, והמומצע שלו
void Pupil::print()
{
	cout << "Student information:\n";
	Person::print();
	cout << "Student class: " << num_class<<endl;
	cout << "Layer: " << layer_name << endl;
	cout << "Grades of Student: \n";
		for (int i = 0; i < Quantity_grades; i++)
		{
			cout << grade[i] << endl;
		}
		cout << "GPA of Student: " << GPA()<<endl;
}
//מתודה הקולטת ציונים לתוך מערך הציונים של הסטודנט
//כמובן כמות הציונים נקבעת על פי שכבת הכיתה בה לומד התלמיד
void Pupil::add_grade()
{
	char c = 'a';
	for (int j = 0; j < 6; j++)
	{
		if (layer_name == c++)
		{
			Quantity_grades = 5+j;
			grade = new int[Quantity_grades];
			cout << "Enter grades: " << endl;
			for (int i = 0; i < Quantity_grades; i++)
			{
				cout << "Grade " << i + 1 << ": ";
				cin >> grade[i];
				cout << endl;
			}
		}
	}



}