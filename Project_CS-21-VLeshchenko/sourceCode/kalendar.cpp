#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <time.h>
#include <iomanip>
using namespace std;
#pragma warning(disable: 4996)
const int n = 9;
FILE *f;

vector<string> teams;


void Menu(int, int);   // vuvid menu
int Menu1(int, int);   // peresyvannia pidmenu
int Menu1_1(int, int); // vubir operatsii
int c = 0, q = -1;         //c-dl'a peresyvannia v golovnomy menu; q-dl'a peresyvannia v pidmenu;
vector <string> menu;
vector <vector <string>> menu2;



class Time
{
public:
	Time(){}
	void time()
	{

		time_t t;
		struct tm *t_m;
	//	t = time(NULL);
		t_m = localtime(&t);
		cout << "Local time is: " << t_m->tm_year + 1900 << "  " << t_m->tm_mon + 1 << ", " << t_m->tm_mday << " - " << t_m->tm_hour << ":" << t_m->tm_min << ":" << t_m->tm_sec << endl;

		
		/*
		time_t t;
		time(&t);
		tm *tme = localetime(&t);
		cout << tme->tm_hour << ":" << tme->tm_min << endl;
		*/
	}
	void celndar(){
		int DaysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int DayForw[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
		char cMonths[] = "Jan\0Feb\0Mar\0Apr\0May\0Jun\0Jul\0Aug\0Sep\0Oct\0Nov\0Dec";
		int DaysPerYear = 365;
		
			cout << "Vvedit mis'ats ta rik (mm yyyy): ";
			int iMonth, iYear;
			int* Direction;
			cin >> iMonth >> iYear;
			cout << endl;
			int iCorrect, DaysDist;
			DaysDist = (iYear - 2008);
			Direction = &DayForw[0];
			iCorrect = (DaysDist) / 4; 
			if (DaysDist>0)
				iCorrect++;
			if ((DaysDist) % 4 == 0) 
			{
				if (DaysDist>0)
					iCorrect--;
				for (int i = 2; i < 12; i++) 
					DayForw[i]++;
				DaysPerMonth[1]++; 
			}
			DaysDist = DaysDist * 365 + iCorrect + Direction[iMonth - 1];
			int DayOfMonth;
			if (DaysDist < 0)
				DayOfMonth = 7 - (5 - DaysDist) % 7;
			else
				DayOfMonth = (DaysDist + 1) % 7 + 1;
			cout << "\t    ************ " << cMonths + (iMonth - 1) * 4 << " " << iYear << " ************" << endl << endl;
			cout << "\tMon\tTue\tWed\tThu\tFri\tSat\tSun" << endl << endl;
			for (int i = 1; i<DayOfMonth; i++)
				cout << "\t";
			for (int i = 0; i<DaysPerMonth[iMonth - 1]; DayOfMonth++, i++)
			{
				cout << "\t" << i + 1;
				if (DayOfMonth == 7)
				{
					DayOfMonth = 0;
					cout << endl << endl;
				}
			}
			cout << endl << endl << "\t    ************ " << cMonths + (iMonth - 1) * 4 << " " << iYear << " ************" << endl;
	
	}
};



class MMenu
{
public:
	int s;
	int g;
	MMenu(int _s, int _g)
	{
		s = _s;
		g = _g;
	}

public:
	int Menu111(int s, int g)
	{
		Time ob;

		int a = g % menu2[s].size();
		switch (c)
		{
		case 0:
			switch (a)
			{

			case 0: ob.celndar(); break;
			case 1: ob.time(); break;
			}; break;
		case 1: {} break;


		}

		return 0;
	}
	void Menu(int c, int q);
	int Menu1(int c, int q);
};


int code;
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

	setlocale(LC_ALL, "Ukrainian");
	menu.insert(menu.begin(), " Godunnuk");
	menu.insert(menu.begin() + 1, " Vuhid");
	menu2.push_back(vector<string>());

	menu2[0].push_back("Kalendar");
	menu2[0].push_back("Chasu");
	
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	Menu(c, q);
	while (1)
	{
		code = getch();
		system("cls");
		switch (code)
		{
		case 72: if (c>0) c--;  break;
		case 80: if (c<3) c++;  break;
		case 77:
			switch (c)
			{
			case 0:	Menu1(c, q); break;
			case 1: Menu1(c, q); break;
			case 2: return 0;
			}
		}
		Menu(c, q);

	}
	return 0;
}
void Menu(int c, int q)
{
	for (int i = 0; i< menu.size(); i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		if (i == c)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << menu[i] << endl;
			if (q != -1)
			for (int j = 0; j<menu2[i].size(); j++)
			if (j == (q % menu2[i].size()))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				cout << "\t\t" << menu2[i][j] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t" << menu2[i][j] << endl;
			}
		}
		else
		{

			cout << menu[i] << endl;
		}

	}
}











int Menu1(int c, int q)
{
	MMenu ob(c, q);
	q++;
	Menu(c, q);
	while (1)
	{
		code = getch();
		system("cls");
		switch (code)
		{
		case 72: q--; break;
		case 80: q++; break;
		case 77: ob.Menu111(c, q); break;
		case 75: return 0;
		}
		Menu(c, q);
	}
	return 0;
}


