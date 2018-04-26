#ifndef _LAYER
#define _LAYER
//הכלה נחוצה
#include "Class.h"
//הכרזה על מחלקת "שכבה" ועל משתנים +מתודות רלוונטיות
class Layer{
	char Layer_name;
	Class **class_of_layer;
	int quan_class;
public:
	Layer(char);
	~Layer();
	Class *which_class(int num);
};
#endif