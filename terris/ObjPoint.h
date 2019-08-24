
#include <iostream> // cout
#include "Rect.h" 

using namespace std;
#pragma once
class ObjPoint
{
public:
	ObjPoint(void);// 預設建構元
	ObjPoint(const int x, const int y); // 建構元
	ObjPoint operator+(const ObjPoint &rhs) const; // 計算兩個點的向量和
	// 判斷點是否在傳入的矩形區間內
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

