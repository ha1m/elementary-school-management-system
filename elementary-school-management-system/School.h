#ifndef _SCHOOL
#define _SCHOOL
#include "Layer.h"
#include "Person.h"
//הכרזה על מחלקת בית ספר ועל משתנים +מתודות נחוצות
class School{
	Layer **layer_school;
	int qaun_layers;
	Person **all_persons;
	int qaun_all_persons;
	bool manager_exsit;
public:
	School();
	~School();
	void Menu();
};
#endif