//���� �����, �� ������ ���������� ��� ����


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


struct AutoStruct{
	string number;
	string marka;
	string typKuzova;
	string dvugun;
	int cost;
	string color;
	string year;
	string model;
}ts;


	class Auto
{
private:
	AutoStruct ts;
public:

	Auto(){}
	Auto(AutoStruct _ts)
	{
		ts = _ts;
	}
	void addAuto()
	{
		
		f = fopen("auto.txt", "a+");

		cout << "\n�����: ";
		cin >> ts.marka;

		cout << "\n������: ";
		cin >> ts.model;

		cout << "\n������: ";
		cin >> ts.number;

		cout << "\n��� ������: ";
		cin >> ts.typKuzova;

		cout << "\n���i�: ";
		cin >> ts.color;

		cout << "\n�i��: ";
		cin >> ts.cost;

		cout << "\n������: ";
		cin >> ts.dvugun;

		cout << "\n�i�: ";
		cin >> ts.year;
		fwrite(&ts, sizeof(AutoStruct), 1, f);
		fclose(f);

	}
	void viewAllAuto()
	{

		f = fopen("auto.txt", "ab+");
		int c;


		cout << setw(8) << "\n�����" << "-"
			<< setw(8) << "�����" << "-"
			<< setw(8) << "������" << "-"
			<< setw(8) << "���i�" << "-"
			<< setw(8) << "������" << "-"
			<< setw(8) << "��� ������" << "-"
			<< setw(8) << "pik" << "-"
			<< setw(8) << "�i��" << "-\n";


		while ((c = fread(&ts, sizeof(AutoStruct), 1, f)) != NULL)
		{
				
			cout << setw(8) << ts.number << "-"
				<< setw(8) << ts.marka << "-"
				<< setw(8) << ts.model << "-"
				<< setw(8) << ts.color << "-"
				<< setw(8) << ts.dvugun << "-"
				<< setw(8) << ts.typKuzova << "-"
				<< setw(8) << ts.year << "-"
				<< setw(8) << ts.cost << "-\n";

				
		}
		fclose(f);

	}
	void searchName()
	{
		f = fopen("auto.txt", "ab+");
		int c;
		bool g = false;
		int k = 0;
		string name;

		cout << "����i�� �����: ";
		cin >> name;

		while ((c = fread(&ts, sizeof(AutoStruct), 1, f)) != NULL)
		{
			if (name == ts.marka)
			{
				g = true;
				k++;
				if (k == 1)
				{

					cout << setw(8) << "\n�����" << "-"
						<< setw(8) << "�����" << "-"
						<< setw(8) << "������" << "-"
						<< setw(8) << "���i�" << "-"
						<< setw(8) << "������" << "-"
						<< setw(8) << "��� ������" << "-"
						<< setw(8) << "pik" << "-"
						<< setw(8) << "�i��\n" << "-";
				}



				cout << setw(8) << ts.number << "-"
					<< setw(8) << ts.marka << "-"
					<< setw(8) << ts.model << "-"
					<< setw(8) << ts.color << "-"
					<< setw(8) << ts.dvugun << "-"
					<< setw(8) << ts.typKuzova << "-"
					<< setw(8) << ts.year << "-"
					<< setw(8) << ts.cost << "-\n";
			}
		}
		if (g == false)
		{
			cout << "�� \"" << name << "\" ������� �i���� �� ��������!\n ";
		}
		fclose(f);




	}
	void findDvugun()
	{

		f = fopen("auto.txt", "ab+");
		int c;
		bool g = false;
		int k = 0;
		string typ;

		cout << "����i�� ��� ������: ";
		cin >> typ;

		while ((c = fread(&ts, sizeof(AutoStruct), 1, f)) != NULL)
		{
			if (typ == ts.typKuzova)
			{
				g = true;
				k++;
				if (k == 1)
				{

					cout << setw(8) << "\n�����" << "-"
						<< setw(8) << "�����" << "-"
						<< setw(8) << "������" << "-"
						<< setw(8) << "���i�" << "-"
						<< setw(8) << "������" << "-"
						<< setw(8) << "��� ������" << "-"
						<< setw(8) << "pik" << "-"
						<< setw(8) << "�i��" << "-\n";
				}



				cout << setw(8) << ts.number << "-"
					<< setw(8) << ts.marka << "-"
					<< setw(8) << ts.model << "-"
					<< setw(8) << ts.color << "-"
					<< setw(8) << ts.dvugun << "-"
					<< setw(8) << ts.typKuzova << "-"
					<< setw(8) << ts.year << "-"
					<< setw(8) << ts.cost << "-\n";
			}
		}
		if (g == false)
		{
			cout << "�� \"" << typ << "\" ������� �i���� �� ��������!\n ";
		}
		fclose(f);

		

	}
	void deleteAuto()
	{

		f = fopen("slkad.txt", "w");
		cout << "\t\t\t�a�� ��������!\n";

		fclose(f);
	}

	
	
};


void Menu(int, int);   // ���� ����
int Menu1(int, int);   // ����c��a��� �o ������
int Menu1_1(int, int); // ���� o���a���
int c = 0, q = -1;         //c-��� ����c��a��� � �o�o��o�� ����; q-��� ����c��a��� � ������;
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
		Auto ob;
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

			case 0: ob.addAuto(); break;
			case 1: ob.viewAllAuto(); break;
			case 2: ob.searchName(); break;
			case 3: ob.findDvugun(); break;
			case 4: ob.deleteAuto(); break;
			}; break;
		case 1: return 0;
		}

		return 0;
	}
	void Menu(int c, int q);
	int Menu1(int c, int q);
};


int code;
int main()
{
//	SetConsoleCP(1251);
///SetConsoleOutputCP(1251);

	setlocale(LC_ALL,"Ukrainian");
	menu.insert(menu.begin(), "auto ");
	menu.insert(menu.begin() + 1, " ���i� ");
	menu2.push_back(vector<string>());

	menu2[0].push_back("������ ���i");
	menu2[0].push_back("����������� �ci ����");
	menu2[0].push_back("�o��� �� ����i");
	menu2[0].push_back("����� �� ���� ������");
	menu2[0].push_back("��������");


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


