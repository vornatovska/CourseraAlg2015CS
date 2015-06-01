#include "positional.h"
#include "nopositional.h"
using namespace std;
ofstream ff;
void menu() {
	setlocale(LC_ALL, "Ukr");
	char choice = '0';
	do {
		system("cls");
		cout << "\t\t ====����====\n" << "\t1 - �������� ����� i����i�\n"
				<< "\t2 - �������� i����i�\n" << "\t3 - ����������� �����\n"
				<< "\t0 - ���i�\n\t";
		choice = getch();
		switch (choice) {
		case '1': {
			system("cls");
			cout << "\n\t�������� � ����� ��������i ������ ?\t y/n\n\t";
			choice = getch();
			if (choice == 'y') {
				ff.open("history.txt");
				ff.close();
				cout << "\n\t----���� �������----\n";
				getch();
			}

			break;
		}
		case '2': {
			ifstream ff;
			char *buff;
			system("cls");
			ff.open("history.txt", ios_base::in);
			while (!ff.eof()) {
				buff=new char [256];
				ff.getline(buff,256);
				cout << buff;
			}
		ff.close();
		cout<<"\n\n\t��� ���������� ������i�� ����-��� ����i��...\n\t";
		getch();
			break;
		}
		case '3': {

			int n, dec = 0;
			char answ1 = '0', answ2 = '0';
			ff.open("history.txt", ios_base::app);
			do {
				system("cls");
				cout
						<< "\t\t����i�� ������� �������� i� ��� ���������� �����\n "
						<< "\t1 - ��i�����\n" << "\t2 - �i�i�����\n"
						<< "\t3 - ���������\n" << "\t4 - �i������������\n"
						<< "\t5 - �������\n\n\n";

				cout << "\t";
				answ1 = getch();

				system("cls");

				cout << "\t\t����i�� ������� �������� � ��� ���������� �����\n "
						<< "\t1 - ��i�����\n" << "\t2 - �i�i�����\n"
						<< "\t3 - ���������\n" << "\t4 - �i������������\n"
						<< "\t5 - I� ���i����� �������\n" << "\t6 - �������\n"
						<< "\t7 - ��������� � ��i ������� �����\n\n\n";

				cout << "\t";
				answ2 = getch();
				system("cls");
				Positional *ptr;
				switch (answ1) {
				case '1': {
					cout
							<< "\t ����i�� ����� � ��i����i� ������i �������� \n\n\t";
					ff << "\t ����� � ��i����i� ������i �������� \n\n\t";
					ptr = new Binary;
					ptr->setNumber();
					ff << ptr->str << "\n\n";
					dec = ptr->ToDec();
					ptr->~Positional();
					break;
				}
				case '2': {
					cout
							<< "\t ����i�� ����� � �i�i����i� ������i �������� \n\n\t";
					ff << "\t ����� � �i�i����i� ������i �������� \n\n\t";
					ptr = new Octal;
					ptr->setNumber();
					ff << ptr->str << "\n\n";
					dec = ptr->ToDec();
					ptr->~Positional();
					break;
				}
				case '3': {
					cout
							<< "\t ����i�� ����� � ��������i� ������i �������� \n\n\t";
					ff << "\t ����� � ��������i� ������i �������� \n\n\t";
					cin >> dec;
					ff << dec << "\n\n";
					break;
				}
				case '4': {
					cout
							<< "\t ����i�� ����� � �i�����������i� ������i �������� \n\n\t";
					ff << "\t ����� � �i�����������i� ������i �������� \n\n\t";
					ptr = new Hexal;
					ptr->setNumber();
					ff << ptr->str << "\n\n";
					dec = ptr->ToDec();
					ptr->~Positional();
					break;
				}
				case '5': {
					cout
							<< "\t ����i�� ����� � ������i� ������i �������� \n\n\t";
					ff << "\t ����� � ������i� ������i �������� \n\n\t";
					NoPositional *ptr;
					ptr = new Roman;
					ff << ptr->str << "\n\n";
					dec = ptr->ToDec();
					ptr->~NoPositional();
					break;
				}
				}
				cout << "\n\n";
				Decimal *ptr1;
				ptr1 = new Decimal(dec);
				ff << "\t���������: ";
				switch (answ2) {
				case '1': {
					cout << "\t���������: ";
					ff << "\n\n\t��i�����: ";
					ptr1->ToBin();
					ff << ptr1->str << endl;
					break;
				}
				case '2': {
					cout << "\t���������: ";
					ff << "\t�i�i�����: ";
					ptr1->ToOct();
					ff << ptr1->str << endl;
					break;
				}
				case '3': {
					cout << "\t���������: ";
					ff << "\t���������: ";
					cout << dec << endl;
					ff << dec << endl;
					break;
				}
				case '4': {
					cout << "\t���������: ";
					ff << "\t�i������������: ";
					ptr1->ToHex();
					ff << ptr1->str << endl;
					break;
				}
				case '5': {
					cout
							<< "\t����i�� ������ ��� ������ ������� ��������\n\n\t";
					cin >> n;
					ff << "\t������� i� ������� " << n << ": ";
					cout << "\t���������: ";
					ptr1->ToArbBas(n);
					ff << ptr1->str << endl;
					break;
				}
				case '6': {
					cout << "\t���������: ";
					ff << "\t�������: ";
					ptr1->ToRom();
					ff << ptr1->str << endl;
					break;
				}
				case '7': {
					cout
							<< "\t����i�� ������ ��� ������ ������� ��������\n\n\t";
					cin >> n;
					cout << "\n\t���������: ";
					cout << "\n\n\t��i�����: ";
					ff << "\n\n\t��i�����: ";
					ptr1->ToBin();
					ff << ptr1->str << endl;
					cout << "\t�i�i�����: ";
					ff << "\t�i�i�����: ";
					ptr1->ToOct();
					ff << ptr1->str << endl;
					cout << "\t���������: ";
					ff << "\t���������: ";
					cout << dec << endl;
					ff << dec << endl;
					cout << "\t�i������������: ";
					ff << "\t�i������������: ";
					ptr1->ToHex();
					ff << ptr1->str << endl;
					cout << "\t������� i� ������� " << n << ": ";
					ff << "\t������� i� ������� " << n << ": ";
					ptr1->ToArbBas(n);
					ff << ptr1->str << endl;
					cout << "\t�������: ";
					ff << "\t�������: ";
					ptr1->ToRom();
					ff << ptr1->str << endl;
				}
				}
				cout << "\n\t9 - �� ���\n" << "\t0 - ����������� � ����\n"
						<< "\tq - ���i�\n\n";
				ff
						<< "\n----------------------------------------------------------------\n";
				cout << "\t";
				answ1 = getch();
				if (answ1 == 'q')
					return;
				break;
			} while (answ1 != '0');
			ff.close();
		}
		}

	} while (choice != '0');
}

int main() {

	menu();

	return 0;
}
