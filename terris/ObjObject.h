
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
	ObjObject(const int face, const ObjPoint position, const ObjPoint data[4]); // �غc��
	bool move(const ObjPoint &offset,  Rect &boundary); // ���� offset �첾
	bool const isInside( Rect &rect) ; // �ˬd����O�_�b�x�ΰϰ� rect ��
	void const draw(bool show=true) ; // ø�s (true), �M�� (false)
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

