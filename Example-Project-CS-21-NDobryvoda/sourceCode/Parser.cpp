#include"parser.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string Parser::GetName(string sourceLine)
{
	//istringstream(string("11")) » k;
	char* tmpName = new char[sourceLine.length()];
	int nameLength = 0;

	//аналізуємо символи, і якщо це букви або пробіли - значить це може бути ім'ям
	for (int i = 0; i < sourceLine.length(); i++)
		if (
			(sourceLine[i] >= 'A' && sourceLine[i] <= 'Z') ||
			(sourceLine[i] >= 'a' && sourceLine[i] <= 'z') || sourceLine[i] == ' ')
		{
		tmpName[nameLength++] = sourceLine[i];
		}
		else
			break;

	tmpName[nameLength] = '\0';
	for (int i = nameLength - 1; i >= 0; i--)
		if (tmpName[i] == ' ')
			tmpName[i] = '\0';
		else
			break;

	return string(tmpName);
}

vector<int> Parser::GetRate(string sourceLine)
{
	sourceLine += ".";
	//масив оцінок у вигляді стрічок, для подальшого парсингу в інти
	vector<string> strRate = vector<string>();
	//це потік, який знає як перетворити стрічку в число.
	stringstream ss;
	//тимчасова стрічка з оцінкою
	string tmpStrRate = "";

	//змінна, яка вказує чи наразі відбувається "збірка" числа.
	bool isNumb = false;

	for (int i = 0; i < sourceLine.length(); i++)
	{
		if (sourceLine[i] >= '0' && sourceLine[i] <= '9')
		{
			isNumb = true;
			tmpStrRate += sourceLine[i];
		}
		else
		{
			if (isNumb)
			{
				//запам'ятовуємо стрічку, яка містить число.
				strRate.push_back(tmpStrRate);
				//готуємось для зчитування нової стрічки-числа.
				tmpStrRate = "";
				isNumb = false;
			}
		}
	}

	//перетворюємо стрічку в число (string -> int)
	vector<int> retRate = vector<int>();

	for (int i = 0; i < strRate.size(); i++)
	{
		int tmpNumb = 0;
		
		ss<<strRate[i];
		ss>>tmpNumb;
		ss.clear();
		//запам'ятовуємо число.
		retRate.push_back(tmpNumb);
	}
	return retRate;
}