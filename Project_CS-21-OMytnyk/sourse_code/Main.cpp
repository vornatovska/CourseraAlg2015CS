#include "Input.h"
#include "Gauss.h"

int main()
{
	setlocale(LC_ALL,".1251"); //підключення української мови
	gauss solution; //оголошення об"єкту класу
		cout<<"Виберiть спосiб вводу:"<<endl;
	cout<<"1. Iнтерфейс командного рядка"<<endl;
	cout<<"2. Файл"<<endl;
	int v;
	cin>>v;
	if(v==1)
		solution.input_cons();
	if(v==2)
		solution.input_txt();
	
	solution.echo_matr (); //вивід отриманої матриці
	solution.gauss_elimination(); //реалізація методу Гауса
	solution.tr_matr (); //вивід трикутної  матриці
	
	cout<<"Result:"<<endl;
	cout<<"1. Screen."<<endl;
	cout<<"2. File."<<endl;
	int m;
	cin>>m;
	if(m==1)
	solution.gauss_output_cons(); //вивід коренів СЛАР на екран
	if(m==2)
	solution.gauss_output_txt(); //вивід коренів СЛАР у файл

	return 0;	
}

gauss::gauss(){ //коструктор класу Gauss
	int n =1;
	x = new double [n];
	a = new double *[n];
	
	for (i = 0; i<n; i++)
	{ a[i] = new double [n+1];}
	
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j]=0;
	
	for(i=0;i<n;i++)
	x[i] = 0;	
}

void gauss :: gauss_output_cons ()
{
//вивід коренів СЛАУ на екран
    cout<<endl<<setw(5)<<"РОЗВ'ЯЗОК:"<<endl<<endl;
    for (int i=0; i<n; i++)
        cout<<"x"<<n-i<<" = "<<x[i]<<endl;
}

void gauss :: gauss_output_txt ()
{
	ofstream fout("solution.txt");
	fout<<endl<<setw(5)<<"РОЗВ'ЯЗОК:"<<endl<<endl;
    for (int i=0; i<n; i++)
        fout<<"x"<<n-i<<" = "<<x[i]<<endl;
    cout<<"ВИКОНАНО"<<endl;
   
}

void gauss :: echo_matr ()
{
	cout<<setw(42)<<"ОТРИМАНА МАТРИЦЯ"<<endl<<endl;
    //вивід на екран отриманої матриці
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n+1; j++)
            cout<<setw(10)<<a[i][j];
        cout<<endl<<endl;
    }
 
}

void gauss :: gauss_elimination ()
{
	for (int i=1; i<n+1; i++)
    {   
        int str = i-1;
        max_el = a[i-1][i-1];
        //пошук максимального елемента в стовпці
        for (int ch=i-1; ch<n; ch++)
        {
            double buf = a[ch][i-1];
            if (max_el<0) max_el*=(-1);
            
            if (buf<0) buf*=(-1);
          
            if (max_el<buf)
            {
                max_el = buf;
                //запам"ятати строку з максимальним елементом
                str = ch;
            }
        }
         
        //якщо максимальний елемент нульовий - вихід
        if (max_el == 0)
        {
            cout<<"РОЗВ'ЯЗКУ НЕМАЄ";
            getch();
     
        }
         //заміна рядків місцями
        //якщо максимальний елемент не знаходиться в поточному рядку
        if (str != (i-1))
        {
            for (int ch=0; ch<n+1; ch++)
            {
                double t = a[i-1][ch];
                a[i-1][ch] = a[str][ch];
                a[str][ch] = t;
            }
        }
        //ділення рядка на найбільший елемент
        for (int ch = 0; ch<n+1; ch++)
            a[i-1][ch]/=max_el;
             //усунення нулів з головної діагоналі
        if (a[i-1][i-1]<0)
            for (int ch=0; ch<n+1; ch++)
            {
                if (a[i-1][ch]!=0)
                    a[i-1][ch]*=(-1);
            }
            
               //знаходження коефіцієнтів
        for (int z=0; z<n-i; z++)
        {
            koef[z] = a[i+z][i-1]/a[i-1][i-1];
        }
 
        //віднімання рядків помножених на коефіцієнти
        for (int k=i; k<n; k++)
                for (int j=i-1; j<n+1; j++)
                    a[k][j] -= koef[k-i]*a[i-1][j];
    }
      //знаходження коренів СЛАР зворотнім ходом
    for (int i=n-1; i>=0; i--)
    {
        
        if (n-i-1 == 0 )
                x[0] = (a[n-1][n])/a[n-1][n-1];
        else 
        {
        for (int j=n; j>i; j-- )
            a[i][n] = a[i][n] - (a[i][j-1]*x[n-j]);
                
        x[n-i-1] = a[i][n]/a[i][i];
        }
            
    }

}

void gauss :: tr_matr()
{
	
    cout<<endl<<setw(45)<<"ТРИКУТНА МАТРИЦЯ"<<endl<<endl;
    //вивід на екран трикутної матриці
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n+1; j++)
            cout<<setw(10)<<a[i][j];
        cout<<endl<<endl;
    }
}

void input::input_txt()
{	ifstream fin ("equ.txt");
	if (!fin.is_open()) 
        cout << "НЕМОЖЛИВО ВІДКРИТИ ФАЙЛ!\n";
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
	cout<<"Введiть кiлькiсть рiвнянь:";
	cin>>n;
	x = new double [n];
	a = new double *[n];
	for (i = 0; i<n; i++)
	{ a[i] = new double [n+1];}
	
	for(i=0;i<n;i++)
	x[i] = 0;
	
	cout << "\nВведiть коефiцiєнти матрицi"<<endl;
	
	for(i=0; i<n; i++)
	for(j = 0; j<n; j++)
	{
		cout<<"a[" << i <<"][" << j << "] = ";
		cin>>a[i][j];
	}
	cout << "\nВведiть стовпець вiльних членiв"<<endl;
	for (i=0; i<n; i++)
	{
		cout << "b["<< i << "] = ";
		cin >> a[i][n];
	}

}
