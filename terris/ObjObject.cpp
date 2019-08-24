#include "ObjObject.h"
#include "ObjPoint.h" 
#include <iostream> // cout
#include "graphics.h"
using namespace std;
ObjObject::ObjObject(void)
{
}

ObjObject::ObjObject(const int face, const ObjPoint position, const ObjPoint data[4]):m_ch(face),m_position(position)
{
	for(int i=0;i<4;i++)
		m_data[i]=data[i];
	for(int i=0;i<4;i++)
		m_data[i]=m_position+m_data[i];
}

bool ObjObject::move(const ObjPoint &offset,  Rect &boundary)
{
	ObjPoint temp[4];
	int check=1;
	for(int i=0;i<4;i++)
	{
		temp[i]=m_data[i]+offset;
		if(!temp[i].isInside(boundary) )
			check=0;
		else
		{
			if(temp[i].isCrashed(boundary))
				check=0;
		}
	}
	if(check)
	{
		draw(0);
		for(int i=0;i<4;i++)
			m_data[i]=temp[i];
		draw();
		gotoxy(1,23);
		return 1;
	}
	else
		return 0;
}

bool const ObjObject::isInside( Rect &rect)
{
	if(get_bigX()<rect.get_right())
		if(get_smallX()>=rect.get_left())
			if(get_bigY()<=rect.get_bottom()+rect.get_top())
				if(get_smallY()>=rect.get_top())
					return 1;
	return 0;
}

void const ObjObject::draw(bool show)
{
	if(show==0) 
	{
		for(int i=0;i<4;i++)
		{
			setfillstyle(SOLID_FILL, BLACK); // 黑色
			bar(m_data[i].get_x(), m_data[i].get_y(), m_data[i].get_x()+20, m_data[i].get_y()+20); // left, top, right, bottom
			setcolor(BLACK); // 黑色
			rectangle(m_data[i].get_x(), m_data[i].get_y(), m_data[i].get_x()+20, m_data[i].get_y()+20); // left, top, right, bottom
		}
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			//gotoxy(m_data[i].get_x(),m_data[i].get_y());get
			//cout << m_ch;
			setfillstyle(SOLID_FILL, m_ch); // 色
			bar(m_data[i].get_x(), m_data[i].get_y(), m_data[i].get_x()+20, m_data[i].get_y()+20); // left, top, right, bottom
			setcolor(WHITE); // 色
			rectangle(m_data[i].get_x(), m_data[i].get_y(), m_data[i].get_x()+20, m_data[i].get_y()+20); // left, top, right, bottom
			
		}
	}
		
}

ObjObject::~ObjObject(void)
{
}





int ObjObject::get_bigY(void)
{
	int big=0;
	for(int i=0;i<4;i++)
		m_data[i].get_y()>big? big=m_data[i].get_y():0;
	return big;
}


int ObjObject::get_bigX(void)
{
	int big=0;
	for(int i=0;i<4;i++)
		m_data[i].get_x()>big? big=m_data[i].get_x():0;
	return big;
	
}


int ObjObject::get_smallY(void)
{
	int s;
	s=m_data[0].get_y();
	for(int i=0;i<4;i++)
		m_data[i].get_y()<s? s=m_data[i].get_y():0;
	return s;
}


int ObjObject::get_smallX(void)
{
	int s=m_data[0].get_x();
	for(int i=0;i<4;i++)
		m_data[i].get_x()<s? s=m_data[i].get_x():0;
	return s;
}


bool ObjObject::reach_left(Rect& rect)
{
	if(get_smallX()<rect.get_left())
		return 1;
	return false;
}


bool ObjObject::reach_top(Rect& rect)
{
	if(get_smallY()<rect.get_top())
		return 1;
	return false;
}


bool ObjObject::reach_right(Rect& rect)
{
	if(get_bigX()>=rect.get_right()+rect.get_left())
		return 1;
	return false;
}


bool ObjObject::reach_bot(Rect& rect)
{
	if(get_bigY()>rect.get_bottom()+rect.get_top())
		return 1;
	return false;
}





int ObjObject::change_move(const ObjPoint& offset, Rect& boundary)
{
	ObjPoint temp[4];
	int check_x=0,check_y=0;
	for(int i=0;i<4;i++)
	{
		temp[i]=m_data[i]+offset;
		if(temp[i].change_x(boundary))
			check_x=1;
		if(temp[i].change_y(boundary))
			check_y=1;
		
	}

	if(check_x)
		return 0;
	if(check_y)
		return -1;
	for(int i=0;i<4;i++)
	{
		draw(0);
		m_data[i]=temp[i];
		draw();
		gotoxy(1,23);
	}
	return 1;
}


int* ObjObject::get_obj(void)
{
	int static a[8];
	for(int i=0;i<4;i++)
	{
		a[i*2]=m_data[i].get_x();
		a[i*2+1]=m_data[i].get_y();
	}
		
	return a;
}


int ObjObject::get_ch(void)
{
	return m_ch;
}


bool const ObjObject::isCrashed(Rect& rect)
{
	int **arr;
	
	arr=rect.get_array();
	for(int i=0;i<4;i++)
	{
		if(arr[(m_data[i].get_y()-rect.get_top())/20][(m_data[i].get_x()-rect.get_left())/20])   //若陣列內有東西
		{
			for(int i=0;i<(rect.get_bottom()-rect.get_top())/20;i++)
				delete arr[i];
			delete arr;
			return 1;      //回傳有碰撞
		}
	}
	for(int i=0;i<(rect.get_bottom()-rect.get_top());i++)
		delete arr[i];
	delete arr;
	return NULL;
}


void ObjObject::rotate(ObjPoint shape[4],Rect & boundary)
{
	ObjPoint t[4];
	ObjPoint s[4];
	int check=1;
	for(int i=0;i<4;i++)
	{
		t[i]=m_data[i];
		s[i]=shape[i];
		t[i]=t[i]-s[i];
		s[i].rotate();
		t[i]=t[i]+s[i];
		if(!t[i].isInside(boundary) )
			check=0;
		
	}

	if(check){
	draw(0);
	ObjPoint *temp=shape;
	for(int i=0;i<4;i++)
	{
		m_data[i]=m_data[i]-shape[i];
		shape[i].rotate();
		m_data[i]=m_data[i]+shape[i];
	}
	draw(1);
	}
	
}


void ObjObject::show_obj(int op)
{

	ObjPoint temp[4];
	for(int i=0;i<4;i++)
	{
		temp[i]=m_data[i]+ObjPoint(-250,0);
	}
	for(int i=0;i<3;i++)
		for(int j=0;j<5;j++)
		{
			setfillstyle(SOLID_FILL, BLACK); // 黑色
			bar(i*20, j*20, i*20+20, j*20+20); // left, top, right, bottom
			setcolor(BLACK); // 黑色
			rectangle(i*20, j*20, i*20+20, j*20+20); // left, top, right, bottom
		}

	ObjObject test(m_ch,ObjPoint(0,0),temp);
	if(op)
		test.draw();
	else
		test.draw(0);
}
