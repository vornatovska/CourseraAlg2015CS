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

		cout << "\n��� ������: ";
		cin >> ts.code;

		cout << "\n����� ������: ";
		cin >> ts.name;

		cout << "\n����� ������: ";
		cin >> ts.group;

		cout << "\n�i���i��� ������: ";
		cin >> ts.size;

		cout << "\n�i��: ";
		cin >> ts.cost;

		fwrite(&ts, sizeof(SkladStruct), 1, f);
		fclose(f);

	}
	void viewAllTovar()
	{

		f = fopen("sklad.txt", "ab+");
		int c;

		cout << setw(6) << "���"<< "|" << setw(10)
			<< "�����"<< "|" << setw(10)
			<< "�����" << "|" << setw(4)
			<< "�i��" << "|" << setw(4)
			<< "�-���" << endl<<
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

		cout << "����i�� �����: ";
		cin >> name;

		while ((c = fread(&ts, sizeof(SkladStruct), 1, f)) != NULL)
		{
			if (name == ts.name)
			{
				g = true;
				k++;
				if (k == 1)
				{
					cout << setw(6) << "���" << "|" << setw(10)
						<< "�����" << "|" << setw(10)
						<< "�����" << "|" << setw(4)
						<< "�i��" << "|" << setw(4)
						<< "�-���" << endl <<
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
			cout << "�� \"" << name << "\" ������� �i���� �� ��������!\n ";
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

		cout << "����i�� �������i�: ";
		cin >> categ;

		while ((c = fread(&ts, sizeof(SkladStruct), 1, f)) != NULL)
		{
			if (categ == ts.group)
			{
				g = true;
				k++;
				if (k == 1)
				{

					cout << setw(6) << "���" << "|" << setw(10)
						<< "�����" << "|" << setw(10)
						<< "�����" << "|" << setw(4)
						<< "�i��" << "|" << setw(4)
						<< "�-���" << endl <<
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
			cout << "�� \"" << categ << "\" ������� �i���� �� ��������!\n ";
		}
		fclose(f);


	}
	void deleteTovar()
	{

		f = fopen("slkad.txt", "w");
		cout << "\t\t\t�a�� o�����o!\n";

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

		cout << "����i�� ���: ";
		cin >> code;
		cout << "��tl�� �i���i��: ";
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
			cout << "������ � ����� ����� �� i���!\n";
		}
		else
		{
			cout << " �� ������ ����� " << name << ", � �i������ - " << count << "\n����i��� ���������: " << count * cost << endl;;

		}



		fclose(f);

	}


};


void Menu(int, int);   // ���� ����
int Menu1(int, int);   // ����c��a��� �o ������
int Menu1_1(int, int); // ���� o���a���
int c = 0, q = -1;         //c-��� ����c��a��� � �o�o��o�� ����; q-��� ����c��a��� � ������;
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

				/*				menu2[0].push_back("������ �����");
				menu2[0].push_back("����������� ���� �����");
				menu2[0].push_back("�o��� �� ����i");
				menu2[0].push_back("����� �� ������pi");
				menu2[0].push_back("��������");

				menu2.push_back(vector<string>());
				menu2[1].push_back("�������� ������");
				menu2[1].push_back("������ �����");*/

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
	menu.insert(menu.begin(), " ��i��� �� a��i�ic��a�o� ");
	menu.insert(menu.begin() + 1, " ��i��� �� �o��c���a� ");
	menu.insert(menu.begin() + 2, " ���i� ");
	menu2.push_back(vector<string>());

	menu2[0].push_back("������ �����");
	menu2[0].push_back("����������� ���� �����");
	menu2[0].push_back("�o��� �� ����i");
	menu2[0].push_back("����� �� ������pi");
	menu2[0].push_back("��������");

	menu2.push_back(vector<string>());
	menu2[1].push_back("�������� ������");
	menu2[1].push_back("������ �����");


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


