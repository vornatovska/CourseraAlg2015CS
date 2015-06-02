
#include <iostream>
#include <math.h>
#include <process.h>
#include <conio.h>
#include <iomanip>
#include <fstream>

using namespace std;
#ifndef _INPUT_H_
#define _INPUT_H_


class input 
{
	protected:
		int n,i,j;
	double *x, **a;
	static input* single;
	input(){}
	virtual ~input() {}
	
	public:
		static input* Instance()
		{
			if(!single)
			{
				single=new input();
			}
			return single;
		}
		static bool DeleteInstance()
		{
			if(single)
			{
				delete single;
				single = 0;
				return true;
			}
			return false;
		}
		void input_cons();
		void input_txt();
};//кінець оголошення класу
input* input ::single = 0;		
#endif
