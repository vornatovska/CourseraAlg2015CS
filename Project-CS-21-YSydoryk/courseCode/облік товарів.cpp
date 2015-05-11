#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <iomanip>

#pragma warning(disable: 4996)

using namespace std;
#include <vector>

#define n 4
FILE *f;


struct SkladStruct{
	int code;
	string name;
	string group;
	int size;
	int cost;
}ts;


class Sklad
{
private:
	SkladStruct ts;
public:

	Sklad(){}
	Sklad(SkladStruct _ts)
	{
		ts = _ts;
	}
	void addTovar()
	{

		f = fopen("sklad.txt", "a+");

		cout << "\nкод товару: ";
		cin >> ts.code;

		cout << "\nназва товару: ";
		cin >> ts.name;

		cout << "\nгрупа товару: ";
		cin >> ts.group;

		cout << "\nкiлькiсть товару: ";
		cin >> ts.size;

		cout << "\nцiна: ";
		cin >> ts.cost;

		fwrite(&ts, sizeof(SkladStruct), 1, f);
		fclose(f);

	}
	void viewAllTovar()
	{

		f = fopen("sklad.txt", "ab+");
		int c;

		cout << setw(6) << "код"<< "|" << setw(10)
			<< "назва"<< "|" << setw(10)
			<< "група" << "|" << setw(4)
			<< "цiна" << "|" << setw(4)
			<< "к-сть" << endl<<
			"----------------------------------"<< endl;

		while ((c = fread(&ts, sizeof(SkladStruct), 1, f)) != NULL)
		{

			cout << setw(6) << ts.code << "|" << setw(10)
				<< ts.name << "|" << setw(10)
				<< ts.group << "|" << setw(4)
				<< ts.cost << "|" << setw(4)
				<< ts.size << endl;

		}
		fclose(f);

	}
	void searchName()
	{
		f = fopen("sklad.txt", "ab+");
		int c;
		bool g = false;
		int k = 0;
		string name;

		cout << "введiть назву: ";
		cin >> name;

		while ((c = fread(&ts, sizeof(SkladStruct), 1, f)) != NULL)
		{
			if (name == ts.name)
			{
				g = true;
				k++;
				if (k == 1)
				{
					cout << setw(6) << "код" << "|" << setw(10)
						<< "назва" << "|" << setw(10)
						<< "група" << "|" << setw(4)
						<< "цiна" << "|" << setw(4)
						<< "к-сть" << endl <<
						"----------------------------------" << endl;
				}



				cout << setw(6) << ts.code << "|" << setw(10)
					<< ts.name << "|" << setw(10)
					<< ts.group << "|" << setw(4)
					<< ts.cost << "|" << setw(4)
					<< ts.size << endl;
			}
		}
		if (g == false)
		{
			cout << "за \"" << name << "\" запитом нiчого не знайдено!\n ";
		}
		fclose(f);




	}
	void serachCategory()
	{

		f = fopen("sklad.txt", "ab+");
		int c;
		bool g = false;
		int k = 0;
		string categ;

		cout << "введiть категорiю: ";
		cin >> categ;

		while ((c = fread(&ts, sizeof(SkladStruct), 1, f)) != NULL)
		{
			if (categ == ts.group)
			{
				g = true;
				k++;
				if (k == 1)
				{

					cout << setw(6) << "код" << "|" << setw(10)
						<< "назва" << "|" << setw(10)
						<< "група" << "|" << setw(4)
						<< "цiна" << "|" << setw(4)
						<< "к-сть" << endl <<
						"----------------------------------" << endl;
				}



				cout << setw(6) << ts.code << "|" << setw(10)
					<< ts.name << "|" << setw(10)
					<< ts.group << "|" << setw(4)
					<< ts.cost << "|" << setw(4)
					<< ts.size << endl;
			}
		}
		if (g == false)
		{
			cout << "за \"" << categ << "\" запитом нiчого не знайдено!\n ";
		}
		fclose(f);


	}
	void deleteTovar()
	{

		f = fopen("slkad.txt", "w");
		cout << "\t\t\tфaйл oчищенo!\n";

		fclose(f);
	}

	void kuputuTovar()
	{

		f = fopen("sklad.txt", "ab+");

		int code, count, cost;
		int c;
		int k = 0;
		string name;
		viewAllTovar();

		cout << "введiть код: ";
		cin >> code;
		cout << "ввtlть кiлькiсь: ";
		cin >> count;

		while ((c = fread(&ts, sizeof(SkladStruct), 1, f)) != NULL)
		{
			cout << code << count ;
			if (ts.code == code)
			{
				k++;
				cost = ts.cost;
				name = ts.name;

				cout << ts.cost << ts.name<<k<<code<<endl;
				break;
			}
		}
		if (k != 0)
		{
			cout << "товару з таким кодом не iснує!\n";
		}
		else
		{
			cout << " ви обрали товар " << name << ", у кiлькості - " << count << "\nвартiсть становить: " << count * cost << endl;;

		}



		fclose(f);

	}


};


void Menu(int, int);   // вивід меню
int Menu1(int, int);   // переcувaння пo підменю
int Menu1_1(int, int); // вибір oперaції
int c = 0, q = -1;         //c-для переcувaння в гoлoвнoму меню; q-для переcувaння в підменю;
//vector <string> menu;
//vector <vector <string>> menu2;








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
		Sklad ob;
		int a = g % menu2[s].size();
		switch (c)
		{
		case 0:
			switch (a)
			{

				/*				menu2[0].push_back("Додати товар");
				menu2[0].push_back("Переглянути весь товар");
				menu2[0].push_back("Пoшук по назвi");
				menu2[0].push_back("Пошук по категоpi");
				menu2[0].push_back("Видалити");

				menu2.push_back(vector<string>());
				menu2[1].push_back("Перегляд товару");
				menu2[1].push_back("Купити товар");*/

			case 0: ob.addTovar(); break;
			case 1: ob.viewAllTovar(); break;
			case 2: ob.searchName(); break;
			case 3: ob.serachCategory(); break;
			case 4: ob.deleteTovar(); break;
			}; break;
		case 1:

			switch (a)
			{
			case 0: ob.viewAllTovar(); break;
			case 1: ob.kuputuTovar(); break;
			}; break;
		case 2:
			switch (a)
			{

			}; break;
		}

		return 0;
	}
	void Menu(int c, int q);
	int Menu1(int c, int q);
};
//vector <string> menu;
//vector <vector <string>> menu2;

int code;
int main()
{
//	SetConsoleCP(1251);
///SetConsoleOutputCP(1251);

	setlocale(LC_ALL,"Ukrainian");
	menu.insert(menu.begin(), " Увiйти як aдмiнicтрaтoр ");
	menu.insert(menu.begin() + 1, " Увiйти як кoриcтувaч ");
	menu.insert(menu.begin() + 2, " Вихiд ");
	menu2.push_back(vector<string>());

	menu2[0].push_back("Додати товар");
	menu2[0].push_back("Переглянути весь товар");
	menu2[0].push_back("Пoшук по назвi");
	menu2[0].push_back("Пошук по категоpi");
	menu2[0].push_back("Видалити");

	menu2.push_back(vector<string>());
	menu2[1].push_back("Перегляд товару");
	menu2[1].push_back("Купити товар");


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
		if (i == c)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << menu[i] << endl;
			if (q != -1)
			for (int j = 0; j<menu2[i].size(); j++)
			if (j == (q % menu2[i].size()))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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


