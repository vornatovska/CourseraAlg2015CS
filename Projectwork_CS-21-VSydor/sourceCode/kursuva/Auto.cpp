#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "Auto.h"

#pragma warning(disable: 4996)

using namespace std;

FILE *ff;

struct AutoStruct{
	string marka;
	string typKuzova;
	string dvugun;
	int cost;
	string color;
	string year;
	string model;
}ts;


	Auto::Auto(){}
	void Auto::addAuto()
	{

		ff = fopen("auto.txt", "a+");

		cout << "\n�����: ";
		cin >> ts.marka;

		cout << "\n������: ";
		cin >> ts.model;


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
		fwrite(&ts, sizeof(AutoStruct), 1, ff);
		fclose(ff);

	}
	void Auto::viewAllAuto()
	{

		ff = fopen("auto.txt", "r+");
		int c;


		cout << setw(10) << "�����" << "|" << setw(8)
			<< "������" << "|" << setw(8)
			<< "���i�" << "|" << setw(8)
			<< "������" << "|" << setw(12)
			<< "��� ������" << "|" << setw(6)
			<< "pi�" << "|" << setw(7)
			<< "�i��" << endl
			<< "__________________________________________________________________________" << endl;


		while ((c = fread(&ts, sizeof(AutoStruct), 1, ff)) != NULL)
		{

			cout << setw(10) << ts.marka << "|" << setw(8)
				<< ts.model << "|" << setw(8)
				<< ts.color << "|" << setw(8)
				<< ts.dvugun << "|" << setw(12)
				<< ts.typKuzova << "|" << setw(6)
				<< ts.year << "|" << setw(7)
				<< ts.cost << "|" << endl;
		}

		fclose(ff);

	}
	void Auto::searchName()
	{
		ff = fopen("auto.txt", "r+");
		int c;
		bool g = false;
		int k = 0;
		string name;

		cout << "����i�� �����: ";
		cin >> name;

		while ((c = fread(&ts, sizeof(AutoStruct), 1, ff)) != NULL)
		{
			if (name == ts.marka)
			{
				g = true;
				k++;
				if (k == 1)
				{

					cout << setw(10) << "�����" << "|" << setw(8)
						<< "������" << "|" << setw(8)
						<< "���i�" << "|" << setw(8)
						<< "������" << "|" << setw(12)
						<< "��� ������" << "|" << setw(6)
						<< "pi�" << "|" << setw(7)
						<< "�i��" << endl
						<< "__________________________________________________________________________" << endl;
				}



				cout << setw(10) << ts.marka << "|" << setw(8)
					<< ts.model << "|" << setw(8)
					<< ts.color << "|" << setw(8)
					<< ts.dvugun << "|" << setw(12)
					<< ts.typKuzova << "|" << setw(6)
					<< ts.year << "|" << setw(7)
					<< ts.cost << "|" << endl;
			}
		}
		if (g == false)
		{
			cout << "�� \"" << name << "\" ������� �i���� �� ��������!\n ";
		}
		fclose(ff);
	}

		void Auto::searchPrice()
		{
			ff = fopen("auto.txt", "r+");
			int c;
			bool g = false;
			int k = 0;
			int price1, price2;

			cout << "������ �������� ����: ";
			cin >> price1;

			cout << "������ ����������� ����: ";
			cin >> price2;
			while ((c = fread(&ts, sizeof(AutoStruct), 1, ff)) != NULL)
			{
				if (price1 <= ts.cost && price2 >= ts.cost)
				{
					g = true;
					k++;
					if (k == 1)
					{

						cout << setw(10) << "�����" << "|" << setw(8)
							<< "������" << "|" << setw(8)
							<< "���i�" << "|" << setw(8)
							<< "������" << "|" << setw(12)
							<< "��� ������" << "|" << setw(6)
							<< "pi�" << "|" << setw(7)
							<< "�i��" << endl
							<< "__________________________________________________________________________" << endl;
					}

					cout << setw(10) << ts.marka << "|" << setw(8)
						<< ts.model << "|" << setw(8)
						<< ts.color << "|" << setw(8)
						<< ts.dvugun << "|" << setw(12)
						<< ts.typKuzova << "|" << setw(6)
						<< ts.year << "|" << setw(7)
						<< ts.cost << "|" << endl;
				}
			}
			if (g == false)
			{
				cout << "�� \"" << price1 << "\" ������� �i���� �� ��������!\n ";
			}
			fclose(ff);
		}

	void Auto::findDvugun()
	{

		ff = fopen("auto.txt", "r+");
		int c;
		bool g = false;
		int k = 0;
		string typ;

		cout << "����i�� ��� ������: ";
		cin >> typ;

		while ((c = fread(&ts, sizeof(AutoStruct), 1, ff)) != NULL)
		{
			if (typ == ts.typKuzova)
			{
				g = true;
				k++;
				if (k == 1)
				{

					cout << setw(10) << "�����" << "|" << setw(8)
						<< "������" << "|" << setw(8)
						<< "���i�" << "|" << setw(8)
						<< "������" << "|" << setw(12)
						<< "��� ������" << "|" << setw(6)
						<< "pi�" << "|" << setw(7)
						<< "�i��" << endl
						<< "__________________________________________________________________________" << endl;
				}

				cout << setw(10) << ts.marka << "|" << setw(8)
					<< ts.model << "|" << setw(8)
					<< ts.color << "|" << setw(8)
					<< ts.dvugun << "|" << setw(12)
					<< ts.typKuzova << "|" << setw(6)
					<< ts.year << "|" << setw(7)
					<< ts.cost << "|" << endl;
			}
		}
		if (g == false)
		{
			cout << "�� \"" << typ << "\" ������� �i���� �� ��������!\n ";
		}
		fclose(ff);

	}


	void Auto::deleteAuto()
	{

		ff = fopen("auto.txt", "w");
		cout << "\t\t\t �a�� ��������!\n";

		fclose(ff);
	}
