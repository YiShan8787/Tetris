

#include <iostream> // cout
using namespace std;
#pragma once
class ObjPoint;
class ObjObject;

class Rect
{
public:
	Rect(void);
	Rect(const int left, const int top, const int right, const int bottom); // 建構元
	bool const contains(ObjPoint &pt) ; // 判斷是否包含傳入的點
	bool const contains( ObjObject &obj) ; // 判斷是否包含傳入的整個物件
	void draw() ; // 繪製矩形的邊界
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

