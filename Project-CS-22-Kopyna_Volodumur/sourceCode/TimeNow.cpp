#include "StdAfx.h"
#include "TimeNow.h"
#include <time.h>
#include <iostream>

using namespace std;

TimeNow::TimeNow(void)
{
}
void TimeNow::now()
{
	
		time_t t;
		struct tm *t_m;
		t=time(NULL);
		t_m=localtime(&t);
		cout<<"Local time is: "<<t_m->tm_year + 1900<<"  "<<t_m->tm_mon+1<<", "<<t_m->tm_mday<<" - "<<t_m->tm_hour<<":"<<t_m->tm_min<<":"<<t_m->tm_sec<<endl;					

}