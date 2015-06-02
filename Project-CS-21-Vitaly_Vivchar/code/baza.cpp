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
   {cout<<"Немає пам'ятi";
    getch();
    exit(1);
   }
  n=0;
  adding();
   do{cout<<"Продовжити ввiд?\n";
     cout<<"1-Так\n";
     cout<<"2-Нi\n";
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
   cout<<"1. Вiдкрити базу даних\n";
   cout<<"2. Створити базу даних\n";
   cout<<"3. Вивести базу даних на екран\n";
   cout<<"4. Добавити запис у базу даних \n";
   cout<<"5. Видалити запис iз бази даних\n";
   cout<<"6. Редагувати запис у базi даних\n";
   cout<<"7. Пошук запису у базi даних\n";
   cout<<"8. Сортування бази даних \n";
   cout<<"9. Збереження бази даних у файл\n";
   cout<<"0. Вихiд\n"<<endl;
   cout <<"Введiть номер пункту: ";     cin>>w;
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
   default:cout<<"Помилка";getch();  } }}




void pharmacy::reading()
 {ifstream in;
  char file[N];
  int i;baza u;
  cout<<"Назва бази даних:\n";
  cin>>file;
  in.open(file);
  if(in.fail())
  {cout<<file<<"База даних не вiдкрилась";getch();exit(1);}
  n=0;
  do{in>>u.nazv>>u.priz>>u.pob>>u.rik>>u.pos;
     n++;
    }while(in.good());
  n--;
  in.close();
  px=new baza[n];
  if(px==NULL)
   {cout<<"Помилка: Бракує пам'ятi'";
    getch();
    exit(1);}
  in.open(file);
  if(in.fail())
   {cout<<"Помилка: "<<file<<"НЕ вiдкрилась";
    getch();
    exit(1);}
  for(i=0;i<n;i++)
   in>>px[i].nazv>>px[i].priz>>px[i].pob>>px[i].rik>>px[i].pos;
  in.close();}
int sravn(baza x,baza y); 
void pharmacy::output()
{int i;
 cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"Iм'я"<<" "<<setw(15)<<"Прiзвище"<<" "<<setw(15)<<"По батьковi"<<" "<<setw(20)<<"Кiлькiсть рокiв"<<" "<<setw(10)<<"Посада"<<endl;
 cout<<"******************************************************************************"<<endl;
 for(i=0;i<n;i++)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}

void pharmacy::find()
{
  int b,i,k;
  char p [20];
 cout<<"Виберiть пункт\n";
 cout<<"1)Пошук за iм'ям.\n"; cout<<"2)Пошук за прiзвищем.\n"; cout<<"3)Пошук по батьковi.\n"; cout<<"4)Пошук за кiлькiстю рокiв.\n"; cout<<"5)Пошук за посадою.\n";  
 cout<<"Пункт=\n";
  cin>>b;
 
 if(b==1)
  {
  cout<<"Iм'я:\n";cin>>p;
 cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"Iм'я"<<" "<<setw(15)<<"Прiзвищем"<<" "<<setw(15)<<"По батьковi"<<" "<<setw(20)<<"Кiлькiсть рокiв"<<" "<<setw(10)<<"Посада"<<endl;
 cout<<"********************************************************************"<<endl;
 for(i=0;i<n;i++)
	 if (strcmp(px[i].nazv,p)==0)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}
	


  if(b==2)
  {
  cout<<"Прiзвище:\n";cin>>p;
cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"Iм'я"<<" "<<setw(15)<<"Прiзвище"<<" "<<setw(15)<<"По батьковi"<<" "<<setw(20)<<"Кiлькiсть рокiв"<<" "<<setw(10)<<"Посада"<<endl;
 cout<<"********************************************************************"<<endl;
 for(i=0;i<n;i++)
	 	if (strcmp(px[i].priz,p)==0)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}


 if(b==3)
  {
  cout<<"По батьковi:\n";cin>>p;
  cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"Iм'я"<<" "<<setw(15)<<"Прiзвище"<<" "<<setw(15)<<"По батьковi"<<" "<<setw(20)<<"Кiлькiсть рокiв"<<" "<<setw(10)<<"Посада"<<endl;
 cout<<"******************************************************************************"<<endl; 
 for(i=0;i<n;i++)
	 if (strcmp(px[i].pob,p)==0)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}
	

 if(b==4)
  {
  cout<<"Кiлькiсть рокiв:\n";cin>>k;
 cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"Iм'я"<<" "<<setw(15)<<"Прiзвище"<<" "<<setw(15)<<"По батьковi"<<" "<<setw(20)<<"Кiлькiсть рокiв"<<" "<<setw(10)<<"Посада"<<endl;
 cout<<"******************************************************************************"<<endl;
 for(i=0;i<n;i++)
	 if (px[i].rik==k)
	cout<<i+1<<"."<<setw(3)<<setw(10)<<px[i].nazv<<" "<<setw(15)<<px[i].priz<<setw(15)<<px[i].pob<<" "<<setw(10)<<px[i].rik<<" "<<setw(20)<<px[i].pos<<endl;
}
	


 if(b==5)
  {
  cout<<"Посада:\n";cin>>p;
 cout<<"******************************************************************************"<<endl;
 cout<<""<<setw(10)<<"Iм'я"<<" "<<setw(15)<<"Прiзвище"<<" "<<setw(15)<<"По батьковi"<<" "<<setw(20)<<"Кiлькiсть рокiв"<<" "<<setw(10)<<"Посада"<<endl;
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
  cout<<"Зберегти базу даних у файл:\n";
  cin>>file;
  out.open(file);
  if(out==NULL)
   {cout<<file<<"Незбережено";
    getch();
	    exit(1);
   }
 cout<<"******************************************************************************"<<endl;
 out<<""<<setw(10)<<"Iм'я"<<" "<<setw(15)<<"Прiзвище"<<" "<<setw(15)<<"По батьковi"<<" "<<setw(20)<<"Кiлькість рокiв"<<" "<<setw(10)<<"Посада"<<endl;
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
 cout<<"Ввiд iнформвцiї:\n";
 cout<<"Iм'я:\n";cin>>s[n].nazv;
 cout<<"Прiзвище:\n";cin>>s[n].priz;
 cout<<"По батьковi:\n";cin>>s[n].pob;
 cout<<"Кiлькість рокiв:\n";cin>>s[n].rik;
 cout<<"Посада:\n";cin>>s[n].pos;
 n++;
 delete[]px;
 px=s;
 cout<<"Add!";
 getch();
}
void pharmacy::correct()
{ int i,q,j;
 output();
 cout<<"Номер рядка для корегування:";cin>>j;
  for(i=0;i<n;i++)
 if(i==j-1)
	 {              
        cout<<"Виберiть iнформацiю для корегування:\n";
		cout<<"Iм'я:\n"<<""<<px[i].nazv<<endl<<"Виправити iм'я?\n"<<"1-Так.0-Нi\n";
		cin>>q;
		if(q==1){cout<<"Нове iм'я':\n";cin>>px[i].nazv;}
		
		cout<<"Прiзвище:\n"<<""<<px[i].priz<<endl<<"Виправити прiзвище?\n"<<"1-Так.0-Нi\n";
		cin>>q;
		if(q==1){cout<<"Нове прiзвище:\n";cin>>px[i].priz;}
		
		cout<<"По батьковi:\n"<<""<<px[i].pob<<endl<<"Виправити по батьковi?\n"<<"1-Так.0-Нi\n";
		cin>>q;
		if(q==1){cout<<"Нове по батьковi:\n";cin>>px[i].pob;}
		
		cout<<"Кiлькiсть рокiв:\n"<<""<<px[i].rik<<endl<<"Виправити кiлькiсть рокiв?\n"<<"1-Так.0-Нi\n";
		cin>>q;
		if(q==1){cout<<"Нова кiлькiсть рокiв:\n";cin>>px[i].rik;}
	
		cout<<"Посада:\n"<<""<<px[i].pos<<endl<<"Виправити посаду?\n"<<"1-Так.0-Нi\n";
		cin>>q;
		if(q==1){cout<<"Нова посада:\n";cout<<"";cin>>px[i].pos;}  																																																						 
		
		cout<<endl<<"Зачекайте!\n.";
              break;         	 }
	 output();
 getch();
}


void pharmacy::del()
{
 int i,h,fl;
 output();
 cout<<"Введiть номер рядка:\n";
 cin>>h;
fl=0;
 for(i=0;i<n;i++)
 if(i==h-1)
   { fl=1;udal(i);
     cout<<endl<<"Зачекайте!\n";
   }
  if(fl==0)cout<<"Не знайдено.\n";
  output();
 getch();
}
void pharmacy::udal(int h)
{int i;
 if(h<0||h>=n){cout<<"Немає рядка";getch();return;}
 for(i=h+1;i<n;i++)
  px[i-1]=px[i];
 n--;
}


void pharmacy::sorting()
{int i,p,fl;
 baza r;
 cout<<"За чим сортувати?\n";
 cout<<"---------------\n";
 cout<<"1.Сортувати за iм'ям\n";
 cout<<"2.Сортувати за прiзвище\n";
 cout<<"3.Сортувати по батьковi\n";
 cout<<"4.Сортувати за кiлькiстю рокiв\n";
 cout<<"5.Сортувати за посадою\n";
 cout<<"Пункт-";
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
