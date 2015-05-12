#include"parser.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string Parser::GetName(string sourceLine)
{
	//istringstream(string("11")) � k;
	char* tmpName = new char[sourceLine.length()];
	int nameLength = 0;

	//�������� �������, � ���� �� ����� ��� ������ - ������� �� ���� ���� ��'��
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
	//����� ������ � ������ ������, ��� ���������� �������� � ����
	vector<string> strRate = vector<string>();
	//�� ����, ���� ��� �� ����������� ������ � �����.
	stringstream ss;
	//��������� ������ � �������
	string tmpStrRate = "";

	//�����, ��� ����� �� ����� ���������� "�����" �����.
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
				//�����'������� ������, ��� ������ �����.
				strRate.push_back(tmpStrRate);
				//�������� ��� ���������� ���� ������-�����.
				tmpStrRate = "";
				isNumb = false;
			}
		}
	}

	//������������ ������ � ����� (string -> int)
	vector<int> retRate = vector<int>();

	for (int i = 0; i < strRate.size(); i++)
	{
		int tmpNumb = 0;
		
		ss<<strRate[i];
		ss>>tmpNumb;
		ss.clear();
		//�����'������� �����.
		retRate.push_back(tmpNumb);
	}
	return retRate;
}