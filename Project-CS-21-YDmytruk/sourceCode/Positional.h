#ifndef POSITIONAL_H_
#define POSITIONAL_H_
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

class Positional { // ���� ��������� ������� ��������
protected:
	int i; //�������� ��� �����, ����� �� ������� � ������ � ���� �� ��������.
	int x; //����� � ��������� ������ ��������
	int size; // ������� ������� � ����
	int power; // ������
public:
	char *str; // �������� �� ������ ������ ������
	Positional(); // �����������
	virtual ~Positional() { // ����������
		delete[] str;
		size = 0;
		x = 0;
		power = 0;
	}

	virtual int ToDec() { // ���������� ����� ��� ����������� � ��������� ������� ��������
		return 0;
	}

	void GetNumber(); // ���� ����� �� �����
	void setNumber(); // ��� ����� � ������
};

class Binary: public Positional { // ����-�������, ������� �-�� ��������
public:

	int ToDec(); // ����������� � ��������� �-�� ��������
};

class Decimal: public Positional { // ����-�������, ��������� �-�� ��������
public:
	Decimal(int); // ����������� � ����������
	Decimal(); //�����������
	void ToBin(); // ����������� � ������� �-�� ����.
	void ToHex(); // ����������� � �������������� �-�� ����.
	void ToOct(); // ����������� � ������� �-�� ����.
	void ToArbBas(int); // ����������� � �-�� ����. �� ������� �������
	void ToRom(); // ����������� � ������� �-�� ����.

};

class Octal: public Positional { // ����-�������, ������� �-�� ��������
public:
	int ToDec(); // ����������� � ��������� �-�� ��������
};

class Hexal: public Positional { // ����-�������, �������������� �-�� ��������
public:
	int ToDec(); // ����������� � ��������� �-�� ��������

};

#endif /* POSITIONAL_H_ */
