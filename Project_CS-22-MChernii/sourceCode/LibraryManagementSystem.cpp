#include <iostream>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdio>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include <windows.h>
#include"header.h"
#include"admin_menu.h"
using namespace std;
int main() {
	char ch;
	intro();
	do {
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t(1) BOOK ISSUE";
		cout << "\n\n\t(2) BOOK DEPOSIT";
		cout << "\n\n\t(3) ADMINISTRATOR MENU";
		cout << "\n\n\t(4) EXIT";
		cout << "\n\n\tPlease Select Your Option (1-4) ";
		ch = getche();
		switch (ch) {
		case '1':
			system("cls");
			book_issue();
			break;
		case '2':
			book_deposit();
			break;
		case '3':
			admin_menu();
			break;
		case '4': exit(0);
		default: cout << "\a";
		}
	} while (ch != '4');
}

