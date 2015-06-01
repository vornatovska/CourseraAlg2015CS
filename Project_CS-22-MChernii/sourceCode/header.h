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
class book {
private:	
	char bno[6];
	char bookName[50]; //title of book
	char authName[20]; //author of book
public:
	void create_book() {
		cout << "\nNEW BOOK ENTRY...\n";
		cout << "\nEnter Book Number : ";
		cin >> bno;
		cout << "\n\nEnter Name of the Book : ";
		cin >> bookName;
		cout << "\n\nEnter Author's name : ";
		cin >> authName;
		cout << "\n\n\nBook Created...";
	}

	void show_book() {
		cout << "\nBook number : " << bno;
		cout << "\nBook Name : ";
		puts(bookName);
		cout << "Author Name : ";
		puts(authName);
	}

	void modify_book() {
		cout << "\nBook number : " << bno;
		cout << "\nModify Book Name : ";
		cin >> bookName;
		cout << "\nModify Author's Name : ";
		cin >> authName;
	}

	char* retbno() { return bno; }

	void report() { cout << bno << setw(30) << bookName << setw(30) << authName << endl; }

}; 

class student {
private:
	char admno[6]; //Admission number
	char name[20]; //Name of the student
	char stbno[6]; //Student Book number
	int token;
public:
	void create_student() {
		system("cls");
		cout << "\nNEW STUDENT ENTRY...\n";
		cout << "\nEnter Admission number : ";
		cin >> admno;
		cout << "\n\nEnter Name of Student : ";
		cin >> name;
		token = 0;
		stbno[0] = '/0';
		cout << "\n\nStudent Record Created..";
	}

	void show_student() {
		cout << "\nAdmission number : " << admno;
		cout << "\nStudent Name : ";
		puts(name);
		cout << "\nNumber of Book(s) issued : " << token;
		if (token == 1) cout << "\nBook No " << stbno;
	}

	void modify_student() {
		cout << "\nAdmission number : " << admno;
		cout << "\nModify Student Name : ";
		cin >> name;
	}

	char* retadmno() { return admno; }

	char* retstbno() { return stbno; }

	int rettoken() { return token; }

	void addtoken() { token = 1; }

	void resettoken() { token = 0; }

	void getstbno(char t[]) { strcpy(stbno, t); }

	void report() { cout << "\t" << admno << setw(20) << name << setw(10) << token << endl; }

};


  //***************************************************************
  // Global declaration for stream object, object
  //****************************************************************

fstream f, f1;
book b;
student s;

//***************************************************************
// Functions to write record to file
//****************************************************************

void write_book() {
	char ch;
	f.open("book.dat", ios::out | ios::app);
	do {
		system("cls");
		b.create_book();
		f.write((char*)&b, sizeof(book));
		cout << "\n\nDo you want to add more books...(y/n?)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	f.close();
}

void write_student() {
	char ch;
	f.open("student.dat", ios::out | ios::app);
	do {
		s.create_student();
		f.write((char*)&s, sizeof(student));
		cout << "\n\nDo you want to add more students...(y/n?)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	f.close();
}


//***************************************************************
// Function to read specific record from file
//****************************************************************


void display_spb(char n[]) {
	cout << "\nBOOK DETAILS\n";
	int flag = 0;
	f.open("book.dat", ios::in);
	while (f.read((char*)&b, sizeof(book))) {
		if (strcmpi(b.retbno(), n) == 0) {
			b.show_book();
			flag = 1;
		}
	}

	f.close();
	if (flag == 0) cout << "\n\nBook does not exist";
	getch();
}

void display_sps(char n[]) {
	cout << "\nSTUDENT DETAILS\n";
	int flag = 0;
	f.open("student.dat", ios::in);
	while (f.read((char*)&s, sizeof(student))) {
		if ((strcmpi(s.retadmno(), n) == 0)) {
			s.show_student();
			flag = 1;
		}
	}
	f.close();
	if (flag == 0) cout << "\n\nStudent does not exist";
	getch();
}


//***************************************************************
// Functions to modify records of file
//****************************************************************


void modify_book() {
	char n[6];
	int found = 0;
	system("cls");
	cout << "\n\n\tMODIFY BOOK REOCORD.... ";
	cout << "\n\n\tEnter The book no. of The book";
	cin >> n;
	f.open("book.dat", ios::in | ios::out);
	while (f.read((char*)&b, sizeof(book)) && found == 0) {
		if (strcmpi(b.retbno(), n) == 0) {
			b.show_book();
			cout << "\nEnter New Details of Book" << endl;
			b.modify_book();
			int pos = -1 * sizeof(b);
			f.seekp(pos, ios::cur);
			f.write((char*)&b, sizeof(book));
			cout << "\n\n\t Record Updated";
			found = 1;
		}
	}

	f.close();
	if (found == 0) cout << "\n\n Record Not Found ";
	getch();
}


void modify_student() {
	char n[6];
	int found = 0;
	system("cls");
	cout << "\n\n\tMODIFY STUDENT RECORD... ";
	cout << "\n\n\tEnter Admission number of Student";
	cin >> n;
	f.open("student.dat", ios::in | ios::out);
	while (f.read((char*)&s, sizeof(student)) && found == 0) {
		if (strcmpi(s.retadmno(), n) == 0) {
			s.show_student();
			cout << "\nEnter The New Details of student" << endl;
			s.modify_student();
			int pos = -1 * sizeof(s);
			f.seekp(pos, ios::cur);
			f.write((char*)&s, sizeof(student));
			cout << "\n\n\t Record Updated";
			found = 1;
		}
	}
	f.close();
	if (found == 0) cout << "\n\n Record Not Found ";
	getch();
}

//***************************************************************
// Function to Delete record of file
//****************************************************************

void delete_student() {
	char n[6];
	int flag = 0;
	system("cls");
	cout << "\n\n\n\tDELETE STUDENT...";
	cout << "\n\nEnter The admission no. of the Student You Want To Delete : ";
	cin >> n;
	f.open("student.dat", ios::in | ios::out);
	fstream f2;
	f2.open("Temp.dat", ios::out);
	f.seekg(0, ios::beg);
	while (f.read((char*)&s, sizeof(student))) {
		if (strcmpi(s.retadmno(), n) != 0) f2.write((char*)&s, sizeof(student));
		else flag = 1;
	}

	f2.close();
	f.close();
	remove("student.dat");
	rename("Temp.dat", "student.dat");
	if (flag == 1) cout << "\n\n\tRecord Deleted ..";
	else cout << "\n\nRecord not found";
	getch();
}


void delete_book() {
	char n[6];
	system("cls");
	cout << "\n\n\n\tDELETE BOOK ...";
	cout << "\n\nEnter Book number of Book to Delete : ";
	cin >> n;
	f.open("book.dat", ios::in | ios::out);
	fstream f2;
	f2.open("Temp.dat", ios::out);
	f.seekg(0, ios::beg);
	while (f.read((char*)&b, sizeof(book))) if (strcmpi(b.retbno(), n) != 0)                          f2.write((char*)&b, sizeof(book));
	f2.close();
	f.close();
	remove("book.dat");
	rename("Temp.dat", "book.dat");
	cout << "\n\n\tRecord Deleted ..";
	getch();
}



//***************************************************************
// Function to display all students list
//****************************************************************

void display_alls() {
	system("cls");
	f.open("student.dat", ios::in);
	if (!f) {
		cout << "ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout << "\n\n\t\tSTUDENT LIST\n\n";
	cout << "==================================================================\n";
	cout << "\tAdmission No." << setw(10) << "Name" << setw(20) << "Book Issued\n";
	cout << "==================================================================\n";

	while (f.read((char*)&s, sizeof(student))) s.report();

	f.close();
	getch();
}


//***************************************************************
// Function to display Books list
//****************************************************************

void display_allb() {
	system("cls");
	f.open("book.dat", ios::in);
	if (!f) {
		cout << "ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}
	cout << "\n\n\t\tBook LIST\n\n";
	cout << "=========================================================================\n";
	cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author\n";
	cout << "=========================================================================\n";
	while (f.read((char*)&b, sizeof(book))) b.report();
	f.close();
	getch();
}



//***************************************************************
//      function to issue book
//****************************************************************

void book_issue() {
	char sn[6], bn[6];
	int found = 0, flag = 0;
	system("cls");
	cout << "\n\nBOOK ISSUE ...";
	cout << "\n\n\tEnter Student's Admission number : ";
	cin >> sn;
	f.open("student.dat", ios::in | ios::out);
	f1.open("book.dat", ios::in | ios::out);
	while (f.read((char*)&s, sizeof(student)) && found == 0) {
		if (strcmpi(s.retadmno(), sn) == 0) {
			found = 1;
			if (s.rettoken() == 0) {
				cout << "\n\n\tEnter Book number : ";
				cin >> bn;
				while (f1.read((char*)&b, sizeof(book)) && flag == 0) {
					if (strcmpi(b.retbno(), bn) == 0) {
						b.show_book();
						flag = 1;
						s.addtoken();
						s.getstbno(b.retbno());
						int pos = -1 * sizeof(s);
						f.seekp(pos, ios::cur);
						f.write((char*)&s, sizeof(student));
						cout << "\n\n\t Book issued successfully\n\nPlease Note: Write the current date in backside of your book \n and submit within 15 days fine Rs. 1 for each day \n after 15 days period";
					}
				}
				if (flag == 0) cout << "Book number does not exist";
			}
			else cout << "You have not returned the last book ";

		}
	}
	if (found == 0) cout << "Student record not exist...";
	getch();
	f.close();
	f1.close();
}

//***************************************************************
// Function to deposit book
//****************************************************************

void book_deposit()
{
	char sn[6], bn[6];
	int found = 0, flag = 0, day, fine;
	system("cls");
	cout << "\n\nBOOK DEPOSIT ...";
	cout << "\n\n\tEnter Student’s Admission number : ";
	cin >> sn;
	f.open("student.dat", ios::in | ios::out);
	f1.open("book.dat", ios::in | ios::out);
	while (f.read((char*)&s, sizeof(student)) && found == 0) {
		if (strcmpi(s.retadmno(), sn) == 0) {
			found = 1;
			if (s.rettoken() == 1) {
				while (f1.read((char*)&b, sizeof(book)) && flag == 0) {
					if (strcmpi(b.retbno(), s.retstbno()) == 0) {
						b.show_book();
						flag = 1;
						cout << "\n\nBook deposited in no. of days : ";
						cin >> day;
						if (day > 15) {
							fine = (day - 15) * 1;
							cout << "\n\nFine to deposited is Rs. " << fine;
						}
						s.resettoken();
						int pos = -1 * sizeof(s);
						f.seekp(pos, ios::cur);
						f.write((char*)&s, sizeof(student));
						cout << "\n\n\t Book deposited successfully";
					}
				}
				if (flag == 0)cout << "Book no does not exist";
			}
			else cout << "No book is issued..please check!!";
		}
	}
	if (found == 0) cout << "Student record not exist...";
	getch();
	f.close();
	f1.close();
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}
void intro() {
	system("cls");
	gotoxy(35, 11);
	cout << "LIBRARY";
	gotoxy(35, 14);
	cout << "MANAGEMENT";
	gotoxy(35, 17);
	cout << "SYSTEM";
	cout << "\n\nMADE BY : M_CHERNII_CS-22";
	getch();
}


