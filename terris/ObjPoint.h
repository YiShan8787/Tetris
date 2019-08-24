
#include <iostream> // cout
#include "Rect.h" 

using namespace std;
#pragma once
class ObjPoint
{
public:
	ObjPoint(void);// �w�]�غc��
	ObjPoint(const int x, const int y); // �غc��
	ObjPoint operator+(const ObjPoint &rhs) const; // �p�����I���V�q�M
	// �P�_�I�O�_�b�ǤJ���x�ΰ϶���
	virtual ~ObjPoint(void);
	bool const isInside( Rect & Rect);
	ObjPoint  const operator+(const ObjPoint & rhs);
	ObjPoint  const operator-(const ObjPoint & rhs);
private:
	int m_x;
	int m_y;
public:
	int get_x(void);
	int get_y(void);
	bool change_x(Rect & Rect);
	bool change_y(Rect& Rect);
	bool const isCrashed(Rect& rect);
	void rotate(void);
};

