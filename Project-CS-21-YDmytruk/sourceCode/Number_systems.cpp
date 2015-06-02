#include "positional.h"
#include "nopositional.h"
using namespace std;
ofstream ff;
void menu() {
	setlocale(LC_ALL, "Ukr");
	char choice = '0';
	do {
		system("cls");
		cout << "\t\t ====МЕНЮ====\n" << "\t1 - Очищення файлу iсторiї\n"
				<< "\t2 - Перегляд iсторiї\n" << "\t3 - Переведення чисел\n"
				<< "\t0 - Вихiд\n\t";
		choice = getch();
		switch (choice) {
		case '1': {
			system("cls");
			cout << "\n\tВилучити з файлу попереднi записи ?\t y/n\n\t";
			choice = getch();
			if (choice == 'y') {
				ff.open("history.txt");
				ff.close();
				cout << "\n\t----Файл очищено----\n";
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
		cout<<"\n\n\tЩоб продовжити натиснiть будь-яку клавiшу...\n\t";
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
						<< "\t\tОберiть систему числення iз якої переводити число\n "
						<< "\t1 - Двiйкова\n" << "\t2 - Вiсiмкова\n"
						<< "\t3 - Десяткова\n" << "\t4 - Шiстнадцяткова\n"
						<< "\t5 - Римська\n\n\n";

				cout << "\t";
				answ1 = getch();

				system("cls");

				cout << "\t\tОберiть систему числення у яку переводити число\n "
						<< "\t1 - Двiйкова\n" << "\t2 - Вiсiмкова\n"
						<< "\t3 - Десяткова\n" << "\t4 - Шiстнадцяткова\n"
						<< "\t5 - Iз довiльною основою\n" << "\t6 - Римська\n"
						<< "\t7 - Перевести у всi системи зразу\n\n\n";

				cout << "\t";
				answ2 = getch();
				system("cls");
				Positional *ptr;
				switch (answ1) {
				case '1': {
					cout
							<< "\t Введiть число у двiйковiй системi числення \n\n\t";
					ff << "\t Число у двiйковiй системi числення \n\n\t";
					ptr = new Binary;
					ptr->setNumber();
					ff << ptr->str << "\n\n";
					dec = ptr->ToDec();
					ptr->~Positional();
					break;
				}
				case '2': {
					cout
							<< "\t Введiть число у вiсiмковiй системi числення \n\n\t";
					ff << "\t Число у вiсiмковiй системi числення \n\n\t";
					ptr = new Octal;
					ptr->setNumber();
					ff << ptr->str << "\n\n";
					dec = ptr->ToDec();
					ptr->~Positional();
					break;
				}
				case '3': {
					cout
							<< "\t Введiть число у десятковiй системi числення \n\n\t";
					ff << "\t Число у десятковiй системi числення \n\n\t";
					cin >> dec;
					ff << dec << "\n\n";
					break;
				}
				case '4': {
					cout
							<< "\t Введiть число у шiстнадцятковiй системi числення \n\n\t";
					ff << "\t Число у шiстнадцятковiй системi числення \n\n\t";
					ptr = new Hexal;
					ptr->setNumber();
					ff << ptr->str << "\n\n";
					dec = ptr->ToDec();
					ptr->~Positional();
					break;
				}
				case '5': {
					cout
							<< "\t Введiть число у римськiй системi числення \n\n\t";
					ff << "\t Число у римськiй системi числення \n\n\t";
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
				ff << "\tРЕЗУЛЬТАТ: ";
				switch (answ2) {
				case '1': {
					cout << "\tРЕЗУЛЬТАТ: ";
					ff << "\n\n\tДвiйкова: ";
					ptr1->ToBin();
					ff << ptr1->str << endl;
					break;
				}
				case '2': {
					cout << "\tРЕЗУЛЬТАТ: ";
					ff << "\tВiсiмкова: ";
					ptr1->ToOct();
					ff << ptr1->str << endl;
					break;
				}
				case '3': {
					cout << "\tРЕЗУЛЬТАТ: ";
					ff << "\tДесяткова: ";
					cout << dec << endl;
					ff << dec << endl;
					break;
				}
				case '4': {
					cout << "\tРЕЗУЛЬТАТ: ";
					ff << "\tШiстнадцяткова: ";
					ptr1->ToHex();
					ff << ptr1->str << endl;
					break;
				}
				case '5': {
					cout
							<< "\tВведiть основу для бажаної системи числення\n\n\t";
					cin >> n;
					ff << "\tСистема iз основою " << n << ": ";
					cout << "\tРЕЗУЛЬТАТ: ";
					ptr1->ToArbBas(n);
					ff << ptr1->str << endl;
					break;
				}
				case '6': {
					cout << "\tРЕЗУЛЬТАТ: ";
					ff << "\tРимська: ";
					ptr1->ToRom();
					ff << ptr1->str << endl;
					break;
				}
				case '7': {
					cout
							<< "\tВведiть основу для бажаної системи числення\n\n\t";
					cin >> n;
					cout << "\n\tРЕЗУЛЬТАТ: ";
					cout << "\n\n\tДвiйкова: ";
					ff << "\n\n\tДвiйкова: ";
					ptr1->ToBin();
					ff << ptr1->str << endl;
					cout << "\tВiсiмкова: ";
					ff << "\tВiсiмкова: ";
					ptr1->ToOct();
					ff << ptr1->str << endl;
					cout << "\tДесяткова: ";
					ff << "\tДесяткова: ";
					cout << dec << endl;
					ff << dec << endl;
					cout << "\tШiстнадцяткова: ";
					ff << "\tШiстнадцяткова: ";
					ptr1->ToHex();
					ff << ptr1->str << endl;
					cout << "\tСистема iз основою " << n << ": ";
					ff << "\tСистема iз основою " << n << ": ";
					ptr1->ToArbBas(n);
					ff << ptr1->str << endl;
					cout << "\tРимська: ";
					ff << "\tРимська: ";
					ptr1->ToRom();
					ff << ptr1->str << endl;
				}
				}
				cout << "\n\t9 - Ще раз\n" << "\t0 - Повернутися у меню\n"
						<< "\tq - Вихiд\n\n";
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
