#ifndef _CLASS
#define _CLASS
//הכלה של מחלקות נחוצות
#include "Pupil.h"
#include "Tutor.h"
//הכרזה על מחלקת "כיתה" ועל כל משתניה הרלוונטים + מתודות לפי הצורך
class Class{
	char Layer_name;
	int num_of_class;
	Pupil **pupil;
	int Quan_pupil;
	Tutor *tutor;
public:
	Class(){ Quan_pupil = 0; tutor = NULL; pupil = NULL; }
	Class(char, int);
	~Class();
	bool Add(Pupil *p);
	Pupil *index(int index);
	//מתודה שהוספתי בודקת האם המחנך של הכיתה הוא מצטיין
	bool tutor_is_excellent();
	//הדפסת סטודנטים הלומדים בכיתה
	void print_students();
	//קליטה של שכבה
	void set_layer(char l){ Layer_name = l; }
	//קליטה של כיתה
	void set_class(int c){ num_of_class = c; }
	//מחזירה שכבה
	char get_layer(){ return Layer_name; }
	//מחזירה כיתה
	int get_class(){ return num_of_class; }
	//מתודה המקבלת מצביע למחנך וקושרת אותו לכיתה
	void Add_tutor(Tutor *t);
	//מתודה הבודקת האם קיים מחנך לכיתה
	bool tutor_exsit(){ return tutor!=NULL; }
};
#endif