#ifndef _LAYER
#define _LAYER
//���� �����
#include "Class.h"
//����� �� ����� "����" ��� ������ +������ ���������
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