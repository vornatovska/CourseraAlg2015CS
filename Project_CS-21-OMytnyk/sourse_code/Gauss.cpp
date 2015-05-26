//���� ��������� ����� gauss.cpp

using namespace std;
//���������� ���������� ����� �� ���� ���������
#include "Gauss.h"
#include "Input.h"

void gauss :: gauss_output_cons ()
{
//���� ������ ���� �� �����
    cout<<endl<<setw(5)<<"����'����:"<<endl<<endl;
    for (int i=0; i<n; i++)
        cout<<"x"<<n-i<<" = "<<x[i]<<endl;
}

void gauss :: gauss_output_txt ()
{
	ofstream fout("solution.txt");
	fout<<endl<<setw(5)<<"����'����:"<<endl<<endl;
    for (int i=0; i<n; i++)
        fout<<"x"<<n-i<<" = "<<x[i]<<endl;
    cout<<"��������"<<endl;
   
}

void gauss :: echo_matr ()
{
	cout<<setw(42)<<"�������� �������"<<endl<<endl;
    //���� �� ����� �������� �������
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
        //����� ������������� �������� � �������
        for (int ch=i-1; ch<n; ch++)
        {
            double buf = a[ch][i-1];
            if (max_el<0) max_el*=(-1);
            
            if (buf<0) buf*=(-1);
          
            if (max_el<buf)
            {
                max_el = buf;
                //�����"����� ������ � ������������ ���������
                str = ch;
            }
        }
         
        //���� ������������ ������� �������� - �����
        if (max_el == 0)
        {
            cout<<"����'���� �����";
            getch();
     
        }
         //����� ����� ������
        //���� ������������ ������� �� ����������� � ��������� �����
        if (str != (i-1))
        {
            for (int ch=0; ch<n+1; ch++)
            {
                double t = a[i-1][ch];
                a[i-1][ch] = a[str][ch];
                a[str][ch] = t;
            }
        }
        //������ ����� �� ��������� �������
        for (int ch = 0; ch<n+1; ch++)
            a[i-1][ch]/=max_el;
             //�������� ���� � ������� �������
        if (a[i-1][i-1]<0)
            for (int ch=0; ch<n+1; ch++)
            {
                if (a[i-1][ch]!=0)
                    a[i-1][ch]*=(-1);
            }
            
               //����������� �����������
        for (int z=0; z<n-i; z++)
        {
            koef[z] = a[i+z][i-1]/a[i-1][i-1];
        }
 
        //�������� ����� ���������� �� �����������
        for (int k=i; k<n; k++)
                for (int j=i-1; j<n+1; j++)
                    a[k][j] -= koef[k-i]*a[i-1][j];
    }
      //����������� ������ ���� �������� �����
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
	
    cout<<endl<<setw(45)<<"�������� �������"<<endl<<endl;
    //���� �� ����� �������� �������
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n+1; j++)
            cout<<setw(10)<<a[i][j];
        cout<<endl<<endl;
    }
}
