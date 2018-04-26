#include "Teacher.h"
//בנאי המפעיל בנאי של "עובד כללי" וכמובן של מורה
//מקבלת משתנים רלוונטים
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
//מתודה המחזירה את המשכורת של המורה על פי נוסחה ספציפית המתאימה לו
float Teacher::paycheck()
{
	float x, y, paycheck;
	x = quan_professions;
	y = Teacher::get_seniority();
	paycheck = basis * (1 + x / 10) + 300 * y;
	return paycheck;
}
//מתודה בוליאנית כדי לדעת האם המורה מצטיין על פי פרמטרים ספציפים
bool Teacher::Outstanding()
{
	return(quan_professions > 5);
}
//מתודה המדפיסה את רשימת המקצועות שהמורה מלמד
void Teacher::print_professions()const
{
	cout << "Professions: \n";
	for (int i = 0; i < quan_professions; i++)
	{
		cout << profession_name[i] << endl;
	}
}
//מתודה המדפיסה את פרטיו של המורה כולל המקצועות שהוא מלמד
void Teacher::print()
{
	cout << "Teacher information:\n";
	Worker::print();
	print_professions();
}
//מתודה המוסיפה מקצועות לרשימת המקצועות של המורה
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