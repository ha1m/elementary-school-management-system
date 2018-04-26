#ifndef _TUTOR
#define _TUTOR
#include "Teacher.h"
class Class;
//הכרזה של מחלקה של "מחנך" שהוא יורש של "מורה" כולל משתנים רלוונטים ומתודות לפי הצורך

class Tutor :public Teacher{
	Class *c;
public:
	//בנאי ממומש מקבל משתנים רלוונטים
	Tutor(string n, string ln, int i, int s) :Teacher(n, ln, i, s){}
	~Tutor();
	virtual float paycheck();
	virtual bool Outstanding();
	void print_students();
	virtual void print();
	//מתודה שהוספתי המקבלת מצביע מסוג כיתה ומשייכת אותו למורה
	void Add_class(Class *t){ c = t; }
	//מתודה שהוספתי המדפיסה את פרטי הכיתה בה המורה מלמד
	void print_class_info();


};
#endif
