#ifndef _PERSON
#define _PERSON
#include <string>
#include <iostream>
using namespace std;
//הכרזה על מחלקה "בן אדם" שהיא מחלקה אבסטרקטית. בנוסף הוספתי למחלקה זו מתודה וירטואלית של משכורת לצרוך נוחות
//ובנוסף הוספתי מתודה וירטואלית המחזירה תעודת זהות של בן אדם
class Person{
	string name, last_name;
	int id;
public:
	Person(string n, string ln, int i) :name(n), last_name(ln), id(i){}
	//~Person();
	virtual void print(){ cout << "Name: " << name << "\nLast name: " << last_name << "\nID: " << id << endl; }
	virtual bool Outstanding() = 0;
	//מתודה וירטואלית המחזירה תעודת זהות
	virtual int get_id(){ return id; }
	//מתודה וירטואלית טהורה המחזירה משכורת
	virtual float paycheck()=0;

};
#endif