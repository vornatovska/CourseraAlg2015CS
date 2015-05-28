#include "NoPositional.h"

using namespace std;

NoPositional::NoPositional() {
	x = 0;
	str = new char[256];
	cout << "\t";
	cin >> str;
	size = strlen(str);
}

NoPositional::~NoPositional() {
	delete[] str;
	size = 0;
	x = 0;
}
int Roman::ToDec() {
	int a, c=0, c1;
	for (int i = 0; i < size; i++) {
		c1 = c;
		switch (str[i]) {
		case 'I':
			c = 1;
			break;
		case 'V':
			c = 5;
			break;
		case 'X':
			c = 10;
			break;
		case 'L':
			c = 50;
			break;
		case 'C':
			c = 100;
			break;
		case 'D':
			c = 500;
			break;
		case 'M':
			c = 1000;
			break;
		}
		if (c > c1)
			a = -2 * c1;
		else
			a = 0;
		x += a + c;
	};
	return x;
}

