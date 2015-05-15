#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <time.h>
#include "Football.h"
#include <iomanip>
using namespace std;

#pragma warning(disable: 4996)

void Menu(int, int);   // вивід меню
int Menu1(int, int);   // пересування по підменю
int Menu1_1(int, int); // вибір операції
int c = 0, q = -1;         //с-для пересування в головному меню; q-для пересування в підменю;
vector <string> menu;
vector <vector <string>> menu2;








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

		Football ph;

		ph.loadIsFile();

		int a = g % menu2[s].size();
		switch (c)
		{
		case 0:
			switch (a)
			{

			case 0: ph.inputTeams(); break;
			case 1: ph.outputTeams(); break;
			case 2: ph.inputTeam(); break;
			case 3: ph.saveResult(); break;
			}; break;
		case 1:

			switch (a)
			{
			case 0: ph.inputData(); break;
			case 1: ph.outputTeams(); break;
			case 2: ph.maxScored(); break;
			}; break;

		}

		return 0;
	}
	void Menu(int c, int q);
	int Menu1(int c, int q);
};

void tnow()
{

}
int code;
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

	setlocale(LC_ALL, "Ukrainian");
	menu.insert(menu.begin(), " <--Адмiнiстратор-->");
	menu.insert(menu.begin() + 1, " <--Модератор-->");
	menu.insert(menu.begin() + 2, " <--Вихiд-->");
	menu2.push_back(vector<string>());

	menu2[0].push_back("додати запис");
	menu2[0].push_back("вивести усi записи");
	menu2[0].push_back("ввести команди!");
	menu2[0].push_back("зберегти у файл данi!");

	menu2.push_back(vector<string>());
	menu2[1].push_back("ввести данi");
	menu2[1].push_back("вивести усi записи");
	menu2[1].push_back("максимальна к-сть забитих голiв");






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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (i == c)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
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


