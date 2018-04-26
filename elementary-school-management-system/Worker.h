#ifndef _WORKER
#define _WORKER
#include "Person.h"
#define basis 5000
//הכרזה על מחלקת "עובד" היורשת ממחלקת "בן אדם" ס
//
class Worker :public Person{
	int seniority;
public:
	Worker(string n, string ln, int i, int s) :Person(n, ln, i), seniority(s){}
	//~Worker();
	//מתודה וירטואלית המדפיסה את פרטיו של העובד, משכורת שלו וותק שלו
	virtual void print(){ Person::print(); cout << "Salary: " << paycheck() << endl << "Seniority: " << seniority << endl; }
	//מתודה שהוספתי המחזירה את שנות הוותק של העובד
	int get_seniority(){ return seniority; }
};
#endif