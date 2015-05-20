
#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>

#include "Football.h"
#include <time.h>
#include <iomanip>
using namespace std;

#pragma warning(disable: 4996)

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
}tm[n + 1];

Football::Football(){

	}

void Football::inputTeams()
	{
		footballChempions fc;
		f = fopen("football.txt", "a+");
		for (int i = 0; i < n; i++)
		{
			cout << "введiть назву: ";
			cin >> tm[i].name;
			cout << "введiть к-сть игор: ";
			cin >> tm[i].countGame;
			cout << "виграних: ";
			cin >> tm[i].winGame;
			cout << "програних: ";
			cin >> tm[i].lostGame;
			cout << "нічія: ";
			cin >> tm[i].nichyuGame;
			cout << "забитих: ";
			cin >> tm[i].scored;
			cout << "пропущених: ";
			cin >> tm[i].missed;
			cout << "очок: ";
			cin >> tm[i].points;
		}



		fclose(f);
	}
void Football::outputTeams()
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
		f = fopen("football.txt", "ab+");
		int c;
		cout << "______________________________________________________\n";
		cout << setw(15) << "назва" << "|" << setw(5) << "З" << "|" << setw(5)
			<< "В" << setw(5) << "|" << "П" << "|" << setw(5) << "Н"
			<< "|" << setw(5) << "З" << "/" << "П" << "|" << setw(5) << "О " << "|" << endl;
		cout << "|----------------------------------------------------|\n";
		while ((c = fread(&fc, sizeof(footballChempions), 1, f)) != NULL)
		{
			cout << setw(15) << fc.name << "|" << setw(5) << fc.countGame << "|" << setw(5)
				<< fc.winGame << setw(5) << "|" << fc.lostGame << "|" << setw(5) << fc.nichyuGame
				<< "|" << setw(5) << fc.scored << "/" << fc.missed << "|" << setw(5) << fc.points << "|" << endl;

			cout << "|----------------------------------------------------|\n";
		}
		fclose(f);
	}
void Football::inputTeam()
	{





		cout << "введiть " << n << " команд:\n";
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << "-a: ";
			cin >> tm[i].name;
		}
	}

void Football::inputData()
	{

		int c;

		int i = 0;
		int t1, t2;  // змінні для номеру команд
		int r1, r2;	//	зміні для зберігання рахунку




		for (i = 0; i < n; i++)
		{
			cout << i + 1 << "|" << setw(5) << tm[i].name << endl;
		}

		cout << "команди якi грають?:\n";
		cin >> t1;
		cin >> t2;

		cout << "рахунок:\n";
		cin >> r1;
		cin >> r2;
		logicTeam(t1 - 1, t2 - 1, r1, r2);
	}
void Football::logicTeam(int t1, int t2, int r1, int r2)
	{
		if (r1 == r2)
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

		if (r1 < r2)
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

		if (r1 > r2)
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
void Football::saveResult()
	{
		sortList();
		f = fopen("football.txt", "w");
		for (int i = 0; i < n; i++)
		{
			fwrite(&tm[i], sizeof(footballChempions), 1, f);
		}
		fclose(f);
	}
void Football::sortList()
	{

		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			string name;
			int countGame;
			int winGame;
			int lostGame;
			int nichyuGame;
			int scored;
			int missed;
			int points;
			if (tm[i].points > tm[j].points)
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
void Football::loadIsFile()
	{


		footballChempions fc;
		f = fopen("football.txt", "ab+");
		int c;
		int i = 0;

		while ((c = fread(&fc, sizeof(footballChempions), 1, f)) != NULL)
		{
			tm[i].name = fc.name;
			tm[i].countGame = fc.countGame;
			tm[i].winGame = fc.winGame;
			tm[i].lostGame = fc.lostGame;
			tm[i].nichyuGame = fc.nichyuGame;

			tm[i].scored = fc.scored;
			tm[i].missed = fc.missed;
			tm[i].points = fc.points;


		}
		fclose(f);
	}
void Football::maxScored()
	{

		footballChempions fc;
		int max = 0;
		f = fopen("football.txt", "ab+");
		int c;

		while ((c = fread(&fc, sizeof(footballChempions), 1, f)) != NULL)
		{

			if (max < fc.scored)
			{
				max = fc.scored;
			}
		}

		while ((c = fread(&fc, sizeof(footballChempions), 1, f)) != NULL)
		{
			if (fc.scored == max){
				cout << "______________________________________________________\n";
				cout << setw(15) << "назва" << "|" << setw(5) << "З" << "|" << setw(5)
					<< "В" << setw(5) << "|" << "П" << "|" << setw(5) << "Н"
					<< "|" << setw(5) << "З" << "/" << "П" << "|" << setw(5) << "О " << "|" << endl;
				cout << "|----------------------------------------------------|\n";
				cout << setw(15) << fc.name << "|" << setw(5) << fc.countGame << "|" << setw(5)
					<< fc.winGame << setw(5) << "|" << fc.lostGame << "|" << setw(5) << fc.nichyuGame
					<< "|" << setw(5) << fc.scored << "/" << fc.missed << "|" << setw(5) << fc.points << "|" << endl;

				cout << "|----------------------------------------------------|\n";
			}
		}
		fclose(f);

	}



