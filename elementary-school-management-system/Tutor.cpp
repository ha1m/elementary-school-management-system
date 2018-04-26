#include "Tutor.h"
#include "Class.h"
//מתודה המחזירה משכורת של מחנך על פי נוסחה המתאימה לו
float Tutor::paycheck()
{
	return Teacher::paycheck() + 1000;
	
}
//מתודה הבודקת האם המחנך הוא מצטיין על פי פרמטרים ספצייפים
bool Tutor::Outstanding()
{
	//הבדיקה נעשה על ידי פונקציה אחרת הנמצאת בתוך מחלקה של "כיתה" ששייכת למחנך
	if (c)
	if (c->tutor_is_excellent())
		return true;
	else return false;

}
//פונקציה המדפיסה את פרטי התלמידים הלומדים בכיתה של המחניך
//הפונקציה מופעלת על ידי פונקציה נוספת שנמצאת בתוך המחלקה של "כיתה" ששייכת למחנך
void Tutor::print_students()
{
	if (c)
	c->print_students();
}
//הדפסת פרטי המחנך כולל איזה כיתה הוא מלמד באיזה שכבה
//כמו כן הדפסה של הסטודנטים/תלמידים הלומדים בכיתתו
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
//הדפסת פרטי כיתה של המחנך כולל תלמידים הלומדים שם
void Tutor::print_class_info()
{

	cout << "Tutor of class number: " << c->get_class() << endl;
	cout << "in Layer: " << c->get_layer() << endl;
	cout << "List of students in class:\n";
	c->print_students();

}