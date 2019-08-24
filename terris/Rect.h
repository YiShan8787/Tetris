

#include <iostream> // cout
using namespace std;
#pragma once
class ObjPoint;
class ObjObject;

class Rect
{
public:
	Rect(void);
	Rect(const int left, const int top, const int right, const int bottom); // �غc��
	bool const contains(ObjPoint &pt) ; // �P�_�O�_�]�t�ǤJ���I
	bool const contains( ObjObject &obj) ; // �P�_�O�_�]�t�ǤJ����Ӫ���
	void draw() ; // ø�s�x�Ϊ����
	virtual ~Rect(void);
private:
	int m_left;
	int m_top;
	int m_right;
	int m_bottom;
public:
	int get_right(void);
	int get_left(void);
	int get_top(void);
	int get_bottom(void);
private:
	
	int** m_array;
public:
	void save_array(ObjObject &obj);
	void draw_array(void);
	
	int** get_array(void);
	bool isLined(int y);
	void down(int y);
	int check_down(ObjObject& obj);
};

