#include "StdAfx.h"
#include "Reminder.h"
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <vector>
using namespace std;


FILE *ff;

struct structTimes{
	int day;
	int month;
	int year;
	int hour;
	int minute;
	char coment[128];
}tm;

Reminder::Reminder(void)
{
}

	void Reminder::reminderForNow()
	{	
		
		time_t t;
		struct tm *t_m;
		t=time(NULL);
		t_m=localtime(&t);
		

		structTimes st;
		ff=fopen("time.txt","ab+");
		int con;
		int k = 1;
		
		
		while((con=fread(&st,sizeof(structTimes),1,ff))!=NULL)
		{			
			
			
			if(st.day == t_m->tm_mday && st.day == t_m->tm_year+1900 && st.month == t_m->tm_mon+1 && st.hour == t_m->tm_hour && t_m->tm_min == st.minute)
			{
				if(k)
				{
					cout<<"У вас запланавана подiя!!\n";
					k = 0;
				}
				cout<<st.year<<" "<<st.month<<", "<<st.day<<" - "<<st.hour<<":"<<st.minute<<endl;
				cout<<"coment:\t"<<st.coment<<endl<<endl;
			}
							
		}		
		fclose(ff); 
	}	
	
	void Reminder::reminder()
	{
	

		structTimes st;
		ff=fopen("time.txt","ab+");
		int con;
		int k = 1;
		vector <structTimes> vec;
		while((con=fread(&st,sizeof(structTimes),1,ff))!=NULL)
		{	
			vec.push_back(st);
		}

		int i =10;
		while(true)
		{

			
			Sleep(500);
			time_t t;
			struct tm *t_m;
			t=time(NULL);
			t_m=localtime(&t);
			system("cls");
			cout<<"Local time is: "<<t_m->tm_year + 1900<<"  "<<t_m->tm_mon+1<<", "<<t_m->tm_mday<<" - "<<t_m->tm_hour<<":"<<t_m->tm_min<<":"<<t_m->tm_sec<<endl;					

			
			for(int i =0; i < vec.size(); i ++)
			{
				if(vec[i].day == t_m->tm_mday && vec[i].year == t_m->tm_year+1900 && vec[i].month == t_m->tm_mon+1 && vec[i].hour == t_m->tm_hour && vec[i].minute == t_m->tm_min)
				{
					cout<<"\a\a\a настала подiя!!\n";
					break;
					goto exit;
				}				
				cout<<"\t"<<vec[i].year<<" "<<vec[i].month<<", "<<vec[i].day<<" - "<<vec[i].hour<<":"<<vec[i].minute<<endl;
			}

		}
		exit: cout<<"";

		fclose(ff); 

	}
	void Reminder::reminderForHour()
	{
		time_t t;
		struct tm *t_m;
		t=time(NULL);
		t_m=localtime(&t);
		

		structTimes st;
		ff=fopen("time.txt","ab+");
		int con;
		int k = 1;
		while((con=fread(&st,sizeof(structTimes),1,ff))!=NULL)
		{			
			
			
			if(st.day == t_m->tm_mday && st.year == t_m->tm_year+1900 && st.month == t_m->tm_mon+1 && st.hour == t_m->tm_hour)
			{
				if(k)
				{
					cout<<"У вас запланаванi подii на цю годину!!\n";
					k = 0;
				}
				cout<<st.year<<" "<<st.month<<", "<<st.day<<" - "<<st.hour<<":"<<st.minute<<endl;
				cout<<"coment:\t"<<st.coment<<endl<<endl;
			}
							
		}		
		fclose(ff);
	}
	void Reminder::reminderForDay()
	{
		time_t t;
		struct tm *t_m;
		t=time(NULL);
		t_m=localtime(&t);
		
				structTimes st;
		ff=fopen("time.txt","ab+");
		int con;
		int k = 1;
		while((con=fread(&st,sizeof(structTimes),1,ff))!=NULL)
		{			
			
			
			if(st.day == t_m->tm_mday && st.year == t_m->tm_year+1900 && st.month == t_m->tm_mon+1)
			{
				if(k)
				{
					cout<<"У вас запланаванi подii на цей день!!\n";
					k = 0;
				}
				cout<<st.year<<" "<<st.month<<", "<<st.day<<" - "<<st.hour<<":"<<st.minute<<endl;
				cout<<"coment:\t"<<st.coment<<endl<<endl;
			}
							
		}		
		fclose(ff);

	}
	void Reminder::reminderForMonth()
	{

		time_t t;
		struct tm *t_m;
		t=time(NULL);
		t_m=localtime(&t);
		
				structTimes st;
		ff=fopen("time.txt","ab+");
		int con;
		int k = 1;
		while((con=fread(&st,sizeof(structTimes),1,ff))!=NULL)
		{			
			
			
			if( st.year == t_m->tm_year+1900 && st.month == t_m->tm_mon+1)
			{
				if(k)
				{
					cout<<"У вас запланаванi подii на цей мiсяць!!\n";
					k = 0;
				}
				cout<<st.year<<" "<<st.month<<", "<<st.day<<" - "<<st.hour<<":"<<st.minute<<endl;
				cout<<"coment:\t"<<st.coment<<endl<<endl;
			}
							
		}		
		fclose(ff);

	}
	void Reminder::reminderForYear()
		
	{
		
		time_t t;
		struct tm *t_m;
		t=time(NULL);
		t_m=localtime(&t);
		
				structTimes st;
		ff=fopen("time.txt","ab+");
		int con;
		int k = 1;
		while((con=fread(&st,sizeof(structTimes),1,ff))!=NULL)
		{			
			
			
			if( st.year == t_m->tm_year+1900 )
			{
				if(k)
				{
					cout<<"У вас запланаванi подii на цей pik!!\n";
					k = 0;
				}
				cout<<st.year<<" "<<st.month<<", "<<st.day<<" - "<<st.hour<<":"<<st.minute<<endl;
				cout<<"coment:\t"<<st.coment<<endl<<endl;
			}
							
		}		
		fclose(ff);

	}
