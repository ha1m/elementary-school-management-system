#ifndef _TEACHER
#define _TEACHER
//#include "Person.h"
#include "Worker.h"
//הכרזה על מחלקת "מורה" היורשת ממחלקת "עובד כללי" ועל כל המשתנים הרלוונטים והמתודות
//הוספתי מתודה שתפקידה להוסיף מקצועות לרשימת המקצועות של המורה
class Teacher :public Worker{
	string *profession_name;
	int quan_professions;
public:
	Teacher(string n, string ln, int i, int s);
	~Teacher();
	virtual float paycheck();
	virtual bool Outstanding();
	void print_professions()const;
	virtual void print();
	//מתודה המוסיפה מקצועות לרשימת המקצועות שהמורה מלמד
	void add_profession();

};
#endif