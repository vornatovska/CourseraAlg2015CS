#include <iostream>

#include "text.h" // ϳ��������� ����� 'Text'-- ������ �� ����������� �������������
#include "MyFunct.h" // ��������� �� ������� ���� ���������
#include "RSA.h"

#include <conio.h>

using namespace std;

int main (int argc, char* argv[])
{
	Text new_text(" - empty - ");
	MyFile data_file("temp.dat", "rt");

	MainMenu(new_text, data_file);
	
	_getch();
	return 0;
}


