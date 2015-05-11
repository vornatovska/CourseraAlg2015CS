#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <time.h>
#include <iomanip>
using namespace std;

#define n 8
FILE *f;


vector<string> teams;
struct footballChempions{
	string name;
	int countGame;
	int winGame;
	int lostGame;
	int nichyuGame;
	int scored;
	int missed;
	int points;
}tm[n+1];


class Football
{
private:
	footballChempions tp;

public :
	Football(){

	}
	Football(footballChempions _tp)
	{
		tp = _tp;
	}
	void inputTeams()
	{
		footballChempions fc;
		f=fopen("football.txt","a+");                                       
		for(int i = 0; i < n; i ++)
		{
			cout<<"введiть назву: ";
			cin>> tm[i].name;
			cout<<"введiть к-сть игор: ";
			cin>>tm[i].countGame;
			cout<<"виграних: ";
			cin>>tm[i].winGame;
			cout<<"програних: ";
			cin>>tm[i].lostGame;
			cout<<"нічія: ";
			cin>>tm[i].nichyuGame;		
			cout<<"забитих: ";
			cin>>tm[i].scored;				
			cout<<"пропущених: ";
			cin>>tm[i].missed;				
			cout<<"очок: ";
			cin>>tm[i].points;				
		}



		fclose(f);
	}
	void outputTeams()
	{
		/*cout<<"______________________________________________________\n";
		cout<<setw(15)<<"назва"<<"|"<<setw(5)<<"З"<<"|"<<setw(5)
		<<"В"<<setw(5)<<"|"<<"П"<<"|"<<setw(5)<<"Н"
		<<"|"<<setw(5)<<"З"<<"/"<<"П"<<"|"<<setw(5)<<"О "<<"|"<<endl;
		cout<<"|----------------------------------------------------|\n";
		for(int i = 0; i < n; i ++)
		{



		cout<<setw(15)<<tm[i].name<<"|"<<setw(5)<<tm[i].countGame<<"|"<<setw(5)
		<<tm[i].winGame<<setw(5)<<"|"<<tm[i].lostGame<<"|"<<setw(5)<<tm[i].nichyuGame
		<<"|"<<setw(5)<<tm[i].scored<<"/"<<tm[i].missed<<"|"<<setw(5)<<tm[i].points<<"|"<<endl;

		cout<<"|----------------------------------------------------|\n";						
		}
		*/


		footballChempions fc;
		f=fopen("football.txt","ab+");
		int c;
		cout<<"______________________________________________________\n";
		cout<<setw(15)<<"назва"<<"|"<<setw(5)<<"З"<<"|"<<setw(5)
			<<"В"<<setw(5)<<"|"<<"П"<<"|"<<setw(5)<<"Н"
			<<"|"<<setw(5)<<"З"<<"/"<<"П"<<"|"<<setw(5)<<"О "<<"|"<<endl;
		cout<<"|----------------------------------------------------|\n";
		while((c=fread(&fc,sizeof(footballChempions),1,f))!=NULL)
		{				
			cout<<setw(15)<<fc.name<<"|"<<setw(5)<<fc.countGame<<"|"<<setw(5)
				<<fc.winGame<<setw(5)<<"|"<<fc.lostGame<<"|"<<setw(5)<<fc.nichyuGame
				<<"|"<<setw(5)<<fc.scored<<"/"<<fc.missed<<"|"<<setw(5)<<fc.points<<"|"<<endl;

			cout<<"|----------------------------------------------------|\n";						
		}		
		fclose(f);
	}
	void inputTeam()
	{





		cout<<"введiть "<<n<<" команд:\n";		
		for(int i = 0; i < n; i ++)
		{
			cout<<i+1<<"-a: ";
			cin>>tm[i].name;			
		}
	}

	void inputData()
	{

		int c;		

		int i =0;
		int t1, t2;  // змінні для номеру команд
		int r1,r2;	//	зміні для зберігання рахунку




		for( i = 0; i < n; i ++)
		{
			cout<<i+1<<"|"<<setw(5)<<tm[i].name<<endl;
		}

		cout<<"команди якi грають?:\n";
		cin>>t1;		
		cin>>t2;

		cout<<"рахунок:\n";
		cin>>r1;		
		cin>>r2;
		logicTeam( t1-1, t2-1, r1, r2);
	}
	void logicTeam(int t1, int t2, int r1, int r2)
	{
		if(r1 == r2)
		{
			tm[t1].countGame++;
			tm[t2].countGame++;
			tm[t1].nichyuGame++;
			tm[t2].nichyuGame++;

			tm[t1].missed += r2;
			tm[t2].missed += r1;

			tm[t1].scored += r1;
			tm[t2].scored += r2;

			tm[t1].points += 1;
			tm[t2].points += 1;
		}

		if(r1 < r2)
		{
			tm[t1].countGame++;
			tm[t2].countGame++;
			tm[t1].lostGame++;
			tm[t2].winGame++;

			tm[t1].missed += r2;
			tm[t2].missed += r1;

			tm[t1].scored += r1;
			tm[t2].scored += r2;

			tm[t1].points += 0;
			tm[t2].points += 3;
		}

		if(r1 > r2)
		{
			tm[t1].countGame++;
			tm[t2].countGame++;
			tm[t2].lostGame++;
			tm[t1].winGame++;

			tm[t1].missed += r2;
			tm[t2].missed += r1;

			tm[t1].scored += r1;
			tm[t2].scored += r2;

			tm[t1].points += 3;
			tm[t2].points += 0;
		}

	}
	void saveResult()
	{
		sortList();	
		f=fopen("football.txt","w");
		for(int i = 0; i < n; i ++)
		{
			fwrite(&tm[i],sizeof(footballChempions),1,f); 
		}
		fclose(f);
	}
	void sortList()
	{

		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
			{
				string name;
				int countGame;
				int winGame;
				int lostGame;			
				int nichyuGame;
				int scored;
				int missed;
				int points;
				if(tm[i].points > tm[j].points)
				{
					name = tm[i].name;
					tm[i].name = tm[j].name;
					tm[j].name = name;

					countGame = tm[i].countGame;
					tm[i].countGame = tm[j].countGame;
					tm[j].countGame = countGame;

					winGame = tm[i].winGame;
					tm[i].winGame = tm[j].winGame;
					tm[j].winGame = winGame;

					lostGame = tm[i].lostGame;
					tm[i].lostGame = tm[j].lostGame;
					tm[j].lostGame = lostGame;

					nichyuGame = tm[i].nichyuGame;
					tm[i].nichyuGame = tm[j].nichyuGame;
					tm[j].nichyuGame = nichyuGame;

					scored = tm[i].scored;
					tm[i].scored = tm[j].scored;
					tm[j].scored = scored;

					missed = tm[i].missed;
					tm[i].missed = tm[j].missed;
					tm[j].missed = missed;

					points = tm[i].points;
					tm[i].points = tm[j].points;
					tm[j].points = points;

				}
			}
	}
	void loadIsFile()
	{


		footballChempions fc;
		f=fopen("football.txt","ab+");
		int c;
		int i = 0;

		while((c=fread(&fc,sizeof(footballChempions),1,f))!=NULL)
		{				
			tm[i].name = fc.name;
			tm[i].countGame= fc.countGame;
			tm[i].winGame = fc.winGame;
			tm[i].lostGame = fc.lostGame;
			tm[i].nichyuGame = fc.nichyuGame;

			tm[i].scored = fc.scored;
			tm[i].missed = fc.missed;
			tm[i].points = fc.points;


		}		
		fclose(f);
	}
	void maxScored()
	{

		footballChempions fc;
		int max = 0;
		f=fopen("football.txt","ab+");
		int c;

		while((c=fread(&fc,sizeof(footballChempions),1,f))!=NULL)
		{				

			if(max < fc.scored)
			{
				max = fc.scored;
			}			
		}	

		while((c=fread(&fc,sizeof(footballChempions),1,f))!=NULL)
		{
			if(fc.scored == max){
				cout<<"______________________________________________________\n";
				cout<<setw(15)<<"назва"<<"|"<<setw(5)<<"З"<<"|"<<setw(5)
					<<"В"<<setw(5)<<"|"<<"П"<<"|"<<setw(5)<<"Н"
					<<"|"<<setw(5)<<"З"<<"/"<<"П"<<"|"<<setw(5)<<"О "<<"|"<<endl;
				cout<<"|----------------------------------------------------|\n";
				cout<<setw(15)<<fc.name<<"|"<<setw(5)<<fc.countGame<<"|"<<setw(5)
					<<fc.winGame<<setw(5)<<"|"<<fc.lostGame<<"|"<<setw(5)<<fc.nichyuGame
					<<"|"<<setw(5)<<fc.scored<<"/"<<fc.missed<<"|"<<setw(5)<<fc.points<<"|"<<endl;

				cout<<"|----------------------------------------------------|\n";						
			}
		}
		fclose(f);

	}

}; 


void Menu(int,int);   // вивід меню
int Menu1(int,int);   // пересування по підменю
int Menu1_1(int,int); // вибір операції
int c=0,q=-1;         //с-для пересування в головному меню; q-для пересування в підменю;
vector <string> menu;
vector <vector <string>> menu2;








class MMenu 
{
public:
	int s;
	int g;
	MMenu(int _s,int _g)
	{
		s=_s;
		g=_g;	
	}

public:
	int Menu111(int s,int g)
	{	

		Football ph;

		ph.loadIsFile();

		int a=g % menu2[s].size();
		switch(c)
		{
		case 0:
			switch(a)
			{

			case 0: ph.inputTeams(); break;
			case 1: ph.outputTeams(); break;
			case 2: ph.inputTeam(); break;
			case 3: ph.saveResult(); break; 
			};break;		
		case 1:

			switch(a)
			{
			case 0: ph.inputData(); break;
			case 1: ph.outputTeams(); break;
			case 2: ph.maxScored(); break;
			};break;

		}

		return 0;
	}
	void Menu(int c,int q);
	int Menu1(int c,int q);
};

void tnow()
{

}
int code;                
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

	setlocale(LC_ALL,"Ukrainian");
	menu.insert(menu.begin()," <--Адмiнiстратор-->");
	menu.insert(menu.begin()+1," <--Модератор-->");		
	menu.insert(menu.begin()+2," <--Вихiд-->");
	menu2.push_back(vector<string>());

	menu2[0].push_back("додати запис");
	menu2[0].push_back("вивести усi записи");	
	menu2[0].push_back("ввести команди!");
	menu2[0].push_back("зберегти у файл данi!");

	menu2.push_back(vector<string>());
	menu2[1].push_back("ввести данi");
	menu2[1].push_back("вивести усi записи");	
	menu2[1].push_back("максимальна к-сть забитих голiв");	






	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	Menu(c,q);
	while(1)
	{
		code=getch();
		system("cls");
		switch(code)
		{
		case 72: if(c>0) c--;  break;
		case 80: if(c<3) c++;  break;
		case 77: 
			switch(c)
			{
			case 0:	Menu1(c,q);break;
			case 1: Menu1(c,q);break;	
			case 2: return 0;
			}
		}
		Menu(c,q);

	}
	return 0;
}
void Menu(int c,int q)
{
	for(int i=0;i< menu.size();i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if(i==c)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout<<menu[i]<<endl;
			if(q!=-1)
				for(int j=0; j<menu2[i].size(); j++)
					if(j==(q % menu2[i].size()))
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
						cout<<"\t\t"<<menu2[i][j] <<endl;
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout<<"\t\t"<<menu2[i][j] <<endl;
					}
		}
		else
		{

			cout<<menu[i]<<endl;
		}

	}
}











int Menu1(int c,int q)
{
	MMenu ob(c,q);
	q++;
	Menu(c,q);
	while(1)
	{
		code=getch();
		system("cls");
		switch(code)
		{
		case 72: q--;break;
		case 80: q++;break;
		case 77: ob.Menu111(c,q);break;
		case 75: return 0;
		}
		Menu(c,q);
	}
	return 0;
}


