#include<iostream>
#include<math.h>
                                           
using namespace std;


class CreateMatrix
{
	private:
		int Rows;
		int Cols;
		double **M;

	public:
		void set();
		void get();
		double **create(int Row, int Col);
};


double** CreateMatrix::create(int Row, int Col)
{
	Rows=Row;
	Cols=Col;
	
	M=new double*[Rows];
	for(int i=0; i<Rows; i++)
	{
		M[i]=new double [Cols];
		for(int j=0; j<Cols; j++)
		{
			M[i][j]=0;
		}
	}
		return M;
}


void CreateMatrix::set()
{
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			cin>>M[i][j];
		}
	}
}


void CreateMatrix::get()
{
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			cout<<M[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}


class MatrixOperation
{
	public:
		void addition(double**a, double**b, int n, int m);
		void multiplication(double**a, int n, int m, double**b, int k, int l);
		double determ(double** Arr, int size);
};

		
void MatrixOperation::addition(double**a, double**b, int n, int m)
{
	double **c = new double*[n];		
	for(int i = 0; i < m; i++)
	{
		c[i] = new double [m];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
		}
}
	
	
void MatrixOperation::multiplication(double**a, int n, int m, double**b, int k, int l)
{
	double **c = new double*[n];
	for(int i = 0; i < l; i++)
	{
		c[i] = new double [l];
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<l; j++)
		{
			for(int g=0; g<m; g++)
			{
				c[i][j]+=a[i][g]*b[g][j];
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<l; j++)
		{
			cout<<c[i][j]<<' ';
		}
		cout<<endl;
	}			
		
}
		
		
double MatrixOperation::determ(double** Arr, int size)
{
int i,j;
double det=0;
double** matr;
	if(size==1)
	{
		det=Arr[0][0];
	}
	else if(size==2)
	{
		det=Arr[0][0]*Arr[1][1]-Arr[0][1]*Arr[1][0];
	}
	else
	{
		matr=new double*[size-1];
		for(i=0;i<size;++i)
		{
			for(j=0;j<size-1;++j)
			{
				if(j<i) 
					matr[j]=Arr[j];
				else
					matr[j]=Arr[j+1];
			}
		det+=pow((double)-1, (i+j))*determ(matr, size-1)*Arr[i][size-1];
		
		}
	delete[] matr;
	}
return det;
}


