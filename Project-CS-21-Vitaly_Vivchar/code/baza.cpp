#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <locale>
using namespace std;
const int L=31, N=100;
struct baza
{ char nazv [L];
  char priz [L];
  char pob [L];
  int rik;
  char pos [L];
};
class pharmacy
{
private:int n;
  baza *px;
   void udal(int j);
 public:
  pharmacy(){} 
  ~pharmacy(){if(n>0)delete[]px;}
  int k;
  void create();
  void reading();
  void output();
  void record();
  void find();
  void adding();
  void del();
  void correct();
  void sorting();
};

void pharmacy::create()
 {int i;
  px=new baza[n];
  if(px==NULL)
   {cout<<"���� ���'��i";
    getch();
    exit(1);
   }
  n=0;
  adding();
   do{cout<<"���������� ��i�?\n";
     cout<<"1-���\n";
     cout<<"2-�i\n";
     cin>>i;
     if(i==1)adding();
     }while(i==1);
 }

int main()
{setlocale(LC_ALL,"Ukrainian");
int w;
pharmacy a;
 while(1)
 {
system("CLS");
cout<<endl;
   cout<<"1. �i������ ���� �����\n";
   cout<<"2. �������� ���� �����\n";
   cout<<"3. ������� ���� ����� �� �����\n";
   cout<<"4. �������� ����� � ���� ����� \n";
   cout<<"5. �������� ����� i� ���� �����\n";
   cout<<"6. ���������� ����� � ���i �����\n";
   cout<<"7. ����� ������ � ���i �����\n";
   cout<<"8. ���������� ���� ����� \n";
   cout<<"9. ���������� ���� ����� � ����\n";
   cout<<"0. ���i�\n"<<endl;
   cout <<"����i�� ����� ������: ";     cin>>w;
  switch(w)
  {case 1:a.reading();break;
   case 2:a.create();break;
   case 3:a.output();getch();break;
   case 4:a.adding();break;
   case 5:a.del();break;
   case 6:a.correct();break;
   case 7:a.find();getch();break;
   case 8:a.sorting();break;
   case 9:a.record();break;
   case 0:exit(0);
   default:cout<<"�������";getch();  } }}




void pharmacy::reading()
 {ifstream in;
  char file[N];
  int i;baza u;
  cout<<"����� ���� �����:\n";
  cin>>file;
  in.open(file);
  if(in.fail())
  {cout<<file<<"���� ����� �� �i��������";getch();exit(1);}
  n=0;
  do{in>>u.nazv>>u.priz>>u.pob>>u.rik>>u.pos;
     n++;
    }while(in.good());
  n--;
  in.close();
  px=new baza[n];
  if(px==NULL)
   {cout<<"�������: ����� ���'��i'";
    getch();
    exit(1);}
  in.open(file);
  if(in.fail())
   {cout<<"�������: "<<file<<"�� �i��������";
    getch();
    exit(1);}
  for(i=0;i<n;i++)
   in>>px[i].nazv>>px[i].priz>>px[i].pob>>px[i].rik>>px[i].pos;
  in.close();}
int sravn(baza x,baza y); 
void pharmacy::output()
{int i;
 cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"I�'�"<<" "<<setw(15)<<"��i�����"<<" "<<setw(15)<<"�� �������i"<<" "<<setw(20)<<"�i���i��� ���i�"<<" "<<setw(10)<<"������"<<endl;
 cout<<"******************************************************************************"<<endl;
 for(i=0;i<n;i++)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}

void pharmacy::find()
{
  int b,i,k;
  char p [20];
 cout<<"�����i�� �����\n";
 cout<<"1)����� �� i�'��.\n"; cout<<"2)����� �� ��i������.\n"; cout<<"3)����� �� �������i.\n"; cout<<"4)����� �� �i���i��� ���i�.\n"; cout<<"5)����� �� �������.\n";  
 cout<<"�����=\n";
  cin>>b;
 
 if(b==1)
  {
  cout<<"I�'�:\n";cin>>p;
 cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"I�'�"<<" "<<setw(15)<<"��i������"<<" "<<setw(15)<<"�� �������i"<<" "<<setw(20)<<"�i���i��� ���i�"<<" "<<setw(10)<<"������"<<endl;
 cout<<"********************************************************************"<<endl;
 for(i=0;i<n;i++)
	 if (strcmp(px[i].nazv,p)==0)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}
	


  if(b==2)
  {
  cout<<"��i�����:\n";cin>>p;
cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"I�'�"<<" "<<setw(15)<<"��i�����"<<" "<<setw(15)<<"�� �������i"<<" "<<setw(20)<<"�i���i��� ���i�"<<" "<<setw(10)<<"������"<<endl;
 cout<<"********************************************************************"<<endl;
 for(i=0;i<n;i++)
	 	if (strcmp(px[i].priz,p)==0)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}


 if(b==3)
  {
  cout<<"�� �������i:\n";cin>>p;
  cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"I�'�"<<" "<<setw(15)<<"��i�����"<<" "<<setw(15)<<"�� �������i"<<" "<<setw(20)<<"�i���i��� ���i�"<<" "<<setw(10)<<"������"<<endl;
 cout<<"******************************************************************************"<<endl; 
 for(i=0;i<n;i++)
	 if (strcmp(px[i].pob,p)==0)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}
	

 if(b==4)
  {
  cout<<"�i���i��� ���i�:\n";cin>>k;
 cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"I�'�"<<" "<<setw(15)<<"��i�����"<<" "<<setw(15)<<"�� �������i"<<" "<<setw(20)<<"�i���i��� ���i�"<<" "<<setw(10)<<"������"<<endl;
 cout<<"******************************************************************************"<<endl;
 for(i=0;i<n;i++)
	 if (px[i].rik==k)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}
	


 if(b==5)
  {
  cout<<"������:\n";cin>>p;
 cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"I�'�"<<" "<<setw(15)<<"��i�����"<<" "<<setw(15)<<"�� �������i"<<" "<<setw(20)<<"�i���i��� ���i�"<<" "<<setw(10)<<"������"<<endl;
 cout<<"******************************************************************************"<<endl;
 for(i=0;i<n;i++)
	 if (strcmp(px[i].pos,p)==0)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}
}

void pharmacy::record()
 {int i;
  ofstream out;
  char file[N];
  cout<<"�������� ���� ����� � ����:\n";
  cin>>file;
  out.open(file);
  if(out==NULL)
   {cout<<file<<"�����������";
    getch();
	    exit(1);
   }
 cout<<"******************************************************************************"<<endl;
 out<<""<<setw(10)<<"I�'�"<<" "<<setw(15)<<"��i�����"<<" "<<setw(15)<<"�� �������i"<<" "<<setw(20)<<"�i������ ���i�"<<" "<<setw(10)<<"������"<<endl;
 cout<<"******************************************************************************"<<endl;
 for(i=0;i<n;i++)
	out<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
getch();out.close();
}
int sravn(baza x,baza y)
{ if(strcmp(x.nazv,y.nazv)>0)return 1; if(strcmp(x.nazv,y.nazv)<0)return -1; return 0;}

  void pharmacy::adding()
{ baza *s;int i;

 s=new baza[n+1];
 for(i=0;i<=n;i++)
   s[i]=px[i];
 cout<<"��i� i�������i�:\n";
 cout<<"I�'�:\n";cin>>s[n].nazv;
 cout<<"��i�����:\n";cin>>s[n].priz;
 cout<<"�� �������i:\n";cin>>s[n].pob;
 cout<<"�i������ ���i�:\n";cin>>s[n].rik;
 cout<<"������:\n";cin>>s[n].pos;
 n++;
 delete[]px;
 px=s;
 cout<<"Add!";
 getch();
}
void pharmacy::correct()
{ int i,q,j;
 output();
 cout<<"����� ����� ��� �����������:";cin>>j;
  for(i=0;i<n;i++)
 if(i==j-1)
	 {              
        cout<<"�����i�� i�������i� ��� �����������:\n";
		cout<<"I�'�:\n"<<""<<px[i].nazv<<endl<<"��������� i�'�?\n"<<"1-���.0-�i\n";
		cin>>q;
		if(q==1){cout<<"���� i�'�':\n";cin>>px[i].nazv;}
		
		cout<<"��i�����:\n"<<""<<px[i].priz<<endl<<"��������� ��i�����?\n"<<"1-���.0-�i\n";
		cin>>q;
		if(q==1){cout<<"���� ��i�����:\n";cin>>px[i].priz;}
		
		cout<<"�� �������i:\n"<<""<<px[i].pob<<endl<<"��������� �� �������i?\n"<<"1-���.0-�i\n";
		cin>>q;
		if(q==1){cout<<"���� �� �������i:\n";cin>>px[i].pob;}
		
		cout<<"�i���i��� ���i�:\n"<<""<<px[i].rik<<endl<<"��������� �i���i��� ���i�?\n"<<"1-���.0-�i\n";
		cin>>q;
		if(q==1){cout<<"���� �i���i��� ���i�:\n";cin>>px[i].rik;}
	
		cout<<"������:\n"<<""<<px[i].pos<<endl<<"��������� ������?\n"<<"1-���.0-�i\n";
		cin>>q;
		if(q==1){cout<<"���� ������:\n";cout<<"";cin>>px[i].pos;}  																																																						 
		
		cout<<endl<<"���������!\n.";
              break;         	 }
	 output();
 getch();
}


void pharmacy::del()
{
 int i,h,fl;
 output();
 cout<<"����i�� ����� �����:\n";
 cin>>h;
fl=0;
 for(i=0;i<n;i++)
 if(i==h-1)
   { fl=1;udal(i);
     cout<<endl<<"���������!\n";
   }
  if(fl==0)cout<<"�� ��������.\n";
  output();
 getch();
}
void pharmacy::udal(int h)
{int i;
 if(h<0||h>=n){cout<<"���� �����";getch();return;}
 for(i=h+1;i<n;i++)
  px[i-1]=px[i];
 n--;
}


void pharmacy::sorting()
{int i,p,fl;
 baza r;
 cout<<"�� ��� ���������?\n";
 cout<<"---------------\n";
 cout<<"1.��������� �� i�'��\n";
 cout<<"2.��������� �� ��i�����\n";
 cout<<"3.��������� �� �������i\n";
 cout<<"4.��������� �� �i���i��� ���i�\n";
 cout<<"5.��������� �� �������\n";
 cout<<"�����-";
 cin>>p;
 do{for(i=0;i<(n-1);i++)
 {
    if(p==1){fl=0;
      if(strcmp(px[i+1].nazv,px[i].nazv)<0)
      {r=px[i];
	  px[i]=px[i+1];
	  px[i+1]=r;
	  fl=1;break;}}
 
    if(p==2){fl=0;
      if(strcmp(px[i+1].priz,px[i].priz)<0)
      {r=px[i];
	  px[i]=px[i+1];
       px[i+1]=r;
	   fl=1;break;}}
 
    if(p==3){fl=0;
      if(strcmp(px[i+1].pob,px[i].pob)<0)
      {r=px[i];
	  px[i]=px[i+1];
	  px[i+1]=r;
	  fl=1;break;}}
     
	if(p==4){fl=0;
      if(px[i+1].rik<px[i].rik)
      {r=px[i];
	  px[i]=px[i+1];
       px[i+1]=r;
	   fl=1;break;}}
    
	if(p==5){fl=0;
      if(strcmp(px[i+1].pos,px[i].pos)<0)
      {r=px[i];
	  px[i]=px[i+1];
       px[i+1]=r;
	   fl=1;break;}}
}
   }while(fl==1);
}
