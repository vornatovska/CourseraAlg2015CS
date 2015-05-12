#ifndef MyFunct_H
#define MyFunct_H

#include <string>
#include <conio.h>
#include <windows.h>

#include "FileFunct.h"
#include "RSA.h"


// ��������� �����i�
void printLine(char whatPrint = '_',unsigned long length = 80);	// �����i� �������� ������ '_' 78 ���, ����� ������ �i�i�
void exitProg(Text& t, MyFile& f);						// �����i� ����i�� ���������� �������� i ����i����� ���i � �����
void outputText(Text& text);							// �����i�, ��� �������� i�������i� ��� ������i ���i (�����)
void encrypt(Text& text);								// �����i� ���������� ������
void unencrypt(Text& text);								// �����i� ������������ ������
void saveSattings(Text& t);								// �����i� ����i�� ����i � ����
void loadFile(Text& text,MyFile& file);					// �����i� ��� ������������ ����� (������) � �����
void saveFile(Text& text, MyFile& file);				// �����i� ��� ���������� ����� (������) � �����
void inputKey(Text& text);								// �����i� ��� �������� ����i�
void menu (Text& text, MyFile& file, string whatToDo);	// �i�����
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// ���� �����i�
void MainMenu(Text& _text, MyFile& _file)  //  �����i� ��������� ����
{
	char answ = '0';
	setlocale(LC_ALL, "rus");
	do 
	{
		system("color 1f");
		cout << "\n\t\t ===== �����i�� ������ ===== \n"
			<< "\n\t 1 - ������� ���i"
			<< "\n\n\t 2 - ����������� ���i"
			<< "\n\t 3 - ������������ ���i"
			<< 	"\n\n\t 4 - �������� ���i � ����"
			<< "\n\t 5 - ����������� ���i i� �����"
			<< "\n\n\t 0 - ���i� \n";

		answ = _getch();

		switch(answ)
		{
		case '1':
			{
				printLine();
				outputText(_text);
				printLine();
				_getch();break;
			}
		case '2':
			{
				printLine();
				menu(_text,_file,"����������");
				printLine();
				_getch();break;
			}
		case '3':
			{
				printLine();
				menu(_text, _file,"������������");
				printLine();
				_getch();break;
			}
		case '4':
			{
				printLine();
				saveFile(_text,_file);
				cout << "\n ���i ��������i � ����";
				printLine();
				_getch();break;
			}
		case '5':
			{
				printLine();
				loadFile(_text,_file);
				outputText(_text);
				printLine();
				_getch();break;
			}
		case '0': 
			{
				printLine();
				exitProg( _text, _file);
				return;
			}
		}
		system("cls");
	} while (1);
}

void menu(Text& text, MyFile& file, string whatToDo)
{

	cout << "\n \t\t === "<< whatToDo <<" ===\n"
		<< "\n\t 1 - "<<whatToDo<<" ���i � ��������"
		<< "\n\t 2 - ������ ���i"
		<< "\n\t 3 - ������� ���i � �����"
		<< "\n\n\t 0 - ����� \n";

	char answ = '9';

	while(!(answ =='1' || answ =='2' || answ == '0'  || answ == '3'))
		answ = _getch();

	if (text.get_data() == " - empty - " && answ == '1')
	{
		answ = '2';
		cout << "\n �i���� �� �������\n";
	}

	switch (answ)
	{
	case '1':
		{
			if(whatToDo == "����������" && !text.show_status())
			{	
				encrypt(text);
				saveFile(text,file);
			}
			else if (whatToDo == "������������" && text.show_status())
			{
				unencrypt(text);
				saveFile(text,file);
			}
			else 
				cout << "\n ��������� \n";

			outputText(text);

			break;
			_getch();
		}
	case '2':
		{
			cout << "\n �����i�� ���i ��� "<<whatToDo<<" : " ;
			string temp;
			getline(cin,temp);
			text.set_data(temp);	

			cout << "\n ������ ����i ��� "<<whatToDo<<" ? (y/n) ";

			char answ = '\0';
			answ = _getche();


			if (answ == 'y')
			{
				inputKey(text);
			}						  	
			if(whatToDo == "����������")
			{	
				
				encrypt(text);
				saveFile(text,file);
			}
			else if (whatToDo == "������������")
			{
				unencrypt(text);
				saveFile(text,file);
			}

			outputText(text);
			
			break;
			_getch();
		}
	case '3':
		{
			loadFile(text,file);
			
			if(whatToDo == "����������" && !text.show_status())
			{
				encrypt(text);
				saveFile(text,file);
			}
			else if (whatToDo == "������������" && text.show_status())
			{					
				unencrypt(text);
				saveFile(text,file);
			}

			outputText(text);
			
			break;
			_getch();
		}
	case '0':
		return;

	default:;
	}

}

void encrypt(Text& text)
{
	RSA rsa ( text.get_data(),text.getOpenKey(),text.getSecretKey(),text.getN());

	rsa.encrypt ();									// ����������
	text.setCrypted( rsa.getCrypted() );			// �������� ����� � ��'��� "�����"
	text.setOpenKey( rsa.getOpentKey());			//
	text.setSecretKey( rsa.getSecretKey());			//
	text.setN( rsa.getN());							// ----------------------------
	if (!text.show_status()) text.change_status();	// ��������, �� ���� "������" ������������
}
void unencrypt(Text& text)
{
	RSA rsa ( text.getCrypted(),text.getOpenKey(),text.getSecretKey(),text.getN());
	text.set_data(  rsa.unencrypt() );
	if (text.show_status()) text.change_status();
}

void outputText(Text& text)
{
	setlocale(LC_ALL,NULL);
	if (!text.show_status())
	{
		cout << "\n ���i (�� ����������i) : \n" ;
		printLine('.');
		cout << endl << text.get_data() << endl;
		printLine('.');
	}
	else 
	{
		cout << "\n ���i (����������i) : \n" ;
		printLine('.');
		cout << endl;
		text.outputCryptedText();
		cout << endl;
		printLine('.');
		cout << "\n �i������� ���� (E) = " << text.getOpenKey()
			<< "\n N = " << text.getN() << endl;
	}
}
void saveFile(Text& text, MyFile& file)
{
	file.saveFile( text);
	saveSattings(text);
}
void printLine(char whatPrint,unsigned long length)
{
	unsigned long i=0;
	cout << "\n ";
	while(i++ < length - 2)
		cout << whatPrint;
	cout << " \n";
}
void exitProg(Text& t, MyFile& f)
{
	f.saveFile(t);

	saveSattings(t);
	cout<< "\n Exit ... \n";
	exit(1);
}
void saveSattings(Text& t)
{
	MyFile settings("settings.key","wt");
	settings.saveFile(t,"settings");
}
void loadFile(Text& text, MyFile& file)
{
	MyFile settings("settings.key","rt");
	if (file.loadFile(text)	) 
		cout << "\n ���i �� �����������!\n";
	else
		cout << "\n ���i �����������\n";

	if (settings.loadFile(text,"settings"))  
	{
		if (text.show_status())
		{
			cout << "\n ���� ( settings.key ) i� ������� �� ��������. ������ ����i? (y/n) ";
			char answer = '\0';

			while(answer != 'n' && answer != 'y')
				answer = _getche();


			if(answer == 'y')
				inputKey(text);
			else if (answer == 'n')
			{
				cout << "\n ������������ ��� ����i� �� �������\n";
				return;
			}
		}

	}
}
void inputKey(Text& text)
{
	unsigned long temp;
	cout << "\n ����i�� �i������� ���� (E) ";
	cin >> temp;
	text.setOpenKey(temp);
	cout << "\n ����i�� �������� ���� (D) ";
	cin >> temp;
	text.setSecretKey(temp);
	cout << "\n ����i�� ����� N ";
	cin >> temp;
	text.setN(temp);
}


#endif