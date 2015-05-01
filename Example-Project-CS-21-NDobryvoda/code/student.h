#include<iostream>
#include<vector>
#include<string>
#include"global.h"
using namespace std;

#if !defined(STUDENT_HEADER)
#define STUDENT_HEADER

class Student
{
private:
	string name;
	vector<int> rate;	//тут оцінки, оцінки по предмету доступні по індексу предмета. 
public :
	Student();
	Student(string _name, vector<int> _rate);
	int GetRateOfTraining(int trainingIndex);
	double GetMiddleRate();
	void Show();
	string Name();
	vector<int> GetRate();
};
#endif