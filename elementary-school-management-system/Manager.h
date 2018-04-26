#ifndef _MANAGER
#define _MANAGER
#include "Worker.h"
//הכררזה על מחלקת "מנהל" היורשת ממחלקת "עובד כללי" ועל מתודות רלוונטיות

class Manager :public Worker{
public:
	//בנאי ממומש מקבל משתנים רלוונטים
	Manager(string n, string ln, int i, int s) :Worker(n, ln, i, s){}
	~Manager();
	//מתודה המחזירה משכורת על פי נוסחת ספציפית המתאימה למנהל
	virtual float paycheck(){ return (basis * 2 + get_seniority() * 500); }
	//מתודה בוליאנית בודקת האם המנהל מצטיין על פי דרישות ספציפיות
	virtual bool Outstanding(){ return get_seniority() > 3; }
	//מתודה המדפיסה את פרטיו של המנהל כולל משכורת וותק
	virtual void print(){ cout << "Manager information:\n";  Worker::print(); }
};
#endif
