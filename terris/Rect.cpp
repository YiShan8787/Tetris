#include "Rect.h"
#include "ObjPoint.h"
#include "ObjObject.h"
#include "utilwin32.h" // clrscr()
#include "graphics.h"

Rect::Rect(void)
	: m_left(0)
	, m_top(0)
	, m_right(0)
	, m_bottom(0)
	
	, m_array(NULL)
{
}

Rect::Rect(const int left, const int top, const int right, const int bottom):m_left(left)
	, m_top(top)
	, m_right(right)
	, m_bottom(bottom)
{
	m_array = new int*[(m_bottom-m_top)/20];
    for(int i = 0; i < m_bottom; i++)
        m_array[i] = new int[(m_right-m_left)/20];
	for(int i=0;i<(m_bottom-m_top)/20;i++)
		for(int j=0;j<(m_right-m_left)/20;j++)
			m_array[i][j]=0;
}

bool const Rect::contains(ObjPoint &pt) 
{
	if(pt.get_x()<m_right && pt.get_x()>=m_left)
		if(pt.get_y()<=m_bottom+m_top && pt.get_y()>=m_top)
			return true;
	
	return false;
}

bool const Rect::contains( ObjObject &obj)
{
	if(obj.get_bigX()<m_right)
		if(obj.get_smallX()>=m_left)
			if(obj.get_bigY()<=m_bottom+m_top)
				if(obj.get_smallY()>=m_top)
					return 1;
	return 0;
}

void Rect:: draw()    //對應的code   Rect canvas(orgX, orgY, orgX+width-1, orgY+height-1)  ???
{   //                         left  top    right          bottom

	rectangle(m_left-1, m_top-1, m_right+1, m_bottom+1);  //因為原本 | 跟 - 長度比至少是2以上，所以所乘上的數至少比率要相差2以上才為美觀
	
	/*int i;
    gotoxy(m_left-1, m_top-1);
    cout << '+';
    for (i=0; i<m_right; i++)
        cout << '-';
    cout << '+';

    for (i=0; i<m_bottom; i++)
    {
        gotoxy(m_left-1, m_top+i); cout << '|';
        gotoxy(m_left+m_right, m_top+i); cout << '|';
    }

    gotoxy(m_left-1, m_top+m_bottom);
    cout << '+';
    for (i=0; i<m_right; i++)
        cout << '-';
    cout << '+';
    gotoxy(1,23); // 把游標移動到視窗中固定的地方, */
}                 // 否則在畫面上會一直看到游標在不同地方閃啊閃的


Rect::~Rect(void)
{
	for(int i=0;i<m_bottom;i++)
		delete m_array[i];
	delete m_array;
}


int Rect::get_right(void)
{
	return m_right;
}


int Rect::get_left(void)
{
	return m_left;
}


int Rect::get_top(void)
{
	return m_top;
}


int Rect::get_bottom(void)
{
	return m_bottom;
}


void Rect::save_array(ObjObject &obj)   //obj.get_obj會有問題
{
	int *a;
	//a=new int[8]; 
	a=obj.get_obj();
	for(int i=0;i<4;i++)
	{
		m_array[(*(a+i*2+1)-m_top)/20][(*(a+i*2)-m_left)/20]=obj.get_ch();
		
	}

}


void Rect::draw_array(void)
{
	for(int i=0;i<(m_bottom-m_top)/20;i++)
	{
		for(int j=0;j<(m_right-m_left)/20;j++)
		{
			if(m_array[i][j])
			{
				setfillstyle(SOLID_FILL, m_array[i][j]); // 色
				bar(20*j+m_left, 20*i+m_top, 20*j+m_left+20, 20*i+m_top+20); // left, top, right, bottom
				setcolor(WHITE); // 色
				rectangle(20*j+m_left, 20*i+m_top, 20*j+m_left+20, 20*i+m_top+20); // left, top, right, bottom
			}
			else
			{
				/*gotoxy(j+m_left,i+m_top);
				cout<<' ';*/
				setfillstyle(SOLID_FILL, BLACK); // 黑色
				bar(20*j+m_left, 20*i+m_top, 20*j+m_left+20, 20*i+m_top+20); // left, top, right, bottom
			}
				
				
		}
	}

}




int** Rect::get_array(void)
{
	return m_array;
}


bool Rect::isLined(int y)
{
	int check=0;
	for(int i=0;i<(m_right-m_left)/20;i++)
		if(m_array[y][i])
			check++;
	if(check>=(m_right-m_left)/20)
		return 1;
	return false;
}


void Rect::down(int y)
{
	for(int j=0;j<m_right/20;j++)
		m_array[y][j]=0;
	for(int i=y;i>0;i--)
		for(int j=0;j<m_right/20;j++)
			m_array[i][j]=m_array[i-1][j];
}


int Rect::check_down(ObjObject& obj)
{
	int*a;
	int check=0;
	a=obj.get_obj();
	for(int i=0;i<4;i++)
	{
		if(isLined((*(a+i*2+1)-m_top)/20)){
			down((*(a+i*2+1)-m_top)/20);
			check++;
		}
	}
	if(check>0)
		return check;
	return 0;
}
