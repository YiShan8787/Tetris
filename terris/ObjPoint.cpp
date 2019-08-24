#include "ObjPoint.h"
#include <iostream> // cout
using namespace std;

ObjPoint::ObjPoint(void)
	: m_x(0)
	, m_y(0)
{
}

ObjPoint::ObjPoint(const int x, const int y):m_x(x),m_y(y)
{
}



ObjPoint::~ObjPoint(void)
{
}




bool const ObjPoint::isInside( Rect & Rect)
{
	if(m_x<Rect.get_right() && m_x>=Rect.get_left())
		if(m_y>=Rect.get_top() && m_y<Rect.get_bottom())
			return 1;
	return NULL;
}


ObjPoint const ObjPoint::operator+(const ObjPoint & rhs)
{
	return ObjPoint(m_x+rhs.m_x,m_y+rhs.m_y);
}

ObjPoint const ObjPoint::operator-(const ObjPoint & rhs)
{
	return ObjPoint(m_x-rhs.m_x,m_y-rhs.m_y);
}


int ObjPoint::get_x(void)
{
	return m_x;
}


int ObjPoint::get_y(void)
{
	return m_y;
}


bool ObjPoint::change_x(Rect & Rect)
{
	if(!(m_x<Rect.get_right()+Rect.get_left() && m_x>=Rect.get_left()))
		return 1;
	return false;
}


bool ObjPoint::change_y(Rect& Rect)
{
	if(!(m_y>=Rect.get_top() && m_y<Rect.get_bottom()+Rect.get_top()))
			return 1;
	return false;
}


bool const ObjPoint::isCrashed(Rect& rect)
{
	int **arr;
	/*arr = new int*[rect.get_bottom()];
	for(int i = 0; i < rect.get_bottom(); i++)
		arr[i] = new int[rect.get_right()];*/
	arr=rect.get_array();
	/*for(int i=0;i<4;i++)          //測試回傳指標2維陣列
		for(int j=0;j<4;j++)
			cout<<arr[i][j];*/
	for(int i=0;i<4;i++)
	{
		if(arr[(m_y-rect.get_top())/20][(m_x-rect.get_left())/20])   //若陣列內有東西
		{
			/*for(int i=0;i<rect.get_bottom();i++)
				delete arr[i];
			delete arr;*/
			return 1;      //回傳有碰撞
		}
	}
	/*for(int i=0;i<rect.get_bottom();i++)
		delete arr[i];
	delete arr;*/
	return NULL;
	return NULL;
}


void ObjPoint::rotate(void)
{
	int a=m_x,b=m_y;
	m_x=-m_y;
	m_y=a;
}
