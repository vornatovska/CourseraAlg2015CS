//������������ ���� ����� gauss.h
//��������� �����
#include "Input.h"
#include <iostream>
#include <math.h>
#include <process.h>
#include <conio.h>
#include <iomanip>


using namespace std;

//���������� �����

class gauss:public input //��'� �����
{
	private: //������������ ������� private
		double max_el, koef[10];
		
	public://������������ ������� public
	 
	    gauss(); //�����������
		
		void echo_matr (); //���� �������� �������
		void gauss_elimination(); //��������� ������ �����
		void tr_matr (); //���� ��������  �������
		void gauss_output_cons(); //���� ������ ���� �� �����
	    void gauss_output_txt();//���� ������ ���� � ����
		 
	
		~gauss () //����������
		{
			delete [] x;
			for (i = 0; i<n; i++){
				delete [] a[i];
			}
			delete [] a;
		}
};//����� ���������� �����
