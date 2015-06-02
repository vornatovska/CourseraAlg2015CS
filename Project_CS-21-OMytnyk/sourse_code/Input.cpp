//файл реал≥зац≥њ класу Input.cpp

using namespace std;
//п≥дключенн€ ≥нтерфейсу класу до його реал≥зац≥њ
#include "Gauss.h"
#include "Input.h"

void input::input_txt()
{	ifstream fin ("equ.txt");
	if (!fin.is_open()) 
        cout << "Ќ≈ћќ∆Ћ»¬ќ ¬≤ƒ –»“» ‘ј…Ћ!\n";
    else{
	
	fin>>n;
		x = new double [n];
	a = new double *[n];
	
	for (i = 0; i<n; i++)
	{ a[i] = new double [n+1];}
	
	for(i=0;i<n;i++)
	x[i] = 0;
		for(i=0; i<n; i++)
	for(j = 0; j<n; j++)
	{
		fin>>a[i][j];
	}
	for (i=0; i<n; i++)
	{
		fin >> a[i][n];
	}
	 fin.close();
	}
}

void input :: input_cons ()
{
	cout<<"¬ведiть кiлькiсть рiвн€нь:";
	cin>>n;
	x = new double [n];
	a = new double *[n];
	for (i = 0; i<n; i++)
	{ a[i] = new double [n+1];}
	
	for(i=0;i<n;i++)
	x[i] = 0;
	
	cout << "\n¬ведiть коефiцiЇнти матрицi"<<endl;
	
	for(i=0; i<n; i++)
	for(j = 0; j<n; j++)
	{
		cout<<"a[" << i <<"][" << j << "] = ";
		cin>>a[i][j];
	}
	cout << "\n¬ведiть стовпець вiльних членiв"<<endl;
	for (i=0; i<n; i++)
	{
		cout << "b["<< i << "] = ";
		cin >> a[i][n];
	}

}
