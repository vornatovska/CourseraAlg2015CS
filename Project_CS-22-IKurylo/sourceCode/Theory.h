#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

class Theory
{
public: void Plus()
		{
			setlocale(LC_ALL, ".1251");

			ifstream ifile("teoria.txt", ios::in | ios::binary);

			 char str[1024];

			ifile.getline(str, 1024);
		    cout << str << endl;
			ifile.getline(str, 1024);
		    cout << str << endl;
			ifile.getline(str, 1024);
		    cout << str << endl;
			
		}

	 void Minus()
		{
			setlocale(LC_ALL, ".1251");
			ifstream ifile("teoria.txt", ios::in | ios::binary);

			char str[1024];

			ifile.getline(str, 1024);
		    cout << str << endl;

				ifile.getline(str, 1024);
				ifile.getline(str, 1024);

				ifile.getline(str, 1024);
			cout << str << endl;
				ifile.getline(str, 1024);
			cout << str << endl;
			
		}
	 void Dobutok()
		{
			setlocale(LC_ALL, ".1251");
			ifstream ifile("teoria.txt", ios::in | ios::binary);

			char str[1024];

			ifile.getline(str, 1024);
		    cout << str << endl;

				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);

				ifile.getline(str, 1024);
			cout << str << endl;
				ifile.getline(str, 1024);
			cout << str << endl;
		}
	 void Det()
		{
			setlocale(LC_ALL, ".1251");
			ifstream ifile("teoria.txt", ios::in | ios::binary);

			char str[1024];

			ifile.getline(str, 1024);
		    cout << str << endl;

				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);

				ifile.getline(str, 1024);
			cout << str << endl;
				ifile.getline(str, 1024);
			cout << str << endl;
		}

	  void Tran()
	  {
		  setlocale(LC_ALL, ".1251");
		  	ifstream ifile("teoria.txt", ios::in | ios::binary);

			char str[1024];

			ifile.getline(str, 1024);
		    cout << str << endl;

				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
			ifile.getline(str, 1024);
				ifile.getline(str, 1024);
			ifile.getline(str, 1024);
				ifile.getline(str, 1024);
			ifile.getline(str, 1024);
			ifile.getline(str, 1024);
						
				
				ifile.getline(str, 1024);
			cout << str << endl;
				ifile.getline(str, 1024);
			cout << str << endl;

	  }

	   void Skalar()
	  {
		  setlocale(LC_ALL, ".1251");
		  ifstream ifile("teoria.txt", ios::in | ios::binary);

			char str[1024];

			ifile.getline(str, 1024);
		    cout << str << endl;

				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
				ifile.getline(str, 1024);
		
				ifile.getline(str, 1024);
			cout << str << endl;
				ifile.getline(str, 1024);
			cout << str << endl;
	  }
};