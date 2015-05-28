#include "Positional.h"

using namespace std;

Positional::Positional() {
	x = 0;
	str = new char[256];
	size = 0;
	power = 0;

	i = 0;

}
void Positional::setNumber() {
	cin >> str;
	x = atoi(str);
	size = strlen(str);
	power = size;

}
Decimal::Decimal(int a) {
	x = a;
	str = 0;
	size = 0;
	power = 0;
}
Decimal::Decimal() {
	x = 0;
	str = new char[256];
	cin >> str;
	x = atoi(str);
	size = strlen(str);
	power = size;
	i = 0;
}
void Positional::GetNumber() {
	cout << '\n';

	cout << str << endl;

}
int Binary::ToDec() {
	x = 0;
	int power = --size;
	for (i = 0; i <= size; i++) {
		x += (str[i] - '0') * pow(2, power);
		power--;
	}
	return x;
}
void Decimal::ToBin() {
	str = new char[256];
	int j = 0;
	int p;
	int k = x;
	if (k < 16)
		power = 3;

	else if (k < 256)
		power = 7;
	else if (k < 65536)
		power = 15;
	else if (k < 4294967296)
		power = 31;

	for (i = power; i >= 0; i--) {
		p = pow(2, i);
		itoa(k / p, str + j, 10);
		j++;
		k %= p;
	}
	cout << str << "\n";

}

void Decimal::ToOct() {
	str = new char[256];
	int j = 0;
	int *ptr;
	int k = x;
	ptr = new int[size];
	i = 0;

	do {
		ptr[i] = k % 8;
		k = k / 8;
		i++;

		ptr[i] = k;
	} while ((k / 8) != 0);
	if (ptr[i] == 0)
		i--;
	while (i >= 0) {
		itoa(ptr[i], str + j, 10);
		j++;

		i--;
	}
	cout << str << "\n";

}
;
void Decimal::ToHex() {
	str = new char[256];
	int j = 0;
	int *ptr;
	int k = x;
	str[0]=0;
	ptr = new int[size];
	i = 0;

	do {
		ptr[i] = k % 16;
		k = k / 16;
		i++;

		ptr[i] = k;
	} while ((k / 16) != 0);
	if (ptr[i] == 0)
		i--;
	while (i >= 0) {
		if (ptr[i] > 9) {
			str[j] = (char) ptr[i] + 55;

			j++;
		} else {
			itoa(ptr[i], str + j, 10);
			j++;

		}
		i--;
	}
	str[j]='\0';
cout<<str<<endl;
}
;
void Decimal::ToArbBas(int n) {
	str = new char[256];
	int j = 0;
	int *ptr, k;
	k = x;
	ptr = new int[size];
	i = 0;
	do {
		ptr[i] = k % n;
		k = k / n;
		i++;
		ptr[i] = k;
	} while ((k / n) > 0);
	if (ptr[i] == 0)
		i--;
	while (i >= 0) {

		if (ptr[i] > 9) {
			str[j] = (char)ptr[i] + 55;
			j++;

		} else {
			itoa(ptr[i], str + j, 10);
			j++;
		}

		i--;
	}
	str[j]='\0';
cout<<str<<endl;
}

void Decimal::ToRom() {
	str = new char[256];
	str[0] = '\0';
	int j = 0;
	int k = x;
	const char *arr1[9] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII",
			"IX" };
	const char *arr2[9] = { "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX",
			"XC" };
	const char *arr3[9] = { "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC",
			"CM" };

	if ((k / 1000) != 0)
		for (i = 0; i < k / 1000; i++) {

			strcat(str, "M");
			j++;
		}
	k %= 1000;
	if ((k / 100) != 0) {
		strcat(str, arr3[(k / 100) - 1]);
	}
	k %= 100;
	if ((k / 10) != 0) {

		strcat(str, arr2[(k / 10) - 1]);
	}
	k %= 10;
	if (k != 0) {

		strcat(str, arr1[k - 1]);
	};
	cout << str << "\n";
}

int Octal::ToDec() {
	x = 0;
	for (i = 0; i < size; i++) {
		x += (str[i] - '0') * pow(8, power - 1);
		power--;
	}
	return x;
}

int Hexal::ToDec() {
	x = 0;
	int k;
	for (i = 0; i < size; i++) {
		switch (str[i]) {
		case 'a':
		case 'A': {
			k = 10;
			break;
		}
		case 'b':
		case 'B': {

			k = 11;
			break;
		}
		case 'c':
		case 'C': {
			k = 12;
			break;
		}
		case 'd':
		case 'D': {
			k = 13;
			break;
		}
		case 'e':
		case 'E': {
			k = 14;
			break;
		}
		case 'f':
		case 'F': {
			k = 15;
			break;
		}
		default: {
			k = str[i] - '0';
			break;
		}
		};
		x += k * pow(16, power - 1);
		power--;
	};
	return x;
}

