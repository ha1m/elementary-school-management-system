#ifndef _SECRETARY
#define _SECRETARY
#include "Worker.h"
//הכרזה על מחלקת "מזכירה" היורשת ממחלקת "עובד כללי" והכרזה על משתנים ומתודות רלוונטיות
class Secretary :public Worker{
	int quan_children_in_school;
public:
	//מימוש הבנאי. מקבל משתנים רלוונטים
	Secretary(string n, string ln, int i, int s, int children) :Worker(n, ln, i, s), quan_children_in_school(children){}
	~Secretary();
	//מתודה המחזירה את המשכורת של המזכירה על פי נוסחה המתאימה לה
	virtual float paycheck(){ return (basis + quan_children_in_school* 200); }
	//מתודה בוליאנית הבודקת האם המזכירה מצטיינת על פי דרישות ספיצפיות
	virtual bool Outstanding(){ return get_seniority() > 10; }
	//מתודה המדפיסה את פרטיה של המזכירה כולל משכורת ווותק
	virtual void print(){ cout<<"Secretary information:\n"; Worker::print(); }
};
#endif