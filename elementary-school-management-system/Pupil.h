#ifndef _PUPIL
#define _PUPIL
#include "Person.h"
//הכרזה על מחלקת "תלמיד" היורשת ממחלקת "בן אדם" כ
//בנוסף הוספתי מתודות לפי צורך ונוחות
class Pupil :public Person{
	int *grade, Quantity_grades,num_class;
	char layer_name;
public:
	Pupil(string n, string ln, int i, int c, char l);
	~Pupil();
	float GPA();
	virtual bool Outstanding();
	virtual void print();
	//מתודה המוסיפה ציונים למערך הציונים של התלמיד
	void add_grade();
	//מתודה המחזירה 0 כיוון שהתלמיד לא מקבל משכורת אך היה צריך לממש את המתודה על מנת להשתמש בהמשך במתודה הנל בשאר המחלקות ובמיין
	virtual float paycheck(){ return 0; }

};
#endif