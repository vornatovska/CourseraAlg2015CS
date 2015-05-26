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

		cout << "\nмарка: ";
		cin >> ts.marka;

		cout << "\nмодель: ";
		cin >> ts.model;


		cout << "\nтип кузова: ";
		cin >> ts.typKuzova;

		cout << "\nколiр: ";
		cin >> ts.color;

		cout << "\nцiна: ";
		cin >> ts.cost;

		cout << "\nдвигун: ";
		cin >> ts.dvugun;

		cout << "\nрiк: ";
		cin >> ts.year;
		fwrite(&ts, sizeof(AutoStruct), 1, ff);
		fclose(ff);

	}
	void Auto::viewAllAuto()
	{

		ff = fopen("auto.txt", "r+");
		int c;


		cout << setw(10) << "марка" << "|" << setw(8)
			<< "модель" << "|" << setw(8)
			<< "колiр" << "|" << setw(8)
			<< "двинун" << "|" << setw(12)
			<< "тип кузова" << "|" << setw(6)
			<< "piк" << "|" << setw(7)
			<< "цiна" << endl
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

		cout << "введiть марку: ";
		cin >> name;

		while ((c = fread(&ts, sizeof(AutoStruct), 1, ff)) != NULL)
		{
			if (name == ts.marka)
			{
				g = true;
				k++;
				if (k == 1)
				{

					cout << setw(10) << "марка" << "|" << setw(8)
						<< "модель" << "|" << setw(8)
						<< "колiр" << "|" << setw(8)
						<< "двинун" << "|" << setw(12)
						<< "тип кузова" << "|" << setw(6)
						<< "piк" << "|" << setw(7)
						<< "цiна" << endl
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
			cout << "за \"" << name << "\" запитом нiчого не знайдено!\n ";
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

			cout << "Введіть мінімальну ціну: ";
			cin >> price1;

			cout << "Введіть максимальну ціну: ";
			cin >> price2;
			while ((c = fread(&ts, sizeof(AutoStruct), 1, ff)) != NULL)
			{
				if (price1 <= ts.cost && price2 >= ts.cost)
				{
					g = true;
					k++;
					if (k == 1)
					{

						cout << setw(10) << "марка" << "|" << setw(8)
							<< "модель" << "|" << setw(8)
							<< "колiр" << "|" << setw(8)
							<< "двинун" << "|" << setw(12)
							<< "тип кузова" << "|" << setw(6)
							<< "piк" << "|" << setw(7)
							<< "цiна" << endl
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
				cout << "за \"" << price1 << "\" запитом нiчого не знайдено!\n ";
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

		cout << "введiть тип кузува: ";
		cin >> typ;

		while ((c = fread(&ts, sizeof(AutoStruct), 1, ff)) != NULL)
		{
			if (typ == ts.typKuzova)
			{
				g = true;
				k++;
				if (k == 1)
				{

					cout << setw(10) << "марка" << "|" << setw(8)
						<< "модель" << "|" << setw(8)
						<< "колiр" << "|" << setw(8)
						<< "двинун" << "|" << setw(12)
						<< "тип кузова" << "|" << setw(6)
						<< "piк" << "|" << setw(7)
						<< "цiна" << endl
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
			cout << "за \"" << typ << "\" запитом нiчого не знайдено!\n ";
		}
		fclose(ff);

	}


	void Auto::deleteAuto()
	{

		ff = fopen("auto.txt", "w");
		cout << "\t\t\t Фaйл видалено!\n";

		fclose(ff);
	}
