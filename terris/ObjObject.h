
#include <iostream> // cout
#include "ObjPoint.h" 
#include "Rect.h" 
#include "utilwin32.h" // clrscr()
using namespace std;
#pragma once
class ObjObject
{
public:
	ObjObject(void);
	ObjObject(const int face, const ObjPoint position, const ObjPoint data[4]); // 建構元
	bool move(const ObjPoint &offset,  Rect &boundary); // 移動 offset 位移
	bool const isInside( Rect &rect) ; // 檢查物件是否在矩形區域 rect 中
	void const draw(bool show=true) ; // 繪製 (true), 清除 (false)
	virtual ~ObjObject(void);
	
private:
	int m_ch;

	ObjPoint m_position;
	ObjPoint m_data[4];
public:
	int get_bigY(void);
	int get_bigX(void);
	int get_smallY(void);
	int get_smallX(void);
	bool reach_left(Rect& rect);
	bool reach_top(Rect& rect);
	bool reach_right(Rect& rect);
	bool reach_bot(Rect& rect);
	
	int change_move(const ObjPoint& offset, Rect& boundary);
	int* get_obj(void);
	int get_ch(void);
	bool const isCrashed(Rect& rect);
	void rotate(ObjPoint shape[4],Rect &boundary);
	void show_obj(int op=1);
};

