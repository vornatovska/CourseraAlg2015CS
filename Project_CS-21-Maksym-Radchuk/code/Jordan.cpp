#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include "Jordan.h"

using namespace std;

 Jordan::Jordan()
  {
    NEQ=1;
    N1=1;
    A=new float *[NEQ];
    for (int i = 0; i<NEQ; i++){
          A[i] = new float [N1];}
      for (int i=0;i<NEQ;i++) {
         for(int j=0;j<N1;j++)
             { 
                 A[i][j]=0;
             }
             }
  }
 
 Jordan::~Jordan()
 {
  for (int count = 0; count < NEQ; count++) {   
              delete [] A[count]; 
 }
 delete [] A;
}
 void Jordan::setJordan()
   {
        cout<<"Ââåä³òü ê³ëüê³ñòü ð³âíÿíü : "; 
        cin>>NEQ;
        N1=NEQ+1;
        cout<<"ÂÂ²Ä "<<endl;
           A=new float *[NEQ];
           for (int i = 0; i<NEQ; i++)
              A[i] = new float [N1];
        for(int i=0;i<NEQ;i++)  
           for(int j=0;j<N1;j++)
           {
            cout<<"Ââåä³òü åëåìåíò ìàòðèö³["<<i+1<<"]"<<"["<<j+1<<"]=";
            cin>>A[i][j];
           }
   }
   void Jordan::fromFile(){
        ifstream in("input.txt");
    if (in == 0)
    {
        cout << "Ïîìèëêà! Ôàéë íå çíàäåíî!" << endl;
    }
    in >> NEQ;
    N1=NEQ+1;
    A = new float *[NEQ];
    for (int i = 0; i < NEQ; i++)
    {
        A[i] = new float [N1];
    }

    for (int i = 0; i < NEQ; i++)
    {
        for (int j = 0; j < N1; j++)
        {
            in >> A[i][j];
        }
    }
        }
 void  Jordan::doCalculate()
 {
   float D,D1;
   for(int N=0;N<NEQ;N++)
      {
         if(A[N][N]==0)
                   {
                         cout<<endl<<"*** ÍÓËÜÎÂÈÉ ÅËÅÌÅÍÒ ÍÀ Ä²ÀÃÎÍÀË² ";
                         cout<<N<<" Ï²Ä ×ÀÑ ÂÈÊÎÍÀÍÍß***"<<endl;
                         system("pause");
                         exit(0);
                         
                   }
            D=(1/A[N][N]);
           for(int j=0;j<N1;j++)
             {
               A[N][j]=D*A[N][j];
             }
           for(int i=0;i<NEQ-1;i++)
                 {
                       if(i==N)
                            {
                              i++;
                            }
                     D1=A[i][N];
                    for(int j=0;j<N1;j++)
                            {
                               A[i][j]=A[i][j]-D1*A[N][j];
                             }
                  }
          A[N][N]=1;
       }
    cout<<endl<<"ÂÈÂ²Ä"<<endl<<endl;
      for(int i=0;i<NEQ;i++){
        for(int j=N1-1;j<N1;j++){
          cout<<setprecision(2)<<setw(5)<<"x"<<i+1<<"="<<A[i][j];}
             cout<<endl;}
}
