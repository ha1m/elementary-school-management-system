#include "Layer.h"
//����� �����
Layer::Layer(char name) :Layer_name(name)
{
	quan_class = 3;
	class_of_layer = new Class*[3];
}

Layer::~Layer()
{
	delete[]class_of_layer;
}
//����� ������ ���� ������� ����� ����� ������ ������ ����� ���
Class *Layer::which_class(int num)
{
	return class_of_layer[num-1];
}