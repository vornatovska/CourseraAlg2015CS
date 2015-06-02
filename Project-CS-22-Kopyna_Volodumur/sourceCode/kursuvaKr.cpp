#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <time.h>
#include "Time.h"
#include "Reminder.h"

using namespace std;


#define n 4
FILE *f;


struct structTime{
	int day;
	int month;
	int year;
	int hour;
	int minute;
	char coment[128];
}tm;




class TimeNow 
{
protected:
		time_t t;
		struct tm *t_m;
public:
	void now()
	{		
		time_t t;
		struct tm *t_m;
		t=time(NULL);
		t_m=localtime(&t);
		cout<<"Local time is: "<<t_m->tm_year + 1900<<"  "<<t_m->tm_mon+1<<", "<<t_m->tm_mday<<" - "<<t_m->tm_hour<<":"<<t_m->tm_min<<":"<<t_m->tm_sec<<endl;					
	}
};



void Menu(int,int); 
int Menu1(int,int); 
int Menu1_1(int,int);
int c=0,q=-1;         
vector <string> menu;
vector <vector <string>> menu2;








class MMenu 
{
public:
	int s;
	int g;
	MMenu(int _s,int _g)
	{
		s=_s;
		g=_g;	
	}

public:
	int Menu111(int s,int g)
	{		
		Time ob;
		TimeNow tn;
		Reminder tr;
		
		int a=g % menu2[s].size();
		switch(c)
		{
	case 0:
		switch(a)
		{
		
		case 0: ob.inputTime(); break;
		case 1: ob.outputTime(); break;
		case 2:	ob.searchComentReminder(); break;
		case 3: ob.deleteFile(); break;

		};break;		
	case 1:

		switch(a)
		{
		case 0: tr.reminder(); break;
		case 1: tn.now(); break;
		case 2: tr.reminderForNow(); break;
		case 3: tr.reminderForHour(); break;
		case 4: tr.reminderForDay(); break;
		case 5: tr.reminderForMonth(); break;
		case 6: tr.reminderForYear(); break;
		
		};break;
	case 2:
		switch(a)
		{
		
		};break;
	}
		
	return 0;
	}
	void Menu(int c,int q);
	int Menu1(int c,int q);
};

	void tnow()
	{

	}
int code;               
int main()
{
	
	setlocale(LC_ALL,"Ukrainian");
	menu.insert(menu.begin()," зайти у нагадування");
	menu.insert(menu.begin()+1," показати нагадування");	
	menu.insert(menu.begin()+2," Вихiд ");
	menu2.push_back(vector<string>());
	
	menu2[0].push_back("Додати нагадування ");
	menu2[0].push_back("Вивести усi нагадування");
	menu2[0].push_back("Пошук нагадування по коментарю");
	menu2[0].push_back("Bидалити базу!");
	
	menu2.push_back(vector<string>());
	menu2[1].push_back("Запустити reminder");
	menu2[1].push_back("Показати дату");
	menu2[1].push_back("Перевiрити нагадування на даний момент");
	menu2[1].push_back("Перевiрити нагадування на сьогоднi");
	menu2[1].push_back("Перевiрити нагадування на день");
	menu2[1].push_back("Перевiрити нагадування на мiсяць");
	menu2[1].push_back("Перевiрити нагадування на pik");
	
	
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	Menu(c,q);
		while(1)
	{
		code=getch();
		system("cls");
		switch(code)
		{
		case 72: if(c>0) c--;  break;
		case 80: if(c<3) c++;  break;
		case 77: 
			switch(c)
			{
			case 0:	Menu1(c,q);break;
			case 1: Menu1(c,q);break;	
			case 2: return 0;
			}
		}
		Menu(c,q);
	
	}
		return 0;
}
void Menu(int c,int q)
{
	for(int i=0;i< menu.size();i++)
	{
		if(i==c)
		{
			cout<<"->";
			cout<<menu[i]<<endl;
			if(q!=-1)
				for(int j=0; j < menu2[i].size(); j++)
					if(j==(q % menu2[i].size()))
					{
						cout<<"->";
						cout<<"\t\t"<<menu2[i][j] <<endl;
					}
					else
					{
						
						cout<<"\t\t"<<menu2[i][j] <<endl;
					}
		}
		else
		{
		
		cout<<menu[i]<<endl;
		}

	}
}


int Menu1(int c,int q)
{
	MMenu ob(c,q);
	q++;
	Menu(c,q);
	while(1)
	{
		code=getch();
		system("cls");
		switch(code)
		{
		case 72: q--;break;
		case 80: q++;break;
		case 77: ob.Menu111(c,q);break;
		case 75: return 0;
		}
		Menu(c,q);
	}
	return 0;
}
