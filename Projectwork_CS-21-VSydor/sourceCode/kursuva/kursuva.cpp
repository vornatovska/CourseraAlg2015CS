#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "Auto.h"

#pragma warning(disable: 4996)

using namespace std;

FILE *f;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	char x;
	Auto ob;
	do
	{   
		cout << endl << "*********************************" << endl;
		cout << "������� ����� ������" << endl;
		cout << "1 - ������ ���������" << endl;
		cout << "2 - �������� �� ��������" << endl;
		cout << "3 - �o��� �� ������" << endl;
		cout << "4 - ����� �� �����" << endl;
		cout << "5 - ����� �� ����� ������" << endl;
		cout << "6 - ��������" << endl;
		cout << "0 - �����" << endl;
		cout << endl << "*********************************" << endl;
		x = getch();
		system("cls");
		switch (x)
		{
		case '0': return 0;
		case '1': ob.addAuto(); break;
		case '2': ob.viewAllAuto(); break;
		case '3': ob.searchName(); break;
		case '4': ob.searchPrice(); break;
		case '5': ob.findDvugun(); break;
		case '6': ob.deleteAuto(); break;
		}
	} while (1);

}