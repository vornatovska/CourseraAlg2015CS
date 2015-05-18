#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdio>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include <windows.h>
using namespace std;
void admin_menu() {
	system("cls");
	int ch2;
	cout << "\n\n\n\tADMINISTRATOR MENU";
	cout << "\n\n\t(1) CREATE STUDENT RECORD";
	cout << "\n\n\t(2) DISPLAY ALL STUDENTS RECORD";
	cout << "\n\n\t(3) DISPLAY SPECIFIC STUDENT RECORD ";
	cout << "\n\n\t(4) MODIFY STUDENT RECORD";
	cout << "\n\n\t(5) DELETE STUDENT RECORD";
	cout << "\n\n\t(6) CREATE BOOK ";
	cout << "\n\n\t(7) DISPLAY ALL BOOKS ";
	cout << "\n\n\t(8) DISPLAY SPECIFIC BOOK ";
	cout << "\n\n\t(9) MODIFY BOOK ";
	cout << "\n\n\t(10) DELETE BOOK ";
	cout << "\n\n\t(11) BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-11) ";
	cin >> ch2;
	switch (ch2) {
	case 1:
		system("cls");
		write_student();
		break;
	case 2:
		display_alls();
		break;
	case 3:
		char n[6];
		system("cls");
		cout << "\n\n\tPlease Enter The Admission No. ";
		cin >> n;
		display_sps(n);
		break;
	case 4:
		modify_student();
		break;
	case 5:
		delete_student();
		break;
	case 6:
		system("cls");
		write_book();
		break;
	case 7:
		display_allb();
		break;
	case 8:
		char num[6];
		system("cls");
		cout << "\n\n\tPlease Enter The book No. ";
		cin >> num;
		display_spb(num);
		break;
	case 9:
		modify_book();
		break;
	case 10:
		delete_book();
		break;
	case 11: return;
	default: cout << "\a";
	}
	admin_menu();
}
