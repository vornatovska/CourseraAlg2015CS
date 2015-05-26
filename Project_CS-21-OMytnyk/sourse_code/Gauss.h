//заголовочний файл класу gauss.h
//інтерфейс класу
#include "Input.h"
#include <iostream>
#include <math.h>
#include <process.h>
#include <conio.h>
#include <iomanip>


using namespace std;

//оголошення класу

class gauss:public input //ім'я класу
{
	private: //специфікатор доступу private
		double max_el, koef[10];
		
	public://специфікатор доступу public
	 
	    gauss(); //конструктор
		
		void echo_matr (); //вивід отриманої матриці
		void gauss_elimination(); //реалізація методу Гауса
		void tr_matr (); //вивід трикутної  матриці
		void gauss_output_cons(); //вивід коренів СЛАР на екран
	    void gauss_output_txt();//вивід коренів СЛАР у файл
		 
	
		~gauss () //деструктор
		{
			delete [] x;
			for (i = 0; i<n; i++){
				delete [] a[i];
			}
			delete [] a;
		}
};//кінець оголошення класу
