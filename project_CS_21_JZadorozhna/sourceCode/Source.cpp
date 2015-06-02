#include<iostream>
#include<math.h>
#include"Header.h"

using namespace std;

int main(){

	int a, b, c, d;
	double det = 0;
	double **M1, **M2;
	MatrixOperation result_obj;
	CreateMatrix obj1, obj2;
	char s = ' ';

	while (s != '0'){
		cout << "Menu:" << endl;
		cout << "1 - Addition" << endl;
		cout << "2 - Multiplication" << endl;
		cout << "3 - Determinant" << endl;
		cout << "0 - Exit" << endl<<endl;

		cout << "Choose option: ";
		cin >> s;
		cout << endl;

		if (s == '0')
			break;

		switch (s){
		case '1':{

			cout << "Enter number of rows = ";
			cin >> a;
			cout << "Enter number of columns = ";
			cin >> b;
			c = a;	d = b;
			M1 = obj1.create(a, b);
			M2 = obj2.create(c, d);

			cout << endl << "Enter elements of 1 matrix:" << endl;
			obj1.set();
			cout << "Enter elements of 2 matrix:" << endl;
			obj2.set();
			cout << endl;

			cout << "Result matrix:"<<endl;
			result_obj.addition(M1, M2, a, b);
			cout << endl;
			break;
		}
		case '2':{

			cout << "Enter number of rows for 1 matrix: ";
			cin >> a;
			cout << "Enter number of columns for 1 matrix: ";
			cin >> b;
			cout << "Enter number of rows for 2 matrix: ";
			cin >> c;
			cout << "Enter number of columns for 2 matrix: ";
			cin >> d;
			cout << endl;

			if (b != c){
				cout << "error" << endl << endl;
			}

			else{
				M1 = obj1.create(a, b);
				M2 = obj2.create(c, d);

				cout << "Enter elements of 1 matrix:" << endl;
				obj1.set();
				cout << "Enter elements of 2 matrix:" << endl;
				obj2.set();
				cout << endl;

				cout << "Result matrix:"<<endl;
				result_obj.multiplication(M1, a, b, M2, c, d);
				cout << endl;
			}
			break;
		}
		case '3':{
			cout << "Enter number of rows and columns = ";
			cin >> a;
			cout << endl;
			b = a;
			
			M1 = obj1.create(a, b);

			cout << "Enter matrix elements:" << endl;
			obj1.set();
			cout << endl;

			det = result_obj.determ(M1, a);
			cout << "det = " << det << endl;
			cout << endl;

			break;
		}

		default:
			break;
		}
	}
	return 0;
}
