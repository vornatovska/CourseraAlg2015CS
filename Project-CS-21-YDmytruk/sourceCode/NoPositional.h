#ifndef NOPOSITIONAL_H_
#define NOPOSITIONAL_H_
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
using namespace std;

class NoPositional { // клас позиційної системи числення
protected:
	int x; // число у позиційній системі числення
	int size; // кількість символів у числі
public:
	char *str;
	NoPositional(); //конструктор
	virtual ~NoPositional(); // віртуальний деструктор
	virtual int ToDec() { // віртуальний метод для переведення у десяткову с-му числення
		return 0;
	} // віртуальний метод для переведення чисел у десяткову систему числення
};
class Roman: public NoPositional {
public:
	int ToDec(); // переведення у десяткову с-му числення
};

#endif /* NOPOSITIONAL_H_ */
