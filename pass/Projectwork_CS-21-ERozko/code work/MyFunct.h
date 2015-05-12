#ifndef MyFunct_H
#define MyFunct_H

#include <string>
#include <conio.h>
#include <windows.h>

#include "FileFunct.h"
#include "RSA.h"


// Прототипи функцiй
void printLine(char whatPrint = '_',unsigned long length = 80);	// Функцiя виводить стмвол '_' 78 раз, малює умовну лiнiю
void exitProg(Text& t, MyFile& f);						// Функцiя реалiзує завершення програми i зберiгання данi у файли
void outputText(Text& text);							// Функцiя, яка виводить iнформацiю про введенi данi (текст)
void encrypt(Text& text);								// Функцiя шифрування тексту
void unencrypt(Text& text);								// Функцiя дешифрування тексту
void saveSattings(Text& t);								// Функцiя зберiгає ключi в файл
void loadFile(Text& text,MyFile& file);					// Фукнцiя для завантеження даних (тексту) з файлу
void saveFile(Text& text, MyFile& file);				// Фукнцiя для збереження даних (тексту) в файлу
void inputKey(Text& text);								// Функцiя для введення ключiв
void menu (Text& text, MyFile& file, string whatToDo);	// Пiдменю
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Опис функцiй
void MainMenu(Text& _text, MyFile& _file)  //  Функцiя головного меню
{
	char answ = '0';
	setlocale(LC_ALL, "rus");
	do 
	{
		system("color 1f");
		cout << "\n\t\t ===== Виберiть комаду ===== \n"
			<< "\n\t 1 - Вивести данi"
			<< "\n\n\t 2 - Зашифрувати данi"
			<< "\n\t 3 - Розшифрувати данi"
			<< 	"\n\n\t 4 - Зберегти данi у файл"
			<< "\n\t 5 - Завантажити данi iз файлу"
			<< "\n\n\t 0 - Вихiд \n";

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
				menu(_text,_file,"шифрування");
				printLine();
				_getch();break;
			}
		case '3':
			{
				printLine();
				menu(_text, _file,"дешифрування");
				printLine();
				_getch();break;
			}
		case '4':
			{
				printLine();
				saveFile(_text,_file);
				cout << "\n Данi збереженi в файл";
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
		<< "\n\t 1 - "<<whatToDo<<" данi з програми"
		<< "\n\t 2 - ввести данi"
		<< "\n\t 3 - зчитати данi з файлу"
		<< "\n\n\t 0 - назад \n";

	char answ = '9';

	while(!(answ =='1' || answ =='2' || answ == '0'  || answ == '3'))
		answ = _getch();

	if (text.get_data() == " - empty - " && answ == '1')
	{
		answ = '2';
		cout << "\n Нiчого не введено\n";
	}

	switch (answ)
	{
	case '1':
		{
			if(whatToDo == "шифрування" && !text.show_status())
			{	
				encrypt(text);
				saveFile(text,file);
			}
			else if (whatToDo == "дешифрування" && text.show_status())
			{
				unencrypt(text);
				saveFile(text,file);
			}
			else 
				cout << "\n Неможливо \n";

			outputText(text);

			break;
			_getch();
		}
	case '2':
		{
			cout << "\n Веведiть данi для "<<whatToDo<<" : " ;
			string temp;
			getline(cin,temp);
			text.set_data(temp);	

			cout << "\n Ввести ключi для "<<whatToDo<<" ? (y/n) ";

			char answ = '\0';
			answ = _getche();


			if (answ == 'y')
			{
				inputKey(text);
			}						  	
			if(whatToDo == "шифрування")
			{	
				
				encrypt(text);
				saveFile(text,file);
			}
			else if (whatToDo == "дешифрування")
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
			
			if(whatToDo == "шифрування" && !text.show_status())
			{
				encrypt(text);
				saveFile(text,file);
			}
			else if (whatToDo == "дешифрування" && text.show_status())
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

	rsa.encrypt ();									// Шифрування
	text.setCrypted( rsa.getCrypted() );			// Передача даних в об'єкт "Текст"
	text.setOpenKey( rsa.getOpentKey());			//
	text.setSecretKey( rsa.getSecretKey());			//
	text.setN( rsa.getN());							// ----------------------------
	if (!text.show_status()) text.change_status();	// Вказання, що стан "Тексту" захифрований
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
		cout << "\n Данi (не зашифрованi) : \n" ;
		printLine('.');
		cout << endl << text.get_data() << endl;
		printLine('.');
	}
	else 
	{
		cout << "\n Данi (зашифрованi) : \n" ;
		printLine('.');
		cout << endl;
		text.outputCryptedText();
		cout << endl;
		printLine('.');
		cout << "\n Вiдкритий ключ (E) = " << text.getOpenKey()
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
		cout << "\n Данi не завантажено!\n";
	else
		cout << "\n Данi завантажено\n";

	if (settings.loadFile(text,"settings"))  
	{
		if (text.show_status())
		{
			cout << "\n Файл ( settings.key ) iз ключами не знайдено. Ввести ключi? (y/n) ";
			char answer = '\0';

			while(answer != 'n' && answer != 'y')
				answer = _getche();


			if(answer == 'y')
				inputKey(text);
			else if (answer == 'n')
			{
				cout << "\n Дешифрування без ключiв не можливе\n";
				return;
			}
		}

	}
}
void inputKey(Text& text)
{
	unsigned long temp;
	cout << "\n Введiть вiдкритий ключ (E) ";
	cin >> temp;
	text.setOpenKey(temp);
	cout << "\n Введiть закритий ключ (D) ";
	cin >> temp;
	text.setSecretKey(temp);
	cout << "\n Введiть число N ";
	cin >> temp;
	text.setN(temp);
}


#endif