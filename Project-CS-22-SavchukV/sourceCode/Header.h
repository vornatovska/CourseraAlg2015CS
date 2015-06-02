#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

const int L=31, N=100;
struct Apteka
{ 
 char Medication [L];
 char Type [L];
 int Amount;
 int Price;
};

class Pharmacy
{
private:int n;
  Apteka *px;
   void Remove(int j);
 public:
  Pharmacy(){} 
  ~Pharmacy(){if(n>0)delete[]px;}
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


void Pharmacy::create()
 {int i;
  px=new Apteka[n];
  if(px==NULL)
   {cout<<"No Memory";
    getch();
    exit(1);
   }
  n=0;
  adding();
  do{cout<<"To add yet?\n";
     cout<<"1-Yes\n";
     cout<<"2-No\n";
     cin>>i;
     if(i==1)adding();
     }while(i==1);
 }


void Pharmacy::reading()
 {ifstream in;
  char file[N];
  int i; Apteka u;
  cout<<"File name:\n";
  cin>>file;
  in.open(file);
  if(in.fail())
  {cout<<file<<"Don't open";getch();exit(1);}
  n=0;
  do{in>>u.Medication>>u.Type>>u.Amount>>u.Price;
     n++;
    }while(in.good());
  n--;
  in.close();
  px=new Apteka[n];
  if(px==NULL)
   {cout<<"Error: No memory";
    getch();
    exit(1);}
  in.open(file);
  if(in.fail())
   {cout<<"Error: "<<file<<" don't open";
    getch();
    exit(1);}
  for(i=0;i<n;i++)
   in>>px[i].Medication>>px[i].Type>>px[i].Amount>>px[i].Price;
  in.close();}


void Pharmacy::output()
{int i;
 cout<<"____________________________________________________________________"<<endl;
 cout<<" "<<setw(10)<<"Medication"<<" "<<setw(15)<<"Type"<<" "<<setw(15)<<"Amount"<<" "<<setw(5)<<"Price"<<endl;
 cout<<"____________________________________________________________________"<<endl;
 for(i=0;i<n;i++)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].Medication<<" "<<setw(15)<<px[i].Type<<setw(15)<<px[i].Amount<<" "<<setw(5)<<px[i].Price<<endl;
}

void Pharmacy::find()
{
  int b,i,k;
  char p [20];
 cout<<"Choose a point\n";
 cout<<"1)Search to Medication.\n"; cout<<"2)Search to Type.\n";  cout<<"3)Search to Price.\n";  
 cout<<"Point=\n";
  cin>>b;
 
 if(b==1)
  {
  cout<<"Medication:\n";cin>>p;
 cout<<"_____________________________________________________________________"<<endl;
 cout<<" "<<setw(10)<<"Medication"<<" "<<setw(15)<<"Type"<<" "<<setw(15)<<""<<" "<<setw(5)<<"Amount"<<" "<<setw(10)<<"Price"<<endl;
 cout<<"_____________________________________________________________________"<<endl;
 for(i=0;i<n;i++)
	 if (strcmp(px[i].Medication,p)==0)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].Medication<<" "<<setw(15)<<px[i].Type<<setw(15)<<px[i].Amount<<" "<<setw(5)<<px[i].Price<<endl;
    
}
	


  if(b==2)
  {
  cout<<"Type:\n";cin>>p;
 cout<<"____________________________________________________________________"<<endl;
 cout<<" "<<setw(10)<<"Medication"<<" "<<setw(15)<<"Type"<<" "<<setw(15)<<"Amount"<<" "<<setw(5)<<"Price"<<endl;
 cout<<"____________________________________________________________________"<<endl;
 for(i=0;i<n;i++)
	 	if (strcmp(px[i].Type,p)==0)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].Medication<<" "<<setw(15)<<px[i].Type<<setw(15)<<px[i].Amount<<" "<<setw(5)<<px[i].Price<<endl;
    
}


 if(b==3)
  {
  cout<<"Price:\n";cin>>k;
 cout<<"____________________________________________________________________"<<endl;
 cout<<" "<<setw(10)<<"Medication"<<" "<<setw(15)<<"Type"<<" "<<setw(15)<<"Amount"<<" "<<setw(5)<<"Price"<<endl;
 cout<<"____________________________________________________________________"<<endl;
 for(i=0;i<n;i++)
	 if (px[i].Price==k)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].Medication<<" "<<setw(15)<<px[i].Type<<setw(15)<<px[i].Amount<<" "<<setw(5)<<px[i].Price<<endl;

}
	


 
}

void Pharmacy::record()
 {int i;
  ofstream out;
  char file[N];
  cout<<"Name file save:\n";
  cin>>file;
  out.open(file);
  if(out==NULL)
   {cout<<file<<"Don' create";
    getch();
	    exit(1);
   }
 out<<"____________________________________________________________________"<<endl;
 out<<" "<<setw(10)<<"Medication"<<" "<<setw(15)<<"Type"<<" "<<setw(15)<<"Amount"<<" "<<setw(5)<<"Price"<<endl;
 out<<"____________________________________________________________________"<<endl;
 for(i=0;i<n;i++)
	out<<i+1<<"."<<setw(3)<<setw(10)<<px[i].Medication<<" "<<setw(15)<<px[i].Type<<setw(15)<<px[i].Amount<<" "<<setw(5)<<px[i].Price<<endl;
getch();out.close();
}

void Pharmacy::adding()
{ Apteka *s;
int i;

 s=new Apteka[n+1];
 for(i=0;i<n;i++)
   s[i]=px[i];
 cout<<"Enter information:\n";
 cout<<"Medication:\n";cin>>s[n].Medication;
 cout<<"Type:\n";cin>>s[n].Type;
 cout<<"Amount:\n";cin>>s[n].Amount;
 cout<<"Price:\n";cin>>s[n].Price;
 
 n++;
 delete[]px;
 px=s;
 cout<<"Add!";
 getch();
}
void Pharmacy::correct()
{ int i,q,j;
 output();
 cout<<"The number of line for editing:";cin>>j;
  for(i=0;i<n;i++)
 if(i==j-1)
	 {              
        cout<<"Enter correct information:\n";
        		
		cout<<"Amount:\n"<<""<<px[i].Amount<<endl<<"Do you want to correct the Amount?\n"<<"1-Yes.0-No\n";
		cin>>q;
		if(q==1){cout<<"New Amount:\n";cin>>px[i].Amount;}
	
		cout<<"Price:\n"<<""<<px[i].Price<<endl<<"Do you want to correct the Price?\n"<<"1-Yes.0-No\n";
		cin>>q;
		if(q==1){cout<<"New Price:\n";cout<<"";cin>>px[i].Price;}  																																																						
		
		cout<<endl<<"Ready!\n.";
              break;         	 }
	 output();
 getch();
}


void Pharmacy::del()
{
 int i,h,fl;
 output();
 cout<<"Enter line number:\n";
 cin>>h;
fl=0;
 for(i=0;i<n;i++)
 if(i==h-1)
   { fl=1;Remove(i);
     cout<<endl<<"Ready!\n";
   }
  if(fl==0)cout<<"Not found.\n";
  output();
 getch();
}
void Pharmacy::Remove(int h)
{int i;
 if(h<0||h>=n){cout<<"Does not exist";getch();return;}
 for(i=h+1;i<n;i++)
  px[i-1]=px[i];
 n--;
}


void Pharmacy::sorting()
{int i,p,fl;
 Apteka r;
 cout<<"How sort?\n";
 cout<<"---------------\n";
 cout<<"1.Sorting Medication\n";
 cout<<"2.Sorting Type\n";
 cout<<"3.Sorting Amount\n";
 cout<<"4.Sorting Price\n";
 cout<<"Punkt-";
 cin>>p;
 do{for(i=0;i<(n-1);i++)
 {
    if(p==1){fl=0;
      if(strcmp(px[i+1].Medication,px[i].Medication)<0)
      {r=px[i];
	  px[i]=px[i+1];
	  px[i+1]=r;
	  fl=1;break;}}
 
    if(p==2){fl=0;
      if(strcmp(px[i+1].Type,px[i].Type)<0)
      {r=px[i];
	  px[i]=px[i+1];
       px[i+1]=r;
	   fl=1;break;}}
 
    if(p==3){fl=0;
      if(px[i+1].Amount<px[i].Amount)
      {r=px[i];
	  px[i]=px[i+1];
	  px[i+1]=r;
	  fl=1;break;}}
     
	if(p==4){fl=0;
      if(px[i+1].Price<px[i].Price)
      {r=px[i];
	  px[i]=px[i+1];
       px[i+1]=r;
	   fl=1;break;}}
    
     }
   }while(fl==1);
}
