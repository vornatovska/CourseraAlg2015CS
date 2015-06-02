#ifndef NOPOSITIONAL_H_
#define NOPOSITIONAL_H_
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
using namespace std;

class NoPositional { // ���� ��������� ������� ��������
protected:
	int x; // ����� � ��������� ������ ��������
	int size; // ������� ������� � ����
public:
	char *str;
	NoPositional(); //�����������
	virtual ~NoPositional(); // ���������� ����������
	virtual int ToDec() { // ���������� ����� ��� ����������� � ��������� �-�� ��������
		return 0;
	} // ���������� ����� ��� ����������� ����� � ��������� ������� ��������
};
class Roman: public NoPositional {
public:
	int ToDec(); // ����������� � ��������� �-�� ��������
};

#endif /* NOPOSITIONAL_H_ */
