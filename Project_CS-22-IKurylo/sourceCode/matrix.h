#include<iostream>
#include<math.h>
                                           
using namespace std;

class Matrix
{
public: void Plus(double**a, int n, int m, double**b, int k, int l)
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
	 void Minus(double**a, int n, int m, double**b, int k, int l)
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
						c[i][j] = a[i][j] - b[i][j];
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
	 void Dobutok(double**a, int n, int m, double**b, int k, int l)
		{
			double **c = new double*[n];
					
				for(int i = 0; i < l; i++)
				{
					c[i] = new double [l];
				}

				
			  for(int j = 0; j < m; j++)
			  {
					for(int d = 0; d < l; d++)
					{
						c[j][d] = 0;
					for(int i = 0; i < n; i++)
					{ 
					
					c[j][d] += a[i][j] * b[j][d];
					
					}
				    }
			  }

			  	for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < l; j++)
					{
						cout << c[i][j] << " ";
					}
					cout << endl;
				}
		}
	 void Det(double**a, int n, int m)
		{
				double det;
				
				if(n==2)
				{
					det=(a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
					cout<<"det = "<<det;
				}
				
				if(n==3)
				{
					det=(a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[1][0]*a[2][1]*a[0][2])-(a[2][0]*a[1][1]*a[0][2]+a[2][1]*a[1][2]*a[0][0]+a[1][0]*a[0][1]*a[2][1]);
					cout<<"det = "<<det;
				}
				
				if(n<2||n>3)
				{
					cout<<"error";
				}
				cout<<endl;
		}

	  void Tran(double**a, double**b, int n, int m)
	  {


		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
				b[j][i] = a[i][j];
		}
			for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						cout << b[i][j] << " ";
					}
					cout << endl;
				}
			cout << endl;
	  }

	   void Skalar(double**a, int n, int m, double sca)
	  {

		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
				a[i][j] *= sca;
		}
			for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						cout << a[i][j] << " ";
					}
					cout << endl;
				}
			cout << endl;
	  }
};



class NewMatrix
{
public: double** Create(int n, int m)
		{
			double **a = new double*[n];
			for(int i = 0; i < n; i++)
			{
				a[i] = new double [m];
			}
		return a;
	    }
};