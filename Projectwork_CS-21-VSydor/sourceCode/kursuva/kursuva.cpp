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
		cout << "Виберіть режим роботи" << endl;
		cout << "1 - Додати автомобіль" << endl;
		cout << "2 - Показати всі автомобілі" << endl;
		cout << "3 - Пoшук за назвою" << endl;
		cout << "4 - Пошук за ціною" << endl;
		cout << "5 - Пошук за типом кузова" << endl;
		cout << "6 - Видалити" << endl;
		cout << "0 - Вихід" << endl;
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