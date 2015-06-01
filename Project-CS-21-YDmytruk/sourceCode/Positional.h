#ifndef POSITIONAL_H_
#define POSITIONAL_H_
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

class Positional { // клас позиційної системи числення
protected:
	int i; //лічильник для циклів, вказує на елемент в стрічці з яким ми працюємо.
	int x; //число у позиційній системі числення
	int size; // кількість символів у числі
	int power; // степінь
public:
	char *str; // вказівник на перший символ стрічки
	Positional(); // конструктор
	virtual ~Positional() { // деструктор
		delete[] str;
		size = 0;
		x = 0;
		power = 0;
	}

	virtual int ToDec() { // віртуальний метод для переведення у десяткову систему числення
		return 0;
	}

	void GetNumber(); // вивід числа на екран
	void setNumber(); // ввід числа у стрічку
};

class Binary: public Positional { // клас-нащадок, двійкова с-ма числення
public:

	int ToDec(); // переведення у десяткову с-му числення
};

class Decimal: public Positional { // клас-нащадок, десяткова с-ма числення
public:
	Decimal(int); // конструктор з параметром
	Decimal(); //конструктор
	void ToBin(); // переведення у двійкову с-му числ.
	void ToHex(); // переведення у шістнадцяткову с-му числ.
	void ToOct(); // переведення у вісімкову с-му числ.
	void ToArbBas(int); // переведення у с-му числ. із заданою основою
	void ToRom(); // переведення у римську с-му числ.

};

class Octal: public Positional { // клас-нащадок, вісімкова с-ма числення
public:
	int ToDec(); // переведення у десяткову с-му числення
};

class Hexal: public Positional { // клас-нащадок, шістнадцяткова с-ма числення
public:
	int ToDec(); // переведення у десяткову с-му числення

};

#endif /* POSITIONAL_H_ */
