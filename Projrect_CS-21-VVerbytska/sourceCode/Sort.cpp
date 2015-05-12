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
const int n=9;
FILE *f;

vector<string> teams;


class Sort
{
private:
	int arr[n];
public:
	Sort(){}
	Sort(int _arr[n])
	{
		for (int i = 0; i < n; i++)
		{
			_arr[i] = arr[i];
		}
	}
	void inputKey()
	{

		for (int i = 0; i < n; i++)
		{
			cout << "\n[" << i + 1 << "]=";
			cin >> arr[i];
		}
	}

	void inputFile()
	{


		for (int i = 0; i < n; i++)
		{
			cout << "[" << i + 1 << "]=" << arr[i] << endl;

		}
	}
	void inputRand()
	{

		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 1000;
		}
	}
	void saveFile()
	{

	}

	void sortPabble()
	{
		int flat;
		flat = arr[0];
		for (int i = 0; i < n; i++)

		for (int j = 0; j <n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				flat = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = flat;
		}
		
	}
	void rozpodil(int *arr, int n)
	{
		const int m = 1001; // m - число,
		int Amount[m];
		int i;

		for (i = 0; i<m; i++) Amount[i] = 0;
		for (i = 0; i<n; i++)
		{
			++Amount[arr[i]];
		}

		int k = 0;

		for (i = 0; i<m; i++)
		{
			for (int j = 0; j<Amount[i]; j++)
			{
				arr[k] = i;
				++k;
			}
		}

	}
	void speedSort(int *arr, int n)
	{
		int i, y;

		for (i = n - 1; i>0; i--)
		{
			int max = 0;

			for (int y = 1; y <= i; y++)
			{
				if (arr[y]>arr[max]) max = y;
			}

			int temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
	void print()
	{

		for (int i = 0; i < n; i++)
		{
			cout << "[" << i + 1 << "]="<<arr[i]<<endl;
			
		}
	}
	




};


void Menu(int, int);   // вивід меню
int Menu1(int, int);   // пересування по підменю
int Menu1_1(int, int); // вибір операції
int c = 0, q = -1;         //с-для пересування в головному меню; q-для пересування в підменю;
vector <string> menu;
vector <vector <string>> menu2;








int arr[n];
Sort sr(arr);
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


		int a = g % menu2[s].size();
		switch (c)
		{
		case 0:
			switch (a)
			{

			case 0: sr.inputKey(); break;
			case 1: sr.inputFile(); break;
			case 2: sr.inputRand(); break;
			case 3: sr.saveFile(); break;
			}; break;
		case 1:

			switch (a)
			{
			case 0: sr.sortPabble(); break;
			case 1: sr.speedSort(arr,n); break;
			case 2: sr.rozpodil(arr, n); break;
			case 3: sr.print(); break;
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
	menu.insert(menu.begin(), " Ввести данi");
	menu.insert(menu.begin() + 1, " Сортування");
	menu.insert(menu.begin() + 2, " Вихiд");
	menu2.push_back(vector<string>());

	menu2[0].push_back("Ввести данi");
	menu2[0].push_back("Загрузити з файлу");
	menu2[0].push_back("Рандомно запвнити");
	menu2[0].push_back("зберегти у файл данi!");

	menu2.push_back(vector<string>());
	menu2[1].push_back("Бульбашкове сортування");
	menu2[1].push_back("Простого вилучення");
	menu2[1].push_back("Метод розподілу");
	menu2[1].push_back("Вивести масив");






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


