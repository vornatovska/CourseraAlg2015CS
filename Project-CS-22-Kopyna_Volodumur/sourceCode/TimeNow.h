#pragma once
class TimeNow
{
private:
	time_t t;
	struct tm *t_m;
public:
	TimeNow(void);
	~TimeNow(void);
	void now();
};




