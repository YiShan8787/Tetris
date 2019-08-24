#include "utilwin32.h" // clrscr()
#include "ObjPoint.h" 
#include "Rect.h" 
#include "ObjObject.h" 
#include <stdlib.h> // system()
#include <iostream> // cout
#include <cassert>
#include <conio.h> // kbhit(), getch()
#include <iomanip>  // setw(), hex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.h"
using namespace std;




int main()
{
	 initwindow(1200, 800, "First Sample");
	 
	srand( (unsigned)time(NULL) );
	int orgX=5,orgY=1,width=20,height=30,x,y;
	int initial_x=20,initial_y=20;
	//setfillstyle(SOLID_FILL, RED); // 紅色
	//bar(120, 150, 140, 170); // left, top, right, bottom
    //clrscr();      //1. 清除螢幕

	//drawBoundary(10,5,25,16);    // 2.1  (orgX=10, orgY=5) 是遊戲畫面的左上角, (orgX+width-1, orgY+height-1) 是遊戲畫面的右下角

	//gotoxy(2,3);        // 2.2    印z在(2,3)位置
    //cout << 'z';


								//3.   文字掉落界面
	/*clrscr();                  //3.   文字掉落界面
    drawBoundary(orgX, orgY, width, height);

    x=orgX+width/2;
    gotoxy(x,orgY), cout << "#";
    for (y=orgY; y<orgY+height-1; y++)
    {
        delay(300); // 每次移動之間間隔 0.3 秒 (300毫秒)
        gotoxy(x,y), cout << " "; // 移動到下一個座標前先清除原來的文字
        gotoxy(x,y+1), cout << "#";
    }
    gotoxy(1,23);*/
   


							//3.     額外程式碼
	/*clrscr();               //3.     額外程式碼
    drawBoundary(orgX, orgY, width, height);
    x=orgX+width/2-1;
    gotoxy(x,orgY), cout << "*";
    for (y=orgY; y<orgY+height-1; y++)
    {
        delay(200);
        gotoxy(x,y+1), cout << "*";
        delay(100);
        gotoxy(x,y), cout << " ";
    }
    gotoxy(1,23);*/
    
	 
     Rect canvas(orgX*initial_x, orgY*initial_y, (width-1)*initial_x, (height-1)*initial_y);

    clrscr();
    canvas.draw();
	int score=0;
	int speed=200;
	gotoxy(orgX+width,orgY+height);
	cout<<"your score is "<<score;
	int c_choose=rand()%4;
	int current_c[4]={RED,YELLOW,BLUE,GREEN};
	int current_choose=rand()%4;
	ObjPoint shape[4] = { ObjPoint(-1*initial_x,0), ObjPoint(0,0), //7字
                             ObjPoint(0,1*initial_y), ObjPoint(0,2*initial_y) };
	 ObjPoint shape1[4] = { ObjPoint(0,0), ObjPoint(0,1*initial_y), //直線
                             ObjPoint(0,2*initial_y), ObjPoint(0,3*initial_y) };
	 ObjPoint shape2[4] = { ObjPoint(-1*initial_x,0), ObjPoint(-1*initial_x,1*initial_y), //閃電
                             ObjPoint(0,1*initial_y), ObjPoint(0,2*initial_y) };
	 ObjPoint shape3[4] = { ObjPoint(-1*initial_x,0), ObjPoint(-1*initial_x,1*initial_y),   //方塊
                             ObjPoint(0,0), ObjPoint(0,1*initial_y) };
	 ObjPoint current[4];
	 switch(current_choose){
		 case 0:
			 for(int i=0;i<4;i++)
				 current[i]=shape[i];
			 break;
		 case 1:
			 for(int i=0;i<4;i++)
				 current[i]=shape1[i];
			 break;
		 case 2:
			 for(int i=0;i<4;i++)
				 current[i]=shape2[i];
			 break;
		 case 3:
			 for(int i=0;i<4;i++)
				 current[i]=shape3[i];
			 break;
	 }
	 ObjPoint rotate[4];
	 ObjObject obj(current_c[rand()%4], ObjPoint((orgX+width/2-1)*initial_x,orgY*initial_y), current);
	//這要+while
	 int check_rotate=1;
	 int check_next=0;
	while(1){
	int temp_c[4]={RED,YELLOW,BLUE,GREEN};
	int choose=rand()%4;
     
	 ObjPoint temp[4];
	 
	 if(check_rotate==1)
		 for(int i=0;i<4;i++)
			 rotate[i]=current[i];
	 switch(choose){
		 case 0:
			 for(int i=0;i<4;i++)
				 temp[i]=shape[i];
			 break;
		 case 1:
			 for(int i=0;i<4;i++)
				 temp[i]=shape1[i];
			 break;
		 case 2:
			 for(int i=0;i<4;i++)
				 temp[i]=shape2[i];
			 break;
		 case 3:
			 for(int i=0;i<4;i++)
				 temp[i]=shape3[i];
			 break;
	 }
    ObjObject next(temp_c[rand()%4], ObjPoint((orgX+width/2-1)*initial_x,orgY*initial_y), temp);
	
	//要用m_array去存最後落下的位置(Rect內已寫好)
    //assert(obj.isInside(canvas));

    obj.draw();
	gotoxy((orgX+width)/2-3,orgY/2);
	cout<<"press p to stop"<<endl;
	gotoxy((orgX+width)/2-3,orgY/2+1);
	cout<<"press esc to exit";
	gotoxy(orgX+width,orgY);
	cout<<"press ← → to move left or right";
	gotoxy(orgX+width,orgY+1);
	cout<<"press ↑ to rotate object";
	gotoxy(orgX+width,orgY+2);
	cout<<"press ↓ to move object to bottom";
	gotoxy(orgX+width,orgY+3);
	cout<<"press d/s to show/clear the next object";
	gotoxy(orgX+width,orgY+4);
	cout<<"press v/b to increase/decrease the speed";
	
	
	char s_score[50]="0";
	int num;
	int temp_score=score;
	int set[100];
	for(num=0 ;temp_score>0;num++)
	{
		set[num]=temp_score%10;
		temp_score/=10;
	}
	int z=0;
	for(int i=num-1;i>=0;i--)
	{
		s_score[z]=set[i]+48;
		z++;
	}
	if(score!=0)
	s_score[num]='\0';

	outtextxy(width*initial_x,orgY/2,"press ← → to move left or right" );
	outtextxy(width*initial_x,orgY/2+20,"press ↑ to rotate object" );
	outtextxy(width*initial_x,orgY/2+40,"press ↓ to move object to bottom" );
	outtextxy(width*initial_x,orgY/2+60,"press d/s to show/clear the next object" );
	outtextxy(width*initial_x,orgY/2+80,"press v/b to increase/decrease the speed" );
	outtextxy(width*initial_x,height*initial_y,"your score is " );
	setfillstyle(SOLID_FILL, BLACK); // 黑色
	bar(width*initial_x+100, height*initial_y, width*initial_x+100+20, height*initial_y+20); // left, top, right, bottom

	outtextxy(width*initial_x+100,height*initial_y,s_score );
	int test_x=0,test_y=1,save=0;
	while(obj.move(ObjPoint(test_x*initial_x,test_y*initial_y),canvas)){
		
		
	/*switch(obj.change_move(ObjPoint(test_x,test_y), canvas)){
		case 0:
			test_x=-test_x;
			break;
		case -1:
			test_y=-test_y;
			break;
		case 1:
			break;

	}*/
		int c=-1, d=-1;
		if(check_next){
			next.show_obj(0);
			next.show_obj();
		}
		else
			next.show_obj(0);
		if (kbhit()) 
        {
           if ((c=getch()) == 0xe0 || c == 0) // 數字鍵或是←→↓↑方向按鍵 
				d = getch();                   // 按下時會得到 0xe0 或是 0x00
			cout << "c=" << setw(2) << hex << c 
			<< "  d=" << setw(2) << hex << d // 第二次 getch() 可以 
			<< endl;                         // 得到實際按鍵的掃描碼
			if(d==0x4d)                      //左
				if(obj.move(ObjPoint(1*initial_x,0), canvas))
					;
			if(d==0x4b)                     //右
				if(obj.move(ObjPoint(-1*initial_x,0), canvas))
					;
			if(d==0x50)                     //下
				while(obj.move(ObjPoint(0,1*initial_y),canvas))   
					;
			if(d==0x48)                 //上
				obj.rotate(rotate,canvas);           //要減掉原本的shape，再+上rotate過的shape
			if(d==0xffffffff &&  c==0x1b){    //esc
				gotoxy(1,23); system("pause");return 0;}
			if(d==0xffffffff && c==0x73)    //s偷看
			{
				check_next=1;
			}
			if(d==0xffffffff && c==0x64)    //d清除偷看
			{
				check_next=0;
			}
			if(d==0xffffffff && c==0x76)    //d加速
			{
				speed/=2;
			}
			if(d==0xffffffff && c==0x62)    //d減速
			{
				speed*=2;
			}
			if(d==0xffffffff && c==0x70)     //p
				while(1)
				{
					if ((c=getch()) == 0xe0 || c == 0) // 數字鍵或是←→↓↑方向按鍵 
						d = getch();                   // 按下時會得到 0xe0 或是 0x00
					//cout << "c=" << setw(2) << hex << c 
					//<< "  d=" << setw(2) << hex << d // 第二次 getch() 可以 
					//<< endl;                         // 得到實際按鍵的掃描碼
					if(d==0xffffffff && c==0x70)
						break;
				}


        }
        delay(speed);
		save++;
		
	}
	
	if(save>0)
	{
		canvas.save_array(obj);
		int s=canvas.check_down(obj);
		if(s>0)
		{
			canvas.draw_array();
			score+=s;
			gotoxy(25,25);
			cout<<"your score is "<<score;
		}
	}
	else
		break;
	check_rotate++;
	if(check_rotate>1)
		for(int i=0;i<4;i++)
			rotate[i]=temp[i];
	obj=next;
	}
    gotoxy(1,23); system("pause");



    
}



