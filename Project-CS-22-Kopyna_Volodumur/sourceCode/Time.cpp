#include "StdAfx.h"
#include "Time.h"
#include <iostream>
#include <Windows.h>
using namespace std;

FILE *fff;

struct structTimess{
	int day;
	int month;
	int year;
	int hour;
	int minute;
	char coment[128];
};

Time::Time(void)
{
}

void Time::inputTime(void)
{

	
		structTimess t;
		fff=fopen("time.txt","a+");                                       
			
		cout<<"����i�� �i�: ";
		cin>> t.year;
		cout<<"����i�� �i����: ";
		cin>>t.month;
		cout<<"����i�� ����: ";
		cin>>t.day;
		cout<<"����i�� ������: ";
		cin>>t.hour;
		cout<<"����i�� �������: ";
		cin>>t.minute;		
		cout<<"����i�� ��������: ";
		cin>>t.coment;		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		if(t.year < 2013 || t.year > 2020)
			cout<<"���i��� �������� �i�\n";
		if(t.month < 0 || t.month > 13)
			cout<<"���i��� �������� �i����\n";
		if(t.day < 0 || t.day > 31)
			cout<<"���i��� �������� ����\n";
		if(t.hour < 0 || t.month > 60)
			cout<<"���i��� �������� ������\n";
		if(t.minute < 0 && t.minute > 60)
			cout<<"���i��� �������� ������\n";
		cout<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if(t.year > 2013 && t.year < 2020 && t.month > 0 && t.month < 13 && t.day > 0 && t.day < 31 && t.hour > 0 && t.month < 60 && t.minute > 0 && t.minute < 60)
		{
			fwrite(&t,sizeof(structTimess),1,fff);
		}
		fclose(fff);
	
}

void Time::outputTime(void)
{
	structTimess t;
		fff=fopen("time.txt","ab+");
		int con;
		while((con=fread(&t,sizeof(structTimess),1,fff))!=NULL)
		{			
			cout<<t.year<<" "<<t.month<<", "<<t.day<<" - "<<t.hour<<":"<<t.minute<<endl;
			cout<<"coment:\t"<<t.coment<<endl<<endl;
							
		}		
		fclose(fff);
}

void Time::searchComentReminder(void)
{
	char q[128];
		structTimess st;
		int fl = 0;
		fff=fopen("testcpp.txt","ab+");
		int c;
		cout<<"coment:";
		cin>>q;
		while((c=fread(&st,sizeof(Time),1,fff))!=NULL)
		{

		
		if(strcat(q,st.coment) != 0)
		{
			fl =1;
			cout<<st.year<<" "<<st.month<<", "<<st.day<<" - "<<st.hour<<":"<<st.minute<<endl;
			cout<<"coment:\t"<<st.coment<<endl<<endl;
			
		}
		}
		if(fl==0)
			cout<<"�� �������!\n";
		fclose(fff);
}

void Time::deleteFile(void)
{
		fff=fopen("time.txt","w");
		cout<<"\t\t\t���� �������!\n";

		fclose(fff);
}