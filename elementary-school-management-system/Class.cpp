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
//מתודה המקבלת מצביע מסוג "תלמיד" ומוסיפה אותו לכיתה
bool Class::Add(Pupil *p)
{
	//במידה ולא קיימים תלמידים וזהו התלמיד הראשון הוא נוסף לתא הראשון במערך התלמידים
	if (!Quan_pupil)
	{
		pupil = new Pupil*[1];
		pupil[0] = p;
		Quan_pupil += 1;
		return true;
	}
	//במידה וקיימים תלמידים בכיתה נוצר מערך חדש בגודל המתאים (+1) אליו מועתק המערך הישן ובתא האחרון מוכנס התלמיד החדש
	//מתבצע עדכון של כמות התלמידים
	//מתבצעת מחיקה למערך המקורי והצבעה מחדש למערך החדש
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
//מתודה המקבלת אינדקס ומחזירה את התלמיד הנמצא במערך באינדקס הנל
Pupil *Class::index(int index)
{
	return pupil[index];
}
//מתודה בוליאנית הבודקת האם המחנך של הכיתה מצטיין
bool Class::tutor_is_excellent()
{
	int cnt = 0;
	//בדיקה בלולאה את כמות התלמידים המצטיינים בכיתה
	for (int i = 0; i < Quan_pupil; i++)
	{
		if (pupil[i]->Outstanding())
			cnt++;
	}
	//במידה וכמות התלמידים המצטינים בכיתה גדול מ50 אחוז מוחזר ערך אמת
	if (cnt > Quan_pupil / 2)
	{
		tutor->print();
		return true;
	}
	else return false;
}
//מתודה המדפיסה את פרטי התלמידים הלומדים בכיתה
//במידה ויש תלמיד מצטיין יש הודעה על כך בהתאם
void Class::print_students()
{
	for (int i = 0; i < Quan_pupil; i++)
	{
		pupil[i]->print();
		if (pupil[i]->Outstanding())
			cout << "This Student is Out Standing!!" << endl;
	}
}
//מתודה המשייכת מחנך לכיתה
//מקבלת מצביע למחנך של הכיתה
void Class::Add_tutor(Tutor *t)
{
	tutor = t;
}



